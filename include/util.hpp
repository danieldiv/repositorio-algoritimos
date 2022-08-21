#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include <string.h>

using namespace std;

class Util {
private:
public:
	Util();
	~Util();

	// C
	void tokenizar(char *str);
	bool compararString(char *str1, char *str2);

	// C++
	void tokenizar(string text);
	void printMap(map<int, int> mapeamento);
	void compararString(string str1, string str2);
};

#endif