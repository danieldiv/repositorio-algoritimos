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

	// C++
	void tokenizar(string text);
	void printMap(map<int, int> mapeamento);
};

#endif