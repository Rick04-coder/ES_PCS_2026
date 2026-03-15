#include <iostream>

using namespace std;

// il numero di parametri digitati viene salvato in argc, argv (indicizzato dallo zero) contiene i parametri digitati 

int main(int argc, const char *argv[])
{
	cout << "Numero di parametri: " << argc << "\n";
	for (int i = 0; i < argc; i++)
	{
		cout << "Parametro " << i << " = " << argv[i] << "\n";
	}
	return 0;
}
