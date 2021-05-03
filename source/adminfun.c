#include"public.h"
#include"adminfun.h"
/*******************************
admin_function.c
copyright:shishengzhi
date:2021/3/2 
*******************************/
/***************************
function name: admin_screen
description:绘制管理员界面
input： void
return: void
***************************/
void admin_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,BLUE);
	bar(160,150,480,210);
	bar(160,290,480,350);
	bar(0,0,40,30);
	bar(160,220,480,280);
	bar(160,360,480,420);
	puthz(200,230,"查询乘车轨迹",32,40,WHITE); 
	puthz(220,50,"管理员界面",32,40,WHITE);
	puthz(200,160,"查询车次信息",32,40,WHITE);
	puthz(200,300,"健康状况变更",32,40,WHITE);
	puthz(200,370,"健康状况统计",32,40,WHITE); 
	puthz(0,5,"注销",16,20,WHITE);
} 
/*************************************************************************************
function name:admin_page
description:管理员界面及其相关功能
input： void
return： 0（登陆界面） or 9（查询对应信息界面） or 10（查询乘车轨迹界面） or 16(健康异常登记)
**************************************************************************************/
int admin_page()
{
	admin_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,40,30))
		{
			if(mouse_press(0,0,40,30)==2)
			{
				MouseS = 1;
			}
			else if(mouse_press(0,0,40,30)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph(); 
				return 0;
			}
		}
		else if(mouse_press(160,150,480,210))
		{
			if(mouse_press(160,150,480,210)==2)
			{
				MouseS = 1;
			}
			else if(mouse_press(160,150,480,210)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 9;
			}	  	
		}
		else if(mouse_press(160,290,480,350))
		{
			if(mouse_press(160,290,480,350)==2)
			{
				MouseS = 1;
			}
			else if(mouse_press(160,290,480,350)==1)
			{
				clrmous(MouseX,MouseY);
	 			delay(500);
	 			closegraph();
	 			return 16;
			}	  	
		}
			else if(mouse_press(160,220,480,280))
		{
			if(mouse_press(160,220,480,280)==2)
			{
				MouseS = 1;
			}
				else if(mouse_press(160,220,480,280)==1)
			{
				clrmous(MouseX,MouseY);
	 			delay(500);
	 			closegraph();
	 			return 10;
			}	  	
		}
			else if(mouse_press(160,360,480,420))
		{
			if(mouse_press(160,360,480,420)==2)
			{
				MouseS = 1;
			}
				else if(mouse_press(160,360,480,420)==1)
			{
				clrmous(MouseX,MouseY);
	 			delay(500);
	 			closegraph();
	 			return 18;
			}	  	
		}
		else 
		{
			MouseS=0;
		}
	}
} 
