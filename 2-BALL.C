#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#define W 20
#define R 3
#define Xmin 200
#define Xmax 450
#define Ymin 20
#define Ymax 460
void flood(int x,int y,int firstcolor,int newcolor){
int aa;
 aa=getpixel(x,y);
 if(aa==firstcolor){
   putpixel(x,y,newcolor);
   flood(x+1,y,firstcolor,newcolor);
   flood(x-1,y,firstcolor,newcolor);
   flood(x,y+1,firstcolor,newcolor);
   flood(x,y-1,firstcolor,newcolor);
 }
}
int main(){
int gdriver = DETECT, gmode;
char c=0;
int Xc=(Xmax+Xmin)/2,Yc=(Ymax+Ymin)/2,Y=Ymax-W,X=Xc-W,Dx=1,Dy=1;

 initgraph(&gdriver, &gmode, "c:\\Borlandc\\BGI");


 ///////// rectangle(Xmin,Ymin,Xmin+70,Ymin+25);
 for(int i=0;i<25;++i){
  for(int j=0;j<50;++j){
   putpixel(Xmin+0+j,Ymin+0+i,1);
   putpixel(Xmin+0+j,Ymin+25+i,2);
   putpixel(Xmin+0+j,Ymin+50+i,3);
   putpixel(Xmin+0+j,Ymin+75+i,4);

   putpixel(Xmin+50+j,Ymin+0+i,5);
   putpixel(Xmin+50+j,Ymin+25+i,6);
   putpixel(Xmin+50+j,Ymin+50+i,7);
   putpixel(Xmin+50+j,Ymin+75+i,8);

   putpixel(Xmin+100+j,Ymin+0+i,9);
   putpixel(Xmin+100+j,Ymin+25+i,10);
   putpixel(Xmin+100+j,Ymin+50+i,11);
   putpixel(Xmin+100+j,Ymin+75+i,12);

   putpixel(Xmin+150+j,Ymin+0+i,13);
   putpixel(Xmin+150+j,Ymin+25+i,14);
   putpixel(Xmin+150+j,Ymin+50+i,17);
   putpixel(Xmin+150+j,Ymin+75+i,18);

   putpixel(Xmin+200+j,Ymin+0+i,19);
   putpixel(Xmin+200+j,Ymin+25+i,20);
   putpixel(Xmin+200+j,Ymin+50+i,21);
   putpixel(Xmin+200+j,Ymin+75+i,22);
  }
return 0;
 }

 rectangle(Xmin,Ymin,Xmax,Ymax);
 circle(Xc,Yc,R); // delay(2000);
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
	if( c == 77 )X+=30 ;
	else         X-=30 ;
	if( X <= Xmin )X=Xmin+1 ;
	if( X+2*W >= Xmax )X=Xmax-2*W-1 ;
	//delay(2000);
	setcolor(12);
	rectangle(X,Y,X+2*W,Y+R);
      }
    }
   if( (Xc+Dx+R) >= Xmax || (Xc+Dx-R) <= Xmin )Dx*=-1 ;
   if( (Yc+Dy+R) >= Ymax || (Yc+Dy-R) <= Ymin )Dy*=-1 ;
   int p1=Yc+Dy+R;
   int p2=Xc+Dx;
   int color=getpixel(p2,p1);

   if( (Yc+Dy+R) ==  Y && color==12){
     Dy=-1 ;
   }
   if( (Yc+Dy+R) == Y+17 ){
     printf(" YOU LOST........");
   }

   int up=(getpixel(Xc,Yc+Dy-R-2)| getpixel(Xc,Yc+Dy+R-2)|   getpixel(Xc+Dx-R-2,Yc)|   getpixel(Xc+Dx+R+2,Yc));

   if( up==1 || up==2 ||up==3||up==4 ||up==5 ||up==6 ||up==7 ||up==8 ||up==9 ||up==10 ||up==11 ||up==12 ||up==13 ||up==14 ||up==17 ||up==18 ||up==19 ||up==20 ||up==21 ||up==22){
     flood(Xc,Yc+Dy-R-2,up,0);
     flood(Xc,Yc+Dy+R-2,up,0);
     flood(Xc+Dx-R-2,Yc,up,0);
     flood(Xc+Dx+R-2,Yc,up,0);
     Dy*=-1;
   }


   setcolor(0);
   circle(Xc,Yc,R);
   Xc+=Dx ;
   Yc+=Dy ;
   setcolor(12);
   circle(Xc,Yc,R);
   delay(5);
 }

}
