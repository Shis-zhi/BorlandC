#include"public.h"
#include"health.h"

/*******************************
admin_function.c
copyright:gaomingjun
date:2021/4/17
*******************************/

/***************************
function name: health_screen
description:绘制健康信息界面 
input： void
return: void
***************************/
void health_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	mouseinit();  
	clrmous(MouseX,MouseY); 
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,40,30);
	bar(160,320,480,380);
	bar(500,420,580,456); 
	bar(100,420,260,456);
	bar(300,420,460,456);
	puthz(200,330,"同步健康信息",32,40,WHITE);
	puthz(220,50,"健康信息界面",32,40,WHITE);
	puthz(0,5,"注销",16,20,WHITE);
	puthz(100,420,"标为健康",32,40,WHITE);
	puthz(300,420,"标为病例",32,40,WHITE);
	puthz(500,420,"返回",32,40,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	puthz(50,180,"身份证号",16,17,WHITE);
	bar(140,175,550,205);
}

/**************************************
function name:health_page
description:健康信息界面及其相关功能 
input： void
return： 0（登陆界面） or 2(管理员界面) 
 **************************************/
int health_page()
{
	int i,j;
 	FILE* fp=NULL;
 	char idnum[19];
	memset(idnum,'\0',sizeof(idnum));
 	health_screen();
 	while(1)
 	{
 		newmouse(&MouseX,&MouseY,&press);
 		if(mouse_press(0,0,40,30))//注销 
		{
			if(mouse_press(0,0,40,30)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(0,0,40,30)==1)
			{
				clrmous(MouseX,MouseY);
				closegraph();
				return 0;
			}
		}
		else if(mouse_press(500,420,580,456))//返回 
		{
			if(mouse_press(500,420,580,456)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(500,420,580,456)==1)
			{
				setfillstyle(SOLID_FILL,WHITE);
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return 2;
			}
		}
		else if(mouse_press(160,320,480,380))//同步健康信息 
		{
			if(mouse_press(160,320,480,380)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(160,320,480,380)==1)
			{
				sy_health(idnum); 
				puthz(140,225,"信息上传成功",16,17,RED);
				delay(1000);
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(140,225,550,250);	
			}
			else
			{
				MouseS=0;
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
				memset(idnum,'\0',sizeof(idnum));
				input_num(idnum,sizeof(idnum),140,175);
				i=judge_id(idnum);
				if(i!=0)
				{
					puthz(140,225,"身份证位数有误",16,17,RED);
					delay(1500);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(140,225,550,250);	
				}
				else
				{
					if(us_search(idnum)!=1)
					{
						puthz(140,225,"无此人信息",16,17,RED);
						delay(2000);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(140,225,550,250);	
					}
					else
					{
						j=1;
					} 
				}
			}
		} 
		else if((j==1)&&(mouse_press(300,420,460,456)))
		{
			if(mouse_press(300,420,460,456)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(300,420,460,456)==1)							
			{
				health_mark(idnum,'1');
				puthz(140,225,"信息上传成功",16,17,RED);
				delay(1000);
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(140,225,550,250);	
			} 
			else 
			{
				MouseS=0;
			}
		}
		else if((j==1)&&(mouse_press(100,420,260,456)))	
		{
			if(mouse_press(100,420,260,456)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(100,420,260,456)==1)
			{
				health_mark(idnum,'0');
				puthz(140,225,"信息上传成功",16,17,RED);	
				delay(1000);
				setfillstyle(SOLID_FILL,LIGHTGRAY);
				bar(140,225,550,250);
			}
			else 
			{
				MouseS=0;
			}			
		}	
		else
		{
			MouseS=0;
		}			
	}
}
/**************************************
function name:sy_health
description:同步健康信息
input:char *idnum
return void
**************************************/
void sy_health(char *idnum)
{
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	int i,j;
	int flag=0;
	char a,b,c,d;
	int m=0,n=0;
	user temp={"\0","\0","\0",'-1'};
	char name1[30]="c:\\mine\\info\\";
	char name2[30]="c:\\mine\\track\\";
	char *temp1=".txt";
	char *temp2="t.txt";
	char inf[4];
	char path[15];
	char info[10][21];
	char track[10][6];
	char id[19];

	memset(track,'\0',sizeof(track));
	memset(path,'\0',sizeof(path));
	memset(id,'\0',sizeof(id));
	memset(info,'\0',sizeof(info));
	memset(inf,'\0',sizeof(inf));

	for(i=0;i<8;i++)
	{
		path[i]=idnum[i+10];
	}
	strcat(path,temp1);
	strcat(name1,path);
	fp=fopen(name1,"rt");
	fscanf(fp,"%s %s %s %c",temp.idnum,temp.password,temp.phonenum,&temp.health);
	fclose(fp);
	if(temp.health=='1')
	{
		memset(path,0,sizeof(path));
		for(i=0;i<7;i++)
		{
			path[i]=idnum[i+10];
		}
		strcat(path,temp2);
		strcat(name2,path);
		fp1=fopen(name2,"rt");
		for(i=0;i<10;i++)
		{
			if((fscanf(fp1,"%5s ",track[i]))==EOF)
			{
				fclose(fp1);
				break;
			}
		}
		for(j=0;j<i;j++)
		{
			inf[0]=track[j][0];
			inf[1]=track[j][1];
			inf[2]=track[j][2];
			a=track[j][3];
			b=track[j][4];
			strcpy(name2,"c:\\mine\\track\\");
			strcat(inf,temp1);
			strcat(name2,inf);
			fp2=fopen(name2,"rt");
			for(;n<10;n++)
			{
				if(fscanf(fp2,"%20s",info[n])==EOF)
				{
					fclose(fp2);
					break;
				}
			}
		}
		for(i=0;i<10;i++)
		{
			c=info[i][0];
			d=info[i][1];
			if(((a<=c)&&(b>=c))||((c<=a)&&(a<=d)))
			{
				for(j=0;j<19;j++)
				{
					id[j]=info[i][j+2];
				}
				health_mark(id,'2');
			}
		}
	}
}
/*************************
function name:health_mark
description:更改健康状态 
input：char *idnum，char a 
return: void 
**************************/
void health_mark(char* idnum,char a)
{
 	FILE *fp;
	char path[30]="C:\\mine\\info\\";
    char name[14];
	char temp1[]=".txt";
	int i; 
	user temp;
	memset(name,'\0',sizeof(name));
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
		fp=fopen(path,"wt+"); 
		temp.health=a;
		fprintf(fp,"%s %s %s %c",temp.idnum,temp.password,temp.phonenum,temp.health);
		fclose(fp);
	}
	else
	{
		delay(2000);
		exit(1);
	}
	health_change(idnum,a);
	info_handle();
}
/**************************************
function name:us_search
description:管理员查询乘客信息
input：char *idnum
return 0(无此用户信息） or 1（查找成功） 
**************************************/
int us_search(char* idnum)
{
	char name[15];
	char path[30]="C:\\mine\\info\\";
	int i;
	FILE* fp=NULL;
	const char* temp=".txt";
	memset(name,'\0',sizeof(name));
	for(i=0;i<8;i++)
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
		fclose(fp); 
		return 1;
	}
} 

