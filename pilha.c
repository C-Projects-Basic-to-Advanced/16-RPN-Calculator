#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void CriarPilha(TPilha *p) {
  p->topo = -1;
}

int PilhaCheia(TPilha p) {
  return ( p.topo >= MAX_PILHA-1 );
}

int PilhaVazia(TPilha p) {
  return ( p.topo <= -1 );
}

int QuantidadeNaPilha(TPilha p) {
  return ( p.topo + 1 );
}

int InserirNaPilha(TPilha *p, Dados dados) {
  if( PilhaCheia(*p) ) return -1;
  p->topo++; // p-->topo == (*p).topo
  p->elemento[p->topo] = dados;
  return p->topo;
}

int RetirarDaPilha(TPilha *p, Dados *dados) {
  if( PilhaVazia(*p) ) return -1;
  *dados = p->elemento[p->topo];
  p->topo--; // p-->topo == (*p).topo
  return p->topo;
}

void read_string(char txt[]){
    fflush(stdin);
    fgets(txt, MAX_STRING, stdin);
    if (txt[strlen(txt)-1]=='\n')
        txt[strlen(txt)-1]='\0';
}
