#include"public.h" 
#include"plan.h"
typedef struct
{
	int num;
	char* name;
}station;
/************************
visitor.c
copyight:gaomingjun
date:2021/4/13
*************************/
/************************
function name:newtrack_screen
description:显示站间路线界面 
input: void
return: void
*************************/
void plan_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY);
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,WHITE);//DARKGRAY
	bar(10,96,170,144);
	bar(200,96,400,144);
	bar(430,96,630,144);
	bar(0,0,40,30);
	bar(300,420,380,456);
	bar(500,420,580,456);
	puthz(0,5,"登录",16,20,DARKGRAY);
	puthz(20,60,"车号",32,40,DARKGRAY);
	puthz(210,60,"起点站",32,40,DARKGRAY);
	puthz(440,60,"终点站",32,40,DARKGRAY);
	puthz(10,110,"请选择",32,40,DARKGRAY);
	puthz(200,110,"请选择",32,40,DARKGRAY);
	puthz(430,110,"请选择",32,40,DARKGRAY);
	puthz(300,420,"显示",32,40,DARKGRAY);
	puthz(500,420,"返回",32,40,DARKGRAY);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(150,96,150,144);
	line(380,96,380,144);
	line(610,96,610,144);
	line(155,108,165,108);
	line(155,120,165,120);
	line(155,132,165,132); 
	line(385,108,395,108);
	line(385,120,395,120);
	line(385,132,395,132);
	line(615,108,625,108);
	line(615,120,625,120);
	line(615,132,625,132);	
 } 
 /*************************
 function name:  newtrack_page
 description： 显示站间轨迹功能 
 input:void
 return:5(游客界面) or 0(登陆界面) 
 **************************/
 int plan_page()
 {
	FILE* fp=NULL;
 	int i=0;
	int flag=0;
	int add=0;
	int temp[3]; 
	int new[3]={0,0,0};
	char track[5][10]; 
	const char tracks[5][10]={"一号","二号","三号","四号","五号"}; 
	station alltracks[5][5]={{{1,"接待中心"},{2,"科技楼"},{3,"机械厂"},{4,"东一楼"},{5,"公管学院"}},
					 {{1,"图书馆"},{2,"东一楼"},{3,"注册中心"},{4,"电影场"},{5,"活动中心"}},
					 {{1,"东三楼"},{2,"集贤楼"},{3,"附属小学"},{4,"科技楼"},{5,"图书馆"}},
					 {{1,"东二楼"},{2,"东八楼"},{3,"教一舍"},{4,"活动中心"},{5,"后勤集团"}},
					 {{1,"机械厂"},{2,"电力车间"},{3,"教工中心"},{4,"出版社"},{5,"管理学院"}}};
	plan_screen();
	memset(new,'\0',sizeof(new)); 
	memset(track,'\0',sizeof(track));
 	while(1)
	{
 		if(add>=0)//flag的值大于零时，代表车次当flag的值为-1时，默认状态，-2时，可以在下拉菜单中选择 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(SOLID_FILL,RED);
			bar(10,144,640,400);
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
				 return 5;
			}
		}
		else if(mouse_press(0,0,40,30))//登录 
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
				return 0;
			}
		}
		else if(mouse_press(150,96,170,144))
 		{
 			if(mouse_press(150,96,170,144)==2)
 			{
 				MouseS=1;
			}
 			else if(mouse_press(150,96,170,144)==1)
  			{
				menu_screen(tracks,10,144,170,192,0,5,32);
				setfillstyle(SOLID_FILL,WHITE);
				bar(10,96,140,144);
				bar(200,96,370,144);
				bar(430,96,600,144);
				puthz(10,110,"请选择",32,40,DARKGRAY);
				puthz(200,110,"请选择",32,40,DARKGRAY);
				puthz(430,110,"请选择",32,40,DARKGRAY);
				new[0]=0;
				new[1]=0;
				new[2]=0; 
				add=-2;
				clrmous(MouseX,MouseY);
			}
		}
		else if(mouse_press(380,96,400,144))
		{
			if(mouse_press(380,96,400,144)==2)
 			{
 				MouseS=1;
			}
 			else if(mouse_press(380,96,400,144)==1)
  			{
				if(new[0]!=0) 
				{	
					menu_screen(track,200,144,400,192,0,4,32);
					setfillstyle(SOLID_FILL,WHITE);
					bar(200,96,370,144);
					bar(430,96,600,144);
					puthz(200,110,"请选择",32,40,DARKGRAY);
					puthz(430,110,"请选择",32,40,DARKGRAY);
					new[1]=0;
					new[2]=0;
					add=-3;
					clrmous(MouseX,MouseY);
				}
				else 
				{
					puthz(150,0,"请先选择车次",32,40,DARKGRAY);
				 	clrmous(MouseX,MouseY);
			 		delay(2000);
				 	setfillstyle(SOLID_FILL,RED); 
			 		bar(150,0,420,50);
		 			continue;
				}
			}
		}
		else if(mouse_press(610,96,630,144))
		{
			if(mouse_press(610,96,630,144)==2)
 			{
 				MouseS=1;
			}
	 		else if(mouse_press(610,96,630,144)==1)
 	 		{
				if((new[0]!=0)&&(new[1]!=0))
				{
					menu_screen(track,430,144,630,192,new[1],5-new[1],32);
					add=-4;
					clrmous(MouseX,MouseY);
				}
				else if(new[0]==0)
				{
					puthz(150,0,"请先选择车次",32,40,DARKGRAY);
				 	clrmous(MouseX,MouseY);
				 	delay(2000);
				 	setfillstyle(SOLID_FILL,RED); 
		 			bar(150,0,420,50);
		 			continue;
				}
				else if(new[1]==0)
				{
					puthz(150,0,"请先选择起点",32,40,DARKGRAY);
				 	clrmous(MouseX,MouseY);
				 	delay(2000);
				 	setfillstyle(SOLID_FILL,RED); 
		 			bar(150,0,420,50);
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
				if(mouse_press(10,146+48*i,170,192+48*i))
				{	
					if(mouse_press(10,146+48*i,170,192+48*i)==2)
					MouseS=1;
					else if(mouse_press(10,146+48*i,170,192+48*i)==1)
					{
						bar(10,96,149,144);
						puthz(10,110,tracks[i],32,40,DARKGRAY);
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
			for(i=0;i<4;i++)
			{
				if(mouse_press(200,146+48*i,400,192+48*i))
				{
					if(mouse_press(200,146+48*i,400,192+48*i)==2)
					MouseS=1;
					else if(mouse_press(200,146+48*i,400,192+48*i)==1)
					{
					bar(200,96,379,144);
					puthz(200,110,alltracks[flag][i].name,32,40,DARKGRAY);
					new[1]=alltracks[flag][i].num;
					add=1;
					break;								
					}
				}
			}
		}
 	    else if(add==-4)
 	    { 
			for(i=0;i<(5-new[1]);i++)
			{
				if(mouse_press(430,146+48*i,630,192+48*i))
				{
					if(mouse_press(430,146+48*i,630,192+48*i)==2)
					MouseS=1;
					else if(mouse_press(430,146+48*i,630,192+48*i)==1)
					{
						bar(430,96,609,144);
						puthz(430,110,alltracks[flag][i+new[1]].name,32,40,DARKGRAY);
						new[2]=alltracks[flag][i+new[1]].num;	
						add=1;
						clrmous(MouseX,MouseY);
						setfillstyle(SOLID_FILL,RED);
						bar(10,144,640,400);	
						break;						
					}
				}
			}
		}
		if((new[1]==new[2])&&(new[1]!=0))
		 {
		 	puthz(150,0,"请勿重复选择站点",32,40,DARKGRAY);
		 	clrmous(MouseX,MouseY);
		 	delay(2000);
		 	bar(150,0,420,50);//如果不加这三行，一旦进入此if语句就无法跳出 
		 	closegraph();
		 	return 7; 
		 }
		 else
		 {
		 	if(mouse_press(300,420,380,456)) //完成 
 			{
 				if(mouse_press(300,420,380,456)==2)
 				MouseS=1;
 				else if(mouse_press(300,420,380,456)==1)
 				{
 					if((judge_num(new[0])&&judge_num(new[1])&&judge_num(new[2]))==0)
					{
						puthz(150,250,"未完成选择",32,40,DARKGRAY);
						delay(2000);
						setfillstyle(SOLID_FILL,RED);
						bar(150,250,350,300);
						continue;
					}
					else
					{
						i=15;
	 					if((fp=fopen("C:\\mine\\info\\show.txt","wt+"))!=NULL)
	 					{
	 						fprintf(fp,"%d%d%d %d",new[0],new[1],new[2],i);
	 						fclose(fp);
	 						clrmous(MouseX,MouseY);
	 						closegraph();
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
	}
} 

