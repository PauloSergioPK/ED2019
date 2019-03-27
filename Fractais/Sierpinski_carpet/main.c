#include "xpaint.h"

void tree(int x, int y, float ang, float tamanho){
    if(tamanho < 1) {
        return;
    }
    int x1 = x - tamanho * xm_cos(ang);
    int y1 = y - tamanho * xm_sin(ang);
    int x2 = x + tamanho * xm_cos(ang);
    int y2 = y + tamanho * xm_sin(ang);

    xs_color((XColor) WHITE);
    xd_filled_rect(x1,y1,x2,y2);

    tree(x,y1-(y2-y1)/2,ang,tamanho/3); //cima
    tree(x,y2+(y2-y1)/2,ang,tamanho/3); //baixo
    tree(x1-(x2-x1)/2,y,ang,tamanho/3); //esquerda
    tree(x2+(x2-x1)/2,y,ang,tamanho/3); //direita

    tree(x1-(x2-x1)/2,y1-(y2-y1)/2,ang,tamanho/3); //SE
    tree(x2+(x2-x1)/2,y2+(y2-y1)/2,ang,tamanho/3); //ID
    tree(x1-(x2-x1)/2,y2+(y2-y1)/2,ang,tamanho/3); //IE
    tree(x2+(x2-x1)/2,y1-(y2-y1)/2,ang,tamanho/3); //SD

}

int main(){
    int largura = 800, altura = 800;
    x_open(largura, altura);
    XColor a = (XColor){40,40,40};
    x_clear(a);
    int x = largura / 2;
    int y = altura/2;
    float tamanho = largura/4.5;
    tree(x, y, 45, tamanho);
    x_save("sierpinsk");
    x_close();
    return 0;
}