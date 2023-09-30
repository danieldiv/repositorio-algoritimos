#include "execute.h"

/**
 * @brief trabalhando com arquivos
 *
 */
void execute_arquivo() {
	Arquivo r;
	Util u;
	string texto;

	cout << "\nLENDO E ESCREVENDO NO ARQUIVO" << endl << endl;

	char *str = (char *)malloc(sizeof(char) * 100);

	cout << "C" << endl << endl;

	strcpy(str, "text2");
	r.readFile(str);
	r.createFile();

	cout << endl << endl;

	r.readFileIntervalo(11, str);
	free(str);

	cout << endl << "\nC++" << endl << endl;

	texto.assign("text.txt");
	r.readFile(texto);
	r.readFileTokenizando(texto);

	texto.assign("newFile.txt");
	r.createFile(texto);

	cout << "\n======================" << endl << endl;
}