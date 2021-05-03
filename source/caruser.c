#include"public.h"
#include"caruser.h"
/*********************************
usercar.c
copyright:shishengzhi
date: 2021/4/1
*********************************/ 
/******************************************* 
function name:caruser_screen
description:根据选择的车次查询对应的乘客信息
input: void
return: void 
********************************************/
void caruser_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	puthz(50,50,"车次",32,40,WHITE);
	bar(50,100,230,150);
	puthz(55,105,"请选择",32,40,DARKGRAY);
	puthz(250,50,"日期",32,40,WHITE);
	bar(250,100,430,150);
	puthz(255,105,"请选择",32,40,DARKGRAY);
	puthz(450,50,"时间",32,40,WHITE);
	bar(450,100,630,150);
	puthz(455,100,"请选择",32,40,DARKGRAY);
	bar(0,0,40,30);	
	puthz(5,5,"返回",16,20,DARKGRAY);
	bar(450,400,500,430);
	puthz(455,405,"查询",16,20,DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	line(200,100,200,150);
	line(205,112,225,112);
	line(205,125,225,125);
	line(205,138,225,138);
	line(400,100,400,150);
	line(405,112,425,112);
	line(405,125,425,125);
	line(405,138,425,138);
	line(600,100,600,150); 
	line(605,112,625,112);
	line(605,125,625,125);
	line(605,138,625,138);
}
/********************************************
function name:caruser_page
description:上述界面的功能函数
input： void
return: 2(管理员界面) or 13(此界面的子界面） 
********************************************/
int caruser_page()
{
	int i;
	int flag=-1; 
	int n=-1;
	int track[3]={0,0,0};
	FILE* fp=NULL;
	const char dates[5][10]={"五月一日","五月二日","五月三日","五月四日","五月五日"};
	const char tracks[5][10]={"一号","二号","三号","四号","五号"};
	const char times[5][10]={"六点","九点","十二点","十五点","十八点"};
	caruser_screen();
	while(1)
	{
		
		if(flag>=0)//flag的值大于零时，代表车次当flag的值为-1时，默认状态，-2时，可以在下拉菜单中选择 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(50,150,630,402);
			flag=-1; 
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,30,40))
		{
			if(mouse_press(0,0,30,40)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(0,0,30,40)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 2;
			}
		} 
		else if(mouse_press(200,100,230,150))//车次 
		{
			if(mouse_press(200,100,230,150)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(200,100,230,150)==1)
			{
				menu_screen(tracks,50,150,200,200,0,5,32);
				flag=-2;
			}
		}
		else if(mouse_press(400,100,430,150))//日期 
		{
			if(mouse_press(400,100,430,150)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(400,100,430,150)==1)
			{
				menu_screen(dates,250,150,400,200,0,5,32);
				flag=-3;
			}
		}
		else if(mouse_press(600,100,630,150))//时间 
		{
			if(mouse_press(600,100,630,150)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(600,100,630,150)==1)
			{
				menu_screen(times,450,150,600,200,0,5,32);
				flag=-4;
			}
		}
		else if(mouse_press(450,400,500,430))//查询按钮 
		{
			if(mouse_press(450,400,500,430)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(450,400,500,430)==1)
			{
				if((track[0]!=0)&&(track[1]!=0)&&(track[2]!=0))
				{
					if((fp=fopen("C:\\mine\\info\\temp1.txt","wt+"))!=NULL)//每次打开都直接清空上次写入的数据
					{
						fprintf(fp,"%d%d%d",track[0],track[1],track[2]);
						fclose(fp);
					}
					else	
					{
						clrmous(MouseX,MouseY);
						puthz(50,50,"操作文件时发生错误",16,17,RED);
						delay(2000);
						closegraph();
						exit(1); 
					}
					clrmous(MouseX,MouseY);
					delay(500);
					closegraph();
					return 13;
				}
				else if(track[0]==0) 
				{
					puthz(200,300,"未选择车次",32,35,RED);
					delay(1500);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					closegraph();
					return 9;
				}
				else if(track[1]==0) 
				{
					puthz(200,300,"未选择日期",32,35,RED);
					delay(1500);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(200,50,300,70);
					closegraph();
					return 9;
				}
				else if(track[2]==0) 
				{
					puthz(200,300,"未选择时间",32,35,RED);
					delay(1500);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(200,50,300,70);
					closegraph(); 
					return 9;
				}
			}
		}
		else 
		{
			MouseS=0;
		}
		if(flag==-2)
		{
			for(i=0;i<5;i++)
			{
				if(mouse_press(50,150+50*i+2,200,200+50*i+2))
				{
					if(mouse_press(50,150+50*i+2,200,200+50*i+2)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(50,150+50*i+2,200,200+50*i+2)==1)
					{
						flag=i;//用于单击查询时的判断
						track[0]=i+1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(50,100,195,150);
						puthz(55,113,tracks[i],32,40,DARKGRAY);
					}
				}
			}
		}
		else if(flag==-3)
		{
			for(i=0;i<5;i++)
			{
				if(mouse_press(250,150+50*i+2,400,200+50*i+2))
				{
					if(mouse_press(250,150+50*i+2,400,200+50*i+2)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(250,150+50*i+2,400,200+50*i+2)==1)
					{
						flag=i;//用于单击查询时的判断
						track[1]=i+1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(250,100,395,150);
						puthz(250,113,dates[i],32,40,DARKGRAY);
					}
				}
			}
		} 
		else if(flag==-4)
		{
			for(i=0;i<5;i++)
			{
				if(mouse_press(450,150+50*i+2,600,200+50*i+2))
				{
					if(mouse_press(450,150+50*i+2,600,200+50*i+2)==2)
					{
					MouseS=1;
					}
					else if(mouse_press(450,150+50*i+2,600,200+50*i+2)==1)
					{
						flag=i;//用于单击查询时的判断
						track[2]=i+1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(450,100,595,150);
						puthz(455,113,times[i],32,40,DARKGRAY);
					}
				}
			}
		}
	} 
} 
 /**************************************
 function name:ctu_screen
 description: 绘制展示界面
 input: void
 return: void
 **************************************/
 void ctu_screen()
 {  
 	int i;
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,40,30);
	
	for(i=0;96+i*26<360;i++)
	{
		bar(10,96+i*26,630,120+i*26);
		//line(600,96+i*26,630,120+i*26);
	}
	bar(300,400,340,430);
	bar(400,400,460,430); 
	puthz(20,60,"身份证号",16,20,DARKGRAY);
	puthz(290,60,"起点站",16,20,DARKGRAY);
	puthz(440,60,"终点站",16,20,DARKGRAY);
	puthz(0,5,"注销",16,20,DARKGRAY);
	puthz(300,405,"返回",16,20,DARKGRAY);
	puthz(400,405,"下一页",16,20,DARKGRAY);
 }
 /*************************************
 function name:ctu_page
 description: 上述界面的功能函数
 input：void
 return：int  
 *************************************/
 int ctu_page(int* page)
 {
	FILE* fp=NULL;
	int i,j,flag;
	int m,n;
	int page_max;
	char info[11][21];
	char num[4];
	char route[4];
	char idnum[19];

	memset(idnum,'\0',sizeof(idnum));
	memset(info,'\0',sizeof(info));
	memset(route,'\0',sizeof(route));
	memset(num,'\0',sizeof(num));
	ctu_screen();

	if((fp=fopen("c:\\mine\\info\\temp1.txt","rt"))!=NULL)
	{
		fscanf(fp,"%s",num);
		fclose(fp);
		fp=NULL;
	}
	else
	{
		puthz(50,0,"打开文件时出错",16,17,DARKGRAY);
		clrmous(MouseX,MouseY);
		delay(2000);
		closegraph();
		exit(1);
	}
	n=user_count(num);
	page_max=n/11+1;
	tracksearch(num,250,400,100,info,page);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if((*page)<page_max)
		{
			m=10;
		}
		else
		{
			m=n%11-1;
		}
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
						flag=i+1;
						for(j=0;j<19;j++)
						{
							idnum[j]=info[i][j+2];
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
				return 11;
			}
		}
		else if(mouse_press(540,96,580,120+26*m))
		{
			if(mouse_press(540,96,580,120+26*m)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(540,90,580,120+26*m)==1)
			{
				for(i=0;i<=m;i++)
				{
					if(mouse_press(540,96+26*i,580,120+26*i)==1)
					{
						flag=i+1;
						route[0]=num[0]+1;
						route[1]=info[i][0];
						route[2]=info[i][1];
						break;
					}
				}
				if((fp=fopen("C:\\mine\\info\\show.txt","wt+"))!=NULL)
				{
					i=9; 
					fprintf(fp,"%s %d",route,i);
					fclose(fp);
					clrmous(MouseX,MouseY);
					closegraph(); 
					(*page)=1;
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
		else
		{
			MouseS=0;
		}
	}
}
 /***************************************************************
function name: tracksearch
description: 根据车次查询并显示对应用户信息
input： char number,int x1,int x2,int y,char info[][21].int* page
return: void
*****************************************************************/
void tracksearch(char number[],int x1,int x2,int y,char info[][21],int* page)
{
	const char dates[5][10]={"五月一日","五月二日","五月三日","五月四日","五月五日"};
	const char tracks[5][5]={"一号","二号","三号","四号","五号"};
	const char times[5][8]={"六点","九点","十二点","十五点","十八点"};
	station alltracks[5][5]={{{1,"接待中心"},{2,"科技楼"},{3,"机械厂"},{4,"东一楼"},{5,"公管学院"}},
					 {{1,"图书馆"},{2,"东一楼"},{3,"注册中心"},{4,"电影场"},{5,"活动中心"}},
					 {{1,"东三楼"},{2,"集贤楼"},{3,"附属小学"},{4,"科技楼"},{5,"图书馆"}},
					 {{1,"东二楼"},{2,"东八楼"},{3,"教一舍"},{4,"活动中心"},{5,"后勤集团"}},
					 {{1,"机械厂"},{2,"电力车间"},{3,"教工中心"},{4,"出版社"},{5,"管理学院"}}};
	int i=0; 
	int n=0;
	int p=0;
	int t=0;
	int j,k,date,time,m; 
	FILE* fp=NULL;
	char num[11][2],start[11][10],end[11][10];
	char idnum[19];
	char path[30]="C:\\mine\\track\\";
	char no[4]; 
	const char* temp=".txt";
	
	memset(start,'\0',sizeof(start));
	memset(end,'\0',sizeof(end));
	memset(num,'\0',sizeof(num));
	memset(idnum,'\0',sizeof(idnum));
	memset(no,'\0',sizeof(no));


	no[0]=number[0];
	no[1]=number[1];
	no[2]=number[2];
	strcat(no,temp);
	strcat(path,no);
	m=number[0]-'1';
	date=number[1]-'1';
	time=number[2]-'1';
	puthz(50,10,tracks[m],16,17,DARKGRAY);
	puthz(90,10,dates[date],16,17,DARKGRAY);
	puthz(250,10,times[time],16,17,DARKGRAY); 
	strcat(path,number);
	strcat(path,temp);
	if((fp=fopen(path,"rt"))!=NULL)
	{
		while(1)
		{
			for(;p<(*page-1)*11;p++)//跳过前11*(*page-1)条信息，
									//此外第一个语句设为空的意义是令此模块最多执行一次 
			{
				fscanf(fp,"%s\n",info[0]);
				memset(info[0],'\0',sizeof(info[0]));//若进入上述for循环，则需要初始化track[0]
			} 
			if((fscanf(fp,"%s",info[n])==EOF))
			{
				break;
			}
			else
			{
				for(i=n;i<=n;i++)
				{
					j=info[n][0]-'1';
					k=info[n][1]-'1';
					for(t=0;t<18;t++)
					{
						idnum[t] = info[i][t+2];
					}
					strcpy(start[i],alltracks[m][j].name);//起始站
					strcpy(end[i],alltracks[m][k].name);//终点站
					setcolor(DARKGRAY);
					settextstyle(1,0,1);
					outtextxy(20,96+26*i,idnum);
					puthz(x1,y+26*i,start[i],16,17,DARKGRAY);
					puthz(x2,y+26*i,end[i],16,17,DARKGRAY);
					puthz(590,100+26*i,"查询",16,20,DARKGRAY);
					puthz(540,100+26*i,"显示",16,20,DARKGRAY); 
				}
				n++;
				if(n>=11)
				{
					break;
				} 
			}
		}
		fclose(fp);
	}
	else
	{
		clrmous(MouseX,MouseY);
		puthz(50,50,"打开文件时出错",32,40,DARKGRAY);
		delay(2000);
		closegraph();
		exit(1); 
	}
}
/************************************
function name:user_count
description:统计某车次对应的乘车信息条数
input: char track[4]
return: int 
*************************************/
int user_count(char track[4])
{
	FILE* fp=NULL;
	int i;
	char path[30]="C:\\mine\\track\\";
	char temp[6]=".txt";
	char name[15];
	char info[21];
	memset(info,'\0',sizeof(track));
	memset(name,'\0',sizeof(name));
	for(i=0;i<4;i++)
	{
		name[i]=track[i];
	}
	strcat(name,temp);
	strcat(path,name);
	if((fp=fopen(path,"rt"))!=NULL)
	{
		for(i=0;;i++)
		{
			if(fscanf(fp,"%s\n",info)==EOF)
			{
				break;
			}
		}
	}
	return i;
}
