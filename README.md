# Trabalho Final AED - Angelo e Diogo Fornelos

##  Objetivo do Projeto

O objetivo deste trabalho de grupo é desenvolver um programa em C para efetuar a gestão de um dia de atividade dum grande supermercado. O sistema lida com os seguintes cenários principais:

  Gestão de Stock e Inventário: O supermercado tem um diversificado stock de produtos, e há reabastecimentos ocasionais (`Stock.c`, `Produto.c`).
  Jornada de Compras do Cliente: Os clientes circulam pelos corredores escolhendo e colocando produtos nos seus cestos de compras (`Cliente.c`, `GerirClientes.c`).
  Processamento em Caixa (Checkout): No final das suas compras, cada cliente vai para uma caixa efetuar o pagamento (`Caixa.c`, `GerirCaixas.c`).
  Histórico e Estatísticas: O supermercado mantém um histórico com estatísticas sobre as vendas individuais (`Historia.c`, `Registo.c`).

---

##  Estrutura de Diretórios e Ficheiros

O projeto está dividido em duas partes principais: uma biblioteca geral de estruturas de dados e a implementação específica do programa do supermercado.

### 1. `biblioteca/`
Contém os cabeçalhos (headers) e implementações base para várias estruturas de dados genéricas e utilitários

### `biblioteca/alternativas/`
Fornece implementações alternativas das estruturas de dados nucleares para comparação ou diferentes otimizações de memória/desempenho:

### 2. `programa/`
Contém o código fonte principal da aplicação de gestão do supermercado:
  Core da Aplicação:** `MainSupermercado.c`, `Supermercado.c`, `Supermercado.h`
  Gestão de Caixas:** `Caixa.c`, `Caixa.h`, `GerirCaixas.c`, `GerirCaixas.h`
  Gestão de Clientes:** `Cliente.c`, `Cliente.h`, `GerirClientes.c`, `GerirClientes.h`
  Gestão de Produtos e Stock:** `Produto.c`, `Produto.h`, `Stock.c`, `Stock.h`
  Registos e Histórico:** `Historia.c`, `Historia.h`, `Registo.c`, `Registo.h`
