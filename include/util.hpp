#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Util {
private:
public:
	Util();
	~Util();

	void tokenizar(string text);
	void printMap(map<int, int> mapeamento);
};

#endif