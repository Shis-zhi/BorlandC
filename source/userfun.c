#include"public.h" 
#include"userfun.h"

/************************************
userfun.c
copyight:gaomingjun
date:2021/3/2
************************************/
typedef struct
{
	int num;
	char* name;
}station;
/***********************************
function name:  user_screen
description:������ͨ�û��������
input�� void
return�� void 
***********************************/
void  user_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY);
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,GREEN);
	bar(160,160,480,240);
	bar(160,320,480,400);
	bar(0,0,40,30);
	puthz(200,180,"�����˳��켣",32,40,WHITE);
	puthz(200,340,"��ѯ�˳�����",32,40,WHITE);
	puthz(0,5,"ע��",16,20,WHITE);
	puthz(200,50,"��ͨ�û�����",32,40,WHITE);
} 
/**********************************
function name:  user_page
description����ͨ�û����漰����ع��� 
input: void 
return: 7(�����˳��켣����) or 8(��ѯ�˳��켣����) 
***********************************/
int user_page()
{
	FILE *fp;
	int i;
	char a;
	char idnum[19];
	char path[30]="C:\\mine\\info\\";
	char name[15];
	char temp1[]=".txt";
	user temp;
 	user *p=&temp; 
	user_screen();
	memset(idnum,'\0',sizeof(idnum));
	memset(name,'\0',sizeof(name));
	memset(p,'\0',sizeof(temp));
	if((fp=fopen("c:\\mine\\info\\temp.txt","rt"))!=NULL)
	{
		fscanf(fp,"%s",idnum);
		fclose(fp);
		for(i=0;i<8;i++)
		{
			name[i]=idnum[i+10];
		}
		strcat(name,temp1); 
		strcat(path,name);
		if((fp=fopen(path,"rt+"))!=NULL)
		{
			fscanf(fp,"%s %s %s %c",temp.idnum,temp.password,temp.phonenum,&temp.health);
			fclose(fp);
			a=temp.health;			
		}	
		else
		{
			clrmous(MouseX,MouseY);
			puthz(150,250,"���ļ�ʱ����",32,40,DARKGRAY);
			delay(2000);
			closegraph(); 
			exit(1);
		}	
	}
	else
	{
		clrmous(MouseX,MouseY);
		puthz(150,250,"���ļ�ʱ����",32,40,DARKGRAY);
		delay(2000);
		closegraph();
		exit(1);
	}
	if(a=='1')
		{
			clrmous(MouseX,MouseY);
			warn_screen1();
			while(1)
			{
				newmouse(&MouseX,&MouseY,&press);
				if(mouse_press(345,280,395,320))
				{
					if(mouse_press(345,280,395,320)==2)
					{
				
						MouseS=1;
					}
					else if(mouse_press(345,280,395,320)==1)
					{
						user_screen();
						a='0';
						break;
					}
				}
				else 
				MouseS=0;
			}
		}
	else if(a=='2')	
	{
		clrmous(MouseX,MouseY);
		warn_screen2();
		while(1)
		{
			newmouse(&MouseX,&MouseY,&press);
			if(mouse_press(345,280,395,320))
			{
				if(mouse_press(345,280,395,320)==2)
				{
					MouseS=1;
				}
				else if(mouse_press(345,280,395,320)==1)
				{
					user_screen();
					a='0';
					break;
				}
			}
		}
	}
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
				return 0;
			}
		}
		else if(mouse_press(160,160,480,240))
		{
			if(mouse_press(160,160,480,240)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(160,160,480,240)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 7;
			}
		}
		else if(mouse_press(160,320,480,400)) 
		{
			if(mouse_press(160,320,480,400)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(160,320,480,400)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 8;
			} 
		}
		else
		{
			MouseS=0;
		}
	} 
}  
/*********************
function name:warn_screen1
description:���ߵ�������
input:void
return:void
*************************/
void warn_screen1()
{
	clrmous(MouseX,MouseY);
	setfillstyle(SOLID_FILL,GREEN);
	bar(150,130,490,330);
	bar(345,280,395,320);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(150,130,490,330);
	rectangle(345,280,395,320);
	puthz(351,290,"ȷ��",16,20,BLUE);
	puthz(240,145,"��ܰ��ʾ",32,40,RED);
	puthz(170,185,"����ǰ����״���쳣������ʵ�ϱ�������",16,17,RED);
	puthz(170,210,"�˳��켣���Ծ����оӼҸ��룬����ʱ��",16,17,RED);
	puthz(170,235,"�йز����ϱ�����״������л��Ϊ������",16,17,RED);
	puthz(170,260,"���Ĺ��ס�",16,17,RED);
}
/*********************
function name:warn_screen2
description:���ߵ�������
input:void
return:void
*************************/
void warn_screen2()
{
	clrmous(MouseX,MouseY);
	setfillstyle(SOLID_FILL,GREEN);
	bar(150,130,490,330);
	bar(345,280,395,320);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(150,130,490,330);
	rectangle(345,280,395,320);
	puthz(351,290,"ȷ��",16,20,BLUE);
	puthz(240,145,"��ܰ��ʾ",32,40,RED);
	puthz(170,185,"��Ϊ���Ʋ������нӴ��ߣ����ϱ�������",16,17,RED);
	puthz(170,210,"�˳��켣���Ծ����оӼҸ��룬����ʱ��",16,17,RED);
	puthz(170,235,"�йز����ϱ�����״������л��Ϊ������",16,17,RED);
	puthz(170,260,"���Ĺ��ס�",16,17,RED);
}
