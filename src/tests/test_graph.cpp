#include "execute.h"

/**
 * @brief grafo
 *
 */
void execute_graph() {
	cout << endl << "GRAFO" << endl << endl;

	Graph G = graph_create(8);

	graph_add_edge(G, G->adj[s_], G->adj[r_]);
	graph_add_edge(G, G->adj[s_], G->adj[w_]);
	graph_add_edge(G, G->adj[w_], G->adj[s_]);
	graph_add_edge(G, G->adj[w_], G->adj[t_]);
	graph_add_edge(G, G->adj[w_], G->adj[x_]);
	graph_add_edge(G, G->adj[r_], G->adj[s_]);
	graph_add_edge(G, G->adj[r_], G->adj[v_]);
	graph_add_edge(G, G->adj[v_], G->adj[r_]);
	graph_add_edge(G, G->adj[t_], G->adj[w_]);
	graph_add_edge(G, G->adj[t_], G->adj[x_]);
	graph_add_edge(G, G->adj[t_], G->adj[u_]);
	graph_add_edge(G, G->adj[x_], G->adj[w_]);
	graph_add_edge(G, G->adj[x_], G->adj[t_]);
	graph_add_edge(G, G->adj[x_], G->adj[u_]);
	graph_add_edge(G, G->adj[x_], G->adj[y_]);
	graph_add_edge(G, G->adj[u_], G->adj[t_]);
	graph_add_edge(G, G->adj[u_], G->adj[x_]);
	graph_add_edge(G, G->adj[u_], G->adj[y_]);
	graph_add_edge(G, G->adj[y_], G->adj[u_]);
	graph_add_edge(G, G->adj[y_], G->adj[x_]);

	graph_print(G);

	cout << endl << "BFS" << endl << endl;
	BFS(G, s_);

	cout << endl << "DFS" << endl;
	DFS(G);
	graph_destroy(G);
}