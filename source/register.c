#include"public.h"
#include"register.h"
/***********************
register.h
copyright: shishengzhi
date:2021/2/15
***********************/

/*****************************
function name:register_screen
description: 绘制注册界面
input： void
output： void
******************************/
void register_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	puthz(100,110,"身份证号",16,17,WHITE);
	puthz(100,190,"设置密码",16,17,WHITE);
	puthz(100,270,"重复密码",16,17,WHITE);
	puthz(120,40,"您正在注册账号",32,55,WHITE);
	bar(190,100,450,150);
	bar(190,180,450,230);
	bar(190,260,450,310);
	setfillstyle(SOLID_FILL,RED);
	bar(10,410,10+80,410+40);
	puthz(20,420,"返回",32,30,WHITE);
	bar(540,410,540+80,410+40);
	puthz(550,420,"确认",32,30,WHITE);
}

/*****************************
function name:inf_screen
description: 绘制信息完善界面
input: void
return :void
*****************************/
void inf_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	puthz(120,40,"请完善您的信息",16,17,WHITE);
	puthz(120,160,"手机号",16,17,WHITE);
	puthz(120,240,"验证码",16,17,WHITE);
	bar(190,150,450,200);
	bar(190,230,450,280);
	setfillstyle(SOLID_FILL,RED);
	bar(10,410,10+80,410+40);
	puthz(20,420,"确认",16,17,WHITE);
}
/****************************************
function name: inf_page
description：信息完善界面及相关功能
input：void
return: 1(普通用户界面） or 2(管理员界面)
****************************************/
int inf_page()
{
	char pin[7];//存放用户输入的验证码
	char right[] = "111111";
	char idnum[19];
	char password[20];
	char phonenum[12];
	char name[15];
	int temp;
	user temp1;
	FILE* fp=NULL;

	memset(idnum,'\0',19);
	memset(password,'\0',20);
	memset(phonenum,'\0',12);
	memset(pin,'\0',7);
	memset(temp1.idnum,'\0',sizeof(temp1.idnum));
	memset(temp1.password,'\0',sizeof(temp1.password));
	memset(temp1.phonenum,'\0',sizeof(temp1.phonenum));
	clrmous(MouseX,MouseY);

	inf_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		setfillstyle(1,LIGHTGRAY);
		bar(190,300,450,350);//用背景色覆盖文字显示区域
		if(mouse_press(190,150,450,200))
		{
			if(mouse_press(190,150,450,200) == 2)
			{
				MouseS = 2;
			}
			else if(mouse_press(190,150,450,200) == 1)
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(1,WHITE);
				bar(190,150,450,200);
				input_num(phonenum,sizeof(phonenum),195,155);
			}
		}
		else if(mouse_press(190,230,450,280))
		{
			if(mouse_press(190,230,450,280) == 2)
			{
				MouseS = 2;
			}
			else if(mouse_press(190,230,450,280) == 1)
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(1,WHITE);
				bar(190,230,450,280);
				input_num(pin,sizeof(pin),195,235);
			}
		}
		else if(mouse_press(10,410,10+80,410+40))
		{
			if(mouse_press(10,410,10+80,410+40) == 2)
			{
				MouseS = 1;
			}
			if(mouse_press(10,410,10+80,410+40) == 1)
			{
				if(strcmp(pin,right) == 0)
				{
					if((fp=fopen("C:\\mine\\info\\temp.txt","rt"))!=NULL)
					{
						fscanf(fp,"%s %s ",idnum,password);
						fclose(fp);
						temp=judge_id(idnum);
						if(temp!=0)
						{
							puthz(190,300,"身份证位数有误",16,17,RED);
							settextstyle(1,0,1);
							outtextxy(190,500,idnum);
							delay(1500);
							continue;
						}
						else if(temp==0)
						{
							strcpy(temp1.idnum,idnum);
							strcpy(temp1.password,password);
							strcpy(temp1.phonenum,phonenum);
							WritetoUser(temp1);
						}
						clrmous(MouseX,MouseY);
						closegraph();
						return 1;
					}
				}
				else
				{
					delay(500);
					puthz(190,300,"验证码错误",16,17,WHITE);
					delay(2000);
					continue;
				}
			}
		}
		else
		{
			MouseS=0;
		} 
	}
}
/***************************************
function name: register_page
description: 注册界面及相关功能
input： void
return: 0(登录界面) or  12(信息完善界面）
***************************************/

int register_page()
{
	int i;
	int temp3; 
	char idnum[21];
	char new_pass[10];
	char temp[10];//存放重复输入的密码
	char phonenum[12];
	char name[15];
	char right[]="123456";
	FILE* fp=NULL;
	user temp1; 

	register_screen();
	memset(idnum, '\0',sizeof(idnum));
	memset(new_pass, '\0',sizeof(new_pass));
	memset(temp, '\0',sizeof(temp));
	memset(phonenum, '\0',sizeof(phonenum));
	memset(name,'\0',sizeof(name));
	clrmous(MouseX,MouseY);

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseS!=0)
		{
			MouseS=0;
		}
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(190,155,450,190);
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
		else if(mouse_press(190,260,450,310)) //鼠标位于重复密码一栏
		{
			if(mouse_press(190,260,450,310) == 2)//未单击
			{
				MouseS = 1;//鼠标形态：光标
			}
			else if(mouse_press(190,260,450,310) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,260,450,310);
				input_password(temp,sizeof(temp),195,265);
			}
		}
		else if(mouse_press(190,180,450,230)) //鼠标位于设置密码一栏
		{
			if(mouse_press(190,180,450,230) == 2)//未单击
			{
				MouseS = 1;//鼠标形态：光标
			}
			else if(mouse_press(190,180,450,230) == 1)//左键单击
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,180,450,230);
				input_password(new_pass,sizeof(new_pass),195,185);
				if(judge_password(new_pass)!=1)
				{
					puthz(190,160,"密码长度不应小于六位",16,17,RED);
					clrmous(MouseX,MouseY);
					delay(2000);
					continue;
				}
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
					continue;
				}
				else
				{
					temp3=register_judge(idnum);
					if(temp3==1)
					{
						if((fp=fopen("C:\\mine\\info\\temp.txt","wt+"))!=NULL)
						{
							fprintf(fp,"%s %s ",idnum,new_pass);
						}
						else
						{
							puthz(190,160,"打开文件时出错",16,17,RED);
							delay(2000);
							closegraph();
							exit(1);
						}
						fclose(fp);
						clrmous(MouseX, MouseY);
						delay(500);
						closegraph();
						return 12;
					}
					else
					{
						puthz(190,160,"此账号已注册",16,17,WHITE);
						delay(2000);
						continue;
					}
				}		
			}
		}
	}
}

