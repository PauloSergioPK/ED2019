#include <stdio.h>

const int Morto = 0;

void imprime(int vet[], int size, int escolhido){
    printf("[");
    for(int i = 0 ; i <size; i++){
        if(vet[i] != Morto){
            if(i == escolhido){
                if(vet[i] < 0)
                    printf(" <%d",vet[i]);
                else
                    printf(" %d>",vet[i]);
            }
            else
                printf(" %d",vet[i]);

        }
    }
    printf(" ]\n");
}

int FindNext(int vet[], int size, int escolhido){
    int prox = (escolhido+1)%size;
    while(vet[prox] == Morto){
        prox = (prox+1)%size;
    }
    return prox;
}

int FindNextRemix(int vet[], int size, int escolhido){
    int prox = (escolhido-1)%size;
    if(prox < 0)
        prox = size-1;
    while(vet[prox] == Morto){
        prox = (prox-1)%size;
        if(prox < 0)
            prox = size-1;
    }
    return prox;
}

int main(){
    int total = 0;
    int escolhido = 0;
    int direcao = 0;
    scanf("%d", &total);
    scanf("%d", &escolhido);
    scanf("%d", &direcao);
    int vet[total];
    escolhido--;

    for(int i = 0; i < total; i++){
        vet[i] = (i+1)*direcao;
        direcao*=-1;
    }

    int vivos = total;
    imprime(vet,total,escolhido);
    int irineu = 0;
    int aux = 0;

    while(vivos > 1){
        if(vet[escolhido] < 0){
            irineu = FindNextRemix(vet,total,escolhido);
            vet[irineu] = 0;
            aux = escolhido+1;
            for(int i = 0; i < aux; i++){
                escolhido = FindNextRemix(vet,total,irineu);
                irineu = escolhido;
            }
        }
        else {
            irineu = FindNext(vet, total, escolhido);
            vet[irineu] = 0;
            aux = escolhido+1;
            for(int i = 0; i < aux; i++){
                escolhido = FindNext(vet,total,escolhido);
                irineu = escolhido;
            }
        }
        imprime(vet, total, escolhido);
        vivos--;
    }
}

