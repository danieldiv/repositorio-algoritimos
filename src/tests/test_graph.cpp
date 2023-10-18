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

	cout << endl << "BFS" << endl << endl;

	G = graph_create(8);



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
	cout << endl;
	BFS(G, s_);
	graph_destroy(G);
}