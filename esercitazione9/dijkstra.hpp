#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <queue>
#include <map>
#include <vector>
#include <utility>
#include "unidirected_graph.hpp"

// calcola albero dei cammini minimi assumendo che ogni arco abbia peso 1 (risultato equivalente al bfs)

template <typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& g, const T& source) {
	unidirected_graph<T> shortest_path_tree;
	
	// controllo esistenza sorgente
	if (g.all_nodes().find(source) == g.all_nodes().end()) {
		return shortest_path_tree;
	}
	
	std::map<T, int> distances;   // distanza minima da source a ogni nodo
	std::map<T, T> parents;       // padre di ogni nodo nel cammino minimo
	
	// ordina gli elementi in modo che il nodo con la distanza minore sia il primo
	using DistNode = std::pair<int, T>;     // coppie distanza nodo
	std::priority_queue<DistNode, std::vector<DistNode>, std::greater<DistNode>> pq;
	                // <tipoElemento, Contenitore, CriterioOrdinamento>
	
	distances[source] = 0;
	pq.push({0, source});
	shortest_path_tree.add_node(source);
	
	while (!pq.empty()) {
		auto [current_dist, u] = pq.top();
		pq.pop();
		
		// se ha già trovato un cammino migliore, salta alla prossima iterazione
		if (current_dist > distances[u]) {
			continue;
		}
		
		// esploro vicini
		for (const T& v : g.neighbours(u)) {
			int peso_edge = 1;
			int altern_dist = distances[u] + peso_edge;
			
			// se il nuovo vicino non è mai stato raggiunto o se cammino più breve
			if (distances.find(v) == distances.end() || altern_dist < distances[v]) {
				distances[v] = altern_dist;
				parents[v] = u;
				pq.push({altern_dist, v});
			}
		}
	}
	
	// ricostruisco albero unendo nodi ai padri ottimali
	for (const auto& [v, u] : parents) {
		shortest_path_tree.add_node(v);
		shortest_path_tree.add_edge(unidirected_edge<T>(u, v));
	}
	
	return shortest_path_tree;
}

#endif