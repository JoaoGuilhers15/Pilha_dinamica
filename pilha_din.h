#ifndef PILHA_ENC_H
#define PILHA_ENC_H

typedef struct elemento No;
typedef struct pilha_din Pilha;

Pilha* criar_pilha(void);
void pilha_push(Pilha* p, int n); 
void pilha_pop(Pilha* p);
void pilha_exibir(Pilha* p);
int pilha_vazia(Pilha* p);
No* pilha_topo(Pilha* p);
int pilha_tamanho(Pilha* p);
void pilha_limpar(Pilha* p);
void pilha_destruir(Pilha* p);

#endif 