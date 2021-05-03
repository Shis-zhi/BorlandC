#ifndef _search_h
#define _search_h

void searchtrack_screen();//绘制查询乘车轨迹界面 
int searchtrack_page(int *page);//查询乘车轨迹界面及其相关功能 
void  usersearch(char* idnum,int x1,int x2,int x3,int x4,char track[][6],int *page); 

typedef struct
{
	int num;
	char* name;
}station;

#endif 
