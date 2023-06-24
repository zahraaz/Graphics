#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void dda(float x1,float y1,float x2,float y2){
float m;
float m1;
float h;
int c;
float d;
int f;
int r;

float dx=x2-x1;
float dy=y2-y1;

 if(abs(dx)>abs(dy)){
  m=dy/dx;
  if(dx>0){
   c=ceil(x1);
   d=y1+m*(c-x1);
   f=floor(x2);
  }
  else{
   c=ceil(x2);
   d=y2+m*(c-x2);
   f=floor(x1);
  }
 r=floor(d+0.5);
 h=r-d+m;
  if(m>0){
    m1=m-1;
    while(c<=f){
     putpixel(c,r,2);
     ++c;
     if(h>=0.5){
     ++r;
     h=h+m1;
     }
     else
     h=h+m;
    }
  }
  else{
   m=-m;
   h=-h;
   m1=m-1;
   while(c<=f){
    putpixel(c,r,2);
    ++c;
    if(h>=0.5){
     --r;
     h=h+m1;
    }
    else
     h=h+m;
   }
  }
 }
}

int main(){
int Gd=DETECT, Gn=0;
initgraph(&Gd ,&Gn ," ");

dda(0,0,640,500);

getchar();
closegraph();
}
