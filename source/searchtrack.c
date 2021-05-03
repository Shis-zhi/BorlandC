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
description: �������֤�Ų�ѯ����ʾ��Ӧ�û��˳��켣
input�� char* idnum,int x1,int x2,int y,char track[][6]
return: int 
******************************************************/
void usersearch(char* idnum,int x1,int x2,int x3,int x4,int y,char track[][6],int* page)
{
	const char dates[5][10]={"����һ��","���¶���","��������","��������","��������"};
	const char tracks[5][5]={"һ��","����","����","�ĺ�","���"};
	const char times[5][8]={"����","�ŵ�","ʮ����","ʮ���","ʮ�˵�"}; 
	station alltracks[5][5]={{{1,"�Ӵ�����"},{2,"�Ƽ�¥"},{3,"��е��"},{4,"��һ¥"},{5,"����ѧԺ"}},
							{{1,"ͼ���"},{2,"��һ¥"},{3,"ע������"},{4,"��Ӱ��"},{5,"�����"}},
							{{1,"����¥"},{2,"����¥"},{3,"����Сѧ"},{4,"�Ƽ�¥"},{5,"ͼ���"}},
							{{1,"����¥"},{2,"����¥"},{3,"��һ��"},{4,"�����"},{5,"���ڼ���"}},
							{{1,"��е��"},{2,"��������"},{3,"�̹�����"},{4,"������"},{5,"����ѧԺ"}}};
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
			for(;m<(*page-1)*11;m++)//����ǰ11*(*page-1)����Ϣ��
									//�����һ�������Ϊ�յ����������ģ�����ִ��һ�� 
			{
				fscanf(fp,"%5s ",track[0]);
				memset(track[0],'\0',sizeof(track[0]));//����������forѭ��������Ҫ��ʼ��track[0]
			} 
			if(fscanf(fp,"%5s ",track[n])==EOF)//�磺track[0]=12345 
			{
				break;
			}
			else
			{
					i=track[n][0]-'1';//���� 
					j=track[n][3]-'1';//��� 
					k=track[n][4]-'1';//�յ� 
					p=track[n][1]-'1';//���� 
					q=track[n][2]-'1';//ʱ�� 
					strcpy(start[n],alltracks[i][j].name);//��ʼվ
					strcpy(end[n],alltracks[i][k].name);//�յ�վ
					strcpy(date[n],dates[p]);
					strcpy(time[n],times[q]);
					settextstyle(1,0,1);
					num[n][0]=track[n][0];
					outtextxy(20,y+26*n,num[n]);
					puthz(x3,y+26*n,start[n],16,17,DARKGRAY);
					puthz(x4,y+26*n,end[n],16,17,DARKGRAY);
					puthz(x1,y+26*n,date[n],16,17,DARKGRAY);
					puthz(x2,y+26*n,time[n],16,17,DARKGRAY);
					puthz(585,y+26*n,"��ʾ",16,17,DARKGRAY);
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
		puthz(0,50,"���ļ�ʱ����",32,40,DARKGRAY);
		delay(2000);
		closegraph();
		exit(1); 
	}
}
/*******************************
function name:searchtrack_screen
description:���Ʋ�ѯ�˳��켣���� 
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
	puthz(20,60,"����",16,20,WHITE);
	puthz(70,60,"����",16,20,WHITE);
	puthz(180,60,"ʱ��",16,20,WHITE);
	puthz(290,60,"���վ",16,20,WHITE);
	puthz(440,60,"�յ�վ",16,20,WHITE);
	puthz(0,5,"ע��",16,20,DARKGRAY);
	puthz(300,405,"����",16,20,DARKGRAY);
	puthz(400,405,"��һҳ",16,20,DARKGRAY);
	
}
/*****************************************
function name:  searchtrack_page
description�� ��ѯ�˳��켣���漰����ع���
input:int* page
return:1(��ͨ�û�����) 
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
		puthz(50,0,"���ļ�ʱ����",16,17,RED);
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
							puthz(50,0,"���ļ�ʱ����",16,17,RED);
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
					puthz(400,440,"��ǰΪ���һҳ",16,17,DARKGRAY);
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
description:ͳ��ĳ���֤�Ŷ�Ӧ�Ĺ켣��Ϣ���� 
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
