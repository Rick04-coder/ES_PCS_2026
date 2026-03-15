#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    // Controllo se l'utente ha passato il nome del file
    if (argc < 2) 
	{
        cerr << "Errore: specifica il file" << endl;
        return 1;
    }

    // Controllo corretta apertura file (argv[1] contiene nome file in input)
    ifstream file(argv[1]);
    if (!file.is_open()) 
	{
        cerr << "Errore lettura file " << argv[1] << endl;
        return 1;
    }

    string citta;
    double t1, t2, t3, t4;

    while (file >> citta >> t1 >> t2 >> t3 >> t4)    // restituisce False se il file è finito 
	{
        double media = (t1 + t2 + t3 + t4) / 4.0;
        cout << citta << " " << media << endl;
    }

    return 0;
}