#include"public.h"
#include"about.h"
/*****************************************
about.c
COPYRIGHT:shishengzhi
DATE:2021/2/26
******************************************/

/******************************************
function name:about_screen
description:绘制关于界面
input:void
return:void
***********************************************/

void about_screen() 
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	puthz(250,0,"关于此系统",16,17,WHITE);
	puthz(0,16,"名称：",16,17,WHITE);
	puthz(0+16*3,16,"公共交通乘客行程系统",16,17,WHITE);
	puthz(0,16*2,"开发者：",16,17,WHITE);
	puthz(0+16*4,16*2,"时圣智",16,17,WHITE);
	puthz(0+16*8,16*2,"高铭君",16,17,WHITE);
	puthz(0, 16*3, "指导教师：",16,17,WHITE);
	puthz(0+16*5, 16*3, "周纯杰",16,17,WHITE);
	puthz(0+16*9, 16*3, "周凯波",16,17,WHITE);
	puthz(0+16*13, 16*3, "彭刚",16,17,WHITE);
	puthz(0+16*16, 16*3, "何顶新",16,17,WHITE);
	puthz(0+16*20, 16*3, "左峥嵘",16,17,WHITE);
	puthz(0+16*24, 16*3, "高常鑫",16,17,WHITE);
	puthz(0+16*28, 16*3, "汪国有",16,17,WHITE);
	puthz(0+16*32, 16*3, "桑农",16,17,WHITE);
	puthz(0+16*35, 16*3, "陈忠",16,17,WHITE);
	puthz(0, 16*4, "编写目的：",16,17,WHITE);
	puthz(0, 16*5, "我国公共交通正在迅速发展，为人们的生活提供了极大的便利，然而在行程管理方面", 16, 17, WHITE);
	puthz(0, 16*6, "还存在一些不足，无法准确地追溯到个人，对于一些特殊情况的处理略显不足。", 16, 17, WHITE);
	puthz(0, 16*8, "不过，在此次疫情中，针对所有用户个人的行程管理在疫情防控以及搜索密切接触者", 16, 17, WHITE);
	puthz(0, 16*9, "方面做出了卓越的贡献，大大推动了疫情防控进程。除此之外，行程管理在一些刑事", 16, 17, WHITE);
	puthz(0, 16*10, "案件的侦破中也能起到及其重要的作用", 16, 17, WHITE);
	puthz(0, 16*12, "基于以上实际，编者希望开发出一款简单的公共交通行程系统，以帮助部门和用户管", 16, 17, WHITE);
	puthz(0, 16*13, "理自己的行程信息，查询乘坐过同车次公共交通工具的其他乘客，以便于对意外情况", 16, 17, WHITE);
	puthz(0, 16*14, "发生后的追溯和紧急处理。", 16, 17, WHITE);
	puthz(0, 16*18, "主要功能：", 16, 17, WHITE);
	puthz(0, 16*19, "用户模式和游客模式", 16, 17, WHITE);
	puthz(0+16*11, 16*19, "游客模式仅供用户查询使用", 16, 17, WHITE);
	puthz(0, 16*20, "用户登录后自行添加乘车记录", 16, 17, WHITE);
	puthz(0, 16*21, "乘车记录可视化显示", 16, 17, WHITE);
	puthz(0, 16*22, "乘车车次关联乘客轨迹图形化显示功能", 16, 17, WHITE);
	puthz(450, 16*26, "二零二一年二月二十六日", 16, 17, WHITE);
	setfillstyle(SOLID_FILL,RED);
	bar(10,410,10+80,410+40);
	puthz(20,420,"返回",32,30,WHITE);
}

/*********************************************
FUNCTION:about_page
DESCRIPTION：关于界面的功能函数
INPUT:void
RETURN:0
***********************************************/

int about_page() 
{
	about_screen();

	while (1) 
	{
		newmouse(&MouseX, &MouseY, &press);
		if(mouse_press(10,410,90,450))
		{
			if(mouse_press(10,410,10+80,410+40)==2) 
			{
				MouseS = 1;
			} 
			else if(mouse_press(10,410,10+80,410+40)==1) 
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 0;
			}
		}
		else 
		{
			MouseS = 0;
		}
	}
}

