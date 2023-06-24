#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<CTYPE.h>
#include<conio.h>
#include<graphics.h>
#define  MaxT 37


class Dis {
 private:
     int Font  , FontH , FontW  ;
     unsigned char F[2][256][16], ch ;
     unsigned char FontT[256][5];
     int Color, i , j ,c;
     unsigned int Text[MaxT] , Mode;
     unsigned int text1[MaxT] ;
     int Index  ;
     check(int  );
     void PutByte(unsigned char ch,int X,int Y);
     void Put(unsigned char *a,int X,int Y);


 public:
     Dis(char * ,char * );
     void ReadFont(unsigned char *A , int L,unsigned char *FN);
     void ReadFontTable();
     void Print();
 };

     Dis::Dis(char *fn ,char *fn1 ){
	ReadFont((unsigned char*)F[0] ,4096,fn);
	ReadFont((unsigned char*)F[1] ,4096,fn1);
	ReadFontTable();

        for( int i = 0 ; i < MaxT ; ++i )text1[i]=Text[i]=32;
     }

void Dis:: Put(unsigned char *a,int X,int Y){

	 for(i=0;i<16;i++){
	   ch=a[i];
	  for(j=0;j<8;++j){
	   if( ch%2 )c = Color ;
	   else      c = 0  ;
	    ch /= 2 ;
	    putpixel((7-j)*2+X,i*2+Y,c);
    }
 }
}

void Dis:: PutByte(unsigned char ch,int X,int Y){

       for(j=0;j<8;++j){
	 if( ch%2 )c = Color ;
	 else      c = 0  ;
	 ch /= 2 ;
	 putpixel((7-j)*2+X,Y,c);
   }
}

void Dis:: ReadFont(unsigned char *A , int L,unsigned char *FN){
FILE *fp;

   fp = fopen(FN,"rb");
   fseek(fp,100,0);
   fread(A,1,L,fp);
   fclose(fp);
}

void Dis:: ReadFontTable(){
FILE *fp;
int i , j , k;
 fp = fopen("dis1.txt","rt");
 for( i = 0 ; i < 256 ; ++i )
    for( j = 0 ; j < 5 ; ++j )
       FontT[i][j]=255;
 for(;;){
    k=fscanf(fp,"%d",&i);
    if(k==EOF)break ;
    for( j = 0 ; j < 5 ; ++j ){
       fscanf(fp,"%d",&k);
       FontT[i][j]=k;
    }
 }
 fclose(fp);
}
int Dis::check(int i ){
 if( i < 0 )return 0 ;
      else if(Text[i]==32)return 0;
	   else if( FontT[Text[i]][4] == 1)return 2;
		else                       return 1;

}
void Dis:: Print(){
int i , j , k , l ;
unsigned char text[MaxT] ;

 for( i = l = 0 ; i < Index ; ++i ){
    if( Text[ i ] & 0xff00 ){
      for( j = i + 1 ; j < Index ; ++j )
	 if( !( Text[ j ] & 0xff00 ) )break ;
      for( k = j-1 ; k >= i ; --k )
	 text[ l++ ] = Text[ k ] & 0x0ff;
      i = j - 1 ;
    }
    else {
      if( FontT[Text[i]][4] ){
	int b,a;
	b = check(i-1)  ;
	a = check(i+1)  ;
	// A  M  F  L
	a = (b<<4)+a ;
	switch(a){
	  case 0x00 :text[ l++ ] = FontT[Text[i]][0] ;break ;
	  case 0x10 :text[ l++ ] = FontT[Text[i]][0] ;break ;
	  case 0x11 :text[ l++ ] = FontT[Text[i]][0] ;break ;
	  case 0x21 :text[ l++ ] = FontT[Text[i]][1] ;break ;
	  case 0x22 :text[ l++ ] = FontT[Text[i]][1] ;break ;
	  case 0x01 :text[ l++ ] = FontT[Text[i]][2] ;break ;
	  case 0x02 :text[ l++ ] = FontT[Text[i]][2] ;break ;
	  case 0x12 :text[ l++ ] = FontT[Text[i]][2] ;break ;
	  case 0x20 :text[ l++ ] = FontT[Text[i]][3] ;break ;
	}
      }
      else text[ l++ ] = FontT[Text[i]][0] ;
    }
 }
 for( i = l ; i < MaxT ; ++i )text[i] = 32 ;

 for( i = 0 ; i < MaxT ; ++ i ){
    if( text[i] != text1[i] ){
      Put(F[1][text[i]],620-16*i,20);
      text1[i] = text[i] ;
    }
 }

}
void main(){
int i ,j,k,l;
unsigned char ch ;
int gdriver = DETECT, gmode ;

Dis p("arabc.fnt","arabe.fnt");

 initgraph(&gdriver, &gmode, "");

 for( ; ; ){
    ch = getch() ;

    if( ch == 27 )break;
    if( ch == 8 ){
      if(--Index <= 0)Index = 0 ;
      Text[Index] = 32 ;
    }
    if( isprint(ch) ){
      if( isdigit(ch) )Text[Index] = 0x0100|ch ;
      else             Text[Index] = Mode  |ch ;
      if(++Index >=MaxT)Index = MaxT - 1 ;
    }
    if( ch == 0 ){
      ch = getch() ;
      if( ch == 59 )Mode ^= 0x0100 ;
    }
    Print.Print();
 }
 closegraph();
}