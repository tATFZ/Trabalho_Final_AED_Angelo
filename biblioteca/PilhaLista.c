/*
 * PilhaLista.c
 */

#include "Pilha.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Pilha{
	Info info;
	lista elems;
};

/*	Os elementos entram e saem pela cabeca da lista.
	Fica eficiente. Comparar com a discussao
	em "FilaLista.c"
*/

/*------------------------------------------*/
/* Funcoes publicas */

Pilha criaPilha(void){
	Pilha p = malloc(sizeof(struct Pilha));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Pilha", destroiPilha, destroiTudoPilha,
				NULL, NULL, textoPilha);
	p->elems = NULL;	// lista vazia
	return p;
}

void destroiPilha(Pilha p){
	destroiLista(p->elems);
	free(p);
}

void destroiTudoPilha(Pilha p){
	destroiTudoLista(p->elems);
	free(p);
}

string textoPilha(Pilha p){
	return textoLista(p->elems);
}

bool vaziaPilha(Pilha p){
	return vaziaLista(p->elems);
}

int tamanhoPilha(Pilha p){
	return tamanhoLista(p->elems);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj topoPilha(Pilha p){
	return p->elems->elem;
}

void emPilha(Pilha p, obj elem){
	p->elems = insereLista(p->elems, elem, 0);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj desemPilha(Pilha p){
	obj res;
	p->elems = removeLista(p->elems, 0, &res);
	return res;
}

Iterador iteradorPilha(Pilha p){
	int n;
	vetor v = vetorLista(p->elems, &n);
	return criaIterador(v, n);
}

Iterador iteradorOrdenadoPilha(Pilha p){
	int n;
	vetor v = vetorLista(p->elems, &n);
	return criaIteradorOrdenado(v, n);
}

#include "Int.h"

void testePilha(void){
	printf("Testando Pilha:\n");
	Pilha p = criaPilha();
	emPilha(p, criaInt(0));
	emPilha(p, criaInt(1));
	emPilha(p, criaInt(2));
	emPilha(p, criaInt(3));
	printf("%s\n", texto(p));

	Iterador it = iteradorPilha(p);
	while (temSeguinteIterador(it))
		printf("%s\n", texto(seguinteIterador(it)));

	printf("topo = %s\n", texto(topoPilha(p)));
	printf("desempilha = %s\n", texto(desemPilha(p)));
	printf("desempilha = %s\n", texto(desemPilha(p)));
	printf("%s\n", texto(p));
}
