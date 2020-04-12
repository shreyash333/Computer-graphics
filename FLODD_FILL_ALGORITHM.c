#include<stdio.h>
//#include<dos.h>
#include<graphics.h>

void Floodfill(int x, int y, int old_col, int new_col)
{
	if(getpixel(x,y) == old_col )
	{
		putpixel(x,y,new_col);
		Floodfill(x+1,y,old_col,new_col);
		Floodfill(x,y+1,old_col,new_col);
		Floodfill(x-1,y,old_col,new_col);
		Floodfill(x,y-1,old_col,new_col);
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
	Floodfill(250+x,250+y,0,15);
	delay(10000);
	closegraph();
}






