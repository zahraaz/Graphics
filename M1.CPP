#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
float x1=0,y1=0,y2=479,x2=639;
float x,y;
float m=(y2-y1)/(x2-x1);
int gd=DETECT,gm=0;

 initgraph(&gd,&gm,"");
 rectangle(0,0,639,479);
 y=y1;
 for(x=x1;x<=x2;++x){
    putpixel(x,y,2);
    y=y+m;
 }
 y=y1;
 for(x=x2;x>=x1;--x){
    putpixel(x,y,2);
    y=y+m;
 }
 getch();
}
