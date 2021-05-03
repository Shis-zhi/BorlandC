#include"public.h"
#include"operation.h"
/***************************************
operation.h
copyroght:shishengzhi
date:2021/2/17
***************************************/

/******************************************
function name: WritetoUser 
description:将某用户数据写入对应文档 
input: user temp 
return: void
*******************************************/
void WritetoUser(user temp)
{
	FILE* file;
	char idnum[19];
	char path[30]="C:\\mine\\info\\";
    char name[15];
    char info[21]; 
	char temp1[]=".txt";
	int health=0;
    int i;
    memset(name,'\0',sizeof(name)); 
    memset(idnum,'\0',sizeof(idnum)); 
    memset(info,'\0',sizeof(info));
    strcpy(idnum,temp.idnum);//防止temp.idnum改变 
	for(i=0;i<8;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp1);
	strcat(path,name);
	info[0]='0';//初始健康状态为正常
	for(i=0;i<19;i++)
	{
		info[i+1]=idnum[i];
	} 
	if((file = fopen(path,"wt+")) == NULL)//用w+打开，可以不用新建空文件
	{
		printf("%s\n",idnum);
		printf("%s",name);
		delay(2000);
		exit(1);
	}
	else 
	{
		fprintf(file,"%s %s %s %c",temp.idnum,temp.password,temp.phonenum,&temp.health);
		fclose(file);
		file=NULL;
	}
	if((file=fopen("C:\\mine\\info\\healinfo.txt","at+"))!=NULL)
	{
		fprintf(file,"%s\n",info);
		fclose(file);
	}
	else
	{
		delay(2000);
		exit(1);
	}
}

/******************************************
function name: WritetoAdmin 
description:将某管理员数据写入对应文件
input: admin temp 
return: void
*******************************************/
void WritetoAdmin(admin temp)
{
	FILE* file;
	char idnum[19];
	char name[15];
	memset(idnum,'\0',sizeof(idnum));
	memset(name,'\0',sizeof(name));
	strcpy(idnum,temp.idnum);
	if(strlen(idnum)!=6)
	{
		transform_id(idnum);
	}
	strcpy(name,inf_handle(idnum));
	if((file = fopen(name,"w+")) == NULL)//用w+打开，可以不用新建空文件
	{
		
		printf("%s\n",idnum);
		printf("%s",name);
		delay(2000); 
		exit(1);
	}
	else
	{
		fprintf(file,"%s %s %s\n",temp.idnum,temp.password,temp.phonenum);
		fclose(file);
	}
}
/*********************************************
function name: tranform_id
description: 用于对管理员身份证号进行处理
input: char *idnum
return: char *idnum1 
*********************************************/
char* transform_id(char *idnum)
{
	char temp[21];
	int a = strlen(idnum);
	int i;
	memset(temp,'\0',sizeof(temp));
	if(a == 18)
	{
		strcat(idnum,"00");
		return idnum;
	}
	else if(a == 20)
	{
		for(i=0;i<18;i++)
		{
			temp[i] = idnum[i];
		}
		return temp;
	}
}
/*****************************************
function name:get_pin
descroption:由身份证号获取验证码
input：char*idnum
return: char*pin 
*****************************************/ 
char* get_pin(char* idnum)
{
	int i;
	char pin[7];
	memset(pin,'\0',sizeof(pin)); 
	for(i=0;i<6;i++)
	{
		pin[i] = idnum[12+i];
	}
	return pin;
}
/***************************************************** 
function name:inf_handle
description: 由身份证号生成对应文件名,用于储存乘客信息 
input： char* idnum
return: char* path 
*****************************************************/
char* inf_handle(char* idnum)
{
	char temp[15];
	int i; 
	const char* temp1=".txt";
	memset(temp,'\0',sizeof(temp));
	for(i=0;i<8;i++)
	{
		temp[i]=idnum[i+10];
	}
	strcat(temp,temp1);
	return temp; 
}
/************************************************************* 
function name:track_handle
description:由身份证号生成对应文件名，用于储存某乘客的出行信息 
input：char* idnum 
return char* path
*************************************************************/
char* track_handle(char* idnum)
{
	char temp[25];
	char* temp1="t.txt"; 
	int i;
	memset(temp,'\0',sizeof(temp)); 
	for(i=0;i<8;i++)
	{
		temp[i]=idnum[i+10];
	}
	strcat(temp,temp1);
	return temp;
}
/*********************************************************** 
function name:input_num
description:从键盘接收输入的字符并将其显示在对应位置
			需要调用此函数输入并显示身份证号，手机号及验证码
input： char* idnum,int size,int x,int y
return： void
************************************************************/ 
void input_num(char* num,int size,int x,int y) 
{
	int i = 0;//用于计数 
	int ch;//存放键值 
	char temp[2] = {'\0','\0'};//第一位用于存放ch对应字符
	while (bioskey(1) != 0)
	{
		getch();
	}
	while(1)
	{
		ch = bioskey(0);
		num[i] = get_key(ch);
		if (num[i] == '\0' && ch != 0xe08)
		{ 
			clrmous(MouseX,MouseY); 
			break;
		}
		if(ch != 0x0e08 )
		{
			if(get_num(ch)==0)//避免误输入除数字和X外的字符
			{
				continue;
			}
			temp[0]= num[i];
			settextstyle(1,0,1);
			outtextxy(x+10*(i+1),y,temp);//显示此数字
			i++;
		}
		else if(ch == 0x0e08 && i>=1)
		{
			num[i-1] = '\0';
			setfillstyle(SOLID_FILL,WHITE);
			bar(x+10*i,y,x+10*(i+1),y+30);
			i--;
		}
		else
		{
			continue;
		}
		if(i>=size-1)//数组num最多有size位且最后一位为'\0'，防止溢出
		{
			break;
		}
	}	
}
/***********************************************************
function name:input_password
description:从键盘接收输入的字符并在相应位置显示圆点 
input: char* password,int size,int x,int y
return： void
************************************************************/

