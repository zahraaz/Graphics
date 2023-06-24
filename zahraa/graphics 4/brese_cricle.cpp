#include <graphics.h>
void brese(int xc, int yc, int r){
int x=0;
int y;
int p=1-r;
y=r;
putpixel(xc+x,yc+y,15);
for(;x<=y;x++){
if(p>=0){
y--;
p=p+2*(x+1)+1-(2*y);}
else{
p=p+2*(x+1)+1;
}
putpixel(xc+x, yc+y, WHITE);
putpixel(xc+x, yc-y, WHITE);
putpixel(xc-x, yc+y, WHITE);
putpixel(xc-x, yc-y, WHITE);
putpixel(yc+y, xc+x, WHITE);
putpixel(yc+y, xc-x, WHITE);
putpixel(yc-y, xc+x, WHITE);
putpixel(yc-y, xc-x, WHITE);
}
}

int main(){
int gm =DETECT, gd;
initgraph(&gm,&gd,"");
brese(375,375,350);
getch();
return 0;
}
