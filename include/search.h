#ifndef _search_h
#define _search_h

void searchtrack_screen();//���Ʋ�ѯ�˳��켣���� 
int searchtrack_page(int *page);//��ѯ�˳��켣���漰����ع��� 
void  usersearch(char* idnum,int x1,int x2,int x3,int x4,char track[][6],int *page); 

typedef struct
{
	int num;
	char* name;
}station;

#endif 
