/*
 * Produto.c
 */

#include "Produto.h"

typedef struct produto {

    Info info;
    string nome;
    int quantidade; //quantidade em stock
    int preco;    //preco centimos
    int peso;     //peso gramas
}*Produto; 

Produto criaProduto(string nome , int quantidade, int preco, int peso){

    if (nome == NULL || quantidade < 0 || preco < 0 || peso <= 0) {
        return NULL;  
    }
    
    Produto p = malloc(sizeof(struct produto));
    if (p == NULL) { 
        semMemoria();
    }

    p->info = criaInfo("Produto", destroiProduto, destroiProduto, NULL, NULL, NULL);
    p->nome = criaString(nome);
    p->quantidade = quantidade;
    p->preco = preco;
    p->peso = peso;
    return p; 
}

void destroiProduto(Produto p){
    if (p == NULL){
        return; 
    }   
    free(p->nome);
    free(p);
}

bool produtoAvulso(Produto p) {
    if (p->peso == 1) {
        return true;                  // se o peso for 1 ent sera um produto avulso
    }
    return false;
}

int devolvePesoProduto(Produto p) {     
    if (p == NULL) {
        return -1;
    }
    return p->peso;
}

int devolvePrecoProduto(Produto p) { 
    if (p == NULL) {
        return -1;
    }
    return p->preco;
}

string devolveNomeProduto(Produto p) {     
    if (p == NULL) {
        return NULL;  
    }
    return p->nome;
}

int devolveQuantidadeProduto(Produto p) {
    if (p == NULL) {
        return -1;
    }
    return p->quantidade;
}

void alteraQuantidadeProduto(Produto p, int novaQuantidade) {     
    if (p != NULL) {
        p->quantidade = novaQuantidade;
    }
}

void alteraNomeProduto(Produto p, string novoNome) {              
    if (p->nome != NULL) free(p->nome);
    p->nome = criaString(novoNome);
}

void alteraPrecoProduto(Produto p, int novoPreco) {   
    if (p != NULL) {
        p->preco = novoPreco; 
    }          
}

void alteraPesoProduto(Produto p, int novoPeso) {                
    if (p != NULL) {
        p->peso = novoPeso;
    }
}

int tempoProduto(Produto p, int quantidadeAdicionar) {
    if (p == NULL) {
        return -1;
    }
    if (produtoAvulso(p)) {
        return 1;
    } 
    else {
        return quantidadeAdicionar;
    }
}


/*Autoria: Angelo Zhang     nº 71099 
           Diogo Fornelos   nº 71105
*/