#include <math.h>
#include <graphics.h>
#include <conio.h>

void dda (int x1,int y1,int x2, int y2,int Exch=0){
double E=0;
double m1,m;
int dx,dy,Xinc,yinc;
dx= x2-x1;
dy = y2-y1;

m = fabs(double(dy)/dx);
m1 = -(1-m);

if(dx<0)
{
dx*=-1;
Xinc= -1;
}
else
    Xinc =1;

    if(dy<0)
        yinc =-1;
        else
            yinc=1;

for(;dx>=0;--dx){

            if(Exch==0)
                putpixel(x1,y1,WHITE);
             else
                       putpixel(y1,x1,WHITE);
             if(E>=0){
                y1=y1+yinc;
                E+=m1;
             }
             else
                E+=m;
             x1=x1+Xinc;
            }
        }
void draw_dda (int x1,int y1,int x2, int y2){
int dx= x2-x1;
int dy = y2-y1;
if(fabs(dx)>=fabs(dy))
    dda(x1,y1,x2,y2,0);
else
    dda(y1,x1,y2,x2,1);

}



int main (){
int gd = DETECT,gm;
initgraph(&gd,&gm,"");

int x1= 230;
int y1 = 240;
int r,rm;
r=200;
int x2=x1;
int xm=x1;
int y2=y1;

int ym;
ym=y1-r;
int th1=0,th2=0;


for(;!kbhit();th1+=6){
    if(th1 >= 360){
        th1=0;
        th2+=6;
        if(th2>=360)
            th2=0;
    }

    delay(1000);
     line(x1,y1,x2,y2);
line(x1,y1,xm,ym);
setcolor(BLUE);
     x2=x1+r*sin(th1 *M_PI/180);
     y2 = y1-r*cos(th1 *M_PI/180);
       line(x1,y1,x2,y2);

   xm=x1+r*sin(th2 *M_PI/180);
     ym = y1-r*cos(th2 *M_PI/180);

       draw_dda(x1,y1,xm,ym);
setcolor(RED);
}
getch();
closegraph();
return 0;
}
