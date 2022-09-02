#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include <string.h>
#include <stdio.h>

using namespace std;

#define VERMELHO "\x1b[31m"
#define VERDE    "\x1b[32m"
#define AZUL     "\x1b[34m"
#define RESET    "\x1b[0m"

class Util {
private:
public:
	Util();
	~Util();

	// C
	void tokenizar(char *str);
	bool compararString(char *str1, char *str2);
	void mudarCorTerminal();

	// C++
	void tokenizar(string text);
	void printMap(map<int, int> mapeamento);
	void compararString(string str1, string str2);
};

#endif