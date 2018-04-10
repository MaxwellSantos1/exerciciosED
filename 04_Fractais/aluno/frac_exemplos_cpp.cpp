#include <lib/pen.h>

//QUADRADO_ESPIRAL
void quadradoEspiral(Pen& p, int lado){
    p.setColor(sf::Color::Yellow);
    for(int i=0;i<4;i++){
        p.walk(lado);
        p.left(90);
    }
}
//FLOCO_NEVE
void flocoNeve(Pen& p, int lado){
    float angulo = 144;
    float decremento = 3;
    if(lado <=0)
        return;
    for (int i=0;i<5;i++) {
        p.walk(lado);
        flocoNeve(p,lado/decremento);
        p.walk(-lado);
        p.left(angulo);
    }
}
//ARVORE
void arvore(Pen& p, int lado){
    float ang = 35;
    float dec = 15;
    if (lado <=0)
        return;
    p.walk(lado);
    p.right(ang);
    arvore(p, lado - dec);
    p.left(ang);
    arvore(p, lado - dec);
    p.left(ang);
    arvore(p, lado - dec);
    p.right(ang);
    p.walk(-lado);

}
//ESFERA_DRAGAO
void esferaDragao(Pen& p, int lado) {
    int angulo = 144;
    for(int i=0;i<5;i++) {
        p.walk(lado);
        p.left(angulo);
    }
}
//TRIGO
void trigo(Pen& p, int lado) {
    float decremento = 2.5;
    float angulo = 40;
    if(lado <=0) {
        return;
    }
    for(int i=0;i<3;i++) {
        p.walk(lado);
        p.right(angulo);
        trigo(p, lado/decremento);
        p.left(angulo*2);
        trigo(p, lado/decremento);
        p.right(angulo);
    }
    p.walk(-lado*3);
}

void fractal(){
    Pen p(800, 600);
    p.setSpeed(20);

    p.setColor(255,255,102);
    p.setXY(400, 580);
    p.setHeading(90);
    trigo(p, 80);
    p.clear();

    p.setColor(255,140,0);
    p.setXY(400, 300);
    p.setThickness(3);
    p.circle(170);
    p.setHeading(35);
    p.setXY(360, 425);
    esferaDragao(p, 130);
    p.setXY(450, 280);
    esferaDragao(p, 100);
    p.setXY(300, 280);
    esferaDragao(p, 100);
    p.clear();

    p.setColor(0,100,0);
    p.setXY(400, 500);
    p.setThickness(2);
    p.setHeading(90);
    arvore(p, 100);
    p.clear();

    p.setColor(176,196,222);
    p.setXY(400, 300);
    p.setThickness(3);
    p.setHeading(0);
    flocoNeve(p, 200);
    p.clear();

    p.setThickness(1);
    p.setHeading(40);
    p.setXY(280, 580);
    quadradoEspiral(p, 200);

    p.setHeading(-10);
    p.setXY(130, 350);
    quadradoEspiral(p, 170);

    p.setHeading(-40);
    p.setXY(180, 160);
    quadradoEspiral(p, 140);

    p.setHeading(-90);
    p.setXY(350, 30);
    quadradoEspiral(p, 110);

    p.setHeading(30);
    p.setXY(470, 200);
    quadradoEspiral(p, 90);

    p.setHeading(0);
    p.setXY(480, 250);
    quadradoEspiral(p, 70);

    p.setHeading(-40);
    p.setXY(470, 280);
    quadradoEspiral(p, 50);

    p.setHeading(-90);
    p.setXY(440, 270);
    quadradoEspiral(p, 40);

    p.setHeading(-40);
    p.setXY(400, 280);
    quadradoEspiral(p, 35);

    p.setHeading(-10);
    p.setXY(390, 260);
    quadradoEspiral(p, 30);

    p.wait(2);
}

int main(){
    fractal();
    return 0;
}void linha(Pen &p, int lado, int rotacao){
    if(lado < 1)
        return;
    //p.setColor(rand()%255, rand()%255, rand()%255);

    p.walk(lado);
    p.right(90 * rotacao);
    //linha(p, lado - 5, 1);

    p.setColor(rand()%255, rand()%255, rand()%255);
    linha(p, lado - 5, -1);
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);
    p.circle(200);
    linha(p, 100, -1);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
