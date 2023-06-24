#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#define Nv 13
#define Ne 13

float V[Nv][2]={{0,0},{0,.2},{.2,.2},{.2,.4},{.3,.4},{.3,0},{.3,.2},{.4,.2},
		{.4,0},{.4,.4},{.5,.3},{1.3},{1,0}};
int   E[Ne][2]={{0,1},{1,2},{2,3},{3,4},{4,5},{5,0},{6,7},{8,9},{9,10},
		{10,11},{11,12},{12,8}};
void Draw(float S){
int i ;
int xa,ya,xb,yb;
  for(i=0;i<Ne;++i){
     xa = V[E[i][0]][0] ;
     line(xa,ya,xb,yb);
  }

}


#define MaxNy 100
#define MaxNx 50
#define W  40
int Xmin , Xmax , Ymin ,Ymax , BL , BH , R , Ax,Ay,A[MaxNy][MaxNx] ;
float SxyMin,SxyMax;
void Box(int , int ,int=0) ;
void ReadData(char*);
int main(){
int  gdriver = DETECT, gmode;
int Y,X,Dx=1,Dy=1;
float Xc,Yc,Sx,Sy;
int SoundFlag = 0 , SoundFreq = 0 ;

// for(  ;  ;  )printf("%d\n",inportb(0x60));
 ReadData("Ball1.txt");
 Xc=(Xmax+Xmin)/2-Xmin ;
 Yc=(Ymax+Ymin)/2-Ymin ;
 Y=Ymin+(Ay-3)*BH+2 ;
 X=Xc-W+Xmin ;
 Sx = Sy = (SxyMax-SxyMin)/2;
 initgraph(&gdriver, &gmode,"");
 delay(1000);
 for(int i = 0 ; i < Ay ; ++i)
    for(int j = 0 ; j < Ax ; ++j)
       Box(i,j);
 setcolor(15);
 rectangle(Xmin-1,Ymin-1,Xmax,Ymax);
 circle(Xc+Xmin,Yc+Ymin,R);
 setcolor(12);
 rectangle(X,Y,X+2*W,Y+R);


 for(  ;  ;  ){
    if( kbhit()){
      char Ch=getch(0x60);//getch();
      if( Ch == 1){//27 ){
	nosound();
	closegraph();
	break ;
      }
      if( Ch == 75 || Ch == 77){
	setcolor(0);
	rectangle(X,Y,X+2*W,Y+R);
	if( Ch == 77 )X+=R/2 ;
	else          X-=R/2 ;
	if( X <= Xmin )X=Xmin+1 ;
	if( X+2*W >= Xmax )X=Xmax-2*W-1 ;
	setcolor(12);
	rectangle(X,Y,X+2*W,Y+R);
      }
    }
    int xc , yc ,Fx=0,Fy=0;
    xc = (Xc+Dx*(Sx+R)+BL)/BL ;  yc = (Yc+Dy*R+BH)/BH      ;
    if( A[yc][xc] )Fx=1 ;
    xc = (Xc+Dx*R+BL)/BL      ;  yc = (Yc+Dy*(Sy+R)+BH)/BH ;
    if( A[yc][xc] )Fy=1 ;

    xc = (Xc+Dx*(Sx+R)+BL)/BL ;  yc = (Yc+Dy*(Sy+R)+BH)/BH ;
    if( A[yc][xc] ){
      SoundFlag = 50 ;
      SoundFreq = A[yc][xc] * 100 + 500 ;
      sound(SoundFreq);
    }
    if(SoundFlag)sound(SoundFreq-5*(--SoundFlag));
    else        nosound();
    switch(A[yc][xc]){
      case 1: case 2: case 3:case 4:case 5:case 6:
	--A[yc][xc];
	Box(yc,xc,1);
	break ;
      case 7 :
	nosound();
	closegraph();
	printf("\n\n\n     You Lost");
	return ;
      case 8 :
	if( (Xmin+Xc) > (X-R) && (Xmin+Xc) < (X+2*W+R) ){
	  Sx += abs((X+W - (Xmin+Xc)))/(2.*W) ;
	  Sy += abs((X+W - (Xmin+Xc)))/(2.*W) ;
	  if( Sx > SxyMax ) Sx = SxyMax ;
	  if( Sy > SxyMax ) Sy = SxyMax ;
	}
	else Fx=Fy=0;
	break ;
    }

    if( Fx ) Dx *= -1 ;
    if( Fy ) Dy *= -1 ;
    Sx -= .00001 ; Sy -= .00001 ;
    if( Sx < SxyMin ) Sx = SxyMin ;
    if( Sy < SxyMin ) Sy = SxyMin ;
    setcolor(0);
    circle(Xc+Xmin,Yc+Ymin,R);
    Xc += Dx*Sx ;
    Yc += Dy*Sy ;
    setcolor(12);
    circle(Xc+Xmin,Yc+Ymin,R);
    delay(2);
 }
}
void Box(int y , int x ,int D){
int x1 , y1 , x2 , y2 ;
 if(A[y][x]<7 && (A[y][x]|D)){
   if(A[y][x])setcolor(7);
   else       setcolor(0);
   setfillstyle(1,A[y][x]);
   x1 = Xmin+(x-1)*BL+2 ;
   y1 = Ymin+(y-1)*BH+2 ;
   x2 = Xmin+x*BL-2 ;
   y2 = Ymin+y*BH-2 ;
   bar(x1,y1,x2,y2);
   rectangle(x1,y1,x2,y2);
 }
}
void ReadData(char*FN){
FILE *fp ;
char ch ;
int x,y;

 fp=fopen(FN,"r");
 fscanf(fp,"%d",&Xmin  );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&Xmax  );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&Ymin  );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&Ymax  );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&BL    );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&BH    );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d",&R     );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%f",&SxyMin);for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%f",&SxyMax);for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 fscanf(fp,"%d %d",&Ay,&Ax  );for(ch=0;ch!='*';)fscanf(fp,"%c",&ch);
 for(y=0;y<Ay;++y){
    int  Temp ;
    fscanf(fp,"%d",&Temp);
    for(x=0;x<Ax;++x){
       fscanf(fp,"%d",&Temp);
       A[y][x] = Temp ;
    }
 }
 fclose(fp);
}
