/*
* Stock.h
*/

#ifndef Stock_h
#define Stock_h

#include "Util.h"
#include "Dicionario.h" 
#include "Str.h"

#include "Produto.h"

/*------------------------------------------*/
/* Tipo publico */

 typedef struct stock *Stock;
 
/*------------------------------------------*/

/* Prototipos das funcoes publicas */

/***********************************************
 criaStock - cria o stock.
 Parametros:  nada.
 Retorno: o stock criado
 Precondicao: O stock ainda nao existe
***********************************************/
Stock criaStock(void);

/***********************************************
 existeChave - Verifica se a chave existe no stock.
 Parametros: s - stock; chave - (string) chave do produto
 Retorno: True - se a chave existir; False - caso contrario 
 Precondicao: s != NULL && chave != NULL
 ***********************************************/
bool existeChave(Stock s, string chave);

/***********************************************
 criaProdutoStock - Adiciona um produto ao stock.
 Parametros: s - stock, p - nome produto, n - quantidade, c - preco, g - peso 
 Retorno: nada
 Precondicao: o produto ja´ existe 
***********************************************/
void criaProdutoStock(Stock s, string p, int n, int c, int g );

/***********************************************
 destroiTudoStock - Elimina o stock e os seus elementos
 Parametros: s - stock
 Retorno: nada
 Precondicao: s != NULL 
***********************************************/
void destroiTudoStock(Stock s);

/***********************************************
 destroiStock - Elimina o stock
 Parametros: s - stock
 Retorno: nada
 Precondicao: s != NULL 
***********************************************/
void destroiStock(Stock s);

/***********************************************
 listaStock - Iterador utilizado para listar o stock.
 Parametros:  s - stock
 Retorno: O iterador do stock ordenado alfabeticamente das chaves (nomes dos produtos) 
 Precondicao: O stock ja' existe
***********************************************/
Iterador listaStock(Stock s);

/***********************************************
 acrescentaUnidadesProdutoStock - Adiciona n unidades a um produto do stock.
 Parametros: s - stock, p - nome produto, n - quantidade
 Retorno: o stock atualizado com a nova quantidade de produto
 Precondicao: o produto ja´ existe
***********************************************/
Stock acrescentaUnidadesProdutoStock(Stock s, string p, int n);

/***********************************************
 devolveDicionarioStock - Devolve o dicionario stock.
 Parametros: s - stock
 Retorno: o stock atualizado com a nova quantidade de produto
 Precondicao: o produto ja´ existe
***********************************************/
Dicionario devolveDicionarioStock(Stock s);

/***********************************************
 devolveProdutoStock - Devolve o produto do stock.
 Parametros: s - stock, chave - chave/nome do produto
 Retorno: o produto do stock
 Precondicao: o produto ja´ existe
***********************************************/
Produto devolveProdutoStock(Stock s, string chave);

/***********************************************
 tamanhoStock - Devolve o tamanho do stock.
 Parametros: s - stock
 Retorno: O tamanho do stock em inteiro
 Precondicao: o produto ja´ existe
***********************************************/
int tamanhoStock(Stock s);

/***********************************************
 temStock - Verifica se o stock esta vazio.
 Parametros: s - stock
 Retorno: True - se o stock estiver vazio; false - caso contrario
 Precondicao: o produto ja´ existe
***********************************************/
bool temStock(Stock s);

#endif /*Stock_H*/

/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/