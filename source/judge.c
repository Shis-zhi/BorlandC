#include"public.h"
#include"judge.h"
/*********************
judge.c
copyright: shishengzhi
date :2021/2/11
*********************/

/*****************************************************************************
function name: login_judge
description: �����Ƿ�����������֤��
			����У��ж�����ʹ�������֤�Ŷ�Ӧ 
			��û�У���ʾһ��������Ϣ 
input��char *idnum,char *password,int i(����������ͨ�û��͹���Ա)
return��2(����Ա�ɹ���½) or 1(��ͨ�û��ɹ���¼) or 0(δע��) or -1��������� 
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
description:����login_judge���Ӻ���
input��char *idnum��char *password
return: 1(�ɹ�) or 0(δע��) or -1(�������) 
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
		return 0;//�����������˵���ļ����޴�����Ϣ
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
description:����login_judge���Ӻ���
input��char *idnum��char *password
return: 2(�ɹ�) or 0(δע��) or -1(�������)
*******************************************/
int admin_login(char *idnum,char *password)
{
	admin temp;
	FILE* fp=NULL;
	int i;

	if((fp=fopen("c:\\mine\\info\\admin.txt","rt"))==NULL)
	{
		return 0;//�����������˵���ļ����޴�����Ϣ
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
description: �����Ƿ�����������֤��
			����У����ж���֤���Ƿ���ȷ
			���û�У���ʾһ��������Ϣ
input��char *idnum��char *pin,int i
return��1(����ȷ,��ͨ�û�) or 0(δע��) or -1(��֤�����)
*********************************************************************************/

int forget_judge(char *idnum, char *pin)
{
	FILE* fp=NULL;
	char path[30]="C;\\mine\\info\\";
	char name[15];
	char num[7];//���ڴ����֤��
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
description:�����Ƿ�����������֤��
			����У���ʾһ��������Ϣ
input: char* idnum,int i
return: 0(�ļ�������������֤��) or 1(�ļ���û�ж�Ӧ�����֤��)
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
		return 1;//�����������˵���޴�����Ϣ
	}
	else
	{
		fclose(fp);
		return 0;
	} 
}
/*****************************************************
function name:judge_id
description:ͨ�������ж�����ͨ�û����ǹ���Ա
input�� char* idnum
return: 0(��ͨ�û�) or 1(����Ա) or -1(���֤λ������)
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
description:ͨ�������ж������Ƿ���Ϲ淶(���Ȳ�С����λ)
input��char* password
return: 1(���Ϲ淶) or 0(�����Ϲ淶) 
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
