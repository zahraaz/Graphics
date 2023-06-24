#include<graphics.h>
#include<math.h>

void simple_circle(int xc,int yc,int R){
int x,y;
y=R;
for(x=0;x<=y;x++){
y=sqrt(R*R-x*x);
putpixel(xc+x,yc+y,BLUE);
putpixel(xc-x,yc+y,BLUE);
putpixel(xc+x,yc-y,BLUE);
putpixel(xc-x,yc-y,BLUE);


putpixel(xc+y,yc+x,BLUE);
putpixel(xc-y,yc+x,BLUE);
putpixel(xc+y,yc-x,BLUE);
putpixel(xc-y,yc-x,BLUE);
}
}
void polar_coordinate(int xc,int yc,int R){
    int x,y,Q;
    float pi=3.14;
    for (Q=0;Q<=45;Q++){
            x=R*cos(Q*pi/180);
            y=R*cos(Q*pi/180);
 putpixel(xc+x,yc+y,YELLOW);
putpixel(xc-x,yc+y,YELLOW);
putpixel(xc+x,yc-y,YELLOW);
putpixel(xc-x,yc-y,YELLOW);


putpixel(xc+y,yc+x,YELLOW);
putpixel(xc-y,yc+x,YELLOW);
putpixel(xc+y,yc-x,YELLOW);
putpixel(xc-y,yc-x,YELLOW);
}
}
void bresenham_circle(int xc,int yc,int r){
    int x,y,p;
    y=r;
    p=3-2*r;
    for (x=0;x<=y;x++){
        putpixel(xc+x,yc+y,100);
putpixel(xc-x,yc+y,100);
putpixel(xc+x,yc-y,100);
putpixel(xc-x,yc-y,100);

putpixel(xc+y,yc+x,100);
putpixel(xc-y,yc+x,100);
putpixel(xc+y,yc-x,100);
putpixel(xc-y,yc-x,100);
if(p>0){
 p=p+4*(x-y)+10;
y--;
}
else
{

    p=p+4*x+6;
}

}
}
int main (){
 initwindow(600,600);

 simple_circle(300,300,150);
 polar_coordinate(300,300,100);
 bresenham_circle(300,300,50);
 getch();
}

