#ifndef BFS_H
#define BFS_H

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

#include "graph.h"

const int INF = 0x3f3f3f3f;

enum Cores {
	BRANCO,
	CINZA,
	PRETO
};

void BFS(Graph g, int s);
std::string getName(int posicao);

#endif