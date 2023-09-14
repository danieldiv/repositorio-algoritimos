#include "./include/util.hpp"
#include "./include/arquivo.hpp"

#include "./tree/binary_tree_1.hpp"
#include "./tree/binary_tree_2.hpp"
#include "./tree/binary_tree_3.hpp"
#include "./tree/avl_tree.hpp"
#include "./tree/huffman_tree.hpp"


#define MAX 4
#define endl '\n'
#define dbg(x) cout << #x << x << endl

// void _class_template();
// void _arquivo();
// void _util();
void _arvores();

template <typename T> T function_template(T a, T b);
template <typename T, typename U> void controlVector(vector<T> &vec);
template <typename T, typename U> void controlMap(map<T, vector<U>> &mapeamento);

#include <unordered_map>

int main() {
	// _arquivo();
	// _class_template();
	// _util();
	_arvores();

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
void controlVector(vector<T> &vec) {
	ClassTemplate <T, void>ct;

	ct.printVector(vec);
}

template <typename T, typename U>
void controlMap(map<T, vector<U>> &mapeamento) {
	ClassTemplate <T, U>ct;

	ct.printMap(mapeamento);

	cout << "Utilizando for each para imprimir map" << endl << endl;
	ct.printMapForEach(mapeamento);
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

	map<int, int> mapeamento;

	mapeamento.insert({ 2,6 });
	mapeamento.insert({ 1,5 });
	mapeamento.insert({ 6,26 });

	int val = 2;
	auto it = mapeamento.find(val);

	cout << "o find retorna o indice do mapeamento" << endl;
	if (it != mapeamento.end()) cout << "encontrou" << endl;
	else cout << "nao encontrou" << endl;

	bool b = mapeamento.contains(val);

	cout << "\no contains retorna true ou false" << endl;
	if (b) cout << "encontrou" << endl;
	else cout << "nao encontrou" << endl;
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

/**
 * @brief funcoes uteis
 *
 */
void _util() {
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

void _arvores() {
	cout << "Arvore binaria simples C\n\n";

	Tree_1 *raiz_1;
	Record_1 r;

	raiz_1 = createTree();

	int vetor[] = { 33, 47, 28, 19, 25, 60, 8, 39 };
	int tam = sizeof(vetor) / sizeof(vetor[0]);

	printf("Elementos arvore: { ");
	for (int i = 0; i < tam; i++) {
		r.key = vetor[i];
		printf("%d ", r.key);
		insertItem(&raiz_1, r);
	}
	printf("}\n\n");

	printf("Pre Ordem: { ");
	preordem(raiz_1);

	printf("}\nCentral:   { ");
	central(raiz_1);

	printf("}\nPos Ordem: { ");
	posordem(raiz_1);
	printf("}\n");

	r.key = 39;
	removeItem(&raiz_1, r);

	printf("\nRemove (39) \nCentral:   { ");
	central(raiz_1);

	printf("}\nPre Ordem: { ");
	preordem(raiz_1);

	printf("}\nPos Ordem: { ");
	posordem(raiz_1);
	printf("}\n");

	cout << "======================" << endl << endl;

	cout << "Arvore binaria simples C++\n\n";

	Tree_2 *raiz_2;
	// Tree_2 *raiz_2 = new Tree_2();
	Record_2 rec_2;
	raiz_2 = raiz_2->createTreeClass();

	printf("Elementos arvore: { ");
	for (int i = 0; i < tam; i++) {
		rec_2.key = vetor[i];
		printf("%d ", rec_2.key);
		raiz_2->insertItemClass(&raiz_2, rec_2);
	}
	printf("}\n\n");

	printf("Pre Ordem: { ");
	raiz_2->preordemClass(raiz_2);

	printf("}\nCentral:   { ");
	raiz_2->centralClass(raiz_2);

	printf("}\nPos Ordem: { ");
	raiz_2->posordemClass(raiz_2);
	printf("}\n");

	rec_2.key = 25;
	raiz_2->removeItemClass(&raiz_2, rec_2);

	printf("\nRemove Class(25) \nPre Ordem: { ");
	raiz_2->preordemClass(raiz_2);

	printf("}\nCentral:   { ");
	raiz_2->centralClass(raiz_2);

	printf("}\nPos Ordem: { ");
	raiz_2->posordemClass(raiz_2);
	printf("}\n");

	cout << "======================" << endl << endl;

	cout << "Arvore binaria simples com nó C++\n\n";

	Tree_3 raiz_3;

	vector<Record_3> vecR = {
		Record_3(5),
		Record_3(23),
		Record_3(96),
		Record_3(33),
		Record_3(68)
	};

	for (auto &r : vecR) raiz_3.insert(r);

	raiz_3.preOrdem();
	raiz_3.central();
	raiz_3.posOrdem();

	freeRaiz_1(raiz_1);
	raiz_2->freeRaiz_2(raiz_2);

	// arvore AVL

	Tree_AVL *raiz_avl = createTree_AVL();
	Tree_1 *raiz_binaria = createTree();

	vector<Record_AVL> vec_rec_avl;
	auto vetor_aux = { 10,5,3,24,24,87,34,9 };

	Record_AVL rec_AVL;

	for (auto v : vetor_aux) {
		rec_AVL.key = v;
		vec_rec_avl.push_back(rec_AVL);
	}
	for (auto ra : vec_rec_avl) {
		insertItem_AVL(&raiz_avl, ra);
		Record_1 r;
		r.key = ra.key;
		insertItem(&raiz_binaria, r);
	}

	cout << endl << "Arvore Binaria AVL em C";
	cout << endl << "comparando com arvore binaria simples" << endl;

	cout << endl << "Pre Ordem AVL: { ";
	preordem_AVL(raiz_avl);
	cout << "}\nPre Ordem BIN: { ";
	preordem(raiz_binaria);
	cout << "}" << endl;


	cout << endl << "Removendo valores ( 10, 6, 3 )" << endl;

	rec_AVL.key = 10;
	removeItem_AVL(&raiz_avl, &raiz_avl, rec_AVL);
	rec_AVL.key = 6;
	removeItem_AVL(&raiz_avl, &raiz_avl, rec_AVL);
	rec_AVL.key = 3;
	removeItem_AVL(&raiz_avl, &raiz_avl, rec_AVL);

	cout << endl << "Pre Ordem AVL: { ";
	preordem_AVL(raiz_avl);
	cout << "}\nPre Ordem BIN: { ";
	preordem(raiz_binaria);
	cout << "}" << endl;

	free_AVL(raiz_avl);
	freeRaiz_1(raiz_binaria);

	cout << "\n======================" << endl << endl;

	cout << "Arvore de Huffman" << endl << endl;

	auto raiz_huffman = std::make_shared<Huffman_Tree>();

	raiz_huffman->insere(std::make_shared<NO_Huffman>("f", 5));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("e", 9));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("c", 12));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("b", 13));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("d", 16));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("a", 45));

	raiz_huffman->constroi();
	raiz_huffman->imprime();

	cout << "\n\n======================" << endl << endl;
}