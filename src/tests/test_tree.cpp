#include "execute.h"

/**
 * @brief realiza operacoes com arvores
 *
 */
void execute_tree() {
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

	Tree_AVL_1 *raiz_avl = createTree_AVL();
	Tree_1 *raiz_binaria = createTree();

	vector<Record_AVL_1> vec_rec_avl;
	// auto vetor_aux = { 10,5,3,24,24,87,34,9 };
	// auto vetor_aux = { 10,20,30,40,50,34 };
	auto vetor_aux = { 10,2,7,5,3,9,16,4,11,1,6,23,14 };

	Record_AVL_1 rec_AVL;

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

	raiz_huffman->insere(std::make_shared<NO_Huffman>("huffman", 3));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("um", 5));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("codigo", 8));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("escrevendo", 9));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("texto", 12));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("a", 13));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("partir", 16));
	raiz_huffman->insere(std::make_shared<NO_Huffman>("do", 45));

	raiz_huffman->constroi();
	raiz_huffman->imprime();

	cout << endl << "Decodificando" << endl << endl;
	for (auto &code : { "1110", "11011", "1111", "100", "101", "0", "1100", "11010" })
		raiz_huffman->decode(code);

	cout << "\n\n======================" << endl << endl;

	cout << "Arvore AVL com no" << endl << endl;

	auto raiz_avl_no = std::make_shared<Tree_AVL_2>();

	for (auto &v : vetor_aux) raiz_avl_no->insert(Record_AVL_NO(v));

	raiz_avl_no->preOrdem();

	cout << "\n======================" << endl << endl;

	cout << "Arvore RB em C" << endl << endl;

	Record_RB_1 rec_rb;
	TreeRB_1 *raiz_rb;
	inicializaTreeRB(&raiz_rb);

	for (auto &v : vetor_aux) {
		rec_rb.key = v;
		insertItemRB(&raiz_rb, rec_rb);
	}

	preordemRB(raiz_rb);
	cout << endl << endl;
	cout << "removendo o valor 16" << endl << endl;
	rec_rb.key = 16;
	search_delete(&raiz_rb, raiz_rb, rec_rb);
	preordemRB(raiz_rb);
	cout << endl;

	cout << "\nArvore RB em C++" << endl << endl;

	auto raiz_rb_2 = make_shared<RB_Tree_2>();
	Record_RB_2 rec_rb_2;

	for (auto &v : vetor_aux) raiz_rb_2->insert(Record_RB_2(v));
	raiz_rb_2->preOrdem();
}