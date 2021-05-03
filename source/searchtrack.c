#include"public.h"
#include"search.h"
typedef struct
{
	int num;
	char* name;
}station;
/************************
newtrack.c
copyight:gaomingjun
date:2021/3/13
*************************/
/******************************************************
function name: usersearch          
description: 根据身份证号查询并显示对应用户乘车轨迹
input： char* idnum,int x1,int x2,int y,char track[][6]
return: int 
******************************************************/
void usersearch(char* idnum,int x1,int x2,int x3,int x4,int y,char track[][6],int* page)
{
	const char dates[5][10]={"五月一日","五月二日","五月三日","五月四日","五月五日"};
	const char tracks[5][5]={"一号","二号","三号","四号","五号"};
	const char times[5][8]={"六点","九点","十二点","十五点","十八点"}; 
	station alltracks[5][5]={{{1,"接待中心"},{2,"科技楼"},{3,"机械厂"},{4,"东一楼"},{5,"公管学院"}},
							{{1,"图书馆"},{2,"东一楼"},{3,"注册中心"},{4,"电影场"},{5,"活动中心"}},
							{{1,"东三楼"},{2,"集贤楼"},{3,"附属小学"},{4,"科技楼"},{5,"图书馆"}},
							{{1,"东二楼"},{2,"东八楼"},{3,"教一舍"},{4,"活动中心"},{5,"后勤集团"}},
							{{1,"机械厂"},{2,"电力车间"},{3,"教工中心"},{4,"出版社"},{5,"管理学院"}}};
	FILE* fp=NULL;
	int i=0;
	int n=0;
	int m=0;
	int j,k,p,q; 
	char num[11][2],start[11][10],end[11][10],date[11][10],time[11][10];
	char name[30]="C:\\mine\\track\\"; 
	char path[15];
	const char* temp="t.txt";

	memset(path,'\0',sizeof(path));
	memset(start,'\0',sizeof(start));
	memset(end,'\0',sizeof(end));
	memset(date,'\0',sizeof(date));
	memset(time,'\0',sizeof(time));
	memset(num,'\0',sizeof(num));
	
	for(i=0;i<7;i++)
	{
		path[i]=idnum[i+10];
	}
	strcat(path,temp);
	strcat(name,path);
	if((fp=fopen(name,"rt"))!=NULL)
	{
		while(1)
		{
			for(;m<(*page-1)*11;m++)//跳过前11*(*page-1)条信息，
									//此外第一个语句设为空的意义是令此模块最多执行一次 
			{
				fscanf(fp,"%5s ",track[0]);
				memset(track[0],'\0',sizeof(track[0]));//若进入上述for循环，则需要初始化track[0]
			} 
			if(fscanf(fp,"%5s ",track[n])==EOF)//如：track[0]=12345 
			{
				break;
			}
			else
			{
					i=track[n][0]-'1';//车次 
					j=track[n][3]-'1';//起点 
					k=track[n][4]-'1';//终点 
					p=track[n][1]-'1';//日期 
					q=track[n][2]-'1';//时间 
					strcpy(start[n],alltracks[i][j].name);//起始站
					strcpy(end[n],alltracks[i][k].name);//终点站
					strcpy(date[n],dates[p]);
					strcpy(time[n],times[q]);
					settextstyle(1,0,1);
					num[n][0]=track[n][0];
					outtextxy(20,y+26*n,num[n]);
					puthz(x3,y+26*n,start[n],16,17,DARKGRAY);
					puthz(x4,y+26*n,end[n],16,17,DARKGRAY);
					puthz(x1,y+26*n,date[n],16,17,DARKGRAY);
					puthz(x2,y+26*n,time[n],16,17,DARKGRAY);
					puthz(585,y+26*n,"显示",16,17,DARKGRAY);
			}
			n++;
			if(n>=11)
			{
				break;
			} 
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
/*******************************
function name:searchtrack_screen
description:绘制查询乘车轨迹界面 
input: void
return: void
*******************************/ 
void searchtrack_screen()
{
	int i;
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY); 
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,40,30);
	
	for(i=0;96+i*26<360;i++)
	{
		bar(10,96+i*26,630,120+i*26);
		//line(600,120+i*26,630,120+i*26);
	}
	bar(300,400,340,430);
	bar(400,400,460,430); 
	puthz(20,60,"车号",16,20,WHITE);
	puthz(70,60,"日期",16,20,WHITE);
	puthz(180,60,"时间",16,20,WHITE);
	puthz(290,60,"起点站",16,20,WHITE);
	puthz(440,60,"终点站",16,20,WHITE);
	puthz(0,5,"注销",16,20,DARKGRAY);
	puthz(300,405,"返回",16,20,DARKGRAY);
	puthz(400,405,"下一页",16,20,DARKGRAY);
	
}
/*****************************************
function name:  searchtrack_page
description： 查询乘车轨迹界面及其相关功能
input:int* page
return:1(普通用户界面) 
*****************************************/
int searchtrack_page(int* page)
{
	FILE* fp=NULL;
	int i;
	int n;
	int m; 
	int flag;
	int page_max;
	char idnum[19];
	char track[11][6];
	char route[6];
	memset(idnum,'\0',sizeof(idnum));
	memset(track,'\0',sizeof(track));
	memset(route,'\0',sizeof(route));
	searchtrack_screen();

	if((fp=fopen("c:\\mine\\info\\temp.txt","rt"))!=NULL)
	{
		fscanf(fp,"%s",idnum);
		fclose(fp);
		fp=NULL;
	}
	else
	{
		puthz(50,0,"打开文件时出错",16,17,RED);
		clrmous(MouseX,MouseY);
		delay(2000);
		closegraph();
		exit(1);
	}
	n=track_count(idnum);
	page_max=n/11+1;
	clrmous(MouseX,MouseY); 
	usersearch(idnum,70,180,290,440,100,track,page);
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
				return 1;
			}
		}
		else if(mouse_press(580,96,610,120+26*m))
		{
			if(mouse_press(580,96,610,120+26*m)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(580,96,610,120+26*m)==1)
			{
				for(i=0;i<=m;i++)
				{
					if(mouse_press(580,96+26*i,610,120+26*i)==1)
					{
						flag=i;
						route[0]=track[flag][0];
						route[1]=track[flag][3];
						route[2]=track[flag][4];
						if((fp=fopen("C:\\mine\\info\\show.txt","wt+"))!=NULL)
						{
							i=8; 
							fprintf(fp,"%s %d",route,i);
							fclose(fp);
							clrmous(MouseX,MouseY);
							closegraph();
							*page=1;
							return 17;
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
			}	
		}
		else if(mouse_press(400,400,440,430))
		{
			if(mouse_press(400,400,440,430)==2)
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
			else if(mouse_press(400,400,440,430)==1)
			{
				if(*page==page_max)
				{
					puthz(400,440,"当前为最后一页",16,17,DARKGRAY);
					clrmous(MouseX,MouseY);
					delay(1500);
					setfillstyle(SOLID_FILL,RED);
					bar(400,440,560,460);
					continue;
				}
				else 
				{
					(*page)++;
					clrmous(MouseX,MouseY);
					delay(100);
					return 8;
				}
			}
		}
		else
		{
			MouseS=0;
		}
	}
}
/*******************************************
function name:track_count
description:统计某身份证号对应的轨迹信息条数 
input: char* idnum
return: int 
********************************************/
int track_count(char* idnum)
{
	FILE* fp=NULL;
	int i;
	char path[30]="C:\\mine\\track\\";
	char temp[6]="t.txt";
	char name[15];
	char track[6];
	memset(track,'\0',sizeof(track));
	memset(name,'\0',sizeof(name));
	for(i=0;i<7;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp);
	strcat(path,name);
	if((fp=fopen(path,"rt"))!=NULL)
	{
		for(i=0;;i++)
		{
			if(fscanf(fp,"%5s ",track)==EOF)
			{
				break;
			}
		}
	}
	return i;
}
