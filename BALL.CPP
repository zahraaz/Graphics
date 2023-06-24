#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void ff(int x,int y,int bc,int fc){
int c=getpixel(x,y);
 if(c == bc ){
   putpixel(x,y,fc);
   ff(x+1,y,bc,fc);
   ff(x-1,y,bc,fc);
   ff(x,y+1,bc,fc);
   ff(x,y-1,bc,fc);
 }
}






int main(){

int count1=0,count2=0;
printf("Player1 Control Keys :\n\nUp Arrow  :  UP\nDown Arrow  :  DOWN\n\n\n*********************************\n\n\nPlayer2 Control Keys :\n\nW  :  UP\nS  :  DOWN\n\n---------------------------------\n\nESC  Exit\n\n\nPress any Key to Play...");
getch();
delay(500);
n:int gdriver = DETECT, gmode;
int xmax, ymax;
initgraph(&gdriver, &gmode, "c:\\Borlandc\\BGI");

char c=0;
int y1=200,y2=300,y11=200,y22=300,d1=1,d11=1,d22=1,d2=1,y=250,x=45,dx=1,dy=1,flag=1;

 for(  ;  ;  ){

    if(kbhit()) c=getch();

    setcolor(0);
    rectangle(600,y1,620,y2);
    setcolor(0);
    rectangle(20,y11,40,y22);


    //Draw the Right Rectangle


    if(c==27)closegraph();
    if(c==72){
      if(y1<=0)d1=(-1);
      else{
	 d1=1;
	 y1=y1-d1;
	 y2=y2-d1;
      }
    }
    if(c==80){
      if(y2>=480)d2=(-1);
      else{
	 d2=1;
	 y1=y1+d2;
	 y2=y2+d2;
      }
    }

   setcolor(3);
   rectangle(600,y1,620,y2);


   //Draw the Left Rectangle


   if(c==27)closegraph();

   if(c=='w' || c=='W'){
     if(y11<=0)d11=(-1);
     else{
	d11=1;
	y11=y11-d11;
	y22=y22-d11;
     }
   }
   if(c=='s' || c=='S'){
     if(y22>=480)d22=(-1);
     else{
	d22=1;
	y11=y11+d22;
	y22=y22+d22;
       }
   }

   setcolor(3);
   rectangle(20,y11,40,y22);


   //Draw The Ball


   x=x+dx;
   y=y+dy;

   if(((y+5)>y1 && ((y+5)<y2 && (x+5)>600)) || ((y+5)>y11 && ((y+5)<y22 && (x-5)<40))) dx=dx*(-1);
   if((x+5)<20){
     count1++;
     closegraph();
     printf("Player1 score : %d",count1);
     getch();
     delay(500);
     if(count1==5){
       printf("\n\nPlayer1 Win !!!");
       getch();
       delay(1000);
       break;
     }
     else goto n;
   }
   if((x+5)>620){
     count2++;
     closegraph();
     printf("Player2 score : %d",count2);
     getch();
     delay(500);
     if(count2==5){
       printf("\n\nPlayer2 Win !!!");
       getch();
       delay(1000);
       break;
     }
     else goto n;
   }

   if((y<=0) || (y+5) >= 480) dy=dy*(-1);

   setcolor(15);
   circle(x,y,10);
   delay(4);
   setcolor(0);
   circle(x,y,10);

 }

 getch();
 closegraph();


}
