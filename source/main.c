#include"public.h"
#include"main.h"
/**************************
function name: main
description:�����������������ת 
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
			case 0://��¼���� 
				page = login_page();
				break;
			case 1://��ͨ�û����� 
				page = user_page();
				break;
			case 2://����Ա���� 
				page = admin_page();
				break;
			case 3://ע����� 
				page = register_page();
				break;
			case 4://����������� 
				page = forget_page();
				break;
			case 5://�ο�ģʽ 
				page = visitor_page();
				break;
			case 6://���ڽ��� 
				page = about_page();
				break;
			case 7://��ͨ�û������켣 
				page = newtrack_page(); 
				break;
			case 8://��ͨ�û���ѯ
				page = searchtrack_page(pages); 
				break;
			case 9://����Ա��ѯ���ζ�Ӧ�˿���Ϣ 
				page = caruser_page();
				break;
			case 10://����Ա��ѯ�û��˳��켣 
				page = usercar_page();
				break; 
			case 11://����Ա��ѯ�˿Ͷ�Ӧ������Ϣ���ӽ���
				page = utc_page(pages); 
				break; 
			case 12://��Ϣ���ƽ���
				page = inf_page();
				break;
			case 13://����Ա��ѯ���ζ�Ӧ�˿���Ϣ
				page = ctu_page(pages);
				break; 
			case 14://��ʾ����·�� 
				page = alltrack_page();
				break;
			case 15://��ʾվ��·�� 
				page = plan_page();
				break;
			case 16://�����쳣�Ǽ�
				page = health_page();
				break; 	
			case 17://�켣չʾ����
				page = show_page(); 
				break; 
			case 18://������Ϣ��ѯ����
				page = healinfo_page(choice,pages);
				break;
		}
	}
}
