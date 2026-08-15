/*
 * Registo.h
 */

#ifndef REGISTO_H_
#define REGISTO_H_

#include "Util.h"
#include "Info.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Registo *Registo;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaRegisto - Cria um registo
Parametros: nada
Retorno: Registo criado
Precondicao: nada
***********************************************/
Registo criaRegisto(int cliente, int caixa, int momento, int custo, int peso);

/***********************************************
destroiRegisto - Destroi a Registo
Parametros: r - Registo
Retorno: nada
Precondicao: r != NULL
***********************************************/
void destroiRegisto(Registo r);

/***********************************************
clienteRegisto - Devolve o id do cliente do registo
Parametros: r - Registo 
Retorno: nada
Precondicao: r != NULL
***********************************************/
int clienteRegisto(Registo r);

/***********************************************
caixaRegisto - Devolve o id da caixa do registo
Parametros: r - Registo 
Retorno: nada
Precondicao: r != NULL
***********************************************/
int caixaRegisto(Registo r);

/***********************************************
momentoRegisto - Devolve o momento do registo
Parametros: r - Registo 
Retorno: nada
Precondicao: r != NULL
***********************************************/
int momentoRegisto(Registo r);

/***********************************************
pagouRegisto - Devolve o dinheiro pago do cliente no registo
Parametros: r - Registo 
Retorno: nada
Precondicao: r != NULL
***********************************************/
int pagouRegisto(Registo r);

/***********************************************
pesoRegisto - Devolve o peso total no registo
Parametros: r - Registo 
Retorno: nada
Precondicao: r != NULL
***********************************************/
int pesoRegisto(Registo r);

#endif /* REGISTO_H_ */