void input_password(char* password,int size,int x,int y)
{
	int i = 0;//用于计数 
	int ch;//存放键值 
	while(bioskey(1) != 0)
	{
		getch();
	}
	while(1) 
	{
		ch = bioskey(0);
		password[i] = get_key(ch);
		if (password[i] == '\0' && ch != 0xe08)
			break;
		if(ch != 0x0e08 )
		{
			if(((password[i] >= '0'&&password[i] <= '9')||
				(password[i] >= 'a'&&password[i] <= 'z')||
				(password[i] >= 'A'&&password[i] <= 'Z'))==0)//避免误输入除数字及字母外的字符
			{
				continue;
			}
			setcolor(BLUE);
			circle(x+5+20*(i+1),y+20,10);
			setfillstyle(1,BLUE);//深蓝纯色填充
			floodfill(x+5+20*(i+1),y+20,BLUE);
			i++;
		}
		else if(ch == 0x0e08 && i>=1)
		{
			setfillstyle(SOLID_FILL,WHITE);
			password[i-1] = '\0';
			bar(x-5+20*i,y,x+20*(i+1)-5,y+30);//遮盖最后一个数字 
			i--;
		} 
		else
		{
			continue;
		} 
		if(i>=size-1)//数组password一共有size位，防止溢出 
		{
			break;
		}
	} 
}
/*******************************************************************************
function name:menu_screen
description:绘制下拉菜单 
input: station alltracks[5][5].int x1,int y1,int x2,int y2,int m, int n,int size
return: void
*******************************************************************************/
void menu_screen(char s[5][10],int x1,int y1,int x2,int y2,int m,int n,int size)
{
	int i;
	int j;
	int width=y2-y1;
	setfillstyle(SOLID_FILL,WHITE);	
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	for(i=m,j=0;j<n;i++,j++)
	{
		bar(x1,y1+width*j+N,x2,y2+width*j);
		puthz(x1+5,y1+width*j+5,s[i],size,size*5/4,DARKGRAY);
	}
}
