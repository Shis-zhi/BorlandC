#ifndef healinfo_h_
#define healinfo_h_

void healinfo_screen(int* choice);
int healinfo_page(int* choice,int* page);
int info_count(int* choice);
void heal_info(int* state,int x1,int x2,int y,char info[][21],int* page);

#endif 
