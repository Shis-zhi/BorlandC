#include"public.h" 
#include"login.h"

/************************************
login.c
copyright:shishengzhi
date: 2021/2/2 
************************************/ 

/******************************************
function name:login_screen
description: 绘制登录界面
input：void
return: void 
******************************************/
void login_screen(void)
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY);
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE); 
	puthz(60,170,"身份证号",16,17,WHITE);
	puthz(100,270,"密码",16,17,WHITE);
	puthz(60,40,"公共交通乘客行程系统",32,55,WHITE);
	bar(150,150,150+250,200);
	bar(150,250,150+250,300);
	setfillstyle(SOLID_FILL,RED);
	bar(440,160,440+110,160+40);
	bar(440,260,440+110,260+40);
	bar(120,350,120+80,350+30);
	bar(350,350,350+80,350+30);
	bar(550,0,550+50,0+30); 
	bar(0,0,0+50,0+30); 
	puthz(450+20,260,"注册",32,30,BLUE);
	puthz(450+20,160,"登录",32,30,BLUE); 
	puthz(130,360,"忘记密码",16,17,WHITE);
	puthz(360,360,"游客模式",16,17,WHITE);
	puthz(560,5,"关于",16,17,WHITE); 
    puthz(10,5,"退出",16,17,WHITE);
}

/******************************************************************************************* 
function name:login_page 
description: 登录界面及相关功能
input：void
return：1(普通用户界面) or 2(管理员界面) or 3(注册) or 4(忘记密码) or 5(游客模式) or 6(关于) 

********************************************************************************************/
int login_page()
{
	int i;
	char idnum[19];
	char password[10];
	int temp;
	FILE* fp=NULL; 

	login_screen();
	
	memset(idnum, '\0',sizeof(idnum));
	memset(password, '\0',sizeof(password));
	clrmous(MouseX,MouseY);
	
	while(1)//循环监测屏幕状态 
	{ 
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(150,150,150+250,200))//鼠标位于身份证号一栏
		{
			if(mouse_press(150,150,150+250,200) == 2)//未单击 
			{
				MouseS = 2;//鼠标形态：光标 
			} 
			else if(mouse_press(150,150,150+250,200) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(150,150,150+250,200);
				input_num(idnum,sizeof(idnum),150,155);
			}
		}
		else if(mouse_press(150,250,150+250,300)) //鼠标位于密码一栏
		{
			if(mouse_press(150,250,150+250,300) == 2)//未单击 
			{
				MouseS = 2;//鼠标形态：光标 
			} 
			else if(mouse_press(150,250,150+250,300) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(150,250,150+250,300);
				input_password(password,sizeof(password),150,250);
			}
		}
		else if(mouse_press(440,160,440+110,160+40))//鼠标位于登录 
		{
			if(mouse_press(440,160,440+110,160+40) == 2)//未单击 
			{
				MouseS = 1; 
			} 
			else if(mouse_press(440,160,440+110,160+40) == 1)//左键单击登录选项 
			{
				i = judge_id(idnum); 
				if (i==-1)
				{
					puthz(450,210,"账号位数错误",16,17,RED);
					clrmous(MouseX, MouseY);
					delay(2000);
					setfillstyle(1,LIGHTGRAY);
					bar(440,200,440+110,200+50);//用背景色覆盖显示消息的区域  
					continue;
				}
				else if(i==0)
				{
					temp=user_login(idnum,password);
					switch(temp)
					{
						case 1:
							if((fp=fopen("c:\\mine\\info\\temp.txt","wt+"))!=NULL)
							{
								fprintf(fp,"%s",idnum);
								fclose(fp);
							}
							clrmous(MouseX, MouseY);
							delay(500); 
							closegraph();
							return 1;//成功登录，进入用户界面
						case 0:
							puthz(450,210,"未注册",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000); 
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break;
						case -1:
							puthz(450,210,"密码错误",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break; 
					}
				}
				else if(i==1)
				{
					temp=admin_login(idnum,password);
					switch(temp)
					{
						case 2:
							clrmous(MouseX, MouseY);
							delay(500); 
							closegraph();
							return 2;//成功登录，进入管理员界面
						case 0:
							puthz(450,210,"未注册",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000); 
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break;
						case -1:
							puthz(450,210,"密码错误",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break; 
					}
				} 
			}
		}
		else if(mouse_press(440,260,440+110,260+40))//鼠标位于注册 
		{
			if(mouse_press(440,260,440+110,260+40) == 2)//未单击 
			{
				MouseS=1;
			} 
			else if(mouse_press(440,260,440+110,260+40) == 1)//左键单击注册选项
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 3;//进入注册界面
			}
		}
		else if(mouse_press(120,350,120+80,350+30))//鼠标位于忘记密码 
		{
			if(mouse_press(120,350,120+80,350+30) == 2)//未单击 
			{
				MouseS=1;
			} 
			else if(mouse_press(120,350,120+80,350+30) == 1)//左键单击忘记密码选项
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 4;//进入忘记密码界面
			}
		}
		else if(mouse_press(350,350,350+80,350+30))//鼠标位于游客模式 
		{
			if(mouse_press(350,350,350+80,350+30) == 2)//未单击 
			{
				MouseS=1;
			} 
			else if(mouse_press(350,350,350+80,350+30) == 1)//左键单击游客模式选项 
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 5;//进入游客模式 
			}
		}
		else if(mouse_press(550,0,550+50,0+30))//鼠标位于关于 
		{
			if(mouse_press(550,0,550+50,0+30) == 2)//未单击  
			{
				MouseS=1;
			}	 
			else if(mouse_press(550,0,550+50,0+30) == 1)//左键单击关于
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 6;//进入关于界面
			}
		} 
		else if(mouse_press(0,0,50,30))
		{
			if(mouse_press(0,0,50,30)==2)
			{
				MouseS = 1;
			}
			else if(mouse_press(0,0,50,30)==1)
			{
				clrmous(MouseX,MouseY);
				closegraph();
				exit(0);
			}
		}
		else
		{
			MouseS=0;//鼠标形态：箭头 
		} 
	}
}
