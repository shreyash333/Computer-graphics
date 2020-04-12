#include<stdio.h>

#include<conio.h>

#include<graphics.h>

#include<dos.h>

 

void main()

{

  int gd=DETECT,gm,x1,y1,tx,ty,x2,y2,x3,y3;

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

 

  x1=x1+(getmaxx()/2);

  y1=(getmaxy()/2)-y1;

  x2=x2+(getmaxx()/2);

  y2=(getmaxy()/2)-y2;

  x3=x3+(getmaxx()/2);

  y3=(getmaxy()/2)-y3;

  line(x1,y1,x2,y2);

  line(x2,y2,x3,y3);

  line(x3,y3,x1,y1);

 

  printf("enter the value of tx");

  scanf("%d",&tx);

  printf("enter the value of ty");

  scanf("%d",&ty);

 

  x1=x1+tx;

  x2=x2+tx;

  x3=x3+tx;

  y1=y1-ty;

  y2=y2-ty;

  y3=y3-ty;

  setcolor(RED);

   line(x1,y1,x2,y2);

  line(x2,y2,x3,y3);

  line(x3,y3,x1,y1);

 

  getch();

  closegraph();

  }

	

