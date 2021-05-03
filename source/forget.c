#include"public.h"
#include"forget.h" 
/********************
copyright:shishengzhi
date:2021/2/6 
*********************/

/*****************************
function name: forget_screen
description: ���������������
input�� void
return��void 
******************************/ 
void forget_screen()//��������������� 
{ 
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	puthz(100,110,"���֤��",16,17,WHITE);
	puthz(120,190,"������",16,17,WHITE);
	puthz(100,270,"�ظ�����",16,17,WHITE);
	puthz(120,350,"��֤��",16,17,WHITE);
	puthz(120,40,"�������޸�����",32,55,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(190,100,450,150);
	bar(190,180,450,230);
	bar(190,260,450,310);
	bar(190,340,450,390);
	setfillstyle(SOLID_FILL,RED);
	bar(10,410,10+80,410+40);
	puthz(20,420,"����",32,30,WHITE);
	bar(540,410,540+80,410+40);
	puthz(550,420,"ȷ��",32,30,WHITE);
}

/**********************************
functio name : forget_page
description:����������漰��ع��� 
input: void
return: 0(��¼����)
**********************************/ 
int forget_page()
{
	int i;
	int n;
	char idnum[21];
	char new_pass[20];
	char temp[20];//����ظ���������� 
	char phonenum[12]; 
	char pin[7];//����û���������� 
	char path[30]="C:\\mine\\info\\"; 
	char name[15];
	char temp3[]=".txt";
	user temp1;
	admin temp2;
	FILE* fp=NULL;

	forget_screen();
	memset(idnum,'\0',sizeof(idnum));
	memset(phonenum,'\0',sizeof(phonenum));
	memset(new_pass,'\0',sizeof(new_pass));
	memset(temp,'\0',sizeof(temp));
	memset(pin,'\0',sizeof(pin));
	memset(name,'\0',sizeof(name));
	clrmous(MouseX,MouseY);

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(10,410,10+80,410+40))
		{
			if(mouse_press(10,410,10+80,410+40) == 2)
			{
				MouseS = 1;//����
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
				MouseS = 2;//���
			}
			else if(mouse_press(190,100,450,150) == 1)
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,100,450,150);
				input_num(idnum,sizeof(idnum),195,105);
			}
		}
		else if(mouse_press(190,180,450,230)) //���λ��������һ��
		{
			if(mouse_press(190,180,450,230) == 2)//δ����
			{
				MouseS = 2;//�����̬�����
			}
			else if(mouse_press(190,180,450,230) == 1)//�������
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,180,450,230);
				input_password(new_pass,sizeof(new_pass),195,185);
				if(judge_password(new_pass)==0)
				{
					puthz(190,160,"���벻��С����λ",16,17,RED);
					clrmous(MouseX,MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(190,160,350,180); 
					continue;
				} 
			}
		}
		else if(mouse_press(190,260,450,310)) //���λ���ظ�����һ��
		{
			if(mouse_press(190,260,450,310) == 2)//δ����
			{
				MouseS = 2;//�����̬�����
			}
			else if(mouse_press(190,260,450,310) == 1)//�������
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,260,450,310);
				input_password(temp,sizeof(temp),195,265);
			}
		}
		else if(mouse_press(190,340,450,390)) //���λ����֤��һ��
		{
			if(mouse_press(190,340,450,390) == 2)//δ����
			{
				MouseS = 2;//�����̬�����
			}
			else if(mouse_press(190,340,450,390) == 1)//�������
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(190,340,450,390);
				input_num(pin,sizeof(pin),195,345);
			}
		}
		else if(mouse_press(540,410,540+80,410+40))//���λ��ȷ��
		{
			if(mouse_press(540,410,540+80,410+40) == 2)
			{
				MouseS = 1;//����
			}
			else if(mouse_press(540,410,540+80,410+40) == 1)
			{
				i = judge_id(idnum);
				if(i==-1)
				{
					puthz(190,160,"���֤��λ������",16,17,WHITE);
					clrmous(MouseX, MouseY);
					delay(2000);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(190,160,350,180); 
					continue;
				}
				else
				{
					switch(forget_judge(idnum, pin))
					{
						case 1:
							for(n=0;n<8;n++)
							{
								name[n]=idnum[n+10];
							}
							strcat(name,temp3);
							strcat(path,name);
							if((fp=fopen(path,"rt+"))!=NULL)
							{
								fscanf(fp,"%s %s %s",temp1.idnum,temp1.password,temp1.phonenum);
								strcpy(temp1.password,new_pass);
								WritetoUser(temp1);
								puthz(190,160,"�޸ĳɹ�",16,17,WHITE);
								clrmous(MouseX,MouseY);
								delay(1500);
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(190,160,350,180);
								break;	
							}
							else
							{
								puthz(190,160,"�����ļ�ʱ��������",16,17,RED);
								delay(2000);
								clrmous(MouseX,MouseY);
								closegraph();
								exit(1); 
							}
						case 0:
							puthz(190,160,"���˺�δע��",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(190,160,350,180);
							break;
						case -1:
							puthz(190,160,"��֤�����",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(190,160,350,180);
							break;
					}
				}
			}
		}
	}
}
