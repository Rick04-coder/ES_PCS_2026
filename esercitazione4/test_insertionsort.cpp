#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>           // per rand()
#include "randfiller.h"
#include "sort_algorithms.hpp"
using namespace std;

int main() {
	randfiller rf;
	
	// test su 100 vettori di dimensioni casuali tra (0 e 500)
	for (int k = 0; k < 100; k++)
	{
		int random_size = rand() % 500;     // resto divisione per 500 da numeri tra 0 e 499
		vector<int> vi(random_size);
		vector<float> vf(random_size);
		vector<double> vd(random_size);
		rf.fill(vi, -1000, 1000);
		rf.fill(vf, -1000.0f, 1000.0f);
		rf.fill(vd, -1000.0, 1000.0);
		
		insertion_sort(vi);
		insertion_sort(vf);
		insertion_sort(vd);
		
		if (!is_sorted(vi))
		{
			cerr << "Insertionsort fallito su vettore int" << endl;
			return EXIT_FAILURE;
		}
		if (!is_sorted(vf))
		{
			cerr << "Insertionsort fallito su vettore float" << endl;
			return EXIT_FAILURE;
		}
		if (!is_sorted(vd))
		{
			cerr << "Insertionsort fallito su vettore double" << endl;
			return EXIT_FAILURE;
		}
	}
	
	// test su vettore stringhe
	vector<string> vs = {"zaino", "mamma", "cielo", "banana", "albero", "giostra", "piatto", "pavimento", "dosso", "arancia"};
	bubble_sort(vs);
	
	if (!is_sorted(vs))
	{
		cerr << "Insertionsort fallito su vettore stringhe" << endl;
		return EXIT_FAILURE;
	}
	cout << "Insertionsort: tutti i test superati" << endl;
	return EXIT_SUCCESS;
}