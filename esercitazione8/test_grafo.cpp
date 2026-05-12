#include <iostream>
#include "unidirected_graph.hpp" 

int main() {
    // Creazione del grafo con nodi di tipo int
    unidirected_graph<int> G1;

    std::cout << "Test Inserimento" << std::endl;
    // Aggiungo archi. Aggiungo (5, 2) per testare l'ordinamento automatico
    G1.add_edge(unidirected_edge<int>(1, 2));
    G1.add_edge(unidirected_edge<int>(2, 3));
    G1.add_edge(unidirected_edge<int>(5, 2)); // Diventerà internamente (2, 5)

    // Test all_nodes()
    std::cout << "Nodi nel grafo G1: ";
    for (int n : G1.all_nodes()) {
        std::cout << n << " ";
    }
    std::cout << "\n"; // Dovrebbe stampare: 1 2 3 5

    // Test all_edges() e operator<<
    std::cout << "Archi nel grafo G1: ";
    for (const auto& e : G1.all_edges()) {
        std::cout << e << " ";
    }
    std::cout << "\n"; // Dovrebbe stampare: (1, 2) (2, 3) (2, 5)

    // Test neighbours()
    std::cout << "Vicini del nodo 2: ";
    for (int v : G1.neighbours(2)) {
        std::cout << v << " ";
    }
    std::cout << "\n"; // Dovrebbe stampare: 1 3 5

    // Test indicizzazione (edge_number e edge_at)
    unidirected_edge<int> cerca(5, 2); 
    int idx = G1.edge_number(cerca);
    std::cout << "L'arco (5, 2) ha indice: " << idx << std::endl;
    std::cout << "L'arco all'indice " << idx << " e': " << G1.edge_at(idx) << std::endl;

    // Test Operatore Differenza (G1 - G2)
    std::cout << "\n--- Test Differenza G1 - G2 ---" << std::endl;
    unidirected_graph<int> G2;
    G2.add_edge(unidirected_edge<int>(2, 3)); // Arco presente in entrambi

    unidirected_graph<int> diff = G1 - G2;
    std::cout << "Archi in G1 ma non in G2: ";
    for (const auto& e : diff.all_edges()) {
        std::cout << e << " ";
    }
    std::cout << "\n"; // Dovrebbe stampare: (1, 2) (2, 5)


    return 0;
}