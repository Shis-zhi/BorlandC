#include"public.h" 
#include"visitor.h"
/************************
visitor.c
copyright:gaomingjun
date:2021/4/13
*************************/
/************************
function name:newtrack_screen
description:绘制游客界面
input: void
return: void
*************************/
void  visitor_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY);
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,GREEN);
	bar(160,160,480,240);
	bar(160,320,480,400);
	bar(0,0,40,30);
	puthz(200,180,"显示所有路线",32,40,WHITE);
	puthz(200,340,"显示站间路线",32,40,WHITE);
	puthz(0,5,"登录",16,20,WHITE);
	puthz(200,50,"游客界面",32,40,WHITE);
} 
/**********************************
function name:  user_page
description：游客界面及其相关功能 
input: void 
return: 14(显示各车路线) or 15(显示站间路线) or 0(登陆界面) 
***********************************/
int visitor_page()
{
	visitor_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,40,30))
		{
			if(mouse_press(0,0,40,30)==2)
				MouseS=1;
			else if(mouse_press(0,0,40,30)==1)
			{
				clrmous(MouseX,MouseY);
				delay(1500);
				closegraph();
				return 0;
			}
		}
		else if(mouse_press(160,160,480,240))
		{
			if(mouse_press(160,160,480,240)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(160,160,480,240)==1)
			{
				clrmous(MouseX,MouseY);
				delay(1500);
				closegraph();
				return 14;
			}
		}
		else if(mouse_press(160,320,480,400)) 
		{
			if(mouse_press(160,320,480,400)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(160,320,480,400)==1)
			{
				clrmous(MouseX,MouseY);
				delay(1500);
				closegraph();
				return 15;
			} 
		}
		else
		{
			MouseS=0;
		}	
	}
}  


