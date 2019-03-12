#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char Parede = '#';
const char Caminho = '.';

const int Horizontal[4] = {1,-1,0,0};
const int Vertical[4] = {0,0,1,-1};


void imprime(int linha, int coluna, char matriz[linha][coluna]){
    for(int i = 1; i <linha-1; i++){
        for(int j = 1; j < coluna-1; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

int qtdvizinhos(int linha, int coluna, char matriz[linha][coluna], int l, int c){
    int qtd = 0;
    if(matriz[l-1][c] == Caminho)
        qtd++;
    if(matriz[l+1][c] == Caminho)
        qtd++;
    if(matriz[l][c-1] == Caminho)
        qtd++;
    if(matriz[l][c+1] == Caminho)
        qtd++;
    return qtd;
}

void fazlab(int linha, int coluna, char matriz[linha][coluna],int l, int c){
    if(l >= linha-1 || l < 1 || c>= coluna-1 || c < 1)
        return;
    if(matriz[l][c] != Parede)
        return;
    int aux = qtdvizinhos(linha,coluna,matriz,l,c);
    if(aux >= 2)
        return;
    matriz[l][c] = Caminho;
    //int aleatorio = rand() % 4;
    for(int i = 0; i < 4; i++) {
       int aleatorio = rand() % 4;
       fazlab(linha, coluna, matriz, (l + Vertical[aleatorio]), (c + Horizontal[aleatorio]));
    }
    //fazlab(linha,coluna,matriz,l+1,c);
    //fazlab(linha,coluna,matriz,l-1,c);
    //fazlab(linha,coluna,matriz,l,c+1);
    //fazlab(linha,coluna,matriz,l,c-1);

}



int main(){
    int linha,coluna;
    scanf("%d %d", &linha, &coluna);

    srand(time(NULL));
    char matriz[linha+2][coluna+2];

    for(int i = 0; i < linha+2; i++){
        for(int j = 0; j < coluna+2; j++) {
            matriz[i][j] = '0';
        }
    }

    for(int i = 1; i < linha+1; i++){
        for(int j = 1; j < coluna+1; j++) {
            matriz[i][j] = Parede;
        }
    }

    fazlab(linha+2,coluna+2,matriz,1,1);
    imprime(linha+2,coluna+2,matriz);

}