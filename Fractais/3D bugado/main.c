#include "xpaint.h"

void tree(int x, int y, float ang, int tamanho){
    if(tamanho < 1) {
        return;
    }
    int x1 = x - tamanho * xm_cos(ang);
    int y1 = y - tamanho * xm_sin(ang);
    int x2 = x + tamanho * xm_cos(ang);
    int y2 = y + tamanho * xm_sin(ang);

    xs_color((XColor) WHITE);
    xd_filled_rect(x1,y1,x2,y2);

    tree(x2+x/tamanho,y,ang,tamanho/2); //direita
    tree(x1-x/tamanho,y,ang,tamanho/2); //esquerda
    tree(x,y1-y/tamanho,ang,tamanho/2); //cima
    tree(x,y2+y/tamanho,ang,tamanho/2); //baixo
    //tree(x1-x/tamanho,y1-y/tamanho,ang,tamanho/2); //superioresquerdo
    //tree(x2+x/tamanho,y1-y/tamanho,ang,tamanho/2); //superiordireito
   // tree(x1-x/tamanho,y2+y/tamanho,ang,tamanho/2); //inferioresquerdo
    //tree(x2+x/tamanho,y2+y/tamanho,ang,tamanho/2); //inferiordireito

}

int main(){
    int largura = 600, altura = 600;
    x_open(largura, altura);
    XColor a = (XColor){40,40,40};
    x_clear(a);
    int x = largura / 2;
    int y = altura/2;
    float tamanho = altura/8;
    tree(x, y, 45, tamanho);
    x_save("sierpinsk");
    x_close();
    return 0;
}