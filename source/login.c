#include"public.h" 
#include"login.h"

/************************************
login.c
copyright:shishengzhi
date: 2021/2/2 
************************************/ 

/******************************************
function name:login_screen
description: ���Ƶ�¼����
input��void
return: void 
******************************************/
void login_screen(void)
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY);
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,WHITE); 
	puthz(60,170,"���֤��",16,17,WHITE);
	puthz(100,270,"����",16,17,WHITE);
	puthz(60,40,"������ͨ�˿��г�ϵͳ",32,55,WHITE);
	bar(150,150,150+250,200);
	bar(150,250,150+250,300);
	setfillstyle(SOLID_FILL,RED);
	bar(440,160,440+110,160+40);
	bar(440,260,440+110,260+40);
	bar(120,350,120+80,350+30);
	bar(350,350,350+80,350+30);
	bar(550,0,550+50,0+30); 
	bar(0,0,0+50,0+30); 
	puthz(450+20,260,"ע��",32,30,BLUE);
	puthz(450+20,160,"��¼",32,30,BLUE); 
	puthz(130,360,"��������",16,17,WHITE);
	puthz(360,360,"�ο�ģʽ",16,17,WHITE);
	puthz(560,5,"����",16,17,WHITE); 
    puthz(10,5,"�˳�",16,17,WHITE);
}

/******************************************************************************************* 
function name:login_page 
description: ��¼���漰��ع���
input��void
return��1(��ͨ�û�����) or 2(����Ա����) or 3(ע��) or 4(��������) or 5(�ο�ģʽ) or 6(����) 

********************************************************************************************/
int login_page()
{
	int i;
	char idnum[19];
	char password[10];
	int temp;
	FILE* fp=NULL; 

	login_screen();
	
	memset(idnum, '\0',sizeof(idnum));
	memset(password, '\0',sizeof(password));
	clrmous(MouseX,MouseY);
	
	while(1)//ѭ�������Ļ״̬ 
	{ 
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(150,150,150+250,200))//���λ�����֤��һ��
		{
			if(mouse_press(150,150,150+250,200) == 2)//δ���� 
			{
				MouseS = 2;//�����̬����� 
			} 
			else if(mouse_press(150,150,150+250,200) == 1)//�������
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(150,150,150+250,200);
				input_num(idnum,sizeof(idnum),150,155);
			}
		}
		else if(mouse_press(150,250,150+250,300)) //���λ������һ��
		{
			if(mouse_press(150,250,150+250,300) == 2)//δ���� 
			{
				MouseS = 2;//�����̬����� 
			} 
			else if(mouse_press(150,250,150+250,300) == 1)//�������
			{
				clrmous(MouseX,MouseY); 
				setfillstyle(SOLID_FILL,WHITE);
				bar(150,250,150+250,300);
				input_password(password,sizeof(password),150,250);
			}
		}
		else if(mouse_press(440,160,440+110,160+40))//���λ�ڵ�¼ 
		{
			if(mouse_press(440,160,440+110,160+40) == 2)//δ���� 
			{
				MouseS = 1; 
			} 
			else if(mouse_press(440,160,440+110,160+40) == 1)//���������¼ѡ�� 
			{
				i = judge_id(idnum); 
				if (i==-1)
				{
					puthz(450,210,"�˺�λ������",16,17,RED);
					clrmous(MouseX, MouseY);
					delay(2000);
					setfillstyle(1,LIGHTGRAY);
					bar(440,200,440+110,200+50);//�ñ���ɫ������ʾ��Ϣ������  
					continue;
				}
				else if(i==0)
				{
					temp=user_login(idnum,password);
					switch(temp)
					{
						case 1:
							if((fp=fopen("c:\\mine\\info\\temp.txt","wt+"))!=NULL)
							{
								fprintf(fp,"%s",idnum);
								fclose(fp);
							}
							clrmous(MouseX, MouseY);
							delay(500); 
							closegraph();
							return 1;//�ɹ���¼�������û�����
						case 0:
							puthz(450,210,"δע��",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000); 
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break;
						case -1:
							puthz(450,210,"�������",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break; 
					}
				}
				else if(i==1)
				{
					temp=admin_login(idnum,password);
					switch(temp)
					{
						case 2:
							clrmous(MouseX, MouseY);
							delay(500); 
							closegraph();
							return 2;//�ɹ���¼���������Ա����
						case 0:
							puthz(450,210,"δע��",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000); 
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break;
						case -1:
							puthz(450,210,"�������",16,17,WHITE);
							clrmous(MouseX, MouseY);
							delay(2000);
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(450,210,530,230); 
							break; 
					}
				} 
			}
		}
		else if(mouse_press(440,260,440+110,260+40))//���λ��ע�� 
		{
			if(mouse_press(440,260,440+110,260+40) == 2)//δ���� 
			{
				MouseS=1;
			} 
			else if(mouse_press(440,260,440+110,260+40) == 1)//�������ע��ѡ��
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 3;//����ע�����
			}
		}
		else if(mouse_press(120,350,120+80,350+30))//���λ���������� 
		{
			if(mouse_press(120,350,120+80,350+30) == 2)//δ���� 
			{
				MouseS=1;
			} 
			else if(mouse_press(120,350,120+80,350+30) == 1)//���������������ѡ��
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 4;//���������������
			}
		}
		else if(mouse_press(350,350,350+80,350+30))//���λ���ο�ģʽ 
		{
			if(mouse_press(350,350,350+80,350+30) == 2)//δ���� 
			{
				MouseS=1;
			} 
			else if(mouse_press(350,350,350+80,350+30) == 1)//��������ο�ģʽѡ�� 
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 5;//�����ο�ģʽ 
			}
		}
		else if(mouse_press(550,0,550+50,0+30))//���λ�ڹ��� 
		{
			if(mouse_press(550,0,550+50,0+30) == 2)//δ����  
			{
				MouseS=1;
			}	 
			else if(mouse_press(550,0,550+50,0+30) == 1)//�����������
			{
				clrmous(MouseX, MouseY);
				delay(500); 
				closegraph();
				return 6;//������ڽ���
			}
		} 
		else if(mouse_press(0,0,50,30))
		{
			if(mouse_press(0,0,50,30)==2)
			{
				MouseS = 1;
			}
			else if(mouse_press(0,0,50,30)==1)
			{
				clrmous(MouseX,MouseY);
				closegraph();
				exit(0);
			}
		}
		else
		{
			MouseS=0;//�����̬����ͷ 
		} 
	}
}
