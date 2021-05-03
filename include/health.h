#ifndef _health_h
#define _health_h 

void health_screen();// 绘制健康信息界面
int health_page();//健康信息界面及其相关功能
void health_mark(char* idnum,char a);//更改健康信息 
void sy_health(char *idnum);//同步健康信息 
int us_search(char* idnum); 
void health_change(char* idnum,char heal);
void info_handle();
#endif 
