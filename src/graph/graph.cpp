#include "graph.h"

Vertex vertex_create(int value) {
	Vertex v = (Vertex)malloc(sizeof(Vertex));
	v->value = value;
	v->prox = NULL;
	return v;
}

Graph graph_create(int V) {
	Graph G = (Graph)malloc(sizeof(Graph));
	G->V = V;
	G->E = 0;
	G->adj = (Vertex *)malloc(V * sizeof(Vertex));
	for (int v = 0; v < V; v++) {
		G->adj[v] = vertex_create(v);
	}
	return G;
}

void graph_add_edge(Graph G, Vertex v1, Vertex v2) {
	Vertex v = G->adj[v1->value];
	while (v->prox != NULL) {
		if (v->value == v2->value)
			return;
		v = v->prox;
	}
	v->prox = vertex_create(v2->value);
	G->E++;
}

void graph_destroy(Graph G) {
	for (int v = 0; v < G->V; v++) {
		Vertex aux = G->adj[v];
		while (aux != NULL) {
			Vertex temp = aux;
			aux = aux->prox;
			free(temp);
		}
	}
	free(G->adj);
	free(G);
}

void graph_print(Graph G) {
	for (int v = 0; v < G->V; v++) {
		Vertex aux = G->adj[v];
		while (aux != NULL) {
			std::cout << getName(aux->value) << " -> ";
			aux = aux->prox;
		}
		if (aux != NULL)
			std::cout << getName(aux->value);
		printf("\n");
	}
}

std::string getName(int posicao) {
	std::string nomes[] = { "s", "w", "r", "v", "t", "x", "u", "y" };
	return (posicao == -1) ? "NULL" : nomes[posicao];
}