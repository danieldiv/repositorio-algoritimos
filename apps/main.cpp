#include "read.hpp"

int main() {
	Read r;

	r.readFile("text.txt");
	r.createFile("newFile.txt");

	return EXIT_SUCCESS;
}