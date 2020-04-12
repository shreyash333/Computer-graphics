#include<stdio.h>
//#include<dos.h>
#include<graphics.h>

void boundaryfill(int x, int y, int f_col, int b_col)
{
	if(getpixel(x,y) != b_col && getpixel(x,y) != f_col)
	{
		putpixel(x,y,f_col);
		boundaryfill(x+1,y,f_col,b_col);
		boundaryfill(x,y+1,f_col,b_col);
		boundaryfill(x-1,y,f_col,b_col);
		boundaryfill(x,y-1,f_col,b_col);
	}
}

void main()
{
	int gm, gd=DETECT, radius;
	int x,y;
	printf("Enter x and y center of circle ");
	scanf("%d%d",&x,&y);
	printf("Enter the radius ");
	scanf("%d",&radius);
	
	initgraph(&gd,&gm,NULL);
	circle(250+x,250+y,radius);
	boundaryfill(250+x,250+y,4,15);
	delay(10000);
	closegraph();
}

	

