#include"public.h" 
#include"alltrack.h"
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
description:��ʾ����·�߽��� 
input: void
return: void
*************************/
void alltrack_screen() 
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit(); 
	clrmous(MouseX,MouseY);
	setbkcolor(RED);
	setfillstyle(SOLID_FILL,GREEN);
	bar(40,100,120,140);
	bar(160,100,240,140);
	bar(280,100,360,140);
	bar(400,100,480,140);
	bar(520,100,600,140);
	bar(0,5,40,30);
	bar(500,405,540,430);
	bar(300,400,340,430);
	puthz(40,100,"һ��",32,40,DARKGRAY);
	puthz(160,100,"����",32,40,DARKGRAY);
	puthz(280,100,"����",32,40,DARKGRAY);
	puthz(400,100,"�ĺ�",32,40,DARKGRAY);
	puthz(520,100,"���",32,40,DARKGRAY);
	puthz(0,5,"��¼",16,20,DARKGRAY);
	puthz(500,405,"����",16,20,DARKGRAY);
	puthz(300,405,"��ѯ",16,20,DARKGRAY);
}
/**********************************
function name:  user_page
description����ʾ����·�߹��� 
input: void 
return: 0(��½����)or 
***********************************/
int alltrack_page()
{
 	char track[4];
 	int flag=0;
	int i;//���ڴ�Ŵ˽����Ӧ��ֵ 
 	FILE* fp=NULL;
	memset(track,'\0',sizeof(track));
 	alltrack_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
 		if(mouse_press(0,0,40,30))//��¼ 
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
		else if(mouse_press(500,405,540,430))//���� 
		{
			if(mouse_press(500,405,540,430)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,405,540,430)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 5;
			}
		}
		else if(mouse_press(40,100,120,140))
 		{
 			if(mouse_press(40,100,120,140)==2)
 			{
				MouseS=1;
			}
 			else if(mouse_press(40,100,120,140)==1)
 			{
 				memset(track,'\0',sizeof(track));
 				clrmous(MouseX,MouseY);
 				strcpy(track,"115");
 				flag=1;
 			}
 		}
 		else if(mouse_press(160,100,240,140))
 		{
 			if(mouse_press(160,100,240,140)==2)
 			{
				MouseS=1;
			}
 			else if(mouse_press(160,100,240,140)==1)
 			{
 				memset(track,'\0',sizeof(track));
 				clrmous(MouseX,MouseY);
 				strcpy(track,"215");
 				flag=1;
 			}
		}
		else if(mouse_press(280,100,360,140))
 		{
 			if(mouse_press(280,100,360,140)==2)
 			{	
				MouseS=1;
			}
 			else if(mouse_press(280,100,360,140)==1)
 			{
 				memset(track,'\0',sizeof(track));
 				clrmous(MouseX,MouseY);
 				strcpy(track,"315");
 				flag=1;
 			}
		}	
		else if(mouse_press(400,100,480,140))
 		{
 			if(mouse_press(400,100,480,140)==2)
 			{
				MouseS=1;
			}
 			else if(mouse_press(400,100,480,140)==1)
 			{
 				memset(track,'\0',sizeof(track));
 				clrmous(MouseX,MouseY);
 				strcpy(track,"415");
 				flag=1;
 			}
		}
 		else if(mouse_press(520,100,600,140))
 		{
 			if(mouse_press(520,100,600,140)==2)
 			{
				MouseS=1;
			}
 			else if(mouse_press(520,100,600,140)==1)
 			{
 				memset(track,'\0',sizeof(track));
 				clrmous(MouseX,MouseY);
				strcpy(track,"515");
				flag=1;
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
 				if(flag==1)
 				{
					if((fp=fopen("C:\\mine\\info\\show.txt","wt+"))!=NULL)
 					{
 						i=14;
 						fprintf(fp,"%s %d",track,i);
						fclose(fp);
						clrmous(MouseX,MouseY);
						closegraph(); 
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
				else if(flag==0)
				{
					puthz(150,200,"����ѡ�񳵴�",32,40,GREEN);
					delay(1000);
					setfillstyle(SOLID_FILL,RED);
					bar(150,200,640,250);	
				}
			}
		}
		else
		{
			MouseS=0;
		}
	} 					
}
