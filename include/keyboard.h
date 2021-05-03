#ifndef _keyboard_h
#define _keyboard_h

typedef struct
{
	int value;
	char ch;
}setKeyValue;

char get_key(int value);//从键盘获取输入的字符 
char get_num(int value);//从键盘获取输入的数字和X（用于身份证号的输入） 

#endif
