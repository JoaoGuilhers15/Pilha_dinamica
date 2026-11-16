#include <stdio.h>
#include <stdlib.h>
#include "pilha_din.h"

struct elemento{
    int n;
    struct elemento *proximo;
};

struct pilha_din {
    No *topo;
    int tamanho;
};

//Aloca a memória do topo da pilha e devolve o endereço
Pilha* criar_pilha(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    if (p==NULL) return p;

    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

//empilha novo valor
void pilha_push(Pilha* p, int n){
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) return;

    novo->n = n;
    
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
}

//desempilha o último valor empilhado e o retorna
void pilha_pop(Pilha* p){
    No *x;
    if(pilha_vazia(p)){ printf("Pilha vazia!\n"); return;}
    
    x = p->topo;
    p->topo = p->topo->proximo;
    int v = x->n;
    free(x);
    p->tamanho--;

}

//Exibe a pilha completa ao usuário // FAZER
void pilha_exibir(Pilha *p){
    No* atual = p->topo;

    if(pilha_vazia(p)){ printf("Pilha vazia\n"); return;}

    while (atual != NULL){
        printf("%d\n", atual->n);
        atual=atual->proximo;
    }
}

//verifica se a pilha está vazia
int pilha_vazia(Pilha* p){
    if(p->topo == NULL) return 1;
    else return 0;
}

//limpa a pilha, mas deixa o struct ainda válido
void pilha_limpar(Pilha* p){
    No *limpa, *no = p->topo;
    while (no != NULL) {
        limpa = no;
        no = no->proximo;
        free(limpa);
    }
}

//libera a memória usada pela pilha
void pilha_destruir(Pilha* p){
    pilha_limpar(p);
    free(p);
}

//Retorna o nó do último elemento empilhado(topo)
No* pilha_topo(Pilha* p){
    return p->topo;

}

//Retorna o total de valores empilhados
int pilha_tamanho(Pilha* p){
    return p->tamanho;
}
