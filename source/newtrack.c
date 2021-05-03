#include"public.h" 
#include"newtrack.h"
/************************
newtrack.c
copyight:gaomingjun
date:2021/3/2
*************************/
typedef struct
{
	int num;
	char* name;
}station;
/************************
function name:newtrack_screen
description:绘制新增车次界面
input: void
return: void
*************************/
void newtrack_screen()
 {
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY);
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,WHITE);
	bar(20,135,130,165);
	bar(145,135,255,165);
	bar(270,135,380,165);
	bar(395,135,505,165);
	bar(520,135,630,165);
	bar(300,420,380,456);
	bar(500,420,580,456);
	puthz(200,50,"新增乘车轨迹",32,40,DARKGRAY);
	puthz(20,110,"车号",16,20,DARKGRAY);
	puthz(145,110,"日期",16,20,DARKGRAY);
	puthz(270,110,"时间",16,20,DARKGRAY);
	puthz(395,110,"起点站",16,20,DARKGRAY);
	puthz(520,110,"终点站",16,20,DARKGRAY);
	puthz(300,420,"完成",32,40,DARKGRAY);
	puthz(500,420,"返回",32,40,DARKGRAY);
	puthz(20,140,"请选择",16,20,DARKGRAY);
	puthz(145,140,"请选择",16,20,DARKGRAY);
	puthz(270,140,"请选择",16,20,DARKGRAY);
	puthz(395,140,"请选择",16,20,DARKGRAY);
	puthz(520,140,"请选择",16,20,DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	line(101,135,101,165);
	line(105,143,125,143);
	line(105,150,125,150);
	line(105,157,125,157);
	line(226,135,226,165);
	line(230,143,250,143);
	line(230,150,250,150);
	line(230,157,250,157);
	line(351,135,351,165);
	line(355,143,375,143);
	line(355,150,375,150);
	line(355,157,375,157);
	line(476,135,476,165);
	line(480,143,500,143);
	line(480,150,500,150);
	line(480,157,500,157); 
	line(601,135,601,165);
	line(605,143,625,143);
	line(605,150,625,150);
	line(605,157,625,157);
	//setcolor(DARKGRAY);
	//setlinestyle(SOLID_LINE,0,NORM_WIDTH);	
 }
 /*************************
 function name:  newtrack_page
 description： 新增乘车轨迹界面及其相关功能
 input:void
 return:1(普通用户界面) 
 **************************/
 int newtrack_page()
 {
	int i=0;
	int j=0;
	int flag=0;
	int add=0;
	int new[5]={0,0,0,0,0};
	char old[3];
	char idnum[19];
	char path[15]; 
	char no[7];
	char name[30]="c:\\mine\\track\\";
	const char* temp1="t.txt";
	char temp2[30]="C:\\mine\\track\\";
	const char* temp3=".txt";
	FILE *fp=NULL;
	char track[5][10]; 
	const char dates[5][10]={"五月一日","五月二日","五月三日","五月四日","五月五日"};
	const char times[5][10]={"六点","九点","十二点","十五点","十八点"}; 
	const char tracks[5][10]={"一号","二号","三号","四号","五号"}; 
	station alltracks[5][10]={{{1,"接待中心"},{2,"科技楼"},{3,"机械厂"},{4,"东一楼"},{5,"公管学院"}},
					 {{1,"图书馆"},{2,"东一楼"},{3,"注册中心"},{4,"电影场"},{5,"活动中心"}},
					 {{1,"东三楼"},{2,"集贤楼"},{3,"附属小学"},{4,"科技楼"},{5,"图书馆"}},
					 {{1,"东二楼"},{2,"东八楼"},{3,"教一舍"},{4,"活动中心"},{5,"后勤集团"}},
					 {{1,"机械厂"},{2,"电力车间"},{3,"教工中心"},{4,"出版社"},{5,"管理学院"}}};
	newtrack_screen();
	memset(old,'\0',sizeof(old));
	memset(track,'\0',sizeof(track));
	memset(idnum,'\0',sizeof(idnum));
	memset(path,'\0',sizeof(path));
	memset(no,'\0',sizeof(no));
	if((fp=fopen("c:\\mine\\info\\temp.txt","rt"))!=NULL)
	{
		fscanf(fp,"%s",idnum);
		fclose(fp);
		for(i=0;i<7;i++)
		{
			path[i]=idnum[i+10];
		}
		strcat(path,temp1);
		strcat(temp2,path); 
		fclose(fp);
	}
	else
	{
		puthz(150,250,"打开文件时出错",32,40,DARKGRAY);
		delay(2000);
		exit(1);
	}
	while(1)
	{
		if(add>=0)//flag的值大于零时，代表车次当flag的值为-1时，默认状态，-2时，可以在下拉菜单中选择 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(SOLID_FILL,RED);
			bar(0,165,640,350);
			add=-1; 
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(500,420,580,456))//返回 
		{
			if(mouse_press(500,420,580,456)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,420,580,456)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				return 1;
			}
		}
		else if(mouse_press(100,135,130,165))//车号 
		{
			if(mouse_press(100,135,130,165)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(100,135,130,165)==1)
			{
				menu_screen(tracks,20,165,100,195,0,5,16);
				setfillstyle(SOLID_FILL,WHITE);
				bar(20,135,100,165);
				bar(395,135,475,165);
				bar(520,135,600,165);
				puthz(20,140,"请选择",16,20,DARKGRAY);
				puthz(395,140,"请选择",16,20,DARKGRAY);
				puthz(520,140,"请选择",16,20,DARKGRAY);
				new[0]=0;
				new[3]=0;
				new[4]=0;
				add=-2;
				clrmous(MouseX,MouseY);
			}
		}
		else if(mouse_press(225,135,255,165))//日期 
		{
			if(mouse_press(225,135,255,165)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(225,135,255,165)==1)
			{	
				menu_screen(dates,145,165,225,195,0,5,16);
				add=-3;
				clrmous(MouseX,MouseY);
			}
		}
		else if(mouse_press(350,135,380,165))//时间 
		{
			if(mouse_press(350,135,380,165)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(350,135,380,165)==1)
			{
					menu_screen(times,270,165,350,195,0,5,16);
					add=-4;
					clrmous(MouseX,MouseY);			
			}
		}
		else if(mouse_press(475,135,505,165))//起点站 
		{
			if(mouse_press(475,135,505,165)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(475,135,505,165)==1)
			{
				if(new[0]!=0) 
				{	
					menu_screen(track,395,165,475,195,0,4,16);
					add=-5;
					new[4]=0;
					bar(520,135,600,165);
					puthz(520,140,"请选择",16,20,DARKGRAY);
					clrmous(MouseX,MouseY);
					
				}
				else
				{
					puthz(200,370,"请先选择车次",16,20,DARKGRAY);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,RED); 
					bar(200,370,640,420);
					continue;
				}
			}
		}
		else if(mouse_press(600,135,630,165))//终点站 
		{
			if(mouse_press(600,135,630,165)==2)
				{
					MouseS=1;
				}
			else if(mouse_press(600,135,630,165)==1)
			{
				if((new[0]!=0)&&(new[3]!=0))
				{
					menu_screen(track,520,165,600,195,new[3],5-new[3],16);
					add=-6;
					clrmous(MouseX,MouseY);
				}
				else if(new[0]==0)
				{
					puthz(200,370,"请先选择车次",16,20,WHITE);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,RED); 
					bar(200,370,640,420);
					continue;
				}
				else if(new[3]==0)
				{
					puthz(200,370,"请先选择起点",16,20,WHITE);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,RED); 
					bar(200,370,640,420);
					continue;
				}		
			}
		}
		else
		{
			MouseS=0;
		}
		if(add==-2)
		{
			for(i=0;i<5;i++)
			{	
				if(mouse_press(20,165+30*i,100,195+30*i))
				{	
					if(mouse_press(20,165+30*i,100,195+30*i)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(20,165+30*i,100,195+30*i)==1)
					{
						bar(20,135,100,165);
						puthz(20,140,tracks[i],16,20,DARKGRAY);
						new[0]=i+1;
						flag=i;	
						add=1;
						break;							
					}
				}
			}
			for(i=0;i<5;i++)
			{
				strcpy(track[i],alltracks[flag][i].name);
			}
		}
		else if(add==-3)
		{ 
			for(i=0;i<5;i++)
			{
				if(mouse_press(145,165+30*i,225,195+30*i))
				{
					if(mouse_press(145,165+30*i,225,195+30*i)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(145,165+30*i,225,195+30*i)==1)
					{
						bar(145,135,225,165);
						puthz(145,140,dates[i],16,20,DARKGRAY);
						new[1]=i+1;	
						add=1;	
						break;						
					}
				}
			}
		}
		else if(add==-4)
		{ 
			for(i=0;i<5;i++)
			{
				if(mouse_press(270,165+30*i,380,195+30*i))
				{
					if(mouse_press(270,165+30*i,380,195+30*i)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(270,165+30*i,380,195+30*i)==1)
					{
						bar(270,135,350,165);
						puthz(270,140,times[i],16,20,DARKGRAY);
						new[2]=i+1;	
						add=1;
						clrmous(MouseX,MouseY);
						break;						
					}
				}
			}
		}
		else if(add==-5)
		{
			for(i=0;i<5;i++)
			{
				if(mouse_press(395,165+30*i,505,195+30*i))
				{
					if(mouse_press(395,165+30*i,505,195+30*i)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(395,165+30*i,505,195+30*i)==1)
					{
						bar(395,135,475,165);
						puthz(395,140,alltracks[flag][i].name,16,20,DARKGRAY);
						new[3]=alltracks[flag][i].num;
						add=1;
						clrmous(MouseX,MouseY);
						break;								
					}
				}
			}
		}
		else if(add==-6)
		{ 
			for(i=0;i<5;i++)
			{
				if(mouse_press(520,165+30*i,630,195+30*i))
				{
					if(mouse_press(520,165+30*i,630,195+30*i)==2)
					{
						MouseS=1;
					}
					else if(mouse_press(520,165+30*i,630,195+30*i)==1)
					{
						bar(520,135,600,165);
						puthz(520,140,alltracks[flag][i+new[3]].name,16,20,DARKGRAY);
						new[4]=alltracks[flag][i+new[3]].num;	
						add=1;
						clrmous(MouseX,MouseY);
						break;						
					}
				}
			}
		}
		if((new[3]==new[4])&&(new[3]!=0))
		{
			puthz(200,370,"请勿重复选择站点",16,20,WHITE);
			clrmous(MouseX,MouseY);
			delay(2000);
			bar(200,370,640,420);//如果不加这三行，一旦进入此if语句就无法跳出 
			closegraph();
			return 7; 
		}
		else
		{
		 	if(mouse_press(300,420,380,456)) //完成 
			{
				if(mouse_press(300,420,380,456)==2)
				{
					MouseS=1;
				}
				else if(mouse_press(300,420,380,456)==1)
				{
					if((judge_num(new[0])&&judge_num(new[1])&&judge_num(new[2])&&judge_num(new[3])&&judge_num(new[4]))==0)
					{
						puthz(200,370,"未完成选择",16,20,WHITE);
						delay(2000);
						setfillstyle(SOLID_FILL,RED);
						bar(200,370,640,420);
						continue;
					}
					else
					{
						if((fp=fopen(temp2,"at+"))==NULL)
						{
							fp=fopen(temp2,"wt+");
						}
						fprintf(fp,"%d%d%d%d%d ",new[0],new[1],new[2],new[3],new[4]);
						fclose(fp);
						no[0]=flag+'1';
						no[1]=new[1]+'0';
						no[2]=new[2]+'0';
						strcat(no,temp3);
						strcat(name,no);
						if((fp=fopen(name,"at+"))==NULL)
						{
							fp=fopen(name,"wt+");
						}
						fprintf(fp,"%d%d%s\n",new[3],new[4],idnum);
						fclose(fp);
						puthz(220,370,"新增成功",32,40,WHITE);
						clrmous(MouseX,MouseY);
						delay(1500);
						closegraph(); 
						return 1;
					}
				}
			}
		}		      		      			
	}
}
/**************************************** 
function name:judge_num
description:判断参数值是否为1，2，3，4，5
			如果是，则返回此参数值
			如果不是，返回0
input：int x
return: int 
****************************************/
int judge_num(int x)
{
	if((x==1)||(x==2)||(x==3)||(x==4)||(x==5))
	{
		return x;
	}
	else 
	{
		return 0;
	}
}
