#include"public.h"
#include"main.h"
/**************************
function name: main
description:主函数，负责界面跳转 
input: void
return: void 
******************************/ 
void main()
{
	int page=0;
	int p=1;
	int choices=0;
	int* pages=&p;
	int* choice=&choices;
	while(1)
	{
		switch(page)
		{
			case 0://登录界面 
				page = login_page();
				break;
			case 1://普通用户界面 
				page = user_page();
				break;
			case 2://管理员界面 
				page = admin_page();
				break;
			case 3://注册界面 
				page = register_page();
				break;
			case 4://忘记密码界面 
				page = forget_page();
				break;
			case 5://游客模式 
				page = visitor_page();
				break;
			case 6://关于界面 
				page = about_page();
				break;
			case 7://普通用户新增轨迹 
				page = newtrack_page(); 
				break;
			case 8://普通用户查询
				page = searchtrack_page(pages); 
				break;
			case 9://管理员查询车次对应乘客信息 
				page = caruser_page();
				break;
			case 10://管理员查询用户乘车轨迹 
				page = usercar_page();
				break; 
			case 11://管理员查询乘客对应车次信息的子界面
				page = utc_page(pages); 
				break; 
			case 12://信息完善界面
				page = inf_page();
				break;
			case 13://管理员查询车次对应乘客信息
				page = ctu_page(pages);
				break; 
			case 14://显示各车路线 
				page = alltrack_page();
				break;
			case 15://显示站间路线 
				page = plan_page();
				break;
			case 16://健康异常登记
				page = health_page();
				break; 	
			case 17://轨迹展示界面
				page = show_page(); 
				break; 
			case 18://健康信息查询界面
				page = healinfo_page(choice,pages);
				break;
		}
	}
}
