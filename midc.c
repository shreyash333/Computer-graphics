#include<stdio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int r=170,x=0,y=r;
    int m=(5/4)-r;
    while(x<=y)
	{
		putpixel(200+x,200+y,5);
		putpixel(200+y,200+x,3);
		putpixel(200+y,200-x,7);
		putpixel(200-x,200+y,5);
		putpixel(200-x,200-y,3);
		putpixel(200-y,200-x,6);
		putpixel(200-y,200+x,3);
		putpixel(200+x,200-y,8);
		if(m<0)
	{
		m=m+(2*x)+3;
	}
	else
	{
		m=m+(2*(x-y))+5;
		y=y-1;
	}
	x=x+1;
}
	delay(60000);
}




