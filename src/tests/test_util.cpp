#include "execute.h"

/**
 * @brief funcoes uteis
 *
 */
void execute_util() {
	cout << "UTILIZANDO FUNCOES UTEIS" << endl << endl;
	Arquivo r;
	Util u;

	char *str1 = (char *)malloc(sizeof(char) * 100);
	char *str2 = (char *)malloc(sizeof(char) * 100);

	cout << "COMPARAR STRINGS" << endl << endl;

	strcpy(str1, "daniel");
	strcpy(str2, "daniel");

	cout << "C" << endl << endl;
	cout << str1 << " - " << str2 << " -> ";
	cout << u.compararString(str1, str2) << endl;

	strcpy(str2, "alves");

	cout << str1 << " - " << str2 << " -> ";
	cout << u.compararString(str1, str2) << endl;

	string s1, s2, texto;

	s1.assign("teste");
	s2 = "teste";

	cout << "\nC++" << endl << endl;
	u.compararString(s1, s2);

	s1.assign("hello");
	u.compararString(s1, s2);

	cout << "\n======================" << endl << endl;

	cout << "TOKENIZANDO UMA STRING POR VIRGULA" << endl << endl;

	texto = "texto de string,possui,virgulas";
	char *str3 = (char *)malloc(sizeof(char) * 100);
	strcpy(str3, "texto de char,possui,virgulas");

	cout << "C" << endl << endl;
	u.tokenizar(str3);

	cout << "\nC++" << endl << endl;
	u.tokenizar(texto);

	cout << "\n======================" << endl << endl;

	map<int, int> mapeamento;

	mapeamento.insert({ 2,6 });
	mapeamento.insert({ 1,5 });
	mapeamento.insert({ 6,26 });
	mapeamento.insert({ 7,222 });
	mapeamento[66] = 55;
	mapeamento[67] = 555;

	cout << "UTILIZANDO MAP DE FORMA COMUM" << endl << endl;

	u.printMap(mapeamento);

	cout << "\nMODIFICAR COR DA LINHA NO TERMINAL" << endl << endl;

	u.mudarCorTerminal();

	cout << "\nCOMBINACOES" << endl << endl;

	int *vec = (int *)malloc(sizeof(int) * MAX);

	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 3;
	vec[3] = MAX;

	int perm[MAX] = { 0 };

	cout << "C" << endl << endl;
	u.combinacoes(vec, perm, 0, MAX, 3);

	vector<int> vec2;

	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(6);
	vec2.push_back(7);

	cout << "\nC++" << endl << endl;
	u.combinacoes(vec2, perm, 0, MAX, 3);

	cout << "\n======================" << endl << endl;

	cout << "Colocar string em minusculo" << endl << endl;
	cout << "C++" << endl << endl;
	u.stringMinuscula();

	cout << "\n======================" << endl << endl;

	cout << "Utilizando vetor de matriz" << endl << endl;
	u.matrizTridimensional();

	cout << "======================" << endl;

	free(str1);
	free(str2);
	free(str3);
	free(vec);
}