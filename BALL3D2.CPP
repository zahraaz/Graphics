#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#define MaxC 3
#define nv  50
#define Nv  2500
#define VarMax 4
float V[Nv][4] ;
float Temp[4][4] ;
float Var[10][2] ={{.5,.5},{.5,.5}};

void Array_Mul(){
float v[4] ;
int i , j , k ;
 for(i =0; i<Nv; i++){
    for( j=0;j<4; j++){
       float Val = 0;
       for( k = 0; k<4 ;k++)
	  Val+=(V[i][k] * Temp[k][j]);
       v[j]=Val;
    }
    for( j=0;j<4; j++)
       V[i][j] = v[j] ;
 }
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

void SetV(float S,int C){
float Q1,Q2,R1,R2,Qy1,Qy2;
int i , j  ;
 Q1  = (Var[2][0] -.5) * 4 ;
 Q2  = (Var[2][1] -.5) * 4 ;
 R1  = (Var[3][0] -.5) * 2 ;
 R2  = (Var[3][1] -.5) * 2 ;
 Qy1 = (Var[4][0] -.5) * 4 ;
 Qy2 = (Var[4][1] -.5) * 4 ;
 setfillstyle(0,1);
 setcolor(15);
 rectangle(2,2,637,57);
 bar(585,5,635,55);
 bar(5,5,55,55);
 rectangle(585,5,635,55);
 rectangle(5,5,55,55);
 line(30,5,30,55);
 line(610,5,610,55);
 char T[6][10]={" T "," S " , " Qxy" , " Rxy "," Qz"," Rh/C"};
 for( i = 0 ; i <= VarMax ; ++i ){
    gotoxy(10+i*7,1);printf("%s",T[i]);
    gotoxy(10+i*7,2);printf("%-4.3f",Var[i][0]);
    gotoxy(10+i*7,3);printf("%-4.3f",Var[i][1]);
 }
 gotoxy(10+i*7,1);printf("%s",T[i]);
 gotoxy(10+i*7,2);printf("%-8.3f",S);
 gotoxy(10+i*7,3);printf("%-d",C);
 line(5,30,635,30);
 putpixel(Var[9][0]*40+590,Var[9][1]*40+10,14);
 float X=0,Y=0,Z=0;
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
    X+=V[i][0];
    Y+=V[i][1];
 }
 for( i=1;i<nv;i++){
    float Q ;
    Q = i*M_PI/nv ;
    for( j=0;j<nv;j++){
       V[i*nv+j][0] = V[j][0]*cos(Q*Qy1) ;
       V[i*nv+j][1] = V[j][1] ;
       V[i*nv+j][2] = V[j][0]*sin(Q*Qy2) ;
       V[i*nv+j][3] = 1;
       X+=V[i*nv+j][0];
       Y+=V[i*nv+j][1];
       Z+=V[i*nv+j][2];

    }
 }
 X /= Nv ; Y /= Nv ; Z /= Nv ;

 for( i=0;i<Nv;i++){
    V[i][0]-=X;
    V[i][1]-=Y;
    V[i][2]-=Z;

 }
}
void Draw_V1(int Color){
int i  ;
 for( i=0;i<Nv;++i){
    int x,y,c;
    if( Color) c = ((V[i][2] + 1 )*6+1);
    else       c = 0;
    float Tx ,Ty,S;
    S  = Var[1][0]*240+10 ;
    Tx = Var[0][0]*640;
    Ty = Var[0][1]*(420-S)+60+S;
    x  = Tx+ V[i][0] *S ;
    y  = Ty+ V[i][1] *S ;
    putpixel(x,y,c);
 }
}
void InitG(){
 int gdriver = DETECT , gmode;
 initgraph(& gdriver , & gmode, " ");
 for( int i=1;i<14;i++){
    setpalette(i,i);
    setrgbpalette(i,(3*i+10),(3*i+10),(3*i+10));
 }
 setpalette(15,15);
 setrgbpalette(15,10,24,30);
}

void main(){
REGPACK io;
float S=1024;
float Q=0;
int C=1,I=0;

 InitG();
// for(;;)printf("            %d\n",getch());
/*  for(;;){
  io.r_ax=0x0003;
  intr(0x33,&io);
  printf(" %f   %f\n",(io.r_cx-3)/629.,(io.r_dx-4)/192.);
  }*/

 SetV(S,C);
 Draw_V1(1);
 setcolor(14);
 line(72+I*56,50,110+I*56,50);
 for(;;){
     Draw_V1(0);

     io.r_ax=0x0003;
     intr(0x33,&io);

     Var[9][0] = (io.r_cx-3)/629.;
     Var[9][1] = (io.r_dx-4)/192. ;
     if(io.r_bx){
       setcolor(0);
       line(72+I*56,50,110+I*56,50);
       switch(io.r_bx){
	   case 1 : if( ++I > VarMax )I=0      ; break;
	   case 2 : Var[I][0] = Var[9][0] ;
		    Var[I][1] = Var[9][1] ;
		    break;
	   case 3 : closegraph(); return;
       }
       setcolor(14);
       line(72+I*56,50,110+I*56,50);
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
	case 59 : if( S/2 >= .125)S/=2 ; break;
	case 60 : if( S*2 <= 1024)S*=2 ; break;
      }
     }
     SetV(S,C);
     Rx(Q+1);
     Ry(Q+2);
     Rz(Q+3);
     ++Q;
     Draw_V1(14);
     delay(50);
 }
}