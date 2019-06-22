#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const char Invalido = '#';

struct Pos{
    int l;
    int c;
    Pos(int l = -1, int c = -1){
        this->l = l;
        this->c = c;
    }
};

vector<Pos> get_neibs(Pos &pos){
    vector<Pos> posicoes = {Pos((pos.l-1),pos.c),Pos((pos.l+1),pos.c),Pos(pos.l,(pos.c-1)),Pos(pos.l,(pos.c+1))};
    return posicoes;
}

bool has_value(vector<string> &mat, int nl, int nc, int l, int c, char desejado){
    if(l >= 0 && l < nl && c >= 0 && c < nc && mat[l][c] == desejado)
        return true;
    return false;
}

int floodfill(vector<string> &mat, int nl, int nc, int l, int c, char desejado){
    queue<Pos> fila;
    int total = 0;
    fila.push(Pos(l,c));
    while(!fila.empty()){
        Pos ref = fila.front();
        fila.pop();
        for(auto neib : get_neibs(ref)){
            if(has_value(mat,nl,nc,neib.l,neib.c,desejado)){
                mat[neib.l][neib.c] = Invalido;
                fila.push(neib);
                total++;
            }
        }
    }
    return total;
}

Pos bestPos(vector<string> mat, int nl, int nc){
    int qtd = 0;
    int qtdAtual = 0;
    Pos melhorpos;
    while(true){
        char atual = Invalido;
        for(int i = 0; i < nl; i++){
            for(int j = 0; j < nc; j++){
                if(mat[i][j] != Invalido){
                    atual = mat[i][j];
                    qtdAtual = floodfill(mat,nl,nc,i,j,atual);
                    if(qtdAtual > qtd){
                        qtd = qtdAtual;
                        melhorpos.l = i;
                        melhorpos.c = j;
                    }
                }
            }
        }
        if(atual == Invalido)
            break;
    }
    return melhorpos;
}

int main(){
    int nl,nc;
    cin >> nl >> nc;
    vector<string> mat (nl,(nc,"x"));
    for(int i = 0; i < nl; i++){
        string linha;
        cin >> linha;
        mat[i] = linha;
    }

    Pos melhorpos = bestPos(mat,nl,nc);
    if(melhorpos.l != -1 && melhorpos.c != -1){
        floodfill(mat,nl,nc,melhorpos.l,melhorpos.c,mat[melhorpos.l][melhorpos.c]);
    }

    for(int i = 0; i < nl; i++)
        cout << mat[i] << endl;

}