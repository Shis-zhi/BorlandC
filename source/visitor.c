#include"public.h" 
#include"visitor.h"
/************************
visitor.c
copyright:gaomingjun
date:2021/4/13
*************************/
/************************
function name:newtrack_screen
description:�����οͽ���
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
	puthz(200,180,"��ʾ����·��",32,40,WHITE);
	puthz(200,340,"��ʾվ��·��",32,40,WHITE);
	puthz(0,5,"��¼",16,20,WHITE);
	puthz(200,50,"�οͽ���",32,40,WHITE);
} 
/**********************************
function name:  user_page
description���οͽ��漰����ع��� 
input: void 
return: 14(��ʾ����·��) or 15(��ʾվ��·��) or 0(��½����) 
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


