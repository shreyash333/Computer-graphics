#include<stdio.h>
#include<graphics.h>

void main()
{
	int l,s;
	printf("\nEnter longest axis value \n");
	scanf("%d",&l);
	printf("\nEnter shortest axis value \n");
	scanf("%d",&s);
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setbkcolor(BLACK);
	int a=l,b=s;
	int x=0,y=b;
	
	// Rgion 1
	
	int p=(b*b)-(a*a*b)+((1/4)*a*a);
	int dx=2*b*b*x,dy=2*a*a*y;

	while(dx<dy)
	{
		
	  putpixel(250+x,250+y,5);
        putpixel(250-x,250+y,3);
        putpixel(250-x,250-y,3);
        putpixel(250+x,250-y,7);
		if(p<0)
		{
			x=x+1;
			dx=dx+2*b*b;
			p=p+dx+b*b;
		}
		else
		{
			x=x+1;
			y=y-1;
			dx=dx+2*b*b;
			dy=dy-2*a*a;
			p=p+dx-dy+b*b;
		}

		}
		printf("region 1 x and y = %d and %d ",x,y);
	// Region 2
	
	int q=((x+(1/2))*(x+(1/2))*b*b)+((y-1)*(y-1)*a*a)-(a*a*b*b);
		
	while(y>=0)
	{
		putpixel(x,y,0);
		if(q>0)
		{
			x=x;
			y=y-1;
			dy=dy-2*a*a;
			q=q-dy+a*a;
		}
		else
		{
			x=x+1;
			y=y-1;
			dy=dy-2*a*a;
			q=q+dx-dy+a*a;
		}
	}
	printf("region 1 x and y = %d and %d ",x,y);		
	delay(10000);
	
}			 


