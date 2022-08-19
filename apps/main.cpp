#include "read.hpp"
#include "class_template.hpp"

/**
 * @brief realiza a soma de duas variaveis somaveis
 *
 * @tparam T tipo de variavel que pode ser somada, int, float, double ...
 * @param a
 * @param b
 * @return T retornar o valor de a e b somado
 */
template <typename T>
T function_template(T a, T b) {
	return a + b;
}

/**
 * @brief imprime um vector utilizando template
 * o tipo do vector eh do tipo T, o tipo U nao eh utilizado nesta funcao
 *
 * @tparam T
 * @tparam U
 * @param vec
 */
template <typename T, typename U>
void controlVector(vector<T> vec) {
	ClassTemplate <T, U>ct;

	ct.printVector(vec);
}

template <typename T, typename U>
void controlMap(map<T, vector<U>> mapeamento) {
	ClassTemplate <T, U>ct;

	ct.printMap(&mapeamento);
}

int main() {
	Read r;
	Util u;


	cout << "\nLENDO E ESCREVENDO NO ARQUIVO" << endl << endl;

	char *str = (char *)malloc(sizeof(char) * 100);
	string texto;

	cout << "C" << endl << endl;

	strcpy(str, "text2");
	r.readFile(str);
	r.createFile();

	cout << endl << "\nC++" << endl << endl;

	texto.assign("text.txt");
	r.readFile(texto);
	r.createFile("newFile.txt");

	cout << "\n======================" << endl << endl;

	cout << "TOKENIZANDO UMA STRING POR VIRGULA" << endl << endl;

	texto = "texto de string,possui,virgulas";
	str = (char *)malloc(sizeof(char) * 100);
	strcpy(str, "texto de char,possui,virgulas");

	cout << "C" << endl << endl;
	u.tokenizar(str);

	cout << "\nC++" << endl << endl;
	u.tokenizar(texto);

	cout << "\n======================" << endl << endl;

	cout << "UTILIZANDO FUNCAO COM TEMPLATE" << endl << endl;

	cout << function_template<int>(4, 6) << endl;
	cout << function_template<float>(6.2, 1.1) << endl;

	cout << "\n======================" << endl << endl;

	vector<string> v1;

	v1.push_back("janeiro");
	v1.push_back("fevereiro");
	v1.push_back("marco");
	v1.push_back("abril");

	vector<int> v2;

	v2.push_back(1243);
	v2.push_back(16);
	v2.push_back(66);
	v2.push_back(988);

	cout << "UTILIZANDO CLASSE COM TEMPLATE PARA IMPRIMIR O VECTOR" << endl << endl;

	controlVector<string, void>(v1);
	controlVector<int, void>(v2);

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

	cout << "\n======================" << endl << endl;

	map<int, vector<int>> map1;
	vector<int> v_map1;

	v_map1.push_back(1);
	v_map1.push_back(5);
	v_map1.push_back(122);
	v_map1.push_back(612);
	v_map1.push_back(13);

	map1.insert({ 34, v_map1 });

	map<int, vector<int>> map2;
	map2.insert({ 55, v2 });

	map<int, vector<string>> map3;
	map3.insert({ 7, v1 });

	map<string, vector<string>> map4;
	vector<string> v_map4;

	v_map4.push_back("MG");
	v_map4.push_back("SP");
	v_map4.push_back("AC");

	map4.insert({ "brasil", v_map4 });

	cout << "UTILIZANDO CLASSE COM TEMPLATE PARA IMPRIMIR O MAP" << endl << endl;

	controlMap<int, int>(map1); // <int, int>
	controlMap(map2); // se nao informa o tipo <T, U>, eh pego altomaticamente <int, int>
	controlMap(map3); // se nao informa o tipo <T, U>, eh pego altomaticamente <int, string>
	controlMap<string, string>(map4); // <string, string>

	return EXIT_SUCCESS;
}