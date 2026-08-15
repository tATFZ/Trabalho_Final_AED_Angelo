/*
 * Historia.h
 */

#ifndef HISTORIA_H_
#define HISTORIA_H_

#include "Util.h"
#include "Info.h"
#include "Iterador.h"
#include "Registo.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Historia *Historia;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaHistoria - Cria a Historia
Parametros: nada
Retorno: Historia criada
Precondicao: nada
***********************************************/
Historia criaHistoria(void);

/***********************************************
destroiHistoria - Destroi a Historia
Parametros: h - Historia a destruir
Retorno: nada
Precondicao: h != NULL
***********************************************/
void destroiHistoria(Historia h);

/***********************************************
destroiTudoHistoria - Destroi a historia e os seus elementos
Parametros: h - Historia a destruir
Retorno: nada
Precondicao: h != NULL
***********************************************/
void destroiTudoHistoria(Historia h);

/***********************************************
acrescentaHistoria - Adiciona um novo registo ao historico
Parametros: h - Historia, r - Registo a adicionar
Retorno: nada
Precondicao: h != NULL && r != NULL
***********************************************/
void acrescentaHistoria(Historia h, Registo r);

/***********************************************
iteradorHistoria - Cria um iterador para percorrer os registos do historico
Parametros: h - Historia
Retorno: iterador para os registos
Precondicao: h != NULL
***********************************************/
Iterador iteradorHistoria(Historia h);

#endif /* HISTORIA_H_ */