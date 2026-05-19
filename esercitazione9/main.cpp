#include <iostream>
#include <vector>

#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include "containers.hpp"
#include "graph_visit.hpp"
#include "write_graph_dot.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"

int main() {
    // Creazione del grafo originale G
    unidirected_graph<int> G;

    std::cout << "Creazione Grafo di Test" << std::endl;
        
    G.add_edge(unidirected_edge<int>(1, 2));
    G.add_edge(unidirected_edge<int>(1, 3));
    G.add_edge(unidirected_edge<int>(2, 4));
    G.add_edge(unidirected_edge<int>(2, 5));
    G.add_edge(unidirected_edge<int>(3, 6));
    G.add_edge(unidirected_edge<int>(3, 7));
    G.add_edge(unidirected_edge<int>(4, 8)); 
    G.add_edge(unidirected_edge<int>(5, 6)); 
    G.add_edge(unidirected_edge<int>(7, 8)); 

    // contenitori
    fifo<int> q; // Per BFS
    lifo<int> s; // Per DFS

    // visite (partendo dal nodo 1)
    std::cout << "Esecuzione visite..." << std::endl;
    auto bfs_tree = graph_visit(G, 1, q);
    auto dfs_tree = graph_visit(G, 1, s);
	auto rec_dfs_tree = recursive_dfs(G, 1);
	auto dijkstra_tree = dijkstra(G, 1);

    // file DOT per GraphViz
    std::cout << "Generazione file .dot..." << std::endl;
    write_graph_dot(G, "0_originale.dot");
    write_graph_dot(bfs_tree, "1_bfs_tree.dot");
    write_graph_dot(dfs_tree, "2_dfs_tree.dot");
	write_graph_dot(rec_dfs_tree, "3_recursive_dfs_tree.dot");
	write_graph_dot(dijkstra_tree, "4_dijkstra_tree.dot");

    std::cout << "\nFile generati" << std::endl;
       
    return 0;
}