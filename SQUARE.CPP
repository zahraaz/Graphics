#include<stdio.h>
#include<dos.h>
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

 if(ya<yb)
  yinc=1;
 else
  yinc=-1;

 if(xa<xb)
  xinc=1;
 else
  xinc=-1;

 if(dy<dx)
  xchange=0;
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
   if(xchange==0)
    xa=xa+xinc;
   else
    ya=ya+yinc;
    g=g+einc;
  }
  else{
   ya=ya+yinc;
   xa=xa+xinc;
   g=g+neinc;
  }
 }
}
void Bar( int xa , int ya , int l , int c ){

  for( int k=0 ; k < l ; ++k )
     br( xa,ya+k,xa+l,ya+k,c);
}
int main(){
int Gd=DETECT, Gn=0;
int xa = 320 , ya=240 , l = 40 , c =2 ;
int i;

initgraph(&Gd ,&Gn ,"");



  Bar( xa ,  ya ,  l , c ) ;
  for( i = 0; i< 100 ;i++){
     Bar( xa ,  ya ,  l , 0 ) ;
     xa++;
     ya++;
     Bar( xa ,  ya ,  l , c ) ;
     delay(150);
  }

getch();
closegraph();

}
