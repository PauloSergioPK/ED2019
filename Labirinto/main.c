#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const char Parede = '#';
const char Caminho = ' ';

int Horizontal[4] = {1,-1,0,0};
int Vertical[4] = {0,0,1,-1};

void imprime(int linha, int coluna, char matriz[linha][coluna]){
    for(int i = 0; i <linha; i++){
        for(int j = 0; j < coluna; j++){
            if(matriz[i][j] == '0' || matriz[i][j] == Parede)
                printf("#");

            else
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

void suffle(){
    int aleatorio = 0;
    for(int i = 0; i < 4; i++){
        aleatorio = rand()%4;
        int aux = Horizontal[aleatorio];
        Horizontal[aleatorio] = Horizontal[i];
        Horizontal[i] = aux;
        aux = Vertical[aleatorio];
        Vertical[aleatorio] = Vertical[i];
        Vertical[i] = aux;
    }
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
    suffle();
    for(int i = 0; i < 4; i++) {
       fazlab(linha, coluna, matriz, (l + Vertical[i]), (c + Horizontal[i]));
    }
}

bool xeroqueroumes(int linha, int coluna, char matriz[linha][coluna], bool matriz2[linha][coluna],int l, int c, int lfinal, int cfinal){
    if(l >= linha-1 || l < 1 || c>= coluna-1 || c < 1)
        return false;
    if(matriz[l][c] != ' ')
        return false;
    if(matriz2[l][c] == true)
        return false;

    matriz2[l][c] = true;
    matriz[l][c] = '.';

    if(l == lfinal && c == cfinal)
        return true;
    if((xeroqueroumes(linha,coluna,matriz,matriz2,l+1,c,lfinal,cfinal))||(xeroqueroumes(linha,coluna,matriz,matriz2,l-1,c,lfinal,cfinal))||(xeroqueroumes(linha,coluna,matriz,matriz2,l,c-1,lfinal,cfinal))||(xeroqueroumes(linha,coluna,matriz,matriz2,l,c+1,lfinal,cfinal)))
        return true;
    matriz[l][c] = ' ';
        return false;
}



int main(){
    int linha,coluna;
    scanf("%d %d", &linha, &coluna);

    srand(time(NULL));
    char matriz[linha+2][coluna+2];
    bool matriz2[linha+2][coluna+2];

    for(int i = 0; i < linha+2; i++){
        for(int j = 0; j < coluna+2; j++) {
            matriz[i][j] = '0';
            matriz2[i][j] = false;
        }
    }

    for(int i = 1; i < linha+1; i++){
        for(int j = 1; j < coluna+1; j++) {
            matriz[i][j] = Parede;
        }
    }



    fazlab(linha+2,coluna+2,matriz,1,1);
    imprime(linha+2,coluna+2,matriz);
    printf("\nDigite uma linha e uma coluna para saida\n");
    int ls, cs;
    scanf("%d %d", &ls, &cs);
    bool achou = xeroqueroumes(linha+2,coluna+2,matriz,matriz2,1,1,ls,cs);
    if(achou)
        imprime(linha+2,coluna+2,matriz);
}