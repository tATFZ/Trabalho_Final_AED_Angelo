/*
 * Fila.h
 */

#ifndef FILA_H
#define FILA_H

#include "Util.h"
#include "Info.h"
#include "Iterador.h"

/***********************************************
	TAD Fila - Filas genericas
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Fila *Fila;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaFila - Cria uma fila vazia.
Parametros: nada
Retorno: a fila criada
Precondicao: nada
***********************************************/
Fila criaFila(void);

/***********************************************
destroiFila - Elimina uma fila, mas nao os seus elementos.
Parametros: f - fila
Retorno: nada
Precondicao: f != NULL
***********************************************/
void destroiFila(Fila f);

/***********************************************
destroiTudoFila - Elimina uma fila, mais os seus elementos.
Parametros: f - fila
Retorno: nada
Precondicao: f != NULL
***********************************************/
void destroiTudoFila(Fila f);

/***********************************************
textoFila - Converte em texto, para mostrar em situacoes de debug.
Parametros: f - fila
Retorno: o texto criado
Precondicao: f != NULL
***********************************************/
string textoFila(Fila f);

/***********************************************
vaziaFila - Testa se a fila esta vazia.
Parametros: f - fila
Retorno: true - caso fila vazia; false - caso contrario
Precondicao: f != NULL
***********************************************/
bool vaziaFila(Fila f);

/***********************************************
tamanhoFila - Numero de elementos na fila.
Parametros: f - fila
Retorno: numero de elementos
Precondicao: f != NULL
***********************************************/
int tamanhoFila(Fila f);

/***********************************************
primeiroFila - O primeiro elemento.
Parametros: f - fila
Retorno: o primeiro elemento
Precondicao: f != NULL && !vaziaFila(f)
***********************************************/
obj primeiroFila(Fila f);

/***********************************************
acrescentaFila - Acrescenta um elemento.
Parametros: f - fila; elem - elemento
Retorno: nada
Precondicao: f != NULL
***********************************************/
void acrescentaFila(Fila f, obj elem);

/***********************************************
removeFila - Remove o elemento ha mais tempo na fila.
Parametros: f - fila
Retorno: retorna o elemento
Precondicao: f != NULL && !vaziaFila(f)
***********************************************/
obj removeFila(Fila f);

/***********************************************
iteradorFila - Iterador para os elementos da fila.
Parametros: f - fila
Retorno: iterador dos elementos
Precondicao: f != NULL
***********************************************/
Iterador iteradorFila(Fila f);

/***********************************************
iteradorOrdenadoFila - Iterador ordenado para os elementos da fila.
Parametros: f - fila
Retorno: iterador dos elementos
Precondicao: f != NULL
***********************************************/
Iterador iteradorOrdenadoFila(Fila f);

/***********************************************
testeFila - Alguns testes simples.
***********************************************/
void testeFila(void);

#endif /* FILA_H */
