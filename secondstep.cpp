#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

void fillsq(int x1, int y1, int x2, int y2){
if(x1>x2){
    int temp = x1; x1=x2; x2 = temp;
    }
if(y1>y2){
    int temp = y1; y1=y2; y2 = temp;
    }
rectangle (x1,y1, x2,y2 );
for(int x=x1;x<x2;x++){
    for(int y=y1;y<y2;y++)
putpixel(x,y,15);
}
}

void fill_right(int x, int y)
    {
        if((getpixel(x,y)!=15) &&(getpixel(x,y)!=RED))
        {
            putpixel(x,y,RED);
            fill_right(++x,y);
            x=x-1;
fill_right(x,y-1);
fill_right(x,y+1);
        }
        delay(1);
    }

    void fill_left (int x, int y)
    {
        if((getpixel(x,y)!=15) &&(getpixel(x,y)!=RED))
        {
            putpixel(x,y,RED);
             fill_left(--x,y);
            x=x+1;
 fill_left(x,y-1);
 fill_left(x,y+1);
        }
        delay(1);

}




void flo_r (int x, int y)
    {
        if(getpixel(x,y)==0)
        {
            putpixel(x,y,YELLOW);
            flo_r(++x,y);
            x=x-1;
flo_r (x,y-1);
flo_r (x,y+1);
        }
        delay(1);
    }

    void flo_l (int x, int y)
    {
        if(getpixel(x,y)==0)
        {
            putpixel(x,y,YELLOW);
             flo_l(--x,y);
            x=x+1;
 flo_l(x,y-1);
flo_l(x,y+1);
        }
        delay(1);

}

int main(){
int gd = DETECT, gm;
initgraph(&gd, &gm,"");


line(10,10,10,30);
line(10,10,30,10);
line(10,30,30,30);
line(30,10,30,30);
int x=20, y=20;
fill_right(x,y);
 fill_left(x-1,y);
line(40,40,40,60);
line(40,40,60,40);
line(40,60,60,60);
line(60,40,60,60);
for(int i=40;i<60;i++){
    line(40,i,60,i);
    delay(100);
}

line(80,80,80,100);
line(80,80,100,80);
line(80,100,100,100);
line(100,80,100,100);
for(int i=80;i<100;i++){
    line(i,80,i,100);
    delay(100);
}


line(120,120,120,140);
line(120,120,140,120);
line(120,140,140,140);
line(140,120,140,140);
int r=130, s=130;
flo_r(r,s);
flo_l(r-1,s);


line(160,160,160,180);
line(160,160,180,160);
line(160,180,180,180);
line(180,160,180,180);

for(int i=160;i<180;i++){
  fillsq(160,i,180,i);
    delay(100);
}

getch();
closegraph();
}
