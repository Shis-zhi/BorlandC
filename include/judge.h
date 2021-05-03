#ifndef _JUDGE_H
#define _JUDGE_H


#include"operation.h"



int login_judge(char *idnum,char *password, int i);//查找是否有输入的身份证号如果有，判断密码使否与身份证号对应若没有，显示一条错误信息
int user_login(char *idnum,char *password);//用作login_judge的子函数 
int admin_login(char *idnum,char *password);//用作login_judge的子函数 
int forget_judge(char *idnum,char *pin);//查找是否有输入的身份证号  如果有，则判断验证码是否正确如果没有，显示一个错误消息
int register_judge(char* idnum);// 查找是否有输入的身份证号	如果有，显示一个错误消息
int judge_id(char* idnum);// 用作register_judge的子函数



#endif






//int user_forget(char *idnum, char *pin);
//int admin_forget(char *idnum, char *pin);
//int user_register(char* idnum);
//int admin_register(char* idnum);
