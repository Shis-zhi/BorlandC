#ifndef _mouse_h_
#define _mouse_h_

int mouse_press(int x1, int y1, int x2, int y2);//�ж�һ�����������ĵ��״̬
void mouse(int,int);//������� 
void mouseinit(void);//��ʼ����� 
void mread(int *,int *,int*);//��ȡ�Ĵ�������
void save_bk_mou(int x,int y);//������긲�ǵı���
void clrmous(int x,int y);//������
void drawmous(int x,int y);//����� 
void newmouse(int *nx,int *ny,int *nbuttons);   //�������״̬

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;

#endif






//void mou_pos(int*,int*,int*);//更改鼠标位置
