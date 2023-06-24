#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void br(int xa,int ya,int xb,int yb,int color){
int dx;
int dy;
int yinc;
int xinc;
int einc;
int neinc;
int xchange;
int temp;
int g;

 dx=abs(xb-xa);
 dy=abs(yb-ya);

 if(ya<yb)  yinc=1;
 else      yinc=-1;

 if(xa<xb)  xinc=1;
 else       xinc=-1;

 if(dy<dx)  xchange=0;
 else{
  temp=dx;
  dx=dy;
  dy=temp;
  xchange=1;
 }
 g=2*dy-dx;
 einc=2*dy;
 neinc=2*(dy-dx);

 for(;--dx;){
  putpixel(xa,ya,color);
  if(g<0){
   if(xchange==0)  xa=xa+xinc;
   else            ya=ya+yinc;
    g=g+einc;
  }
  else{
   ya=ya+yinc;
   xa=xa+xinc;
   g=g+neinc;
  }
 }
}

int main(){
int Gd=DETECT, Gn=0;

 initgraph(&Gd ,&Gn ,"");
  for(int f=0;f<400;++f)
     br(f,0,f,300,15);

  for( int f=0;f<50;++f){
     br(50+f,50,50+f,100,3);
     br(100+f,50,100+f,100,3);
  }
  for( int f=0;f<51;++f){
     br(100-f,50,50-f,100,0);
     br(101,50-f,151,100-f,0);
  }
getch();
closegraph();

}
