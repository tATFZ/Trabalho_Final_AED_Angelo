/*
* Stock.c
*/

#include "Stock.h"

typedef struct stock{
    Info info;
    Dicionario stock;

}*Stock;

Stock criaStock(void){ 

    Stock s = malloc(sizeof(struct stock));

    s->info = criaInfo("Stock", destroiStock, destroiTudoStock, NULL, NULL, NULL);
    s->stock = criaDicionario();

    return s; 
}

bool existeChave(Stock s, string chave){

    if (elementoDicionario(s->stock, criaStr(chave)) != NULL) { 
        return true;
    }
    return false;
}
void criaProdutoStock(Stock s, string p, int n, int c, int g){ 

    if (s == NULL || p == NULL) {
         return; // Verifica se o stock e o produto existem 
    }
    Produto p_criado = criaProduto(p, n, c, g); // Cria o produto 
    // Atualiza todos os dados do produto       
        
    string chave = strdup(p); // Cria a chave do produto 
    if (!existeChave(s, chave)) {   // Verifica se a chave existe 

        acrescentaDicionario(s->stock, criaStr(chave), p_criado); // Adiciona o produto ao dicionario
        free(chave); // Liberta a memoria alocada para a chave 
    }
}

void destroiTudoStock(Stock s){
    if (s == NULL) {
        return;
    }
   
    destroiTudoDicionario(s->stock); 
}

void destroiStock(Stock s){
    if (s == NULL) {
        return;
    }

    destroiDicionario(s->stock);
    free(s);

}

Iterador listaStock(Stock s){
    if (s == NULL) {
            return NULL; // Verifica se o stock existe 
        }
    Iterador it = iteradorOrdenadoChavesDicionario(s->stock);
    return it;
}

Stock acrescentaUnidadesProdutoStock(Stock s, string p, int n){ 
    if(s == NULL || p == NULL){
        printf("Dados invalidos.\n");
        return NULL; // Verifica se o stock e o produto existem
    }

    string chave = strdup(p); //copia o nome do produto
    if (elementoDicionario(s->stock, criaStr(chave)) == NULL) {
        return NULL;
    }
    Produto p_adiciona = elementoDicionario(s->stock, criaStr(chave)); // Obtem o produto do dicionario
    free(chave); // Liberta a memoria alocada para a chave
    alteraQuantidadeProduto(p_adiciona, devolveQuantidadeProduto(p_adiciona) + n); // Atualiza a quantidade do produto

    return s; // Retorna o stock atualizado

}

Produto devolveProdutoStock(Stock s, string chave){
    if (s == NULL || chave == NULL) {                 
        return NULL; // Verifica se o stock e o produto existem
    }
    Produto p = elementoDicionario(s->stock, criaStr(chave)); // Obtem o produto do dicionario
    return p;
}

int tamanhoStock(Stock s){
    if (s == NULL) {
        return -1; // Verifica se o stock existe
    }
    return tamanhoDicionario(s->stock); // Devolve o tamanho do dicionario
}

bool temStock(Stock s){
    if (vazioDicionario(s->stock)) {
        return false; // Verifica se o stock existe
    } else {
        return true;
    }
}


/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/