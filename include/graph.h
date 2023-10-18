#ifndef GRAPH_H
#define GRAPH_H

#define s_ 0
#define w_ 1
#define r_ 2
#define v_ 3
#define t_ 4
#define x_ 5
#define u_ 6
#define y_ 7

#include <iostream>
#include <queue>
#include <string>

#include <stdio.h>
#include <stdlib.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

const int INF = 0x3f3f3f3f;

enum Cores {
	BRANCO,
	CINZA,
	PRETO
};

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

void BFS(Graph g, int s);
std::string getName(int posicao);

#endif