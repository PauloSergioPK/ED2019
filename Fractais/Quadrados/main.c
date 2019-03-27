#include "xpaint.h"

void tree(int x, int y, float ang, float tamanho){
    if(tamanho < 1) {
        return;
    }
    int x1 = x - tamanho * xm_cos(ang);
    int y1 = y - tamanho * xm_sin(ang);
    int x2 = x + tamanho * xm_cos(ang);
    int y2 = y + tamanho * xm_sin(ang);

    xs_color((XColor) {xm_rand(0,255),xm_rand(0,255),xm_rand(0,255)});
    xd_thick_line(x1, y1, x1, y2, 1);
    xd_thick_line(x1, y2, x2, y2, 1);
    xd_thick_line(x2, y2, x2, y1, 1);
    xd_thick_line(x2, y1, x1, y1, 1);

    tree(x1, y1, ang, tamanho/2.25); //SE
    tree(x2, y1, ang, tamanho/2.25); //SD
    tree(x1, y2, ang, tamanho/2.25); //IE
    tree(x2, y2, ang, tamanho/2.25); //ID

}

int main(){
    int largura = 800, altura = 800;
    x_open(largura, altura);
    XColor a = (XColor){40,40,40};
    x_clear(a);
    int x = largura / 2;
    int y = altura/2;
    float tamanho = largura/3;
    tree(x, y, 45, tamanho);
    x_save("quadrados");
    x_close();
    return 0;
}