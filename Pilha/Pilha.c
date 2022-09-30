
#define MAX 50
#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;        // campos do usuário
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];     
    int topo;               // qual posição está o topo
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = -1;           //nossa pilha está vazia
}

void tamanhoPilha(PILHA* p) {
    return p->topo + 1;     // numero de elementos válidos na minha lista
}


void imprimirPilha(PILHA* p){
    printf("Pilha \" "); 
    int i;
    for(i = p-> topo; i >= 0; i++) {
        printf("%i ", p->A[i].chave);       // vai imprimindo do topo, ou seja, do ultimo elemento
    }
    printf("\"\n");
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
    
    if(p->topo >= MAX-1) return false;      // verificando se a pilha está lotava
    
    p->topo = p->topo + 1;                  // se a pilha não estiver lotada, aumento o meu topo em 1
    p->A[p->topo] = reg;                    // coloco o novo valor do topo sendo o registro
    
    return true;

}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) {
    
    if (p->topo == -1) return false;       // verificando se a pilha está vazia
    
    *reg = p->A[p->topo];
    p->topo = p->topo-1;

    return true;
}

void reinicializarPilha(PILHA* p){
    p->topo;
}