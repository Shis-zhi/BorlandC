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
description:�����������ν���
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
	puthz(200,50,"�����˳��켣",32,40,DARKGRAY);
	puthz(20,110,"����",16,20,DARKGRAY);
	puthz(145,110,"����",16,20,DARKGRAY);
	puthz(270,110,"ʱ��",16,20,DARKGRAY);
	puthz(395,110,"���վ",16,20,DARKGRAY);
	puthz(520,110,"�յ�վ",16,20,DARKGRAY);
	puthz(300,420,"���",32,40,DARKGRAY);
	puthz(500,420,"����",32,40,DARKGRAY);
	puthz(20,140,"��ѡ��",16,20,DARKGRAY);
	puthz(145,140,"��ѡ��",16,20,DARKGRAY);
	puthz(270,140,"��ѡ��",16,20,DARKGRAY);
	puthz(395,140,"��ѡ��",16,20,DARKGRAY);
	puthz(520,140,"��ѡ��",16,20,DARKGRAY);
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
 description�� �����˳��켣���漰����ع���
 input:void
 return:1(��ͨ�û�����) 
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
	const char dates[5][10]={"����һ��","���¶���","��������","��������","��������"};
	const char times[5][10]={"����","�ŵ�","ʮ����","ʮ���","ʮ�˵�"}; 
	const char tracks[5][10]={"һ��","����","����","�ĺ�","���"}; 
	station alltracks[5][10]={{{1,"�Ӵ�����"},{2,"�Ƽ�¥"},{3,"��е��"},{4,"��һ¥"},{5,"����ѧԺ"}},
					 {{1,"ͼ���"},{2,"��һ¥"},{3,"ע������"},{4,"��Ӱ��"},{5,"�����"}},
					 {{1,"����¥"},{2,"����¥"},{3,"����Сѧ"},{4,"�Ƽ�¥"},{5,"ͼ���"}},
					 {{1,"����¥"},{2,"����¥"},{3,"��һ��"},{4,"�����"},{5,"���ڼ���"}},
					 {{1,"��е��"},{2,"��������"},{3,"�̹�����"},{4,"������"},{5,"����ѧԺ"}}};
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
		puthz(150,250,"���ļ�ʱ����",32,40,DARKGRAY);
		delay(2000);
		exit(1);
	}
	while(1)
	{
		if(add>=0)//flag��ֵ������ʱ�������ε�flag��ֵΪ-1ʱ��Ĭ��״̬��-2ʱ�������������˵���ѡ�� 
		{
			clrmous(MouseX,MouseY);
			setfillstyle(SOLID_FILL,RED);
			bar(0,165,640,350);
			add=-1; 
		}
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(500,420,580,456))//���� 
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
		else if(mouse_press(100,135,130,165))//���� 
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
				puthz(20,140,"��ѡ��",16,20,DARKGRAY);
				puthz(395,140,"��ѡ��",16,20,DARKGRAY);
				puthz(520,140,"��ѡ��",16,20,DARKGRAY);
				new[0]=0;
				new[3]=0;
				new[4]=0;
				add=-2;
				clrmous(MouseX,MouseY);
			}
		}
		else if(mouse_press(225,135,255,165))//���� 
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
		else if(mouse_press(350,135,380,165))//ʱ�� 
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
		else if(mouse_press(475,135,505,165))//���վ 
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
					puthz(520,140,"��ѡ��",16,20,DARKGRAY);
					clrmous(MouseX,MouseY);
					
				}
				else
				{
					puthz(200,370,"����ѡ�񳵴�",16,20,DARKGRAY);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,RED); 
					bar(200,370,640,420);
					continue;
				}
			}
		}
		else if(mouse_press(600,135,630,165))//�յ�վ 
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
					puthz(200,370,"����ѡ�񳵴�",16,20,WHITE);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,RED); 
					bar(200,370,640,420);
					continue;
				}
				else if(new[3]==0)
				{
					puthz(200,370,"����ѡ�����",16,20,WHITE);
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
			puthz(200,370,"�����ظ�ѡ��վ��",16,20,WHITE);
			clrmous(MouseX,MouseY);
			delay(2000);
			bar(200,370,640,420);//������������У�һ�������if�����޷����� 
			closegraph();
			return 7; 
		}
		else
		{
		 	if(mouse_press(300,420,380,456)) //��� 
			{
				if(mouse_press(300,420,380,456)==2)
				{
					MouseS=1;
				}
				else if(mouse_press(300,420,380,456)==1)
				{
					if((judge_num(new[0])&&judge_num(new[1])&&judge_num(new[2])&&judge_num(new[3])&&judge_num(new[4]))==0)
					{
						puthz(200,370,"δ���ѡ��",16,20,WHITE);
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
						puthz(220,370,"�����ɹ�",32,40,WHITE);
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
description:�жϲ���ֵ�Ƿ�Ϊ1��2��3��4��5
			����ǣ��򷵻ش˲���ֵ
			������ǣ�����0
input��int x
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
