#ifndef WRITE_GRAPH_DOT_HPP
#define WRITE_GRAPH_DOT_HPP

#include <fstream>
#include <string>
#include "unidirected_graph.hpp"

// Supporto AI
template <typename T>
void write_graph_dot(const unidirected_graph<T>& g, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Impossibile aprire il file per la scrittura");
    }

    // Per i grafi non orientati si usa 'graph', per quelli orientati 'digraph'
    out << "graph G {\n";
    out << "    node [shape=circle];\n"; // rende i nodi circolari

    // Scrivo tutti i nodi 
    for (const auto& node : g.all_nodes()) {
        out << "    \"" << node << "\";\n";
    }

    // Scrivo tutti gli archi
    // Uso '--' per grafi non orientati
    for (const auto& edge : g.all_edges()) {
        out << "    \"" << edge.from() << "\" -- \"" << edge.to() << "\";\n";
    }

    out << "}\n";
    out.close();
}

#endif