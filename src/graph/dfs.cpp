#include "graph.h"

int *cor;
int *d;
int *f;
int tempo;

void DFS(Graph g) {
	cor = (int *)malloc(g->V * sizeof(int));
	d = (int *)malloc(g->V * sizeof(int));
	f = (int *)malloc(g->V * sizeof(int));

	for (int v = 0; v < g->V; v++) {
		cor[v] = BRANCO;
	}

	tempo = 0;

	for (int v = 0; v < g->V; v++) {
		if (cor[v] == BRANCO) {
			DFS_VISIT(g, v);
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < g->V; i++) {
		std::cout << "d[" << getName(i) << "]: " << d[i] << " -> ";
		std::cout << "f[" << getName(i) << "]: " << f[i] << std::endl;
	}
	free(cor);
	free(d);
	free(f);
}

void DFS_VISIT(Graph g, int v) {
	cor[v] = CINZA;
	tempo = tempo + 1;
	d[v] = tempo;

	for (Vertex u = g->adj[v]; u != NULL; u = u->prox) {
		if (cor[u->value] == BRANCO) {
			DFS_VISIT(g, u->value);
		}
	}
	cor[v] = PRETO;
	tempo = tempo + 1;
	f[v] = tempo;
}
