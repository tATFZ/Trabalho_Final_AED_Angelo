/*
 * Pilha.h
 */

#ifndef PILHA_H
#define PILHA_H

#include "Util.h"
#include "Info.h"
#include "Iterador.h"

/***********************************************
	TAD Pilha - Pilhas genericas
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Pilha *Pilha;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaPilha - Cria uma pilha vazia.
Parametros: nada
Retorno: a pilha criada
Precondicao: nada
***********************************************/
Pilha criaPilha(void);

/***********************************************
destroiPilha - Elimina uma pilha, mas nao os seus elementos.
Parametros: p - pilha
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiPilha(Pilha p);

/***********************************************
destroiTudoPilha - Elimina um pilha, mais os seus elementos.
Parametros: p - pilha
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiTudoPilha(Pilha p);

/***********************************************
textoPilha - Converte em texto, para mostrar em situacoes de debug.
Parametros: p - pilha
Retorno: o texto criado
Precondicao: p != NULL
***********************************************/
string textoPilha(Pilha p);

/***********************************************
vaziaPilha - Testa se a pilha esta vazia.
Parametros: p - pilha
Retorno: true - caso pilha vazia; false - caso contrario
Precondicao: p != NULL
***********************************************/
bool vaziaPilha(Pilha p);

/***********************************************
tamanhoPilha - Numero de elementos na pilha.
Parametros: p - pilha
Retorno: numero de elementos
Precondicao: p != NULL
***********************************************/
int tamanhoPilha(Pilha p);

/***********************************************
topoPilha - O elemento no topo.
Parametros: p - pilha
Retorno: o elemento no topo
Precondicao: p != NULL && !vaziaPilha(p)
***********************************************/
obj topoPilha(Pilha p);

/***********************************************
emPilha - Empilha um elemento dado.
Parametros: p - pilha, elem - elemento
Retorno: nada
Precondicao: p != NULL
***********************************************/
void emPilha(Pilha p, obj elem);

/***********************************************
desemPilha - Desempilha o elemento no topo.
Parametros: p - pilha
Retorno: retorna o elemento desempilhado
Precondicao: p != NULL && !vaziaPilha(p)
***********************************************/
obj desemPilha(Pilha p);

/***********************************************
iteradorPilha - Iterador para os elementos da pilha.
Parametros: p - pilha
Retorno: iterador dos elementos
Precondicao: p != NULL
***********************************************/
Iterador iteradorPilha(Pilha p);

/***********************************************
iteradorOrdenadoPilha - Iterador ordenado para os elementos da pilha.
Parametros: p - pilha
Retorno: iterador dos elementos
Precondicao: p != NULL
***********************************************/
Iterador iteradorOrdenadoPilha(Pilha p);

/***********************************************
testePilha - Alguns testes simples.
***********************************************/
void testePilha(void);

#endif /* PILHA_H */
