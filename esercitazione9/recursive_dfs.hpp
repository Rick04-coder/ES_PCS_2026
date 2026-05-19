#ifndef RECURSIVE_DFS_HPP
#define RECURSIVE_DFS_HPP

#include <set>
#include "unidirected_graph.hpp"

// funzione di supporto (parte ricorsiva di recursive_dfs)
template <typename T>
void dfs_supp(const unidirected_graph<T>& g, const T& u, std::set<T>& visited, unidirected_graph<T>& tree) {
	visited.insert(u);
	
	// esploro vicini
	for (const T& v : g.neighbours(u)) {
		// se vicino non è ancora stato visitato, lo esploro ricorsivamente
		if (visited.find(v) == visited.end()) {
			tree.add_edge(unidirected_edge<T>(u,v));
			dfs_supp(g, v, visited, tree);
		}
	}
}



// funzione principale
template <typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& g, const T& source) {
	unidirected_graph<T> tree;
	std::set<T> visited;
	
	//controllo esistenza nodo sorgente
	auto nodes = g.all_nodes();
	if (nodes.find(source) == nodes.end()) {
		return tree;
	}
	
	// aggiungo radice e inizio ricorsione
	tree.add_node(source);
	dfs_supp(g, source, visited, tree);
	
	return tree;
}

#endif