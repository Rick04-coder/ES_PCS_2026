#ifndef GRAPH_VISIT_HPP
#define GRAPH_VISIT_HPP

#include <set>
#include "unidirected_graph.hpp"
#include "containers.hpp"

template <typename T, typename Container>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& g, const T& source, Container c) {
	unidirected_graph<T> tree;
	
	// insieme nodi già visitati
	std::set<T> visited;
	
	// se il nodo sorgente non esiste nel grafo originale restituisco grafo vuoto
	auto nodes = g.all_nodes();
	if (nodes.find(source) == nodes.end()) {
		return tree;
	}
	
	// metto la sorgente nel contenitore, nell'albero e la segno come visitata
	c.put(source);
	visited.insert(source);
	tree.add_node(source);
	
	while (!c.empty()) {
		// estraggo il prossimo nodo da esplorare
		T u = c.get();
		
		// esploro tutti i vicini del nodo corrente
		for (const T& v : g.neighbours(u)) {
			// se il vicino non è ancora stato visitato aggiorno
			if (visited.find(v) == visited.end()) {
				visited.insert(v);
				c.put(v);
				tree.add_edge(unidirected_edge<T>(u,v));
			}
		}
	}
	
	return tree;
}

#endif