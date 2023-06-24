#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void BarFill5(int x , int y , int Bc , int Fc ){
int C ;
  C = getpixel(x,y);
  if( C != Bc && C != Fc){
    putpixel(x,y,Fc);
    BarFill5(x+1,y+0,Bc,Fc);
    BarFill5(x+0,y+1,Bc,Fc);
    BarFill5(x-1,y+0,Bc,Fc);
    BarFill5(x+0,y-1,Bc,Fc);
  }
}
void BarF(int x , int y , int L , int Bc , int Fc ){

 setcolor(Bc);
 rectangle(x-L,y-L,x+L,y+L);
 BarFill5(x,y,Bc,Fc);
 if( Fc == 0){
    setcolor(0);
    rectangle(x-L,y-L,x+L,y+L);

 }
}
int main(){
int Gd=DETECT, Gn=0;
int x = 320 , y=240,dx=3 , dy=3;
 initgraph(&Gd ,&Gn ,"");
 BarF(x,y,5,4,2);
 for(;!kbhit();){
    BarF(x,y,5,4,0);
    x+=dx;
    y+=dy;
    if(x>628 || x<12)dx*=-1;
    if(y>468 || y<12)dy*=-1;
    BarF(x,y,5,4,2);
    delay(20);
 }
 getch();
closegraph();
}
