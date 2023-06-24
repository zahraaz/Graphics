#include <graphics.h>
#include <conio.h>
#include <math.h>

void first_c (int xc, int yc,int r){
    int x,y;
    y=r;
    for(x=-r;x<=r;x++){
        y=pow((r*r)-(x*x),0.5);

        putpixel(xc+x,yc+y,15);
        putpixel(xc+x,yc-y,15);
        putpixel(xc-x,yc+y,15);
    putpixel(xc-x,yc-y,15);

    putpixel(xc+y,yc+x,15);
        putpixel(xc+y,yc-x,15);
        putpixel(xc-y,yc+x,15);
    putpixel(xc-y,yc-x,15);

}}

void polar_c(int xc, int yc, int r){

int x, y, q;
float pi=3.14;
for(q=0;q<=45;q++){
    x=r*cos(q*pi/180);
    y=r*sin(q*pi/180);
       putpixel(xc+x,yc+y,15);
        putpixel(xc-x,yc+y,15);
        putpixel(xc+x,yc-y,15);
    putpixel(xc-x,yc-y,15);

    putpixel(xc+y,yc+x,15);
        putpixel(xc-y,yc+x,15);
        putpixel(xc+y,yc-x,15);
    putpixel(xc-y,yc-x,15);
}
}



int main (){
int gd =DETECT, gm;
initgraph(&gd, &gm, "");
int xc=320;
int yc=240;
int r=150;

for(r=150;r>1; r--){
first_c(xc,yc,r);
delay(100);
 }

getch();
closegraph();
return 0;
}

