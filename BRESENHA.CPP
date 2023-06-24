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

 if(ya<yb){
   yinc=1;
 }
 else{
   yinc=-1;
 }
 if(xa<xb){
   xinc=1;
 }
 else{
   xinc=-1;
 }
 if(dy<dx){
   xchange=0;
 }
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
   if(xchange==0){
     xa=xa+xinc;
   }
   else{
     ya=ya+yinc;
   }
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
//int i,j,k;
//for(i=0;i<3;++i){
// for(j=0;j<3  ;++j){
//  for(k=0;k<280  ;++k){


br(120,120,400,120,2);
br(120,120,120,400,3);
br(400,120,400,400,4);
br(120,400,400,400,5);


getch();
closegraph();
}
