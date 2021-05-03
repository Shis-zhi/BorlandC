#ifndef _usercar_h
#define _usercar_h

#include"judge.h"
#include"search.h"
void usercar_screen();//根据乘客身份证号查询对应乘车信息  
int usercar_page(); //上述界面的相关功能
void utc_screen();
int utc_page(int* page); 
int ad_search(char* idnum); 
#endif 
