#include"public.h"
#include"forget.h" 
/********************
copyright:shishengzhi
date:2021/2/6 
*********************/

/*****************************
function name: forget_screen
description: 绘制忘记密码界面
input： void
return：void 
******************************/ 
void forget_screen()//绘制忘记密码界面 
{ 
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	puthz(100,110,"身份证号",16,17,WHITE);
	puthz(120,190,"新密码",16,17,WHITE);
	puthz(100,270,"重复密码",16,17,WHITE);
	puthz(120,350,"验证码",16,17,WHITE);
	puthz(120,40,"您正在修改密码",32,55,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(190,100,450,150);
	bar(190,180,450,230);
	bar(190,260,450,310);
	bar(190,340,450,390);
	setfillstyle(SOLID_FILL,RED);
	bar(10,410,10+80,410+40);
	puthz(20,420,"返回",32,30,WHITE);
	bar(540,410,540+80,410+40);
	puthz(550,420,"确认",32,30,WHITE);
}

/**********************************
functio name : forget_page
description:忘记密码界面及相关功能 
input: void
return: 0(登录界面)
**********************************/ 
int forget_page()
{
	int i;
	int n;
	char idnum[21];
	char new_pass[20];
	char temp[20];//存放重复输入的密码 
	char phonenum[12]; 
	char pin[7];//存放用户输入的密码 
	char path[30]="C:\\mine\\info\\"; 
	char name[15];
	char temp3[]=".txt";
	user temp1;
	admin temp2;
	FILE* fp=NULL;

	forget_screen();
	memset(idnum,'\0',sizeof(idnum));
	memset(phonenum,'\0',sizeof(phonenum));
	memset(new_pass,'\0',sizeof(new_pass));
	memset(temp,'\0',sizeof(temp));
	memset(pin,'\0',sizeof(pin));
	memset(name,'\0',sizeof(name));
	clrmous(MouseX,MouseY);

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(10,410,10+80,410+40))
		{
			if(mouse_press(10,410,10+80,410+40) == 2)
			{
				MouseS = 1;//手势
			}
			else if(mouse_press(10,410,10+80,410+40) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(500);
				closegraph();
				return 0;
			}
		}
		else if(mouse_press(190,100,450,150))
		{
			if(mouse_press(190,100,450,150) == 2)
			{
				MouseS = 2;//光标
			}
			else if(mouse_press(190,100,450,150) == 1)
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,100,450,150);
				input_num(idnum,sizeof(idnum),195,105);
			}
		}
		else if(mouse_press(190,180,450,230)) //鼠标位于新密码一栏
		{
			if(mouse_press(190,180,450,230) == 2)//未单击
			{
				MouseS = 2;//鼠标形态：光标
			}
			else if(mouse_press(190,180,450,230) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,180,450,230);
				input_password(new_pass,sizeof(new_pass),195,185);
				if(judge_password(new_pass)==0)
				{
					puthz(190,160,"密码不得小于六位",16,17,RED);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(190,160,350,180); 
					continue;
				} 
			}
		}
		else if(mouse_press(190,260,450,310)) //鼠标位于重复密码一栏
		{
			if(mouse_press(190,260,450,310) == 2)//未单击
			{
				MouseS = 2;//鼠标形态：光标
			}
			else if(mouse_press(190,260,450,310) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,260,450,310);
				input_password(temp,sizeof(temp),195,265);
			}
		}
		else if(mouse_press(190,340,450,390)) //鼠标位于验证码一栏
		{
			if(mouse_press(190,340,450,390) == 2)//未单击
			{
				MouseS = 2;//鼠标形态：光标
			}
			else if(mouse_press(190,340,450,390) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,340,450,390);
				input_num(pin,sizeof(pin),195,345);
			}
		}
		else if(mouse_press(540,410,540+80,410+40))//鼠标位于确定
		{
			if(mouse_press(540,410,540+80,410+40) == 2)
			{
				MouseS = 1;//手势
			}
			else if(mouse_press(540,410,540+80,410+40) == 1)
			{
				i = judge_id(idnum);
				if(i==-1)
				{
					puthz(190,160,"身份证号位数有误",16,17,WHITE);
					clrmous(MouseX, MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(190,160,350,180); 
					continue;
				}
				else
				{
					switch(forget_judge(idnum, pin))
					{
						case 1:
							for(n=0;n<8;n++)
							{
								name[n]=idnum[n+10];
							}
							strcat(name,temp3);
							strcat(path,name);
							if((fp=fopen(path,"rt+"))!=NULL)
							{
								fscanf(fp,"%s %s %s",temp1.idnum,temp1.password,temp1.phonenum);
								strcpy(temp1.password,new_pass);
								WritetoUser(temp1);
								puthz(190,160,"修改成功",16,17,WHITE);
								clrmous(MouseX,MouseY);
								delay(1500);
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(190,160,350,180);
								break;	
							}
							else
							{
								puthz(190,160,"操作文件时发生错误",16,17,RED);
								delay(2000);
								clrmous(MouseX,MouseY);
								closegraph();
								exit(1); 
							}
						case 0:
							puthz(190,160,"此账号未注册",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(190,160,350,180);
							break;
						case -1:
							puthz(190,160,"验证码错误",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(190,160,350,180);
							break;
					}
				}
			}
		}
	}
}
