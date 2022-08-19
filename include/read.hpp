#ifndef READ_HPP
#define READ_HPP

#include <util.hpp>

#include <fstream>

class Read {
private:
public:
	Read();
	~Read();

	// C
	void readFile(char *path);
	void createFile();

	// C++
	void readFile(string path);
	void createFile(string path);
};

#endif