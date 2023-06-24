#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#define MaxC 3
#define nv  30
#define Nv  900
float V[Nv][4];
float V1[Nv][4] ,V2[Nv][4] ;
float Temp[4][4] ;
float Tx=320 , Ty=240 , Sxyz = 120 ;

void Array_Mul(){
 for(int i =0; i<Nv; i++)
	for(int j=0;j<4; j++){
	   float Val = 0;
	   for(int k = 0; k<4 ;k++)
		  Val+=(V1[i][k] * Temp[k][j]);
		  V2[i][j]=Val;
	}
 for( int i=0;i<Nv;i++)
	for(int j=0;j<4;j++)
	   V1[i][j]=V2[i][j];
}
void Tra( float Tx , float Ty ,float Tz ){
int i , j ;
 for(i=0;i<4;++i)
	for(j=0;j<4;++j)
	   if(i==j)Temp[i][j]=1;
	   else    Temp[i][j]=0;
 Temp[3][0]=Tx;
 Temp[3][1]=Ty;
 Temp[3][2]=Tz;
 Array_Mul();
}
void Sc( float Sx , float Sy , float Sz ){
int i , j ;
 for(i=0;i<4;++i)
	for(j=0;j<4;++j)
	   if(i==j)Temp[i][j]=1;
	   else    Temp[i][j]=0;
 Temp[0][0]=Sx;
 Temp[1][1]=Sy;
 Temp[2][2]=Sz;
 Array_Mul();
}
void Rz( float Q ){
int i , j ;
 for(i=0;i<4;++i)
	for(j=0;j<4;++j)
	   if(i==j)Temp[i][j]=1;
	   else    Temp[i][j]=0;
 Temp[0][0]=cos(Q*M_PI/180.);
 Temp[0][1]=sin(Q*M_PI/180.);
 Temp[1][0]=-sin(Q*M_PI/180.);
 Temp[1][1]=cos(Q*M_PI/180.);
 Array_Mul();
}
void Ry( float Q ){
int i , j ;
 for(i=0;i<4;++i)
	for(j=0;j<4;++j)
	   if(i==j)Temp[i][j]=1;
	   else    Temp[i][j]=0;
 Temp[0][0]=cos(Q*M_PI/180.);
 Temp[0][2]=sin(Q*M_PI/180.);
 Temp[2][0]=-sin(Q*M_PI/180.);
 Temp[2][2]=cos(Q*M_PI/180.);
 Array_Mul();
}
void Rx( float Q ){
int i , j ;
 for(i=0;i<4;++i)
	for(j=0;j<4;++j)
	   if(i==j)Temp[i][j]=1;
	   else    Temp[i][j]=0;
 Temp[1][1]=cos(Q*M_PI/180.);
 Temp[1][2]=sin(Q*M_PI/180.);
 Temp[2][1]=-sin(Q*M_PI/180.);
 Temp[2][2]=cos(Q*M_PI/180.);
 Array_Mul();
}

