#include"public.h"
#include"adminfun.h"
/*******************************
admin_function.c
copyright:shishengzhi
date:2021/3/2 
*******************************/
/***************************
function name: admin_screen
description:���ƹ���Ա����
input�� void
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
	puthz(200,230,"��ѯ�˳��켣",32,40,WHITE); 
	puthz(220,50,"����Ա����",32,40,WHITE);
	puthz(200,160,"��ѯ������Ϣ",32,40,WHITE);
	puthz(200,300,"����״�����",32,40,WHITE);
	puthz(200,370,"����״��ͳ��",32,40,WHITE); 
	puthz(0,5,"ע��",16,20,WHITE);
} 
/*************************************************************************************
function name:admin_page
description:����Ա���漰����ع���
input�� void
return�� 0����½���棩 or 9����ѯ��Ӧ��Ϣ���棩 or 10����ѯ�˳��켣���棩 or 16(�����쳣�Ǽ�)
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
