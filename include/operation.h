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
  
void WritetoUser(user temp);//��ĳ�û�����д���Ӧ�ĵ� 
void WritetoAdmin(admin temp);//��ĳ����Ա����д���Ӧ�ļ� 
char* transform_id(char *idnum);//���ڶԹ���Ա���֤�Ž��д��� 
char* get_pin(char* idnum);//�����֤�Ż�ȡ��֤�� 
char* inf_handle(char* idnum);// �����֤�����ɶ�Ӧ�ļ���,���ڴ���˿���Ϣ 
char* track_handle(char* idnum);// �����֤�����ɶ�Ӧ�ļ��������ڴ���ĳ�˿͵ĳ�����Ϣ 
void input_num(char* num,int size,int x,int y);//�Ӽ��̽���������ַ���������ʾ�ڶ�Ӧλ�� 
void input_password(char* password,int size,int x,int y);//�Ӽ��̽���������ַ�������Ӧλ����ʾԲ�� 
void menu_screen(char s[5][10],int x1,int y1,int x2,int y2,int m,int n,int size);

#endif
