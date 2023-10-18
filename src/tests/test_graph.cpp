#include "execute.h"

/**
 * @brief grafo
 *
 */
void execute_graph() {
	cout << endl << "GRAFO" << endl << endl;

	Graph G = graph_create(10);

	graph_add_edge(G, G->adj[0], G->adj[2]);
	graph_add_edge(G, G->adj[0], G->adj[1]);
	graph_add_edge(G, G->adj[1], G->adj[0]);
	graph_add_edge(G, G->adj[1], G->adj[4]);
	graph_add_edge(G, G->adj[1], G->adj[5]);
	graph_add_edge(G, G->adj[2], G->adj[0]);
	graph_add_edge(G, G->adj[2], G->adj[3]);
	graph_add_edge(G, G->adj[3], G->adj[2]);
	graph_add_edge(G, G->adj[4], G->adj[1]);
	graph_add_edge(G, G->adj[4], G->adj[5]);
	graph_add_edge(G, G->adj[4], G->adj[6]);
	graph_add_edge(G, G->adj[5], G->adj[1]);
	graph_add_edge(G, G->adj[5], G->adj[4]);
	graph_add_edge(G, G->adj[5], G->adj[6]);
	graph_add_edge(G, G->adj[5], G->adj[7]);
	graph_add_edge(G, G->adj[6], G->adj[4]);
	graph_add_edge(G, G->adj[6], G->adj[5]);
	graph_add_edge(G, G->adj[6], G->adj[7]);
	graph_add_edge(G, G->adj[7], G->adj[6]);
	graph_add_edge(G, G->adj[7], G->adj[5]);

	graph_print(G);
	graph_destroy(G);
}