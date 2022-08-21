#include "arquivo.hpp"
#include "class_template.hpp"

void _arquivo();
void _class_template();
void _util();

template <typename T> T function_template(T a, T b);
template <typename T, typename U> void controlVector(vector<T> vec);
template <typename T, typename U> void controlMap(map<T, vector<U>> mapeamento);

int main() {
	_arquivo();
	_class_template();
	_util();

	return EXIT_SUCCESS;
}

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
template <typename T>
void controlVector(vector<T> vec) {
	ClassTemplate <T, void>ct;

	ct.printVector(vec);
}

template <typename T, typename U>
void controlMap(map<T, vector<U>> mapeamento) {
	ClassTemplate <T, U>ct;

	ct.printMap(&mapeamento);
}

/**
 * @brief trabalhando com arquivos
 *
 */
void _arquivo() {
	Arquivo r;
	Util u;
	string texto;

	cout << "\nLENDO E ESCREVENDO NO ARQUIVO" << endl << endl;

	char *str = (char *)malloc(sizeof(char) * 100);

	cout << "C" << endl << endl;

	strcpy(str, "text2");
	r.readFile(str);
	r.createFile();

	cout << endl << "\nC++" << endl << endl;

	texto.assign("text.txt");
	r.readFile(texto);
	r.createFile("newFile.txt");

	cout << "\n======================" << endl << endl;
}

/**
 * @brief funcoes que utilizam template
 *
 */
void _class_template() {
	string texto;

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

	controlVector<string>(v1);
	controlVector<int>(v2);

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

	cout << "======================" << endl << endl;
}

/**
 * @brief funcoes uteis
 *
 */
void _util() {
	Arquivo r;
	Util u;

	char *str = (char *)malloc(sizeof(char) * 100);
	char *str2 = (char *)malloc(sizeof(char) * 100);

	cout << "COMPARAR STRINGS" << endl << endl;

	strcpy(str, "daniel");
	strcpy(str2, "daniel");

	cout << "C" << endl << endl;
	cout << str << " - " << str2 << " -> ";
	cout << u.compararString(str, str2) << endl;

	strcpy(str2, "alves");

	cout << str << " - " << str2 << " -> ";
	cout << u.compararString(str, str2) << endl;

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
	str = (char *)malloc(sizeof(char) * 100);
	strcpy(str, "texto de char,possui,virgulas");

	cout << "C" << endl << endl;
	u.tokenizar(str);

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

	cout << "\n======================" << endl << endl;
}