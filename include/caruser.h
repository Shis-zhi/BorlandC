#ifndef _caruser_h
#define _caruser_h


#include"search.h"

void caruser_screen();//���ݳ��β�ѯ��Ӧ�˿���Ϣ 
int caruser_page();//��������Ĺ��ܺ��� 
void ctu_screen();
int ctu_page(int* page);
void tracksearch(char number[],int x1,int x2,int y,char info[][21],int* page);
int user_count(char track[4]); 

typedef struct
{
	int num;
	char* name;
}station;

#endif 
