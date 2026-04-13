#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "timecounter.h"
#include "randfiller.h"
#include "sort_algorithms.hpp"
using namespace std;

// non so se richiesto: ho scritto i tempi in un file di output txt.
// Dopo ho scritto un codice Matlab che legge i dati dal txt e li mette su grafico.
// Per il codice Matlab mi sono fatto aiutare da AI perché non ricordavo alcuni comandi.

int main() {
	randfiller rf;
	timecounter tc;
	ofstream outFile("dati_sorting.txt");   
	
	for (int n = 4; n <= 8192; n *= 2) 
	{
		vector<int> base(n);
		rf.fill(base, -1000, 1000);
		
		vector<int> v1 = base;
		vector<int> v2 = base;
		vector<int> v3 = base;
		vector<int> v4 = base;
		
		tc.tic();
		bubble_sort(v1);
		double t_bubble = tc.toc();
		
		tc.tic();
		insertion_sort(v2);
		double t_insert = tc.toc();
		
		tc.tic();
		selection_sort(v3);
		double t_select = tc.toc();
		
		tc.tic();
		sort(v4.begin(), v4.end());
		double t_sort = tc.toc();
		
		outFile << n << " " << t_bubble << " " << t_insert << " " << t_select << " " << t_sort << "\n";
	}
	outFile.close();
	return 0;
}