#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void BarFill1(int x1 , int y1 , int x2 , int y2 ){
int x ;
  for( x = x1 ; x <= x2 ; ++x ){
     line(x,y1,x,y2);
     delay(50);
  }
}
void BarFill2(int x1 , int y1 , int x2 , int y2 ){
int y ;
  for( y = y1 ; y <= y2 ; ++y ){
     line(x1,y,x2,y);
     delay(50);
  }
}
void BarFill3(int x1 , int y1 , int x2 , int y2 ){
int x , y ;
  for( x = x1 ; x <= x2 ; ++x )
     for( y = y1 ; y <= y2 ; ++y ){
	putpixel(x,y,15);
	delay(5);
     }
}
void BarFill4(int x , int y , int Bc , int Fc ){
int C ;
  C = getpixel(x,y);
  if( C == Bc ){
    delay(5);
    putpixel(x,y,Fc);
    BarFill4(x+1,y+0,Bc,Fc);
    BarFill4(x+0,y+1,Bc,Fc);
    BarFill4(x-1,y+0,Bc,Fc);
    BarFill4(x+0,y-1,Bc,Fc);
  }
}
void BarFill5(int x , int y , int Bc , int Fc ){
int C ;
  C = getpixel(x,y);
  if( C != Bc && C != Fc){
    delay(5);
    putpixel(x,y,Fc);
    BarFill5(x+1,y+0,Bc,Fc);
    BarFill5(x+0,y+1,Bc,Fc);
    BarFill5(x-1,y+0,Bc,Fc);
    BarFill5(x+0,y-1,Bc,Fc);
  }
}
void main(){
int Gd=DETECT, Gn=0;
 initgraph(&Gd ,&Gn ,"");

 BarFill1(10,10,30,30);
 BarFill2(40,40,60,60);
 BarFill3(70,70,90,90);
 rectangle(100,100,120,120);
 BarFill4(110,110,0,4);
 rectangle(130,130,150,150);
 BarFill5(140,140,15,2);
 getch();
closegraph();
}