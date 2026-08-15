/*
 * DicionarioVetor.c
*/

#include "Dicionario.h"
#include "Par.h"

/*------------------------------------------*/
/* Constantes privadas */

#define CAPACIDADE_INICIAL	4

/*------------------------------------------*/
/* Tipo privado */

struct Dicionario{
	Info info;
	vetor pares;
	int numElems;
	int capacidade;
};

/*	No vetor 'pares' guardam-se pares (chave, elem).
	As chaves nao podem ocorrer repetidas.
*/

/*------------------------------------------*/
/* Funcoes privadas */

static void asseguraCapacidade(Dicionario d){
	if (tamanhoDicionario(d) == d->capacidade){ // se dicionario cheio...
		int novaCapacidade = d->capacidade * 2; // duplica capacidade
		d->pares = realloc(d->pares, sizeof(obj) * novaCapacidade);
		d->capacidade = novaCapacidade;
	}
}

static int posDicionario(Dicionario d, obj ch){
	for (int i = 0; i < d->numElems; i++)
		if (compara(ch, valorAPar(d->pares[i])) == 0)
			return i;
	return NAO_EXISTE;
}

// usado nos iteradores
static vetor chaves(Dicionario d){
	vetor v = malloc(sizeof(obj) * d->numElems);
	if (v == NULL) semMemoria();
	for (int i = 0 ; i < d->numElems ; i++)
		v[i] = valorAPar(d->pares[i]);
	return v;
}

// usado nos iteradores
static vetor elems(Dicionario d){
	vetor v = malloc(sizeof(obj) * d->numElems);
	if (v == NULL) semMemoria();
	for (int i = 0 ; i < d->numElems ; i++)
		v[i] = valorBPar(d->pares[i]);
	return v;
}

/*------------------------------------------*/
/* Funcoes publicas */

Dicionario criaDicionario(void){
	int cap = CAPACIDADE_INICIAL;
	Dicionario d = malloc(sizeof(struct Dicionario));
	if (d == NULL) semMemoria();
	d->pares = malloc(sizeof(obj) * cap);
	if (d->pares == NULL) semMemoria();
	d->info = criaInfo("Dicionario", destroiDicionario,
			destroiTudoDicionario, NULL, NULL, textoDicionario);
	d->numElems = 0;
	d->capacidade = cap;
	return d;
}

void destroiDicionario(Dicionario d){
	for (int i = 0; i < d->numElems; i++){
		destroi(valorAPar(d->pares[i])); // respeita a componente B
		destroiPar(d->pares[i]);
	}
	free(d->pares);
	free(d);
}

void destroiTudoDicionario(Dicionario d){
	for (int i = 0; i < d->numElems; i++){
		destroiTudoPar(d->pares[i]);
	}
	free(d->pares);
	free(d);
}

string textoDicionario(Dicionario d){
	return textoVetor(d->pares, d->numElems);
}

bool vazioDicionario(Dicionario d){
	return d->numElems == 0;
}

int tamanhoDicionario(Dicionario d){
	return d->numElems;
}

bool existeDicionario(Dicionario d, obj ch){
	bool res = posDicionario(d, ch) != NAO_EXISTE;
	destroi(ch); // consome ch
	return res;
}

obj elementoDicionario(Dicionario d, obj ch){
	int pos = posDicionario(d, ch);
	destroi(ch); // consome ch
	if (pos == NAO_EXISTE)
		return NULL;
	return valorBPar(d->pares[pos]);
}

bool acrescentaDicionario(Dicionario d, obj ch, obj elem){
	int pos = posDicionario(d, ch);
	if (pos != NAO_EXISTE){	// ja existe
		destroi(ch); // consome ch
		return false;
	}
	asseguraCapacidade(d);
	d->pares[d->numElems] = criaPar(ch, elem); // consome ch
	d->numElems++;
	return true;
}

obj removeDicionario(Dicionario d, obj ch){
	int pos = posDicionario(d, ch);
	destroi(ch); // consome ch
	if (pos == NAO_EXISTE)
		return NULL;
	obj elem = valorBPar(d->pares[pos]);
	destroi(valorAPar(d->pares[pos]));
	destroiPar(d->pares[pos]);
	d->numElems--;
	d->pares[pos] = d->pares[d->numElems]; // puxa ultimo para pos livre
	return elem;
}

Iterador iteradorDicionario(Dicionario d){
	return criaIterador(elems(d), d->numElems);
}

Iterador iteradorChavesDicionario(Dicionario d){
	return criaIterador(chaves(d), d->numElems);
}

Iterador iteradorOrdenadoDicionario(Dicionario d){
	return criaIteradorOrdenado(elems(d), d->numElems);
}

Iterador iteradorOrdenadoChavesDicionario(Dicionario d){
	return criaIteradorOrdenado(chaves(d), d->numElems);
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
