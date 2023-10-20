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

// const char *nomes[] = { "s", "w", "r", "v", "t", "x", "u", "y" };

#include <iostream>
#include <queue>
#include <string>

#include <stdlib.h>
#include <stdio.h>

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
std::string getName(int posicao);

void BFS(Graph g, int s);
void DFS(Graph g);
void DFS_VISIT(Graph g, int v);

#endif