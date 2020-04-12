#include<stdio.h>

#include<conio.h>

#include<graphics.h>

#include<dos.h>

#include<math.h>

void main()

{

  int gd=DETECT,gm;

  double x1,y1,xr,yr,r,x2,y2,x3,y3;

  clrscr();

   printf("enter the co-ordinates of point A of triangle");

  scanf("%lf  %lf",&x1,&y1);

  printf("enter the co-ordinates of point B of triangle");

  scanf("%lf  %lf",&x2,&y2);

  printf("enter the co-ordinates of point C of triangle");

  scanf("%lf  %lf",&x3,&y3);

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

 

  printf("enter the co-ordinate of pivot point");

  scanf("%lf %lf",&xr,&yr);

  printf("enter the degreeof rotation");

  scanf("%lf",&r);

  xr=xr+(getmaxx()/2);

  yr=(getmaxy()/2)-yr;

  x1=(x1*cos(r))-(y1*sin(r))+(xr*(1-cos(r)))+(yr*sin(r));

  y1=(x1*sin(r))+(y1*cos(r))+(yr*(1-cos(r)))-(xr*sin(r));

  x2=(x2*cos(r))-(y2*sin(r))+(xr*(1-cos(r)))+(yr*sin(r));

  y2=(x2*sin(r))+(y2*cos(r))+(yr*(1-cos(r)))-(xr*sin(r));

  x3=(x3*cos(r))-(y3*sin(r))+(xr*(1-cos(r)))+(yr*sin(r));

  y1=(x3*sin(r))+(y3*cos(r))+(yr*(1-cos(r)))-(xr*sin(r));

  setcolor(RED);

   line(x1,y1,x2,y2);

  line(x2,y2,x3,y3);

  line(x3,y3,x1,y1);

  getch();

 closegraph();

}