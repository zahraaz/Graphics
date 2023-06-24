#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#define MaxC 3
#define Nv  8
#define Ne  12
#define Ns  6
float V[Nv][4]={{ 1 , 1 , 1 , 1 },
		{-1 , 1 , 1 , 1 },
		{-1 ,-1 , 1 , 1 },
		{ 1 ,-1 , 1 , 1 },
		{ 1 , 1 ,-1 , 1 },
		{-1 , 1 ,-1 , 1 },
		{-1 ,-1 ,-1 , 1 },
		{ 1 ,-1 ,-1 , 1 }};

int   S[Ns][5]={{0,1,2,3,0},{4,5,6,7,4},{0,1,5,4,0},{1,2,6,5,1},
		{2,3,7,6,2},{3,0,4,7,3}};
int   P[Nv][3]={{0,2,5},{0,2,3},{0,3,4},{0,4,5},
		{1,2,5},{1,2,3},{1,3,4},{1,4,5}};
float V1[Nv][4] ,V2[Nv][4] ;
float Temp[4][4] ;

void Array_Mul(){
 for(int i =0; i<Nv; i++)
	for(int j=0;j<4; j++){
	   float Val = 0;
	   for(int k = 0; k<4 ;k++)
		  Val+=(V1[i][k] * Temp[k][j]);
		  V2[i][j]=Val;
	}
 for( i=0;i<Nv;i++)
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

void GetV1(){
int i , j ;
 for( i=0;i<Nv;i++)
	for( j=0;j<4;j++)
	   V1[i][j]=V[i][j];
}
void Draw_V1(int Color){
int xy[10] ;
int Z=-10000;
int Pz=0;
 for( int i=0;i<Nv;++i){
    if(V1[i][2]>Z){
      Z  = V1[i][2] ;
      Pz = i ;
    }
 }
 for( i=0;i<3;++i){
    if( Color){
      setcolor(15);
      setfillstyle(1,P[Pz][i]+1);
    }
    else{
      setcolor(0);
      setfillstyle(1,0);
    }
    for( int j=0;j < 5;++j){
       xy[j*2]   = V1[S[P[Pz][i]][j]][0] ;
       xy[j*2+1] = V1[S[P[Pz][i]][j]][1] ;
    }
    drawpoly( 5,xy);
    fillpoly( 5,xy);
 }
}
void main(){
int gdriver = DETECT , gmode;
int i ;
char ch ;
float Tx=320 , Ty=240 , Qx = 20 , Qy= 20 , Qz =20, Sxyz=40;
 initgraph(& gdriver , & gmode, " ");

// for(;;)printf("            %d\n",getch());

 for(Qy=0;!kbhit();Qy+=2){
    GetV1();
    Tra(-1,-1,-1);
    Sc(Sxyz,-Sxyz,Sxyz);
    Qx = atan(V1[6][2]/V1[6][1] )*180/M_PI;
    Rx(-Qx);
    Qz = atan(V1[6][0]/V1[6][1] )*180/M_PI;
    Rz(Qz);
    Ry(Qy);
    Tra(Tx,Ty,0);
    Draw_V1(1);
    delay(10);
    Draw_V1(0);
 }
 closegraph();
}