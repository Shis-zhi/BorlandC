#ifndef _JUDGE_H
#define _JUDGE_H


#include"operation.h"



int login_judge(char *idnum,char *password, int i);//�����Ƿ�����������֤������У��ж�����ʹ�������֤�Ŷ�Ӧ��û�У���ʾһ��������Ϣ
int user_login(char *idnum,char *password);//����login_judge���Ӻ��� 
int admin_login(char *idnum,char *password);//����login_judge���Ӻ��� 
int forget_judge(char *idnum,char *pin);//�����Ƿ�����������֤��  ����У����ж���֤���Ƿ���ȷ���û�У���ʾһ��������Ϣ
int register_judge(char* idnum);// �����Ƿ�����������֤��	����У���ʾһ��������Ϣ
int judge_id(char* idnum);// ����register_judge���Ӻ���



#endif






//int user_forget(char *idnum, char *pin);
//int admin_forget(char *idnum, char *pin);
//int user_register(char* idnum);
//int admin_register(char* idnum);
