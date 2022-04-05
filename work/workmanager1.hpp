
#include<fstream>
#include"worker.h"
#include"manager.hpp"
#include"employee.hpp"
#include"boss.hpp"

using namespace std;

class workermanager
{
public:

	//构造函数
	workermanager();
	void show_menu();
	void exitSystem();
	int m_empnum;
void add_emp();
void save();
 worker ** m_emparry;
 bool m_fileempty;
int get_empnum();
	//析构函数
	~workermanager();
 
};














workermanager::workermanager()
{
	ifstream ifs;
	ifs.open("insert.txt",ios::in);
	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_empnum= 0;  //初始化人数
		this->m_fileempty = true; //初始化文件为空标志
		this->m_emparry= NULL; //初始化数组
		ifs.close(); //关闭文件
		return;

	}
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		cout << "文件为空" << endl; //测试输出
		this->m_empnum= 0;  //初始化人数
		this->m_fileempty = true; //初始化文件为空标志
		this->m_emparry= NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
}


void workermanager::show_menu()

{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}



void workermanager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	
	exit(0);
}



void workermanager::add_emp()
{
   cout<<"please insert the number of workers"<<endl;
   int add_number=0;
   cin>>add_number;
   if(add_number>0)
   {
       int new_size = this->m_empnum+add_number;
	   worker ** new_space = new worker* [new_size];
	   if(this->m_emparry!=NULL)
	   {
		   for(int i=0;i<this->m_empnum;i++)
		   {
			   new_space[i]=this->m_emparry[i];
		   }
	   }
	   for (int i=0;i<add_number;i++)
	   {
		   int id;
		   string name;
		   int d_select;
		   cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> d_select;

			worker * worker =NULL;
			switch(d_select)
			{
				case 1:
				worker=new employee(id,name,1);
				break;
				case 2: //经理
				worker = new manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			new_space[this->m_empnum+i]=worker;
	   }
	   delete [] this->m_emparry;
	   this->m_emparry=new_space;
	   this->m_empnum=new_size;
	   this->m_fileempty=false;
	   cout << "成功添加" << add_number << "名新职工！" << endl;
	   this->save();
   }

   else
   {
	   cout<<"error"<<endl;
   }
  // system("pause");
	system("cls");
}

void  workermanager::save()
{

   ofstream ofs;
   ofs.open("output.txt",ios::out);
   if(ofs.is_open())
   {

   
  for(int i=0;i<this->m_empnum;i++)
  {
	  ofs<<this->m_emparry[i]->m_id<<" "
	  <<this->m_emparry[i]->m_name<<" "
	  <<this->m_emparry[i]->m_departid<<endl;
  }

  }
  else
  {
	  cout<<"error"<<endl;
  }
  ofs.close();
}

int workermanager::get_empnum()
{
  ifstream ifs;
  ifs.open("insert.txt,ios::in");
  int id;
  string name;
  int did;
  int num=0;
  while(ifs>>id&&ifs>>name&&ifs>>did)
  {
	  num++;
  }
  ifs.close();
  return num;

}
workermanager::~workermanager()
{
	if(this->m_emparry!=NULL)
	{
		delete[] this->m_emparry;
	}
}
