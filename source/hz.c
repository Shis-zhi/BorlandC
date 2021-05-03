#include <graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hz.h"
/******************************************************
function name:puthz
description :在图形化界面的指定位置输出指定字符串 
input： int x,int y,char *s,int flag,int part,int color
		(x,y为位置坐标，s为字符串首地址，
		flag为格式，part为距离，color为颜色)
return: void 
*******************************************************/ 
void puthz(int x, int y,char *s,int flag,int part,int color)
{
	FILE *hzk_p=NULL;                                    
	unsigned char quma,weima;                 
	unsigned long offset;                     
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  
	int i,j,pos;


	switch(flag)    
	{
		case 16 :
				  {
					char mat[32];   
					int y0=y;
					int x0=x;
					hzk_p = fopen("HZK\\HZ16","rb");           
					if(hzk_p==NULL)
					{
						settextjustify(LEFT_TEXT,TOP_TEXT);         
						settextstyle(GOTHIC_FONT,HORIZ_DIR,1);				
						outtextxy(10,10,"Can't open hzk16 file!Press any key to quit...");
						getch();
						exit(1);
					}
					while(*s!=NULL)
					{
						while (x<640-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                     
							weima=s[1]-0xa0;                    
							offset=(94*(quma-1)+(weima-1))*32L;  
							fseek(hzk_p,offset,SEEK_SET);       
							fread (mat,32,1,hzk_p);          

							for(i=0;i<16;i++)
							{
								pos=2*i;       
								for(j=0;j<16;j++)    
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   
									{
										putpixel(x+j,y,color);

									}

								}
								y++;
							}
							
							x+=part;       
							s+=2;           
						}
						x=x0;y0+=flag+10; 
					}
					break;
				 }


		case 24 :
				  {
					char mat[72];   
					 int y0=y;
					 int x0=x;
					hzk_p = fopen("HZK\\Hzk24k","rb");
					if (hzk_p==NULL)
					{
						settextjustify(LEFT_TEXT,TOP_TEXT);         
						settextstyle(GOTHIC_FONT,HORIZ_DIR,3);					
						outtextxy(10,10,"Can't open hzk24 file!Press any key to quit...");
						getch();
						exit(1);

					}
					while(*s!=NULL)
					{
						while(x<640-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                     
							weima=s[1]-0xa0;                    
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,72,1,hzk_p);
							for (i=0;i<24;i++)
							{
								pos=3*i;   
								for (j=0;j<24;j++)   
								{
									if ((mask[j%8]&mat[pos+j/8])!=NULL)
										putpixel(x+j,y,color);

								}
								y++;

							}
							x+=part;
							s+=2;
						}
						x=x0;y0+=flag+10;
					}
						break;
				}

		case 32 :
				  {
					 char mat[128];  
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZK32S","rb");
					 if(hzk_p==NULL)
					 {
						settextjustify(LEFT_TEXT,TOP_TEXT);       
						settextstyle(GOTHIC_FONT,HORIZ_DIR,3);									
						outtextxy(10,10,"Can't open hzk32 file!Press any key to quit...");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<640-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                
							weima=s[1]-0xa0;            
							offset=(94*(quma-1)+(weima-1))*128L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,128,1,hzk_p);
							for(i=0;i<32;i++)
							{
								pos=4*i;      
								for(j=0;j<32;j++)
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)
									{
										putpixel(x+j,y,color);

									}

								}
								y++;


							}
							
							x+=part;  
							s+=2;         

						}
						x=x0;y0+=flag+10;   
					}
						break;

				 }


		case 48:
				  {
					char mat[288];  
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\Hzk48k","rb");
					 if(hzk_p==NULL)
					 {
						settextjustify(LEFT_TEXT,TOP_TEXT);      
						settextstyle(GOTHIC_FONT,HORIZ_DIR,3);				
						outtextxy(10,10,"Can't open hzk48 file!Press any key to quit...");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<640-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                     
							weima=s[1]-0xa0;                    
							offset=(94*(quma-1)+(weima-1))*288L;   
							fseek(hzk_p,offset,SEEK_SET);        
							fread (mat,288,1,hzk_p);           

							for(i=0;i<48;i++)
							{
								pos=6*i;
								for(j=0;j<48;j++)    
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL) 
									{
										putpixel(x+j,y,color);

									}

								}
								y++;
							}
							
							x+=part;    
							s+=2;          

						}
						x=x0;y0+=flag+10;   
					}
						break;

				}

		default:
				  break;

	}

	fclose(hzk_p);
}

