#include "xpaint.h"

void tree(int x, int y, float ang, int tamanho,int expessura){
    if(tamanho < 15) {
        xs_color(make_xcolor(255,183,200));
        xd_filled_circle(x, y, 20);
        return;
    }
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    xs_color((XColor) WHITE);
    xd_thick_line(x, y, xf, yf, expessura);
    x_step("tree");
    int galhos = xm_rand(2,3);
    if(galhos == 2) {
        tree(xf, yf, ang - 27, tamanho - xm_rand(20, 25),expessura-1);
        tree(xf, yf, ang + 27, tamanho - xm_rand(20, 25),expessura-1);
    }
    else{
        tree(xf, yf, ang - xm_rand(15,27), tamanho - xm_rand(20, 25),expessura-1);
        tree(xf, yf, ang + xm_rand(15,27), tamanho - xm_rand(20, 25),expessura-1);
        tree(xf, yf, ang , tamanho - xm_rand(20, 25),expessura-1);

    }
}

int main(){
    int largura = 2560, altura = 1080;
    x_open(largura, altura);
    XColor a = (XColor){40,40,40};
    x_clear(a);
    float ang = 90;
    int x = largura / 2;
    int y = altura;
    float tamanho = 200;
    tree(x, y, ang, tamanho,11);
    x_save("tree");
    x_close();
    return 0;
}