/************************************************
function name: health_change
description: 将healinfo.txt中的健康状态改为指定值
input:char* idnum,char heal
return:void 
*************************************************/
 void health_change(char* idnum,char heal)
{
	FILE* fp=NULL;
	FILE* fp1=NULL;
	int i;
	char info[21];
	char id[19];
	memset(id,'\0',sizeof(id));
	memset(info,'\0',sizeof(info)); 
	if(((fp=fopen("C:\\mine\\info\\healinfo.txt","rt+"))!=NULL)&&
		((fp1=fopen("C:\\mine\\info\\heal.txt","wt+"))!=NULL))
	{
		while((fscanf(fp,"%s",info))!=EOF)
		{
			for(i=0;i<19;i++)
			{
				id[i]=info[i+1]; 
			}
			if(strcmp(id,idnum)==0)
			{
				info[0]=heal;
				fprintf(fp1,"%s\n",info);
			}
			else
			{
				fprintf(fp1,"%s\n",info);
			}
		}
		fclose(fp);
		fclose(fp1);
	}
	else
	{
		delay(2000);
		exit(1);
	}
	remove("C:\\mine\\info\\healinfo.txt");
	rename("C:\\mine\\info\\heal.txt","C:\\mine\\info\\healinfo.txt");
}
/******************************************************
function name:info_handle
description:将healinfo.txt中的确诊或风险信息存至对应文件
input：void
return： void
********************************************************/
void info_handle()
{
	FILE* fp1=NULL;
	FILE* fp2=NULL;
	FILE* fp3=NULL;
	char info[21];
	char id[19];
	int i;
	memset(info,'\0',sizeof(info));
	memset(id,'\0',sizeof(id));
	if(((fp1=fopen("C:\\mine\\info\\healinfo.txt","rt"))!=NULL)&&
		((fp2=fopen("C:\\mine\\info\\worse.txt","wt"))!=NULL)&&
		((fp3=fopen("C:\\mine\\info\\worst.txt","wt")))!=NULL)
	{
		while((fscanf(fp1,"%s",info))!=EOF)
		{
			for(i=0;i<19;i++)
			{
				id[i]=info[i+1];
			}
			if(info[0]=='1')
			{
				fprintf(fp3,"%s\n",id);
			}
			else if(info[0]=='2')
			{
				fprintf(fp2,"%s\n",id);
			}
			else
			{
				continue;
			}
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	}
	else
	{
		delay(2000);
		exit(1);
	}
}
