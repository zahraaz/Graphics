#include<graphics.h>
#include <math.h>
 int CENTER_X=300;
 int CENTER_Y=300;
 int R=200;
void drawLineClockWise(double angle,int length){
int endX=CENTER_X+R*cos(angle);
int endY=CENTER_Y+R*sin(angle);
setcolor(YELLOW);
line (CENTER_X,CENTER_Y,endX,endY);

}
int main (){
int gd = DETECT ,gm ;
initgraph(&gd, &gm, "");
circle(CENTER_X,CENTER_Y,R);
for(int i =0; i<12;i++){
    double angle= i *30 *M_PI/180;

    drawLineClockWise(angle,R);

}
getch();
closegraph();
return 0;}