void SetV(float R,float G,float B,float Q1,float Q2,float R1,float R2,float S,int C){
int i , j  ;
 setfillstyle(0,1);
 setcolor(15);
 bar(5,5,55,55);
 rectangle(5,5,55,55);
 line(5,30,55,30);
 line(30,5,30,55);
 for( i=0;i<nv;i++){
    float s1,s2 ;
    s1 = (i/float(nv)+S)/(S+1);
    switch(C){
       case 1 : s2 = s1     ;break;
       case 2 : s2 = (1-s1) ;break;
       case 3 : s2 = sin((1-s1)*M_PI) ; break;
       case 4 : s2 = s1 ; s1 = sin((1-s2)*M_PI) ; break;
       case 5 : s2 = cos((1-s1)*M_PI) ; break;
       case 6 : s2 = s1 ; s1 = cos((1-s2)*M_PI) ; break;
    }

    V[i][0]= R1*s1*cos( i *Q1*M_PI/nv)  ;
    V[i][1]= R2*s2*sin( i *Q2*M_PI/nv) ;
    V[i][2]= 0;
    V[i][3]= 1 ;
    putpixel(V[i][0]*20+30,V[i][1]*20+30,14);
 }
 for( i=1;i<nv;i++){
    float Q ;
    Q = i*2.*M_PI/nv ;
    for( j=0;j<nv;j++){
       V[i*nv+j][0] = V[j][0]*cos(Q) ;
       V[i*nv+j][1] = V[j][1] ;
       V[i*nv+j][2] = V[j][0]*sin(Q) ;
       V[i*nv+j][3] = 1;
    }
 }
 for( i=1;i<14;i++){
    setpalette(i,i);
    setrgbpalette(i,R*(3*i+10),G*(3*i+10),B*(3*i+10));
 }
 setpalette(15,15);
 setrgbpalette(15,10,24,30);
}
void GetV1(){
int i , j ;
 for( i=0;i<Nv;i++)
	for( j=0;j<4;j++)
	   V1[i][j]=V[i][j];
}
void Draw_V1(int Color){
int i  ;
 for( i=0;i<Nv;++i){
    int x,y,c;
    if( Color) c = ((V1[i][2] + 1 )*6+1);
    else       c = 0;
    x = Tx + V1[i][0] *Sxyz ;
    y = Ty + V1[i][1] *Sxyz ;
    putpixel(x,y,c);
 }
}
int main(){
int gdriver = DETECT , gmode;
REGPACK io;
float R = 1 , G =1 , B = 1,Q1=2,Q2=2,R1=1,R2=1,S=1024;
int C=1;



 initgraph(& gdriver , & gmode, " ");

// for(;;)printf("            %d\n",getch());

 SetV(R,G,B,Q1,Q2,R1,R2,S,C);
 GetV1();
 Draw_V1(1);
 for(;;){
     Draw_V1(0);
     io.r_ax=0x0003;
     intr(0x33,&io);
     Tx=io.r_cx;
     Ty=io.r_dx*2+Sxyz+60;
     switch(io.r_bx){
	 case 1 : if( Sxyz-1 > 0   )Sxyz-=1 ; break;
	 case 2 : if( Sxyz+1 < 300  )Sxyz+=1 ; break;
	 case 3 : closegraph(); return;
     }
     if(kbhit()){
      char ch ;
      ch = getch();
      switch(ch){
	case 27 : closegraph(); return;
	case 49 : C=1 ; break;
	case 50 : C=2 ; break;
	case 51 : C=3 ; break;
	case 52 : C=4 ; break;
	case 53 : C=5 ; break;
	case 59 : if( R1+.1 <= 1)R1+=.1 ; break;
	case 60 : if( R1-.1 >=-1)R1-=.1 ; break;
	case 61 : if( R2+.1 <= 1)R2+=.1 ; break;
	case 62 : if( R2-.1 >=-1)R2-=.1 ; break;
	case 63 : if( S*2 <= 1024)S*=2 ; break;
	case 64 : if( S/2 >= .125)S/=2 ; break;
	case 72 : if( Q1-.1 >=-8)Q1-=.1 ; break;
	case 80 : if( Q1+.1 <= 8)Q1+=.1 ; break;
	case 75 : if( Q2-.1 >=-8)Q2-=.1 ; break;
	case 77 : if( Q2+.1 <= 8)Q2+=.1 ; break;
	case 'r': if( R+.1 <= 1)R+=.1 ; break;
	case 'R': if( R-.1 >= 0)R-=.1 ; break;
	case 'g': if( G+.1 <= 1)G+=.1 ; break;
	case 'G': if( G-.1 >= 0)G-=.1 ; break;
	case 'b': if( B+.1 <= 1)B+=.1 ; break;
	case 'B': if( B-.1 >= 0)B-=.1 ; break;
      }
      gotoxy(10,2);
      printf("%-4.3f %-4.3f %-4.3f %-4.3f  %-5.1f %-d  ",Q1,Q2,R1,R2,S,C);
      SetV(R,G,B,Q1,Q2,R1,R2,S,C);
      GetV1();
     }
     Rx(1);
     Ry(2);
     Rz(3);
     Draw_V1(14);
     delay(50);
 }
}
