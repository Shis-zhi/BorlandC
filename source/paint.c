#include"public.h"
#include"paint.h" 
typedef struct
{
	int num;
	char* name;
}station;
/***************************
function name: putbmp
description: 贴图函数 
input: int x,int y,char *s
return: 1 or 2 or 0 
*****************************/ 
int putbmp(int x, int y, char *s)
{
    FILE *fp;
    long begin, w, h;
    unsigned char k;
    unsigned char color[256], R, G, B;
    unsigned int i, j, bit;
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28l, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&B, 1, 1, fp);
        fread(&G, 1, 1, fp);
        fread(&R, 1, 1, fp);
        if (R < 42)
		{

            color[i] = (B > 84) + 2 * (G > 84);
        }
        else if (R < 126)
        {
            color[i] = 8 + (B > 168) + 2 * (G > 168);
        }
        else if (R < 210)
        {
            color[i] = 4 + (B > 84) + 2 * (G > 60);
        }
        else
		{
			color[i] = 12 + (B > 168) + 2 * (G > 168);
        }

        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {

        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);

        for (j = 0; j < w; j++)
        {

			fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}
/***************************
function name: draw
description: 绘制站点 
input: int x,int y
return: void 
*****************************/
void draw(int x,int y)
{
	setcolor(GREEN);
	circle(x,y,5);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(x,y,GREEN);
}
/***********************************
function name:draw_line 
description: 用矩形替代线条
input： int x1,int y1,int x2,int y2 
***********************************/
void draw_line(int x1,int y1,int x2,int y2)
{
	setfillstyle(SOLID_FILL,RED);
	if(y1==y2)
	{
		bar(x1,y1-3,x2,y2+3);
	}
	else if(x1==x2)
	{
		bar(x1-3,y1,x2+3,y2);
	}
}
/*****************************
function name: showtrack
description: 可视化显示路径函数
input: char *n
return:void
*****************************/
void showtrack(char*n)
{
	const char tracks[5][5]={"一号","二号","三号","四号","五号"}; 
	station alltracks[5][5]={{{1,"接待中心"},{2,"科技楼"},{3,"机械厂"},{4,"东一楼"},{5,"公管学院"}},
					 {{1,"图书馆"},{2,"东一楼"},{3,"注册中心"},{4,"电影场"},{5,"活动中心"}},
					 {{1,"东三楼"},{2,"集贤楼"},{3,"附属小学"},{4,"科技楼"},{5,"图书馆"}},
					 {{1,"东二楼"},{2,"东八楼"},{3,"教一舍"},{4,"活动中心"},{5,"后勤集团"}},
					 {{1,"机械厂"},{2,"电力车间"},{3,"教工中心"},{4,"出版社"},{5,"管理学院"}}};
	puthz(60,0,"车次：",16,17,BLUE);
	puthz(105,0,tracks[n[0]-'1'],16,17,DARKGRAY);
	puthz(160,0,"起点：",16,17,BLUE);
	puthz(205,0,alltracks[n[0]-'1'][n[1]-'1'].name,16,17,DARKGRAY); 
	puthz(360,0,"终点：",16,17,BLUE);
	puthz(405,0,alltracks[n[0]-'1'][n[2]-'1'].name,16,17,DARKGRAY);
	if(n[0]=='1')
	{
		draw(74,120);//接待中心
		draw(148,250);//科技楼
		draw(225,380);//机械厂
		draw(400,380);//东一楼
		draw(500,100);//公管学院
	}
	else if(n[0]=='2')
	{
		draw(74,380);//图书馆
		draw(400,380);//东一楼
		draw(500,365);//注册中心
		draw(500,250);//电影场
		draw(225,205);//大学生活动中心
	}
	else if(n[0]=='3')
	{
		draw(500,430);//东三楼
		draw(500,140); //集贤楼
		draw(255,120);//附属小学
		draw(148,250);//科技楼
		draw(74,380);//图书馆
	}
	else if(n[0]=='4')
	{
		draw(310,430);//东二楼
		draw(310,315);//东八楼
		draw(310,250);//教一舍
		draw(225,205);//大学生活动中心
		draw(74,205);//后勤集团
	}
	else if(n[0]=='5')
	{
		draw(225,380);//机械厂
		draw(148,315);//电力系车间
		draw(210,290);// 教工俱乐部
		draw(310,140);//出版社
		draw(410,120);//管理学院
	}
	setfillstyle(SOLID_FILL,RED);
	if(strcmp(n,"112")==0)
	{
		draw_line(74,120,148,120);
		draw_line(148,120,148,250);//接待中心-科技楼
	}
	else if(strcmp(n,"113")==0)
	{
		draw_line(74,120,148,120);
		draw_line(148,120,148,250);//接待中心-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
	}
	else if(strcmp(n,"114")==0)
	{
		draw_line(74,120,148,120);
		draw_line(148,120,148,250);//接待中心-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
		draw_line(225,380,400,380);//机械厂-东一楼
	}
	else if(strcmp(n,"115")==0)
	{
		draw_line(74,120,148,120);
		draw_line(148,120,148,250);//接待中心-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
		draw_line(225,380,400,380);//机械厂-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,100);//东一楼-公共管理学院

	}
	else if(strcmp(n,"123")==0)
	{
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
	}
	else if(strcmp(n,"124")==0)
	{
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
		draw_line(225,380,400,380);//机械厂-东一楼
	}
	else if(strcmp(n,"125")==0)
	{
		draw_line(148,250,148,380);
		draw_line(148,380,225,380);//科技楼-机械厂
		draw_line(225,380,400,380);//机械厂-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,100);//东一楼-公共管理学院
	}
	else if(strcmp(n,"134")==0)
	{
		draw_line(225,380,400,380);//机械厂-东一楼
	}
	else if(strcmp(n,"135")==0)
	{
		draw_line(225,380,400,380);//机械厂-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,100);//东一楼-公共管理学院
	}
	else if(strcmp(n,"145")==0)
	{
		draw_line(400,380,500,380);
		draw_line(500,380,500,100);//东一楼-公共管理学院
	}
	else if(strcmp(n,"312")==0)
	{
		draw_line(500,430,500,140);//东三楼-集贤楼
	}
	else if(strcmp(n,"313")==0)
	{
		draw_line(500,430,500,140);//东三楼-集贤楼
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
	}
	else if(strcmp(n,"314")==0)
	{
		draw_line(500,430,500,140);//东三楼-集贤楼
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
	}
	else if(strcmp(n,"315")==0)
	{
		draw_line(500,430,500,140);//东三楼-集贤楼
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,74,380);//科技楼-图书馆
	}
	else if(strcmp(n,"323")==0)
	{
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
	}
	else if(strcmp(n,"324")==0)
	{
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
	}
	else if(strcmp(n,"325")==0)
	{
		draw_line(500,140,500,120);
		draw_line(500,120,255,120);//集贤楼-附属小学
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,74,380);//科技楼-图书馆
	}
	else if(strcmp(n,"334")==0)
	{
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
	}
	else if(strcmp(n,"335")==0)
	{
		draw_line(255,120,148,120);
		draw_line(148,120,148,250);//附属小学-科技楼
		draw_line(148,250,148,380);
		draw_line(148,380,74,380);//科技楼-图书馆
	}
	else if(strcmp(n,"345")==0)
	{
		draw_line(148,250,148,380);
		draw_line(148,380,74,380);//科技楼-图书馆
	}
	else if(strcmp(n,"212")==0)
	{
		draw_line(74,380,400,380);//图书馆-东一楼
	}
	else if(strcmp(n,"213")==0)
	{
		draw_line(74,380,400,380);//图书馆-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
	}
	else if(strcmp(n,"214")==0)
	{
		draw_line(74,380,400,380);//图书馆-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
		draw_line(500,365,500,250);//注册中心-电影场
	}
	else if(strcmp(n,"215")==0)
	{
		draw_line(74,380,400,380);//图书馆-东一楼
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
		draw_line(500,365,500,250);//注册中心-电影场
		draw_line(500,250,500,205);
		draw_line(500,205,225,205);//电影厂-大学生活动中心
	}
	else if(strcmp(n,"223")==0)
	{
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
	}
	else if(strcmp(n,"224")==0)
	{
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
		draw_line(500,365,500,250);//注册中心-电影场
	}
	else if(strcmp(n,"225")==0)
	{
		draw_line(400,380,500,380);
		draw_line(500,380,500,365);//东一楼-注册中心
		draw_line(500,365,500,250);//注册中心-电影场
		draw_line(500,250,500,205);
		draw_line(500,205,225,205);//电影厂-大学生活动中心
	}
	else if(strcmp(n,"234")==0)
	{
		draw_line(500,380,500,365);//东一楼-注册中心
	}
	else if(strcmp(n,"235")==0)
	{
		draw_line(500,365,500,250);//注册中心-电影场
		draw_line(500,250,500,205);
		draw_line(500,205,225,205);//电影厂-大学生活动中心
	}
	else if(strcmp(n,"245")==0)
	{
		draw_line(500,250,500,205);
		draw_line(500,205,225,205);//电影厂-大学生活动中心
	}
	else if(strcmp(n,"412")==0)
	{
		draw_line(310,430,310,315);//东二楼-东八楼
	}
	else if(strcmp(n,"413")==0)
	{
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
	}
	else if(strcmp(n,"414")==0)
	{
		draw_line(310,430,310,315);//东二楼-东八楼
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
	}
	else if(strcmp(n,"415")==0)
	{
		draw_line(310,430,310,315);//东二楼-东八楼
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
		draw_line(225,205,74,205);//大学生活动中心-后勤集团
	}
	else if(strcmp(n,"423")==0)
	{
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
	}
	else if(strcmp(n,"424")==0)
	{
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
	}
	else if(strcmp(n,"425")==0)
	{
		draw_line(310,315,310,205);
		draw_line(310,205,310,250);//东八楼-教一舍
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
		draw_line(225,205,74,205);//大学生活动中心-后勤集团
	}
	else if(strcmp(n,"434")==0)
	{
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
	}
	else if(strcmp(n,"435")==0)
	{
		draw_line(310,250,310,205);
		draw_line(310,205,225,205);//教一舍-大学生活动中心
		draw_line(225,205,74,205);//大学生活动中心-后勤集团
	}
	else if(strcmp(n,"445")==0)
	{
		draw_line(225,205,74,205);//大学生活动中心-后勤集团
	}
	else if(strcmp(n,"512")==0)
	{
		draw_line(225,380,148,380);
		draw_line(148,380,148,315);//机械厂-电力系车间
	}
	else if(strcmp(n,"513")==0)
	{
		draw_line(225,380,148,380);
		draw_line(148,380,148,315);//机械厂-电力系车间
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
	}
	else if(strcmp(n,"514")==0)
	{
		draw_line(225,380,148,380);
		draw_line(148,380,148,315);//机械厂-电力系车间
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
	}
	else if(strcmp(n,"515")==0)
	{
		draw_line(225,380,148,380);
		draw_line(148,380,148,315);//机械厂-电力系车间
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
		draw_line(310,140,310,120);
		draw_line(310,120,410,120);//出版社-管理学院
	}
	else if(strcmp(n,"523")==0)
	{
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
	}
	else if(strcmp(n,"524")==0)
	{
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
	}
	else if(strcmp(n,"525")==0)
	{
		draw_line(148,315,148,290);
		draw_line(148,290,210,290);//电力系车间-教工俱乐部
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
		draw_line(310,140,310,120);
		draw_line(310,120,410,120);//出版社-管理学院
	}
	else if(strcmp(n,"534")==0)
	{
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
	}
	else if(strcmp(n,"535")==0)
	{
		draw_line(210,290,310,290);
		draw_line(310,290,310,140);//教工俱乐部-出版社
		draw_line(310,140,310,120);
		draw_line(310,120,410,120);//出版社-管理学院
	}
	else if(strcmp(n,"545")==0)
	{
		draw_line(310,140,310,120);
		draw_line(310,120,410,120);//出版社-管理学院
	}
	//delay(3000);
}
/*********************************
function name: show_screen
description:用于绘制展示轨迹的界面
input: void
return void
**********************************/
void show_screen()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"C:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY);
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(0,0,640,480);
	putbmp(0,20,"c:\\mine\\hust.bmp");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,40,30);
	puthz(0,5,"返回",16,20,DARKGRAY); 
	setfillstyle(SOLID_FILL,GREEN); 
	bar(50,128,117,144);
	puthz(50,128,"接待中心",16,17,BLUE);
	bar(80,240,130,256);
	puthz(80,240,"科技楼",16,17,BLUE);
	bar(220,335,270,351); 
	puthz(220,335,"机械厂",16,17,BLUE);
	bar(382,351,432,367);
	puthz(382,351,"东一楼",16,17,BLUE);
	bar(432,84,499,100);	
	puthz(432,84,"公管学院",16,17,BLUE);
	bar(50,360,100,376);
	puthz(50,360,"图书馆",16,17,BLUE);
	bar(505,345,572,361);
	puthz(505,345,"注册中心",16,17,BLUE);
	bar(505,218,521,266);
	puthz(505,218,"电",16,17,BLUE); 
	puthz(505,234,"影",16,17,BLUE); 
	puthz(505,250,"场",16,17,BLUE);
	bar(220,180,287,196);
	puthz(220,180,"活动中心",16,17,BLUE);
	bar(445,418,495,434);
	puthz(445,418,"东三楼",16,17,BLUE);
	bar(445,170,495,186);
	puthz(445,170,"集贤楼",16,17,BLUE);
	bar(225,84,292,100);
	puthz(225,84,"附属小学",16,17,BLUE);
	bar(315,418,365,434);
	puthz(315,418,"东二楼",16,17,BLUE); 
	bar(315,299,331,347);
	puthz(315,299,"东",16,17,BLUE);
	puthz(315,315,"八",16,17,BLUE);
	puthz(315,331,"楼",16,17,BLUE);
	bar(315,218,331,266);
	puthz(315,218,"教",16,17,BLUE); 
	puthz(315,234,"一",16,17,BLUE); 
	puthz(315,250,"舍",16,17,BLUE);
	bar(50,180,117,196);
	puthz(50,180,"后勤集团",16,17,BLUE);
	bar(80,299,147,315); 
	puthz(80,299,"电力车间",16,17,BLUE);
	bar(200,270,267,286);
	puthz(200,270,"教工中心",16,17,BLUE);
	bar(255,128,305,144);
	puthz(255,128,"出版社",16,17,BLUE);
	bar(370,100,437,116);
	puthz(370,100,"管理学院",16,17,BLUE);
}
/*********************************
function name: show_page
description:展示轨迹界面的功能
input：void
return: int
*********************************/
int show_page()
{
	FILE* fp=NULL;
	char route[4];
	int n;
	memset(route,'\0',sizeof(route));
	if((fp=fopen("C:\\mine\\info\\show.txt","rt"))!=NULL)
	{
		fscanf(fp,"%s %d",route,&n);
		fclose(fp);
	}
	else
	{
		puthz(50,50,"打开文件时出错",32,40,RED);
		delay(2000);
		clrmous(MouseX,MouseY);
		closegraph();
		exit(1);
	}

	show_screen();
	showtrack(route);
	while(1)
	{
		
		newmouse(&MouseX,&MouseY,&press); 
		if(mouse_press(0,0,40,30))
		{
			if(mouse_press(0,0,40,30)==2)
			{
				MouseS=1;
			}
			else if(mouse_press(0,0,40,30)==1)
			{
				clrmous(MouseX,MouseY);
				delay(500);
				closegraph();
				return n;
			}
		}
		else 
		{
			MouseS=0;
		}
	}
}
