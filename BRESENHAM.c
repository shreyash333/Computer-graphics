//Bresenham line plotting algorithm 

#include<stdio.h>
#include<graphics.h>

int main()
{
	int x1,y1,x2,y2,l,i;
	float dx,dy,tdy,dxy,p;
	printf("\nEnter Starting Co-ordinates: \n");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter Final Co-ordinates: \n");
	scanf("%d%d",&x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	tdy=2*dy;
	dxy=tdy-2*dx;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	if(dx>dy)
	{
		l=dx;
	}
	else
	{
		l=dy;
	}
	p=tdy-dx;
	for(i=0;i<100;i++)
	{
		putpixel(i+200,200,2);
		putpixel(200-i,200,2);
		putpixel(200,-i+200,4);
		putpixel(200,i+200,4);	
	}
	putpixel(200+x1,200-y1,3);
	for(i=0;i<l;i++)
	{
		if(p<0)
		{
			x1++;
			putpixel(200+x1,200-y1,3);
			p=p+tdy;
		}
		else
		{
			x1++;
			y1++;
			putpixel(200+x1,200-y1,3);
			p+=dxy;
		}
	}
	delay(15000);
	closegraph();
}
