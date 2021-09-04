#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX_STRING 20
#define MAX_PILHA 10

typedef struct {
  float valor;
} Dados;

typedef struct {
  Dados elemento[MAX_PILHA];
  int topo;
} TPilha;

void CriarPilha(TPilha *p); 
// Inserir/retirar retorna -1 se nao foi bem sucedido
// retorna p.topo se foi bem sucedido
int InserirNaPilha(TPilha *p, Dados dados); 
// Retirar da pilha coloca os dados do ultimo elemento da pilha
// na variavel dados antes de tira-lo da pilha
int RetirarDaPilha(TPilha *p, Dados *dados); 
// Pilha vazia/cheia retorna 1 se estiver vazia/cheia
// retorna 0 se nao.
int PilhaVazia(TPilha p); 
int PilhaCheia(TPilha p); 
int QuantidadeNaPilha(TPilha p); 

void read_string(char txt[]);

#endif // PILHA_H_INCLUDED 