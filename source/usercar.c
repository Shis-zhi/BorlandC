#include"public.h"
#include"usercar.h"
/***************************
usercar.c
copyright:shishengzhi
date:2021/3/2
***************************/
typedef struct
{
	int num;
	char* name;
}station;

/************************************
function name:usercar_screen
description:���ݳ˿���Ϣ��ѯ��Ӧ���� 
input:void
return:void
************************************/
void usercar_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE);
	puthz(50,180,"���֤��",16,17,WHITE);
	bar(140,175,550,205);
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,40,30);
	bar(290,400,350,420);
	puthz(300,400,"��ѯ",16,20,WHITE);
	puthz(0,5,"����",16,20,WHITE);
} 
/********************************************** 
function name:usercar_page
description:�����������ع���
input��void
return: 2(���ع���Ա����) or  11(�˹��ܵ��ӽ���)
***********************************************/
int usercar_page()
{
	char idnum[19];
	char tracks[20][4];
	char track[4];
	char path[30]="C:\\mine\\track\\"; 
	char name[15];
	const char temp[]="t.txt";
	int i;
	int n;
	FILE* fp;
	usercar_screen();
	memset(tracks,'\0',sizeof(tracks));
	memset(idnum,'\0',sizeof(idnum));
	memset(track,'\0',sizeof(track));
	memset(name,'\0',sizeof(name));
	while(1)
	{
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
				return 2;
			}
		}
		else if(mouse_press(140,175,550,205))
		{
			if(mouse_press(140,175,550,205)==2)
			{
				MouseS=2;
			}
			else if(mouse_press(140,175,550,205)==1)
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(140,175,550,205);
				input_num(idnum,sizeof(idnum),140,175);
			}	
		}
		else if(mouse_press(290,400,350,420))
		{
			if(mouse_press(290,400,350,420)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(290,400,350,420)==1)
			{
				i=judge_id(idnum);
				if(i!=0)
				{
					puthz(140,225,"���֤λ������",16,17,RED);
					delay(1500);
					continue;
				}
				if(ad_search(idnum)!=1)
				{
					puthz(140,225,"�޴�����Ϣ",16,17,RED);
					delay(2000);
					memset(idnum,'\0',sizeof(idnum));
					setfillstyle(SOLID_FILL,WHITE);
					bar(140,175,550,205);
					continue;
				}
				else
				{
					if((fp=fopen("c:\\mine\\info\\temp.txt","wt+"))!=NULL)
					{
						fprintf(fp,"%s",idnum);
						fclose(fp);
						delay(500);
						closegraph();
						return 11;
					}
					else
					{
						puthz(140,225,"���ļ�ʱ����",16,17,DARKGRAY);
						clrmous(MouseX,MouseY);
						delay(2000);
						closegraph();
						exit(1);
					}
				}
			}
		}
		else 
		{
			MouseS=0;
		} 
	}
} 
/*********************************************
function name:utc_page
description:����������ӽ��� 
input�� void
return�� 0(��½����) or 2(����Ա����)
*********************************************/
int utc_page(int *page)
{
	station alltracks[5][5]={{{1,"�Ӵ�����"},{2,"�Ƽ�¥"},{3,"��е��"},{4,"��һ¥"},{5,"����ѧԺ"}},
							{{1,"ͼ���"},{2,"��һ¥"},{3,"ע������"},{4,"��Ӱ��"},{5,"�����"}},
							{{1,"����¥"},{2,"����¥"},{3,"����Сѧ"},{4,"�Ƽ�¥"},{5,"ͼ���"}},
							{{1,"����¥"},{2,"����¥"},{3,"��һ��"},{4,"�����"},{5,"���ڼ���"}},
							{{1,"��е��"},{2,"��������"},{3,"�̹�����"},{4,"������"},{5,"����ѧԺ"}}};
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
				return 2;
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
							i=11; 
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
					return 11;
				}
			}
		}
		else
		{
			MouseS=0;
		}
	}
}
/**************************************
function name:ad_search
description:����Ա��ѯ��Ӧ��Ϣ
input��char *idnum
return 0(�޴��û���Ϣ�� or 1�����ҳɹ��� 
**************************************/
int ad_search(char* idnum)
{
	char name[15];
	char path[30]="C:\\mine\\track\\";
	int i;
	FILE* fp=NULL;
	const char* temp="t.txt";
	memset(name,'\0',sizeof(name));
	for(i=0;i<7;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp);
	strcat(path,name);
	if((fp=fopen(path,"r"))==NULL)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
} 
