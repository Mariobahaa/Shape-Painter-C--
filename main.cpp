#include <iostream>
#include "graphics.h"

using namespace std;
class point {
    int xpos;
    int ypos;
public:

    point(int x=0,int y=0)
    {
        xpos = x;
        ypos =y;
    }
    void setX(int x=0) {xpos = x;}
    void setY (int y=0) {ypos=y;}

    int getX() {return xpos;}
    int getY() {return ypos;}

};


class rect {
    point BR;
    point UL;
    int color;

public :
    rect(point u, point b,int c){
        BR = b;
        UL = u;
        color = c;
    }

    void draw(){
        //initgraph();
        setcolor(color);
        rectangle(BR.getX(), BR.getY(),UL.getX(), UL.getY());

    }


};



class Line {
    point BR;
    point UL;
    int color;

public :
    Line(point u, point b,int c){
        BR = b;
        UL = u;
        color = c;
    }

    void draw(){
       // initgraph();
        setcolor(color);
        line(BR.getX(), BR.getY(),UL.getX(), UL.getY());

    }


};


class Triangle {
    point a;
    point b;
    point c;
    int color;

public :
    Triangle(point aa, point bb, point cc, int cl){
        a =aa;
        b =bb;
        c =cc;
        color = cl;
    }

    void draw(){
       // initgraph();
        Line L1(a,b,color);
        L1.draw();

        Line L2(b,c,color);
        L2.draw();

        Line L3(c,a,color);
        L3.draw();

    }


};


class Circle {
    point center;
    int radius;
    int color;

public :
    Circle(point p, int r,int c){
        center = p;
        radius = r ;
        color = c;
    }

    void draw(){
        //initgraph();
        setcolor(color);
        circle(center.getX(),center.getY(), radius);

    }


};

class Square : public rect{
    public:
    Square(point p,int side,int c): rect(p,point(p.getX()+side,p.getY()+side),c){}
};



int main()
{
    system("cls");
    initgraph();
    Circle c1(point(400,100),100,100);
    c1.draw();
    Line l1(point(450,100),point(470,280),100);
    l1.draw();
    Line l2(point(350,100),point(330,280),100);
    l2.draw();
    Circle c2(point(400,280),140,100);
    c2.draw();
    rect r(point(300,380),point(500,500),100);
    r.draw();
    Line l3(point(385,350),point(385,420),100);
    l3.draw();
    Line l4(point(415,350),point(415,420),100);
    l4.draw();
    Triangle tri(point(485,475),point(475,490),point(495,490),100);
    tri.draw();
    //Square Sq((0,0),200,200);
    //Sq.draw();

    int x;
    cin >> x;
    return 0;
}
