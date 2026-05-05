#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "timecounter.h"
#include "randfiller.h"
#include "sort_algorithms.hpp"

using namespace std;

int main() {
    randfiller rf;
    timecounter tc; 
    ofstream outfile("tempi_ordinamento.txt");
    const int NUM_VECTORS = 100; 

    outfile << "N Bubble Selection Insertion Merge Quick QuickMod StdSort" << endl;

    for (int n = 4; n <= 8192; n *= 2) {
        cout << "Calcolo per N = " << n << "..." << endl;

        vector<vector<double>> base_data(NUM_VECTORS, vector<double>(n));
        for (int i = 0; i < NUM_VECTORS; i++) {
            rf.fill(base_data[i], -1000.0, 1000.0); 
        }

        // --- BUBBLE SORT ---
        vector<vector<double>> v_bubble = base_data;
        tc.tic(); 
        for (int i = 0; i < NUM_VECTORS; i++) bubble_sort(v_bubble[i]);
        double t_bubble = tc.toc() / NUM_VECTORS; 

        // --- SELECTION SORT ---
        vector<vector<double>> v_select = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) selection_sort(v_select[i]);
        double t_select = tc.toc() / NUM_VECTORS;

        // --- INSERTION SORT ---
        vector<vector<double>> v_insert = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) insertion_sort(v_insert[i]);
        double t_insert = tc.toc() / NUM_VECTORS;

        // --- MERGE SORT ---
        vector<vector<double>> v_merge = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) merge_sort(v_merge[i]);
        double t_merge = tc.toc() / NUM_VECTORS;

        // --- QUICK SORT ---
        vector<vector<double>> v_quick = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) quick_sort(v_quick[i]);
        double t_quick = tc.toc() / NUM_VECTORS;

        // --- QUICK SORT MODIFICATO ---
        vector<vector<double>> v_qmod = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) quick_sort_mod(v_qmod[i]);
        double t_qmod = tc.toc() / NUM_VECTORS;

        // --- STD::SORT  ---
        vector<vector<double>> v_std = base_data;
        tc.tic();
        for (int i = 0; i < NUM_VECTORS; i++) {
            std::sort(v_std[i].begin(), v_std[i].end()); 
        }
        double t_std = tc.toc() / NUM_VECTORS;

        
        outfile << n << " " << t_bubble << " " << t_select << " " << t_insert << " " << t_merge << " " << t_quick << " " << t_qmod << " " << t_std << endl;
    }

    outfile.close();
    cout << "File 'tempi_ordinamento.txt' generato" << endl;
    return 0;
}