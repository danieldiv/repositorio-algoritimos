#ifndef READ_HPP
#define READ_HPP

#include <util.hpp>

#include <fstream>

class Read {
private:
public:
	Read();
	~Read();

	void readFile(string path);
	void createFile(string path);
};

#endif