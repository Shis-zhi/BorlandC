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
description:显示各车路线界面 
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
	puthz(40,100,"一号",32,40,DARKGRAY);
	puthz(160,100,"二号",32,40,DARKGRAY);
	puthz(280,100,"三号",32,40,DARKGRAY);
	puthz(400,100,"四号",32,40,DARKGRAY);
	puthz(520,100,"五号",32,40,DARKGRAY);
	puthz(0,5,"登录",16,20,DARKGRAY);
	puthz(500,405,"返回",16,20,DARKGRAY);
	puthz(300,405,"查询",16,20,DARKGRAY);
}
/**********************************
function name:  user_page
description：显示各车路线功能 
input: void 
return: 0(登陆界面)or 
***********************************/
int alltrack_page()
{
 	char track[4];
 	int flag=0;
	int i;//用于存放此界面对应的值 
 	FILE* fp=NULL;
	memset(track,'\0',sizeof(track));
 	alltrack_screen();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
 		if(mouse_press(0,0,40,30))//登录 
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
		else if(mouse_press(500,405,540,430))//返回 
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
						puthz(50,0,"打开文件时出错",16,17,RED);
						clrmous(MouseX,MouseY);
						delay(2000);
						closegraph();
						exit(1);
					}				
				}
				else if(flag==0)
				{
					puthz(150,200,"请点击选择车次",32,40,GREEN);
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
