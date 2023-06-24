#include <graphics.h>
#include <math.h>
#include <conio.h>

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

void bound(int x, int y, int fillcol, int bordercol){
int col= getpixel(x,y);
if((col!=bordercol) && (col != fillcol))
{
putpixel(x,y,fillcol);
  bound(x+1,y,fillcol, bordercol);
    bound(x-1,y,fillcol, bordercol);
     bound(x,y+1,fillcol, bordercol);
      bound(x,y-1,fillcol, bordercol);
      delay(1);
}
}

void flood(int x, int y, int fillcol, int oldcol){

if((getpixel(x,y)) ==oldcol){
    putpixel(x,y,fillcol);
 flood(x+1,y,fillcol, oldcol);
    flood(x-1,y,fillcol, oldcol);
     flood(x,y+1,fillcol, oldcol);
      flood(x,y-1,fillcol, oldcol);
      delay(1);
}
}
int main(){
int gd = DETECT, gm;
initgraph(&gd, &gm,"");


line(120,120,120,140);
line(120,120,140,120);
line(120,140,140,140);
line(140,120,140,140);
   flood(130, 130,RED,BLACK);


line(10,10,10,30);
line(10,10,30,10);
line(10,30,30,30);
line(30,10,30,30);
   bound(20, 20, 1, 15);


line(160,160,160,180);
line(160,160,180,160);
line(160,180,180,180);
line(180,160,180,180);

for(int i=160;i<180;i++){
  fillsq(160,i,180,i);
    delay(100);
}

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

getch();
closegraph();
}
