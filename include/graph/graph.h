#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

struct TipoVertex {
	int value;
	Vertex prox;
};

struct graph {
	int V;
	int E;
	Vertex *adj;
};

Vertex vertex_create(int value);
Graph graph_create(int V);
void graph_add_edge(Graph G, Vertex v1, Vertex v2);
void graph_destroy(Graph G);
void graph_print(Graph G);

#endif