#include <iostream>
#include <vector>
#include "timecounter.h"
#include "randfiller.h"
#include "sort_algorithms.hpp"

using namespace std;

// confronto i tempi per trovare da quale n in giù i quadratici vincono.
// "\t" suggerito da AI per rappresentazione dei dati


int main() {
    randfiller rf;
	timecounter tc;
    const int NUM_VECTORS = 100; 
    
    cout << "N\tBubble\tSelect\tInsert\tQuick\tMerge" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int n = 2; n <= 60; n += 2) {
         
        vector<vector<double>> base_data(NUM_VECTORS, vector<double>(n));
        for (int i = 0; i < NUM_VECTORS; i++) {
            rf.fill(base_data[i], -1000.0, 1000.0); 
        }

        // BUBBLESORT
        vector<vector<double>> v_bubble = base_data;
        tc.tic(); // 
        for (int i = 0; i < NUM_VECTORS; i++) {
            bubble_sort(v_bubble[i]);
        }
        double t_bubble = tc.toc() / NUM_VECTORS; 

        // SELECTIONSORT
        vector<vector<double>> v_select = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) {
            selection_sort(v_select[i]);
        }
        double t_select = tc.toc() / NUM_VECTORS;

        // INSERTIONSORT
        vector<vector<double>> v_insert = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) {
            insertion_sort(v_insert[i]);
        }
        double t_insert = tc.toc() / NUM_VECTORS;

        // QUICKSORT
        vector<vector<double>> v_quick = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) {
            quick_sort(v_quick[i]);
        }
        double t_quick = tc.toc() / NUM_VECTORS;

        // MERGESORT
        vector<vector<double>> v_merge = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) {
            merge_sort(v_merge[i]);
        }
        double t_merge = tc.toc() / NUM_VECTORS;

        cout << n << "\t" << t_bubble << "\t" << t_select << "\t" << t_insert << "\t" << t_quick << "\t" << t_merge;

        if (t_insert < t_quick) {
            cout << " <--- Quadratico migliore";
        }
        cout << endl;
    }

    return 0;
}