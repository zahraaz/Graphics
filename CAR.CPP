#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#define Nv 13
#define Ne 13

float V[Nv][2]={{0,0},{0,.2},{.2,.2},{.2,.4},{.3,.4},{.3,0},{.3,.2},{.4,.2},
		{.4,0},{.4,.4},{.5,.3},{1,.3},{1,0}};
int   E[Ne][2]={{0,1},{1,2},{2,3},{3,4},{4,5},{5,0},{6,7},{8,9},{9,10},
		{10,11},{11,12},{12,8}};
void Draw(int X , int Y ,float S){
int i ;
int xa,ya,xb,yb;
  for(i=0;i<Ne;++i){
     xa = X + V[ E[i][0] ][0] * S ;
     ya = Y - V[ E[i][0] ][1] * S ;
     xb = X + V[ E[i][1] ][0] * S ;
     yb = Y - V[ E[i][1] ][1] * S ;
     line(xa,ya,xb,yb);
  }

}

int main(){
int  gdriver = DETECT, gmode;

 initgraph(&gdriver, &gmode,"");
 for(;!kbhit();){
    int x , y , s ;
    x = random(640) ;
    y = random(480) ;
    s = 10+random(200) ;
    setcolor(random(14)+1 );
    Draw( x , y , s );
    delay(50);
    setcolor(0);
    Draw( x , y , s );
 }
    getch();
 closegraph();
}
