/*
 * PilhaLentaLista.c
 */

#include "Pilha.h"
#include "Sequencia.h"

/*------------------------------------------*/
/* Tipo privado */

struct Pilha{
	Info info;
	Sequencia seq;
};

/*	Os elementos entram pelo indice 0 da sequencia e
	saem pelo indice 0 da sequencia.
	As duas situacoes ficam ineficientes, assumindo que
	estamos a usar uma sequencia implementada com vetor.
	Realmente, desviam todos os elementos, sempre que
	se empilha ou desempilha um elemento.
*/

/*------------------------------------------*/
/* Funcoes privadas */

static void destroiPilha(Pilha p){
	destroi(p->seq);
	free(p);
}

static void destroiTudoPilha(Pilha p){
	destroiTudo(p->seq);
	free(p);
}

static string textoPilha(Pilha p){
	return texto(p->seq);
}

static Info info = NULL;

static Info criaInfoPilha(void){
	if (info == NULL)	// primeira vez
		info = criaInfo("Pilha", destroiPilha, destroiTudoPilha,
				NULL, NULL, textoPilha);
	return info;
}

/*------------------------------------------*/
/* Funcoes publicas */

Pilha criaPilha(void){
	Pilha p = malloc(sizeof(struct Pilha));
	if (p == NULL) semMemoria();
	p->info = criaInfoPilha();
	p->seq = criaSequencia();	// sequencia vazia
	return p;
}

bool vaziaPilha(Pilha p){
	return vaziaSequencia(p->seq);
}

int tamanhoPilha(Pilha p){
	return tamanhoSequencia(p->seq);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj topoPilha(Pilha p){
	return elementoSequencia(p->seq, 0);
}

void emPilha(Pilha p, obj elem){
	insereSequencia(p->seq, elem, 0);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj desemPilha(Pilha p){
	return removeSequencia(p->seq, 0);
}

Iterador iteradorPilha(Pilha p){
	return iteradorSequencia(p->seq);
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











