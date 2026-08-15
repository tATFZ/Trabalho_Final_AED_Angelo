/*
 * PilhaLista.c
 */

#include "Pilha.h"
#include "Vetor.h"

/*------------------------------------------*/
/* Constantes privadas */

#define CAPACIDADE_INICIAL	4

/*------------------------------------------*/
/* Tipo privado */

struct Pilha{
	Info info;
	vetor elems;	  // vetor dinamico
	int numElems;
	int capacidade;
};

/*	Os elementos entram pela ultima posicao e saem pela
	ultima posicao. Assim fica eficiente.
*/

/*------------------------------------------*/
/* Funcoes privadas */

static void asseguraCapacidade(Pilha p){
	if (tamanhoPilha(p) == p->capacidade){ // se pilha cheia...
		int novaCapacidade = p->capacidade * 2; // duplica capacidade
		p->elems = realloc(p->elems, sizeof(obj) * novaCapacidade);
		p->capacidade = novaCapacidade;
	}
}

/*------------------------------------------*/
/* Funcoes publicas */

Pilha criaPilha(void){
	int cap = CAPACIDADE_INICIAL;
	Pilha p = malloc(sizeof(struct Pilha));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Pilha", destroiPilha, destroiTudoPilha,
				NULL, NULL, textoPilha);
	p->elems = malloc(sizeof(obj) * cap);
	if (p->elems == NULL) semMemoria();
	p->numElems = 0;
	p->capacidade = cap;
	return p;
}

void destroiPilha(Pilha p){
	free(p->elems);
	free(p);
}

void destroiTudoPilha(Pilha p){
	for (int i=0 ; i < p->numElems; i++)
		destroi(p->elems[i]);
	destroiPilha(p);
}

string textoPilha(Pilha p){
	return textoVetor(p->elems, p->numElems);
}

bool vaziaPilha(Pilha p){
	return p->numElems == 0;
}

int tamanhoPilha(Pilha p){
	return p->numElems;
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj topoPilha(Pilha p){
	return p->elems[p->numElems - 1];
}

void emPilha(Pilha p, obj elem){
	asseguraCapacidade(p);
	p->elems[p->numElems++] = elem;
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj desemPilha(Pilha p){
	return p->elems[--p->numElems];
}

Iterador iteradorPilha(Pilha p){
	return criaIterador(copiaVetor(p->elems, p->numElems), p->numElems);
}

Iterador iteradorOrdenadoPilha(Pilha p){
	return criaIteradorOrdenado(copiaVetor(p->elems, p->numElems), p->numElems);
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











