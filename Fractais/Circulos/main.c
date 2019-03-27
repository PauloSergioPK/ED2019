#include "xpaint.h"

void tree(int x, int y, float ang, float tamanho){
    if(tamanho < 5) {
        return;
    }
    xs_color((XColor) {xm_rand(0,255),xm_rand(0,255),xm_rand(0,255)});
    xd_circle(x, y, tamanho);


    for(int i = 0; i < 6; i++) {
        int x1 = x + tamanho * xm_cos(ang+i*60);
        int y1 = y - tamanho * xm_sin(ang+i*60);
        tree(x1, y1, ang , tamanho / 3);
        tree(x1, y1, ang + 60, tamanho / 3);
        tree(x1, y1, ang + 2*60, tamanho / 3);
        tree(x1, y1, ang + 3*60, tamanho / 3);
        tree(x1, y1, ang + 4*60, tamanho / 3);
        tree(x1, y1, ang + 5*60, tamanho / 3);
    }


}

int main(){
    int largura = 800, altura = 800;
    x_open(largura, altura);
    XColor a = (XColor){40,40,40};
    x_clear(a);
    int x = largura / 2;
    int y = altura/2;
    float tamanho = largura/3;
    tree(x, y, 360/6, tamanho);
    x_save("circulos");
    x_close();
    return 0;
}