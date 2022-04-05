#include <iostream>
using namespace std;
#include "workmanager1.hpp"
#include"employee.hpp"
#include"worker.h"
#include"boss.hpp"
#include"manager.hpp"


int main()
 {


	workermanager wm;
	int choice = 0;
while(true)
{
	wm.show_menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
   //system("pause");
switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
		wm.add_emp();
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
}
	return 0;
}