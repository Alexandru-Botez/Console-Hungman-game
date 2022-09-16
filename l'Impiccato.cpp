
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define invio 13
#define cancella 8
#define MAX_ERRORI 9

// Stampo il menu del gioco
void stampaMenu()
{
	cout << "============================== \n";
	cout << "||      IMPICCATO           || \n";
	cout << "||   scegli una opzione     || \n";
	cout << "============================== \n";
	cout << "1) Inserisci una parola \n";
   	cout << "2) Genera una parola  \n";
   

}

// Prende l'input e controlla che sia uno valido
int inputUtenteF()
{
	int temp{};

	cin >> temp;
	
	while (temp <= 0 || temp >= 3)
	{
		cout << "Errore! deve essere per forza 1 o 2 \n";
		cin >> temp;
	}

    return temp;
}

void inserisciUnaParola(string& parola)
{
    bool carattere = false;
    char c;
    cout << "Inserisci la parola:";

    do {

        // Prendo il carattere come input
        c = _getch();

        // Trasformo il carattere in maiuscolo 
        c = toupper(c);


        // Se l'utente preme invio vado a capo  
        if (c == invio)
            cout << '\n';

        // Se l'utente preme cancella elimino la parola
        if (c == cancella && parola.length() > 0)
        {
            parola.erase(parola.end() - 1);
            cout << c << ' ' << c;
        }

        // Se l'utente utilizza un carrattere diverso dall'alfabeto ritenta con l'input
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            continue;

        //Aggiungo parola e stampo l'asterisco nella console
        parola += c;
        cout << '*';


    } while (c != invio);

    system("cls");
}

void generaParolaNascosta(string& parola,string& parola_nascosta)
{
    for (int i{ 0 }; i < parola.size(); ++i)
    {
        if (i == 0 || i == parola.size() - 1)
            parola_nascosta += parola[i];
        else
            parola_nascosta += '_';

    }
}

void stampaParolaNascostaEsbagliata(string& parola_nascosta,char* lettera_usata,int conta_parole_usate)
{
    for (int i{ 0 }; i < parola_nascosta.size(); ++i)
    {
        cout << parola_nascosta[i] << " ";
    }

    cout << '\n';
    cout << "Lettere usate: ";

    for (int i{ 0 }; i < conta_parole_usate; ++i)
    {
        cout << lettera_usata[i] << " ";
    }

    cout << '\n';
}

int contaParoleSbagliateF(bool indovinato,int &conta_parole_sbagliate)
{

    if (!indovinato)
        ++conta_parole_sbagliate;

    return conta_parole_sbagliate;
}


char inputF(char* lettera_usata,int conta_parole_usate)
{
 
    char temp{};
    bool uguale{ false };


    do {
        uguale = false;
        
        cout << "Prova ad indovinare inserendo una lettera, diversa da quelle usate:";
        cin >> temp;

        temp = toupper(temp);

        for (int i{ 0 }; i < conta_parole_usate; ++i)
        {
            if (lettera_usata[i] == temp)
            {
                uguale = true;
            }
        }
    } while (uguale);

    return temp;

}

int controllaInput(char lettera_scelta,string& parola,char* lettera_usata,string& parola_nascosta, int& conta_parole_usate,int& conta_parole_sbagliate)
{
    bool indovinato{ false };




    for (int i{ 1 }; i < parola.size() - 1; ++i)
    {
        if (parola[i] == lettera_scelta)
        {
            parola_nascosta[i] = lettera_scelta;
            indovinato = true;
        }

    }


    lettera_usata[conta_parole_usate] = lettera_scelta;
    ++conta_parole_usate;

    return contaParoleSbagliateF(indovinato,conta_parole_sbagliate);



}

void controllaVittoria(string& parola,string& parola_nascosta,bool& esecuzione,int conta_parole_sbagliate)
{
    int conta_parole_temp{ 0 };

    if (conta_parole_sbagliate == 8)
    {
        esecuzione = false;
        cout << "Hai perso! \n";
        cout << "La parola era: " << parola << '\n';
    }
  


    for (int i{ 0 }; i < parola.length(); ++i)
    {
        if (parola[i] == parola_nascosta[i])
        {
            ++conta_parole_temp;
        }
    }

    if (parola.length() == conta_parole_temp)
    {
        esecuzione = false;
        cout << "Hai vinto! \n";
    }
      

}

void contaTentativi(int conta_parole_sbagliate)
{

    cout << "Tentativi usati (8 max): " << conta_parole_sbagliate << '\n';
    
}

   
void stampaOmino(int conta_parole_sbagliate)
{
    switch (conta_parole_sbagliate)
    {
    case 0:
        cout << "  +-------+ \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 1:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 2:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 3:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 4:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << " /        | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 5:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << " /|       | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 6:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << " /|\\      | \n";
        cout << "          | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    case 7:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << " /|\\      | \n";
        cout << " /        | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;

    case 8:
        cout << "  +-------+ \n";
        cout << "  |       | \n";
        cout << "  |       | \n";
        cout << "  O       | \n";
        cout << " /|\\      | \n";
        cout << " / \\      | \n";
        cout << "          | \n";
        cout << "=========== \n";
        break;
    default:
        cout << "error!";

    }
}

void parolaMaiuscolo(string& parola)
{
    for (int i{ 0 }; i < parola.length(); ++i)
    {
        parola[i] = toupper(parola[i]);
    }
}



int main()
{
	string parola{};
    string parola_nascosta{};
    char lettera_usata[50];
    int dim_logica_lettera_usata{};
    int conta_parole_usate{0};
    int conta_parole_sbagliate{0};
    bool esecuzione{ true };
    ifstream fin("parole.txt");
    srand(time(NULL));

        stampaMenu();
        int inputUtente = inputUtenteF();
        int counter{ 0 };
        int random = rand() % (1080 - 1 + 1) + 1;


        switch (inputUtente)
        {
            case 1:
                inserisciUnaParola(parola);
                generaParolaNascosta(parola, parola_nascosta);
                break;
            case 2:
               while (counter < random)
               {
                   fin >> parola;
                   ++counter;
               }
               parolaMaiuscolo(parola);
               generaParolaNascosta(parola, parola_nascosta);

                break;
   

        }

		do
		{
            switch (inputUtente)
            {
                case 1:
                case 2:
                    system("cls");
                    stampaParolaNascostaEsbagliata(parola_nascosta, lettera_usata, conta_parole_usate);
                    contaTentativi(conta_parole_sbagliate);
                    stampaOmino(conta_parole_sbagliate);
                    controllaVittoria(parola, parola_nascosta, esecuzione, conta_parole_sbagliate);

                    if (esecuzione)
                    { 
                        char lettera_scelta = inputF(lettera_usata, conta_parole_usate);
                        controllaInput(lettera_scelta, parola, lettera_usata, parola_nascosta, conta_parole_usate, conta_parole_sbagliate);
                    }
                    break;

                default:
                    cout << "Input Utente inesistente!";

            }

		} while (esecuzione);

        return 0;
}

