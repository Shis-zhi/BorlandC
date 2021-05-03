#include"public.h"
#include"judge.h"
/*********************
judge.c
copyright: shishengzhi
date :2021/2/11
*********************/

/*****************************************************************************
function name: login_judge
description: 查找是否有输入的身份证号
			如果有，判断密码使否与身份证号对应 
			若没有，显示一条错误信息 
input：char *idnum,char *password,int i(用于区分普通用户和管理员)
return：2(管理员成功登陆) or 1(普通用户成功登录) or 0(未注册) or -1（密码错误） 
******************************************************************************/
int login_judge(char *idnum,char *password,int i)
{
	int a;
	if(i == 0)
	{
		a = user_login(idnum,password);
	}
	else if(i == 1)
	{
		
		a = admin_login(idnum,password);
	}
	return a;
} 
/****************************************** 
function name: user_login
description:用作login_judge的子函数
input：char *idnum，char *password
return: 1(成功) or 0(未注册) or -1(密码错误) 
*******************************************/ 
int user_login(char *idnum,char *password) 
{
	user temp;
	FILE* fp=NULL;
	int i; 
	char path[30]="C:\\mine\\info\\"; 
	char name[15];
	char temp1[]=".txt";
	memset(name,'\0',sizeof(name));
	for(i=0;i<8;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp1);
	strcat(path,name);
	if((fp=fopen(path,"rt"))==NULL)
	{
		return 0;//如果运行至此说明文件中无此人信息
	}
	else
	{
		fscanf(fp,"%s %s %s",temp.idnum,temp.password,temp.phonenum);
		if(strcmp(password,temp.password)==0)
		{
			fclose(fp);
			return 1;
		}
		else
		{
			fclose(fp);
			return -1;
		}
	}
}

/******************************************
function name: admin_login
description:用作login_judge的子函数
input：char *idnum，char *password
return: 2(成功) or 0(未注册) or -1(密码错误)
*******************************************/
int admin_login(char *idnum,char *password)
{
	admin temp;
	FILE* fp=NULL;
	int i;

	if((fp=fopen("c:\\mine\\info\\admin.txt","rt"))==NULL)
	{
		return 0;//如果运行至此说明文件中无此人信息
	}
	else
	{
		fscanf(fp,"%s %s %s",temp.idnum,temp.password,temp.phonenum);
		if(strcmp(password,temp.password)==0)
		{
			fclose(fp);
			return 2;
		}
		else
		{
			fclose(fp);
			return -1;
		}
	}
}
/*******************************************************************************
function name:forget_judge
description: 查找是否有输入的身份证号
			如果有，则判断验证码是否正确
			如果没有，显示一个错误消息
input：char *idnum，char *pin,int i
return：1(均正确,普通用户) or 0(未注册) or -1(验证码错误)
*********************************************************************************/

int forget_judge(char *idnum, char *pin)
{
	FILE* fp=NULL;
	char path[30]="C;\\mine\\info\\";
	char name[15];
	char num[7];//用于存放验证码
	char temp1[]=".txt";
	int i; 
	
	memset(name,'\0',sizeof(name));
	memset(num,'\0',sizeof(num)); 
	for(i=0;i<8;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp1);
	strcat(path,name);
	for(i=0;i<6;i++)
	{
		num[i]=idnum[12+i];
	}

	if(strcmp(pin,num)==0)
	{
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
	else
	{
		return -1;
	}
}
/************************************************************************
function name: register_judge
description:查找是否有输入的身份证号
			如果有，显示一个错误消息
input: char* idnum,int i
return: 0(文件中有输入的身份证号) or 1(文件中没有对应的身份证号)
************************************************************************/
int register_judge(char* idnum)
{
	FILE* fp=NULL;
	char path[30]="C:\\mine\\info\\";
	char name[15];
	char temp1[]=".txt";
	int i; 
	memset(name,'\0',sizeof(name));
	for(i=0;i<8;i++)
	{
		name[i]=idnum[i+10];
	}
	strcat(name,temp1);
	strcat(path,name);
	if((fp=fopen(path,"rt"))==NULL)
	{
		return 1;//如果运行至此说明无此人信息
	}
	else
	{
		fclose(fp);
		return 0;
	} 
}
/*****************************************************
function name:judge_id
description:通过输入判断是普通用户还是管理员
input： char* idnum
return: 0(普通用户) or 1(管理员) or -1(身份证位数有误)
*****************************************************/
int judge_id(char* idnum)
{
	int len = strlen(idnum);
	if(len == 18)
	{
		return 0;
	}
	else if(len == 6)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
/*******************************************************
function name:judge_password
description:通过输入判断密码是否符合规范(长度不小于六位)
input：char* password
return: 1(符合规范) or 0(不符合规范) 
********************************************************/
int judge_password(char* password)
{
	int i;
	i=strlen(password);
	if(i<6)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
} 
