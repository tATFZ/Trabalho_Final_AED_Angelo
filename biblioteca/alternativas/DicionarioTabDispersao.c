/*
 * DicionarioTabDispersao.c
*/

#include "Dicionario.h"
#include "Lista.h"
#include "Par.h"
#include "Lista.h"

/*------------------------------------------*/
/* Constantes privadas */

#define NUM_LISTAS_INICIAL		16
#define TAXA_OCUPACAO_MAXIMA	3.0

/*------------------------------------------*/
/* Tipo privado */

struct Dicionario{
	Info info;
	lista *listas;	/* vetor de listas */
	int numListas;
	int numElems;
};

/*	Tabela de dispersao que resolve os conflitos usando
	endereçamento encadeado (listas de colisão).
	O dicionario guarda pares (chave, elem).
	As chaves nao podem ocorrer repetidas.
*/

/*------------------------------------------*/
/* Funcoes privadas */

static lista procuraDicionario(Dicionario d, obj ch, lista *prev, int *pos){
	*pos = dispersao(ch, d->numListas);
	*prev = NULL;
	for (lista l = d->listas[*pos]; l != NULL; *prev = l, l = l->seg){
		if (compara(valorAPar(l->elem), ch) == 0)
			return l;
	}
	return NULL;
}

// usado nos iteradores
static vetor chaves(Dicionario d, int *n){
	*n = d->numElems;
	vetor v = malloc(sizeof(obj) * d->numElems);
	if (v == NULL) semMemoria();
	for (int i = 0, j = 0 ; i < d->numListas; i++)
		for (lista l = d->listas[i]; l != NULL; l = l->seg)
			v[j++] = valorAPar(l->elem);
	return v;
}

// usado nos iteradores
static vetor elems(Dicionario d, int *n){
	*n = d->numElems;
	vetor v = malloc(sizeof(obj) * d->numElems);
	if (v == NULL) semMemoria();
	for (int i = 0, j = 0 ; i < d->numListas; i++)
		for (lista l = d->listas[i]; l != NULL; l = l->seg)
			v[j++] = valorBPar(l->elem);
	return v;
}

static bool primo(int n){
	for (int i = 2; i*i <= n; i++){
		if (n % i == 0)
			return false;
	}
	return n > 1;
}

static int primoMaiorQue(int n){
	for (n++; !primo(n); n++);
	return n;
}

// load factor
static double taxaDeOcupação(Dicionario d){
	return d->numElems / (double)d->numListas;
}

static void asseguraCapacidade(Dicionario d){
	if (taxaDeOcupação(d) < TAXA_OCUPACAO_MAXIMA)
		return;	// esta' ok, nao precisa de crescer

	// mais do que duplica o numero de listas
	int novoNumListas = primoMaiorQue(d->numListas * 2);

	// toma nota da estrutura de dados interna
	lista *listasOriginal = d->listas;
	int numListasOriginal = d->numListas;

	// recria estrutura de dados interna
	d->numListas = novoNumListas;
	d->listas = malloc(sizeof(lista) * d->numListas);
	if (d->listas == NULL) semMemoria();
	for (int i=0 ; i < d->numListas ; i++)
		d->listas[i] = NULL;
	d->numElems = 0;

	// transfere todos os elementos da estrutura antiga para a nova
	// e destroi a estrutura antiga
	for (int i=0 ; i < numListasOriginal ; i++){
		for (lista l = listasOriginal[i]; l != NULL; l = l->seg){
			acrescentaDicionario(d, valorAPar(l->elem), valorBPar(l->elem));
			destroiPar(l->elem);
		}
		destroiLista(listasOriginal[i]);
	}
	free(listasOriginal);
}

/*------------------------------------------*/
/* Funcoes publicas */

Dicionario criaDicionario(void){
	Dicionario d = malloc(sizeof(struct Dicionario));
	if (d == NULL) semMemoria();
	d->info = criaInfo("Dicionario", destroiDicionario,
			destroiTudoDicionario, NULL, NULL, textoDicionario);
	d->numListas = primoMaiorQue(NUM_LISTAS_INICIAL);
	d->listas = malloc(sizeof(lista) * d->numListas);
	if (d->listas == NULL) semMemoria();
	for (int i=0 ; i < d->numListas ; i++)
		d->listas[i] = NULL;
	d->numElems = 0;
	return d;
}

void destroiDicionario(Dicionario d){
	for (int i=0 ; i < d->numListas ; i++){
		for (lista l = d->listas[i]; l != NULL; l = l->seg){
			destroi(valorAPar(l->elem)); // respeita a componente B
			destroiPar(l->elem);
		}
		destroiLista(d->listas[i]);
	}
	free(d->listas);
	free(d);
}

