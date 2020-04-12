#include<stdio.h>

#include<conio.h>

#include<graphics.h>

#include<dos.h>

 

void main()

{

  int gd=DETECT,gm,x1,y1,x2,y2,x3,y3;

  double sx,sy,x11,x22,x33,y11,y22,y33;

  clrscr();

   printf("enter the co-ordinates of point A of triangle");

  scanf("%d  %d",&x1,&y1);

  printf("enter the co-ordinates of point B of triangle");

  scanf("%d  %d",&x2,&y2);

  printf("enter the co-ordinates of point C of triangle");

  scanf("%d  %d",&x3,&y3);

 

 

  initgraph(&gd,&gm," ");

  line(getmaxx()/2,0,getmaxx()/2,getmaxy());

  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 

  x11=x1+(getmaxx()/2);

  y11=(getmaxy()/2)-y1;

  x22=x2+(getmaxx()/2);

  y22=(getmaxy()/2)-y2;

  x33=x3+(getmaxx()/2);

  y33=(getmaxy()/2)-y3;

  line(x11,y11,x22,y22);

  line(x22,y22,x33,y33);

  line(x33,y33,x11,y11);

 

  printf("enter the value of sx");

  scanf("%lf",&sx);

  printf("enter the value of sy");

  scanf("%lf",&sy);

 

  x1=(x1*sx);

  x2=(x2*sx);

  x3=(x3*sx);

  y1=(y1*sy);

  y2=(y2*sy);

  y3=(y3*sy);

  setcolor(RED);

  x1=x1+(getmaxx()/2);

  y1=(getmaxy()/2)-y1;

  x2=x2+(getmaxx()/2);

  y2=(getmaxy()/2)-y2;

  x3=x3+(getmaxx()/2);

  y3=(getmaxy()/2)-y3;

   line(x1,y1,x2,y2);

  line(x2,y2,x3,y3);

  line(x3,y3,x1,y1);

 

  getch();

  closegraph();

  }