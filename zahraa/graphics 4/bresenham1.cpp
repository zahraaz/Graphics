#include <graphics.h>
#include <conio.h>

void bresenham (int x1, int y1, int x2, int y2,int c){

int dx = x2-x1;
int dy = y2-y1;
int xinc, yinc, p, exch, pinc, ninc;
if(dx>0){
    xinc=1;
}
else {
    xinc= -1;
    dx=-dx;

}
if (dy>0){
    yinc=1;
}
else {
    yinc=-1;
    dy=-dy;
}

if(dx>dy){
    exch=0;
}
else{
    exch =1;
    int swa;
    swa=dx;
    dx=dy;
    dy=swa;
    }
p=2*dy-dx;
pinc =2*dy-2* dx;
ninc =2*dy;

for (;dx>0;dx--){
    putpixel(x1,y1,c);
    if(p>0)
{

    x1=x1+xinc;
    y1=y1+yinc;
    p=p+pinc;
}
else{
    p=p+ninc;
    if(exch==1)
        y1=y1+yinc;
    else
        x1=x1+xinc;
}
}
}

int main (){
int gd = DETECT, gm;
initgraph (&gd, &gm, "");
int x1,x2;
int y1,y2;
x1=600;
y1 =100;
y2= 120;
x2 = 580;
bresenham(x1,y1,x1,y2,15);
bresenham(x2,y1,x2,y2,15);
bresenham(x2,y1,x1,y1,15);
bresenham(x2,y2,x1,y2,15);


double u;
for(u=280;u>0;u-=10){
    bresenham(x1,y1,x1,y2,0);
    bresenham(x2,y1,x2,y2,0);
    bresenham(x2,y1,x1,y1,0);
    bresenham(x2,y2,x1,y2,0);

    x1=x1-5;
    x2=x2-5;
    bresenham(x1,y1,x1,y2,15);
    bresenham(x2,y1,x2,y2,15);
    bresenham(x2,y1,x1,y1,15);
    bresenham(x2,y2,x1,y2,15);

    delay(100);
}
getch();
closegraph();
return 0;
}