void destroiTudoDicionario(Dicionario d){
	for (int i=0 ; i < d->numListas ; i++)
		destroiTudoLista(d->listas[i]);
	free(d->listas);
	free(d);
}

string textoDicionario(Dicionario d){
	vetor v = malloc(sizeof(obj) * d->numElems);
	if (v == NULL) semMemoria();
	for (int i = 0, j = 0; i < d->numListas; i++)
		for (lista l = d->listas[i]; l != NULL; l = l->seg)
			v[j++] = l->elem;
	string txt = textoVetor(v, d->numElems);
	free(v);
	return txt;
}

bool vazioDicionario(Dicionario d){
	return d->numElems == 0;
}

int tamanhoDicionario(Dicionario d){
	return d->numElems;
}

bool existeDicionario(Dicionario d, obj ch){
	lista prev;
	int pos;
	lista l = procuraDicionario(d, ch, &prev, &pos);
	destroi(ch);	// consome ch
	return l != NULL;
}

obj elementoDicionario(Dicionario d, obj ch){
	lista prev;
	int pos;
	lista l = procuraDicionario(d, ch, &prev, &pos);
	destroi(ch);	// consome ch
	if (l == NULL)
		return NULL;
	return valorBPar(l->elem);
}

bool acrescentaDicionario(Dicionario d, obj ch, obj elem){
	asseguraCapacidade(d);	// faz crescer se necessario
	lista prev;
	int pos;
	lista l = procuraDicionario(d, ch, &prev, &pos);
	if (l != NULL){	// ja existe
		destroi(ch);	// consome ch
		return false;
	}
	d->listas[pos] = criaNo(criaPar(ch, elem), d->listas[pos]); // acrescenta na cabeca
	d->numElems++;
	return true;
}

obj removeDicionario(Dicionario d, obj ch){
	lista prev;
	int pos;
	lista l = procuraDicionario(d, ch, &prev, &pos);
	destroi(ch);	// consome ch
	if (l == NULL)	// nao existe
		return NULL;
	if (prev == NULL)
		d->listas[pos] = l->seg;	// cabeca
	else
		prev->seg = l->seg;	// meio ou fim
	obj elem = valorBPar(l->elem);
	destroi(valorAPar(l->elem));
	destroiPar(l->elem);
	d->numElems--;
	return elem;
}

Iterador iteradorDicionario(Dicionario d){
	int n;
	vetor v = elems(d, &n);
	return criaIterador(v, n);
}

Iterador iteradorChavesDicionario(Dicionario d){
	int n;
	vetor v = chaves(d, &n);
	return criaIterador(v, n);
}

Iterador iteradorOrdenadoDicionario(Dicionario d){
	int n;
	vetor v = elems(d, &n);
	return criaIteradorOrdenado(v, n);
}

Iterador iteradorOrdenadoChavesDicionario(Dicionario d){
	int n;
	vetor v = chaves(d, &n);
	return criaIteradorOrdenado(v, n);
}

#include "Int.h"

void testeDicionario(void){
	Dicionario d = criaDicionario();
	int chaves[] = {10, 8, 5, 3, 78, 44, 33, 22, 1, 99, -1};
	for (int i = 0 ; chaves[i] != -1 ; i++){
		int val = 999-i*100;
		printf("add (%2d,%3d) -- ", chaves[i], val);
		acrescentaDicionario(d, criaInt(chaves[i]), criaInt(val));
		printf("%s\n", texto(d));
	}
	printf("%s\n", texto(d));

	Iterador it;
	printf("-----------------\n");
	it = iteradorDicionario(d);
	while (temSeguinteIterador(it)){
		obj elem = seguinteIterador(it);
		printf("%s\n", texto(elem));
	}
	destroiIterador(it);
	printf("-----------------\n");
	it = iteradorOrdenadoDicionario(d);
	while (temSeguinteIterador(it)){
		obj elem = seguinteIterador(it);
		printf("%s\n", texto(elem));
	}
	destroiIterador(it);
	printf("-----------------\n");
	it = iteradorChavesDicionario(d);
	while (temSeguinteIterador(it)){
		obj elem = seguinteIterador(it);
		printf("%s\n", texto(elem));
	}
	destroiIterador(it);
	printf("-----------------\n");
	it = iteradorOrdenadoChavesDicionario(d);
	while (temSeguinteIterador(it)){
		obj elem = seguinteIterador(it);
		printf("%s\n", texto(elem));
	}
	destroiIterador(it);
	printf("-----------------\n");

	printf("%s\n", texto(d));
	int chaves2[] = {44, 22, 5, 3, 10, 8, 78, 99, 33, 1, -1};
	for (int i = 0 ; chaves2[i] != -1 ; i++){
		printf("rem %2d -- ", chaves2[i]);
		removeDicionario(d, criaInt(chaves2[i]));
		printf("%s\n", texto(d));
	}
}
