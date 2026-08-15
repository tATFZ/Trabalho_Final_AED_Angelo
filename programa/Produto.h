/*
 * Produto.h
 */

#ifndef Produto_h
#define Produto_h

#include "Util.h"
#include "Dicionario.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct produto *Produto;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaProduto - Cria um produto.
Parametros: nome - nome do produto, quantidade - quantidade em stock, preco - preco centimos, peso - peso gramas
Retorno: O produto criado
Precondicao: Preco >= 0 e quantidade >= 0
***********************************************/
Produto criaProduto(string nome, int quantidade, int preco, int peso);

/***********************************************
destroiProduto - Elimina um produto
Parametros: p - produto
Retorno: Nada
Precondicao: O produto tem que existir
***********************************************/
void destroiProduto(Produto p);

/***********************************************
produtoAvulso - Indica se o produto e´ avulso ou nao
Parametros: p - produto
Retorno: True - se o produto e' avulso; False - caso contrario     
Precondicao: O produto tem que existir
***********************************************/
bool produtoAvulso(Produto p);

/***********************************************
devolvepesoProduto - Devolve o peso do produto
Parametros: p - produto
Retorno: O peso do produto se existir; "-1" - se o produto nao existir
Precondicao: O produto tem que existir
***********************************************/
int devolvePesoProduto(Produto p); 

/***********************************************
devolvePrecoProduto - Devolve o preco do produto
Parametros: p - produto
Retorno: O peso do produto se existir; "-1" - se o produto nao existir
Precondicao: O produto tem que existir
***********************************************/
int devolvePrecoProduto(Produto p); 

/***********************************************
devolveNomeProduto - Devolve o nome do produto
Parametros: p - produto
Retorno: o Nome do produto se existir; "NULL" - se o produto nao existir
Precondicao: O produto tem que existir
***********************************************/
string devolveNomeProduto(Produto p);  

/***********************************************
devolveQuantidadeProduto - Devolve a quantidade do produto
Parametros: p - produto
Retorno: A quantidade do produto se existir; "-1" - se o produto nao existir
Precondicao: O produto tem que existir
***********************************************/
int devolveQuantidadeProduto(Produto p);

/***********************************************
alteraQuantidadeProduto - altera a quantidade do produto
Parametros: p - produto, novaQuantidade - nova quantidade
Retorno: A nova quantidade do produto se existir
Precondicao: O produto tem que existir
***********************************************/
void alteraQuantidadeProduto(Produto p, int novaQuantidade);

/***********************************************
alteraNomeProduto - altera o nome do produto
Parametros: p - produto, novoNome - novo nome
Retorno: O novo nome do produto se existir
Precondicao: O produto tem que existir
***********************************************/
void alteraNomeProduto(Produto p, string novoNome);

/***********************************************
alteraPrecoProduto - altera o preco do produto
Parametros: p - produto, novoPreco - novo preco
Retorno: O novo preco do produto se existir
Precondicao: O produto tem que existir
***********************************************/
void alteraPrecoProduto(Produto p, int novoPreco);

/***********************************************
alteraPesoProduto - altera o peso do produto
Parametros: p - produto, novaPeso - novo peso
Retorno: O novo peso do produto se existir
Precondicao: O produto tem que existir
***********************************************/
void alteraPesoProduto(Produto p, int novoPeso);

/***********************************************
tempoProduto - Devolve o tempo que sera acrescentado devido ao produto p
Parametros: p - produto, quantidadeAdicionar - quantidade a adicionar
Retorno: tempo do produto, "-1" - se o produto nao existir
Precondicao: o produto existe
***********************************************/
int tempoProduto(Produto p, int quantidadeAdicionar);

#endif /*Produto_H*/


/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/