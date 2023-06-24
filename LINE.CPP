#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void lin(int x1,int y1,int x2,int y2){

float dx=x2-x1;
float dy=y2-y1;
float m=dy/dx;
float b=y1-m*x1;
float y;
float x;

for(x=x1;x<x2;++x){
 y=m*x+b;
 putpixel(x,y,2);
}
}
int main(){
int Gd=DETECT, Gn=0;
initgraph(&Gd ,&Gn ,"");

lin(0,0,20,10);

getch();
closegraph();
}


