/*
 * DicionarioLista.c
*/

#include "Dicionario.h"
#include "Par.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Dicionario{
	Info info;
	lista pares;
	int numElems;
};

/*	Na lista 'pares' guardam-se pares (chave, elem).
	As chaves nao podem ocorrer repetidas.
	As adicoes sao feitas na cabeca da lista.
*/

/*------------------------------------------*/
/* Funcoes privadas */

// retorna no' com a chave ch, e tambem retorna o no' previo
static lista procuraDicionario(Dicionario d, obj ch, lista *prev){
	*prev = NULL;
	for (lista l = d->pares; l != NULL ; *prev = l, l = l->seg){
		if (compara(valorAPar(l->elem), ch) == 0)
			return l;
	}
	return NULL;
}

// usado nos iteradores
static vetor chaves(Dicionario d, int *n){
	vetor v = vetorLista(d->pares, n);
	for (int i = 0; i < *n; i++)
		v[i] = valorAPar(v[i]);
	return v;
}

// usado nos iteradores
static vetor elems(Dicionario d, int *n){
	vetor v = vetorLista(d->pares, n);
	for (int i = 0; i < *n; i++)
		v[i] = valorBPar(v[i]);
	return v;
}

/*------------------------------------------*/
/* Funcoes publicas */

Dicionario criaDicionario(void){
	Dicionario d = malloc(sizeof(struct Dicionario));
	if (d == NULL) semMemoria();
	d->info = criaInfo("Dicionario", destroiDicionario,
			destroiTudoDicionario, NULL, NULL, textoDicionario);
	d->pares = NULL;
	d->numElems = 0;
	return d;
}

void destroiDicionario(Dicionario d){
	lista seg;
	for (lista l = d->pares ; l != NULL; l = seg){
		seg = l->seg;
		destroi(valorAPar(l->elem));
		destroiPar(valorAPar(l->elem));
		destroiNo(l);
	}
}

void destroiTudoDicionario(Dicionario d){
	destroiTudoLista(d->pares);
	free(d);
}

string textoDicionario(Dicionario d){
	return textoLista(d->pares);
}

bool vazioDicionario(Dicionario d){
	return d->numElems == 0;
}

int tamanhoDicionario(Dicionario d){
	return d->numElems;
}

bool existeDicionario(Dicionario d, obj ch){
	lista prev;
	lista l = procuraDicionario(d, ch, &prev);
	destroi(ch);	// consome ch
	return l != NULL;
}

obj elementoDicionario(Dicionario d, obj ch){
	lista prev;
	lista l = procuraDicionario(d, ch, &prev);
	destroi(ch);	// consome ch
	if (l == NULL)
		return NULL;
	return valorBPar(l->elem);
}

bool acrescentaDicionario(Dicionario d, obj ch, obj elem){
	lista prev;
	lista l = procuraDicionario(d, ch, &prev);
	if (l != NULL){	// ja existe
		destroi(ch);	// consome ch
		return false;
	}
	d->pares = criaNo(criaPar(ch, elem), d->pares); // acrescenta na cabeca
	d->numElems++;
	return true;
}

obj removeDicionario(Dicionario d, obj ch){
	lista prev;
	lista l = procuraDicionario(d, ch, &prev);
	destroi(ch);	// consome ch
	if (l == NULL)	// ja existe
		return NULL;
	if (prev == NULL)
		d->pares = l->seg;	// cabeca
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
