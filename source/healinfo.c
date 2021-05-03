#include"public.h"
#include"healinfo.h"
/*****************************
healinfo.c
copyright:shishengzhi
date:2021/4/30
*****************************/ 
/************************************
function name:healinfo_screen
description:绘制健康信息查询界面
input：int* choice
return: void 
************************************/
void healinfo_screen(int* choice)
{
	int gd=VGA;
	int gm=VGAHI;
	int i;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY);
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,40,30);
	bar(300,400,340,430);
	puthz(305,405,"返回",16,17,DARKGRAY); 
	puthz(5,5,"注销",16,20,DARKGRAY);
	puthz(200,10,"健康信息查询",32,35,WHITE);
	for(i=0;96+i*26<360;i++)
	{
		bar(10,96+i*26,630,120+i*26);
		//line(600,96+i*26,630,120+i*26);
	}
	bar(400,400,460,430); 
	puthz(20,60,"身份证号",16,20,DARKGRAY);
	if(*choice==0)
	{
		puthz(350,60,"健康状态",16,20,DARKGRAY); 
	}
	puthz(405,405,"下一页",16,20,DARKGRAY);
	if(*choice==0)
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(500,10,580,30);
		setfillstyle(SOLID_FILL,WHITE);
		bar(500,35,580,55);
		bar(500,60,580,80);
	}
	else if(*choice==1)
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(500,35,580,55);
		setfillstyle(SOLID_FILL,WHITE);
		bar(500,10,580,30);
		bar(500,60,580,80);
	}
	else if(*choice==2)
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(500,60,580,80);
		setfillstyle(SOLID_FILL,WHITE);
		bar(500,10,580,30);
		bar(500,35,580,55);
	}
	puthz(500,10,"全部",16,20,RED);
	puthz(500,35,"确诊",16,20,RED);
	puthz(500,60,"风险",16,20,RED);
}
/*****************************
function name:healinfo_page
description:上述界面的功能函数
input:int* choice,int* page
return:int 
******************************/
int healinfo_page(int* choice,int* page)
{
	FILE* fp=NULL;
	int i,j;
	int m,n;
	int page_max;
	char info[11][20];
	char num[4];
	char route[4];
	char idnum[19];

	memset(idnum,'\0',sizeof(idnum));
	memset(info,'\0',sizeof(info));
	memset(route,'\0',sizeof(route));
	memset(num,'\0',sizeof(num));
	healinfo_screen(choice);

	n=info_count(choice);
	page_max=n/11+1;
	heal_info(choice,20,350,100,info,page);
	while(1)
	{
		if((*page)<page_max)
		{
			m=10;
		}
		else
		{
			m=n%11-1;
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,40,30))
		{
			if(mouse_press(0,0,40,30)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(0,0,40,30)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				*page=1;
				*choice=0;
				return 0;
			}
		}
		else if(mouse_press(300,400,340,430))
		{
			if(mouse_press(300,400,340,430)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(300,400,340,430)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				*page=1;
				*choice=0;
				return 2;
			}
		}
		else if(mouse_press(590,96,630,120+26*m))
		{
			if(mouse_press(590,96,630,120+26*m)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(590,90,630,120+26*m)==1)
			{
				for(i=0;i<=m;i++)
				{
					if(mouse_press(590,96+26*i,630,120+26*i)==1)
					{
						for(j=0;j<19;j++)
						{
							idnum[j]=info[i][j+1];
						}	
						if((fp=fopen("c:\\mine\\info\\temp.txt","wt+"))!=NULL)//确保此文档中仅有一个数据 
						{
							fprintf(fp,"%s",idnum);
							fclose(fp);
							break;
						}
						else
						{
							puthz(50,0,"打开文件时出错",16,17,RED);
							clrmous(MouseX,MouseY);
							delay(2000);
							closegraph();
							exit(1); 
						}
					}
				}
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				*page=1;
				*choice=0;
				return 11;
			}
		}
		else if(mouse_press(400,400,460,430))
		{
			if(mouse_press(400,400,460,430)==2)
			{
				if(*page==page_max)
				{
					MouseS=0;
				}
				else
				{
					MouseS=1;
				}
			}
			else if(mouse_press(400,400,460,430)==1)
			{
				if(*page==page_max)
				{
					puthz(400,440,"当前为最后一页",16,17,DARKGRAY);
					clrmous(MouseX,MouseY);
					delay(1500);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(400,440,560,460);
					continue;
				}
				else 
				{
					(*page)++;
					clrmous(MouseX,MouseY);
					delay(100);
					return 13;
				}
			}
		}
		else if(mouse_press(500,10,580,30)) 
		{
			if(mouse_press(500,10,580,30)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,10,580,30)==1)
			{
				(*choice)=0;
				clrmous(MouseX,MouseY);
				closegraph();
				return 18;
			}
		}
		else if(mouse_press(500,35,580,55)) 
		{
			if(mouse_press(500,35,580,55)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,35,580,55)==1)
			{
				(*choice)=1;
				clrmous(MouseX,MouseY);
				closegraph();
				return 18;
			}
		}
		else if(mouse_press(500,60,580,80)) 
		{
			if(mouse_press(500,60,580,80)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,60,580,80)==1)
			{
				(*choice)=2;
				clrmous(MouseX,MouseY);
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
/*******************************************
function name:info_count
description:统计healinfo.txt中储存的数据条数
input: void
return:int  
*******************************************/
int info_count(int* choice)
{
	FILE* fp=NULL;
	int i;
	char info[21];
	char path[3][30] = {"C:\\mine\\info\\healinfo.txt",
						"C:\\mine\\info\\worst.txt",
						"C:\\mine\\info\\worse.txt"}; 
	memset(info,'\0',sizeof(info));
	if((fp=fopen(path[*choice],"rt"))!=NULL)
	{
		for(i=0;;i++)
		{
			if(fscanf(fp,"%s",info)==EOF)
			{
				break;
			}
		}
	}
	fclose(fp); 
	return i;
}
/******************************************************
function name: heal_info       
description: 根据身份证号查询并显示对应用户乘车轨迹
input： char* idnum,int x1,int x2,int y,char track[][6]
return: int 
******************************************************/
void heal_info(int* state,int x1,int x2,int y,char info[][21],int* page)
{
	char health[3][6]={"正常","确诊","风险"}; 
	FILE* fp=NULL;
	int i=0;
	int n=0;
	int m=0;
	int states; 
	char idnum[11][19];
	char heal[11][2];
	char name[3][30] = {"C:\\mine\\info\\healinfo.txt",
						"C:\\mine\\info\\worst.txt",
						"C:\\mine\\info\\worse.txt"}; 
	
	memset(heal,'\0',sizeof(heal));
	memset(idnum,'\0',sizeof(idnum));
	

	if((fp=fopen(name[*state],"rt"))!=NULL)
	{
		while(1)
		{
			for(;m<(*page-1)*11;m++)//跳过前11*(*page-1)条信息，
									//此外第一个语句设为空的意义是令此模块最多执行一次 
			{
				fscanf(fp,"%s",info[0]);
				memset(info[0],'\0',sizeof(info[0]));//若进入上述for循环，则需要初始化track[0]
			} 
			if((fscanf(fp,"%s",info[n])==EOF)||(n>=11))//如：track[0]=12345 
			{
				break;
			}
			else 
			{
				heal[n][0]=info[n][0];//健康状态 
				states=heal[n][0]-'0';
				
				if(*state==0)
				{
					puthz(x2,y+26*n,health[states],16,17,DARKGRAY);
					for(i=0;i<18;i++)
					{
						idnum[n][i]=info[n][i+1];
					}
					settextstyle(1,0,1);
					outtextxy(x1,y+26*n,idnum[n]);
				}
				else
				{
					for(i=0;i<19;i++)
					{
						idnum[n][i]=info[n][i];
					}
					settextstyle(1,0,1);
					outtextxy(x1,y+26*n,idnum[n]);
				}
				puthz(585,y+26*n,"查询",16,17,DARKGRAY);
			}
			n++;
		}
		fclose(fp);
	}
	else
	{
		clrmous(MouseX,MouseY);
		puthz(0,50,"打开文件时出错",32,40,DARKGRAY);
		delay(2000);
		closegraph();
		exit(1); 
	}
}
