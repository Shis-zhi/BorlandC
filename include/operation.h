#ifndef _OPERATION_H
#define _OPERATION_H
#define N 2
typedef struct
{
	char idnum[19];
	char password[10];
	char phonenum[12];
	char health;
 } user;
 
 typedef struct
{
	char idnum[7];
	char password[10];
	char phonenum[12];
 } admin;
  
void WritetoUser(user temp);//将某用户数据写入对应文档 
void WritetoAdmin(admin temp);//将某管理员数据写入对应文件 
char* transform_id(char *idnum);//用于对管理员身份证号进行处理 
char* get_pin(char* idnum);//由身份证号获取验证码 
char* inf_handle(char* idnum);// 由身份证号生成对应文件名,用于储存乘客信息 
char* track_handle(char* idnum);// 由身份证号生成对应文件名，用于储存某乘客的出行信息 
void input_num(char* num,int size,int x,int y);//从键盘接收输入的字符并将其显示在对应位置 
void input_password(char* password,int size,int x,int y);//从键盘接收输入的字符并在相应位置显示圆点 
void menu_screen(char s[5][10],int x1,int y1,int x2,int y2,int m,int n,int size);

#endif
