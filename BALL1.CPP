#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#define W 20
#define R 3
#define Xmin 200
#define Xmax 440
#define Ymin 20
#define Ymax 460
void main(){
int gdriver = DETECT, gmode;
char c=0;
int Xc=(Xmax+Xmin)/2,Yc=(Ymax+Ymin)/2,Y=Ymax-W,X=Xc-W,Dx=1,Dy=1;

 initgraph(&gdriver, &gmode, "c:\\Borlandc\\BGI");

 rectangle(Xmin,Ymin,Xmax,Ymax);
 circle(Xc,Yc,R);
 rectangle(X,Y,X+2*W,Y+R);
 for(  ;  ;  ){

    if(kbhit()){
      c=getch();
      if( c == 27 ){
	closegraph();
	break ;
      }
      if( c == 75 || c == 77){
	setcolor(0);
	rectangle(X,Y,X+2*W,Y+R);
	if( c == 77 )X+=R ;
	else         X-=R ;
	if( X <= Xmin )X=Xmin+1 ;
	if( X+2*W >= Xmax )X=Xmax-2*W-1 ;
	setcolor(15);
	rectangle(X,Y,X+2*W,Y+R);
      }
    }
   if( (Xc+Dx+R) >= Xmax || (Xc+Dx-R) <= Xmin )Dx*=-1 ;
   if( (Yc+Dy+R) >= Ymax || (Yc+Dy-R) <= Ymin )Dy*=-1 ;
   setcolor(0);
   circle(Xc,Yc,R);
   Xc+=Dx ;
   Yc+=Dy ;
   setcolor(15);
   circle(Xc,Yc,R);
   delay(20);
 }

}
