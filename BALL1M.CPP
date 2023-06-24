#include <dos.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define N      40
#define R      (N/2)
#define R2     (R*R)
#define R2M    ((R-1)*(R-1))
#define Ratio  .6

unsigned long int RegOff = 0 ;
int               RegB = 50  ;
long Xmax ,Ymax;
unsigned char far *A000 = ( unsigned char far *)MK_FP(0xa000,0);
void PutPic(char * );
void InitGaph(int );
void CloseGraph();
void Putpixel(int  , int  , int  );
int Getpixel(int , int );
int Ball[N][N] ;
void DrawBall(int x , int y , int C =1){
static int X = 0 , Y = 0 ;
int i , j ;

 if(C){
   for( i = 0 ; i < N ; ++i)
      for( j = 0 ; j < N ; ++j)
	 Putpixel(X+i,Y+j,Ball[i][j]);
 }

 x -= R ; y -= R ;

 for( i = 0 ; i < N ; ++i)
    for( j = 0 ; j < N ; ++j)
       Ball[i][j] = Getpixel(x+i,y+j);

 for( i = 0 ; i < N ; ++i){
    for( j = 0 ; j < N ; ++j){
       int I=i-R,J=j-R;
       int r = (I*I+J*J);
       if(r<R2M){
	 Putpixel(x+i,y+j,Ball[I*Ratio+R][J*Ratio+R]);
       }
       else if( r <= R2 )Putpixel(x+i,y+j,1);
    }
 }
 X  = x ; Y  = y ;
}
void main( ){
int Xc , Yc ,XminB ,XmaxB,YminB,YmaxB,Dx=2,Dy=2;
 InitGaph(2);
 for(int i=0;i<Xmax;++i)
    for(int j=0;j<Ymax;++j)
       Putpixel(i,j,128+127*sin((i+j)*M_PI/80)*cos((j-i)*M_PI/60));
 PutPic("a3.bmp");
 XminB = Xmax/2-320 ;
 XmaxB = Xmax/2+320 ;
 YminB = Ymax/2-240 ;
 YmaxB = Ymax/2+240 ;
 Xc=(XmaxB+XminB)/2+R ;
 Yc=(YmaxB+YminB)/2+R ;

 DrawBall(Xc,Yc,0);

 for(;;){
    if(kbhit()){
      char c=getch();
      if(c==27)break;
      c=getch();
    }
    if( (Xc+Dx-R) < XminB || (Xc+Dx+R) > XmaxB  )Dx*=-1;
    if( (Yc+Dy-R) < YminB || (Yc+Dy+R) > YmaxB  )Dy*=-1;
    Xc+=Dx;
    Yc+=Dy;
    DrawBall(Xc,Yc);
    delay(50);
 }
 CloseGraph();

}
void PutPic(char *FileName ){
REGPACK io ;
int i , j ;
int X , Y ;
int DX , DY ;
unsigned char ch   ;
unsigned char *Pal ;

FILE *fp  ;

 Pal = new unsigned char[1024] ;
 fp =fopen(FileName,"rb");

 fseek(fp,18,0);
 fread(&X,2,1,fp);
 fseek(fp,22,0);
 fread(&Y,2,1,fp);
 fseek(fp,54,0);
 fread(Pal,1,1024,fp);
 outportb(0x3c8,0);
 for( i = 0 ; i < 256 ; ++i ){
    outportb(0x3c9,Pal[i*4+2]/4);
    outportb(0x3c9,Pal[i*4+1]/4);
    outportb(0x3c9,Pal[i*4+0]/4);
 }
 DX = (Xmax-X)/2 ;if(DX<0)DX=0;
 DY = (Ymax-Y)/2 ;if(DY<0)DY=0;
 for( i = 0 ; i < Y ; ++i ){
    if(i>=Ymax)break;
    for( j = 0 ; j < X ; ++j ){
       fread(&ch,1,1,fp);
       Putpixel(j+DX,(Ymax-1-DY-i),ch);
    }
 }
 fclose(fp);
 delete Pal ;
}
void InitGaph(int M ){
REGPACK io ;

 io.r_ax = 0x4f02 ;
 switch(M){
   default :
     io.r_bx = 0x101;
     Xmax=640;Ymax=480;
     break ;
   case 1 :
     io.r_bx = 0x103;
     Xmax=832;Ymax=600;
     break ;
   case 2 :
     io.r_bx = 0x105;
     Xmax=1024;Ymax=768;
     break ;
   case 3 :
     io.r_bx = 0x107;
     Xmax=1280;Ymax=1024;
     break ;
 }
 intr(0x10,&io);

}
void CloseGraph(){
REGPACK io ;
 io.r_ax = 0x0003 ;
 intr(0x10,&io);
}
void Putpixel(int X , int Y , int  C){
REGPACK io ;
 RegOff = Y*Xmax+X;
 if( RegB != (RegOff>>16) ){
   io.r_ax = 0x4f05 ;
   io.r_bx = 0x000  ;
   io.r_dx = RegB = (int)(RegOff>>16)  ;
   intr(0x10,&io);
 }
 *(A000+(int)(RegOff))=C ;
}
int Getpixel(int X , int Y ){
REGPACK io ;
 RegOff = Y*Xmax+X;
 if( RegB != (RegOff>>16) ){
   io.r_ax = 0x4f05 ;
   io.r_bx = 0x000  ;
   io.r_dx = RegB = (int)(RegOff>>16)  ;
   intr(0x10,&io);
 }
 return (int)(*(A000+(int)(RegOff)));
}
