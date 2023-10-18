#include "graph/bfs.h"

void BFS(Graph g, int s) {
	int *cor = (int *)malloc(g->V * sizeof(int));
	int *d = (int *)malloc(g->V * sizeof(int));
	int *pi = (int *)malloc(g->V * sizeof(int));

	for (int u = 0; u < g->V; u++) {
		cor[u] = BRANCO;
		d[u] = INF;
		pi[u] = -1; // NULL
	}

	cor[s] = CINZA;
	d[s] = 0;
	pi[s] = -1;
	std::queue<int> Q;

	Q.push(s);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (Vertex v = g->adj[u]; v != NULL; v = v->prox) {
			if (cor[v->value] == BRANCO) {
				cor[v->value] = CINZA;
				d[v->value] = d[u] + 1;
				pi[v->value] = u;
				Q.push(v->value);
			}
		}
		cor[u] = PRETO;
	}

	for (int i = 0; i < g->V; i++) {
		std::cout << "d[" << getName(i) << "]: " << getName(d[i]) << " -> ";
		std::cout << "pi[" << getName(i) << "]: " << getName(pi[i]) << std::endl;
	}
	free(cor);
	free(d);
	free(pi);
}

std::string getName(int posicao) {
	std::string nomes[] = {"s", "w", "r", "v", "t", "x", "u", "y"};
	return (posicao == -1) ? "NULL" : nomes[posicao];
}