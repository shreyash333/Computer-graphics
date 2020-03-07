// read comments before printing this experiment

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#define Round(x) ((int)(x+0.5))

void main()
{
    int i;
    float  x1 =100,x2=200,y1=20,y2=170,l,dx,dy,x,y;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode," ");
    dx=x2-x1;
    dy=y2-y1;
    if(dx>dy)
    {
        l=dx;
    }
    else
    {
        l=dy;
    }
    dx=(float)(dx)/l;
    dy=(float)(dy)/l;
    x=x1;
    y=y1;
    // this for loop creates co ordinate axis this is for your understanding
    for(i=0;i<100;i++)
    {
        putpixel(i+200,200,1);
        putpixel(-i+200,200,2);
        putpixel(200,i+200,3);
        putpixel(200,-i+200,4);
    }
    // 200 ,200 is the center for your understanding 
    for(i=0;i<l;i++)
    {
        putpixel(Round(x)+200,-Round(y)+200,3);
        x=x+dx;
        y=y+dy;
    }
    delay(15000);

    closegraph();
}

