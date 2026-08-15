/*
 * Dicionario.h
 */

#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "Util.h"
#include "Info.h"
#include "Iterador.h"

/***********************************************
  TAD Dicionario - Dicionarios genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Dicionario *Dicionario;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaDicionario - Cria um dicionario vazio.
Parametros: nada
Retorno: o dicionario criado
Precondicao: nada
***********************************************/
Dicionario criaDicionario(void);

/***********************************************
destroiDicionario - Elimina um dicionario, mas nao os seus elementos.
Parametros: d - dicionario
Retorno: nada
Precondicao: d != NULL
***********************************************/
void destroiDicionario(Dicionario d);

/***********************************************
destroiTudoDicionario - Elimina um dicionario, mais os seus elementos.
Parametros: d - dicionario
Retorno: nada
Precondicao: d != NULL
***********************************************/
void destroiTudoDicionario(Dicionario d);

/***********************************************
textoDicionario - Converte em texto, para mostrar em situacoes de debug.
Parametros: d - dicionario
Retorno: o texto criado
Precondicao: d != NULL
***********************************************/
string textoDicionario(Dicionario d);

/***********************************************
vazioDicionario - Testa se o dicionario esta vazio.
Parametros: d - dicionario
Retorno: true - caso dicionario vazio; false - caso contrario
Precondicao: d != NULL
***********************************************/
bool vazioDicionario(Dicionario d);

/***********************************************
tamanhoDicionario - Numero de elementos no dicionario.
Parametros: d - dicionario
Retorno: numero de elementos
Precondicao: d != NULL
***********************************************/
int tamanhoDicionario(Dicionario d);

/***********************************************
existeDicionario - Testa se uma chave ocorre no dicionario.
	(O dicionario consome a chave passada.)
Parametros: d - dicionario; ch - chave
Retorno: true - se a chave ocorrer; false - caso contrario
Precondicao: d != NULL && ch != NULL
***********************************************/
bool existeDicionario(Dicionario d, obj ch);

/***********************************************
elementoDicionario - Elemento com a chave dada.
	(O dicionario consome a chave passada.)
Parametros: d - dicionario; ch - chave do elemento
Retorno: elemento com a chave dada se ocorrer; NULL - se nao ocorrer
Precondicao: d != NULL && ch != NULL
***********************************************/
obj elementoDicionario(Dicionario d, obj ch);

/***********************************************
acrescentaDicionario - Acrescenta elemento se a chave for nova.
	(O dicionario consome a chave passada.)
Parametros: d - dicionario, ch - chave do elemento, elem - elemento
Retorno: true - se adicao com sucesso; false - caso contrario
Precondicao: d != NULL && ch != NULL && elem != NULL
***********************************************/
bool acrescentaDicionario(Dicionario d, obj ch, obj elem);

/***********************************************
removeDicionario - Remove o elemento com a sua chave, se esta ocorrer.
	(O dicionario consome a chave passada.)
Parametros: d - dicionario; ch - chave
Retorno: o aluno removido; ou NULL se a chave nao ocorrer
Precondicao: d != NULL && ch != NULL
***********************************************/
obj removeDicionario(Dicionario d, obj ch);

/***********************************************
iteradorDicionario - Iterador dos elementos do dicionario.
Parametros: d - dicionario
Retorno: iterador dos elementos
Precondicao: d != NULL
***********************************************/
Iterador iteradorDicionario(Dicionario d);

/***********************************************
iteradorChavesDicionario - Iterador das chaves do dicionario.
Parametros: d - dicionario
Retorno: iterador das chaves
Precondicao: d != NULL
***********************************************/
Iterador iteradorChavesDicionario(Dicionario d);

/***********************************************
iteradorOrdenadoDicionario - Iterador ordenado dos elementos do dicionario.
Parametros: d - dicionario
Retorno: iterador ordenado dos elementos
Precondicao: d != NULL
***********************************************/
Iterador iteradorOrdenadoDicionario(Dicionario d);

/***********************************************
iteradorOrdenadoChavesDicionario - Iterador ordenado das chaves do dicionario.
Parametros: d - dicionario
Retorno: iterador ordenado das chaves
Precondicao: d != NULL
***********************************************/
Iterador iteradorOrdenadoChavesDicionario(Dicionario d);

/***********************************************
testeDicionario - Alguns testes simples.
***********************************************/
void testeDicionario(void);

#endif /* DICIONARIO_H */
