#ifndef _mouse_h_
#define _mouse_h_

int mouse_press(int x1, int y1, int x2, int y2);//判断一个矩形内鼠标的点击状态
void mouse(int,int);//绘制鼠标 
void mouseinit(void);//初始化鼠标 
void mread(int *,int *,int*);//读取寄存器变量
void save_bk_mou(int x,int y);//保存鼠标覆盖的背景
void clrmous(int x,int y);//清除鼠标
void drawmous(int x,int y);//画鼠标 
void newmouse(int *nx,int *ny,int *nbuttons);   //更新鼠标状态

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;

#endif






//void mou_pos(int*,int*,int*);//鏇存敼榧犳爣浣嶇疆
