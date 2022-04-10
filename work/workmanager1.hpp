
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

	void init_emp();

	void del_emp();

	void show_emp();

    void change_emp();

	void search_emp();

	void sort_emp();


	void clean_file();

 worker ** m_emparry;

 int is_exit(int id);

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

		int num= this->get_empnum();
	cout<<"the number of worker : "<<num<<endl;
	this->m_empnum=num;

	this->m_emparry = new  worker* [this->m_empnum];

	init_emp();

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

void workermanager::init_emp()
{
   ifstream ifs;
   ifs.open("insert.txt",ios::in);
   int id;
   string name;
   int did;

   int index=0;
   while(ifs>>id&& ifs>> name&& ifs>>did)
   {
	   worker * worker=NULL;
	   if(did==1)
	   {
		   worker= new   employee (id , name, did);
	   }
	   else if (did==2)
	   {
		   worker = new manager(id ,name,did);
	   }
	   else
	   {
		   worker  =  new boss (id,name,did);
	   }
	   this->m_emparry[index]=worker;
	   index++;
   }
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


int workermanager::is_exit(int id)
{
  int index = -1;
  for(int i=0;i<this->m_empnum;i++)
  {
	  if(this->m_emparry[i]->m_id==id)
	  {
		  index=i;
		  break;
	  }
  }
  return index;


}

void workermanager::show_emp()
{
 if(this->m_fileempty)
 {
	 cout<<"the file is empty"<<endl;

 }
 else
 {
	 for(int i=0;i<this->m_empnum;i++)
	 {
		 this->m_emparry[i]->showinfo();
		 //system("pause");
		system("cls");
	 }
 }

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


void workermanager::del_emp()
{
   if(this->m_fileempty)
   {
	   cout<<"the file is empty"<<endl;
   }
   else
   {
        cout<<"which employee do you want to delete "<<endl;
		int id=0;
		cin>>id;
		int index =0;
		index = this->is_exit(id);//判断是否存在
         if (index==-1)
		 {
			 cout<<"error -there is no employee in this number"<<endl;

		 }
		 else
		 {
           for (int i=index;i<this->m_empnum-1;i++)
		   {
			   this->m_emparry[i]=this->m_emparry[i+1];
		   }
		   this->m_empnum--;
		   this->save();
		   cout<<"delete success"<<endl;
		 }
   }
}


int workermanager::get_empnum()
{
  ifstream ifs;
  ifs.open("insert.txt",ios::in);
  int id;
  string name;
  int did;
  int num=0;

  if (!ifs.is_open())
  {
	  cout<<"open_error"<<endl;
  }
  else
  {
	while(ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
  }
  ifs.close();
  return num;

}

void workermanager::change_emp()
{
	cout<<"which employee do you want to change "<<endl;
	int id=0;
	cin>>id;

	if(this->is_exit(id)==-1)
	{
		cout<<"the empolyee isn't here"<<endl;

	}
	else if(this->m_fileempty)
	{
		cout<<"the file is empty"<<endl;
	}
	else
	{
		int new_id=0;
		string new_name;
		int new_did;
       
			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> new_id;

			cout << "请输入新姓名： " << endl;
			cin >> new_name;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> new_did;
			worker *worker=NULL;
			 int ret = this->is_exit(id);
			 delete this->m_emparry[ret];
			 switch (ret)
			 {
				 case 1 : 
				 worker = new employee(new_id,new_name,new_did);
				 break;
				 
				 case 2:
				 worker = new manager (new_did,new_name,new_did);
				 break;

				 case 3:
				 worker= new boss(new_id,new_name,new_did);
				 break;

				 default:
				 break;
			 }
			 this->m_emparry[ret]=worker;
 				cout<<"change success"<<endl;
			 this->save();
			
         system("pause");
		 system("cls");
	}
}
// int  workermanager::get_empnum()
// {
// 	ifstream ifs;
// 	ifs.open("insert.txt",ios::in);
// 	if(!ifs.is_open())
// 	{
// 		cout<<"error"<<endl;
// 	}
// 	else
// 	{
// 		int id;
// 		string name;
// 		int did;

// 		int num=0;

// 	}
// }
 
void workermanager::search_emp()
{
	if(this->m_fileempty)
	{
		cout<<"the file is empty"<<endl;
	}
	else
	{
			cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int target=0;
		cin>>target;
		if(target==1)
		{
			cout<<"please input the number for search"<<endl;
			int find=0;
			cin>>find;
			int ret=is_exit(find);
			if(ret==-1)
			{
				cout<<"no person"<<endl;
			}
			else
			{
				this->m_emparry[ret]->showinfo();
			}
			
		}
		else
		{
				cout<<"please input the name for search"<<endl;
				string find;
				cin>>find;
				bool find_target  = false;
				for(int i=0;i<this->m_empnum;i++)
				{
					if(this->m_emparry[i]->m_name==find )
					{
						find_target=true;
						this->m_emparry[i]->showinfo();
					}
				}
				if(find_target==false)
				{
					cout<<"find no people"<<endl;
				}
		}
	}
	system("cls");
}


void workermanager::sort_emp()
{
	if(this->m_fileempty)
	{ 
      cout<<"no file"<<endl;
	}
	else
	{
		cout<<"please choose the way of sort"<<endl;
		cout<<"1. 序号升序"<<endl;
		cout<<"2. 序号降序"<<endl;
		int choose=0;
		cin>>choose;
		if(choose ==1)
		{
			for(int i=0;i<this->m_empnum-1;i++)
			{
				for(int j=0;j<this->m_empnum-1-i;j++)
				{
					if(this->m_emparry[j]>this->m_emparry[j+1])
					{
					worker *temp=this->m_emparry[j];
					this->m_emparry[j]=this->m_emparry[j+1];
					this->m_emparry[j+1]= temp;
					}

				}
			}
		}
		else
		{
			for(int i=0;i<this->m_empnum-1;i++)
			{
				for(int j=0;j<this->m_empnum-1-i;j++)
				{
					if(this->m_emparry[j]<this->m_emparry[j+1])
					{
					worker *temp=this->m_emparry[j];
					this->m_emparry[j]=this->m_emparry[j+1];
					this->m_emparry[j+1]= temp;
					}

				}
			}
		}
	}
	cout<<"sort success"<<endl;
	this->save();
	this->show_emp();
}


void workermanager::clean_file()
{
  cout<<"sure?"<<endl;
  cout<<"1.yes"<<endl;
  cout<<"2.no "<<endl;
  int choose=0;
  cin>>choose;
  if(choose==1)
  {
	  ofstream ofs("output.txt",ios::trunc);
	  ofs.close();
	  for(int i=0;i<this->m_empnum;i++)
	  {
		  delete this->m_emparry[i];
	  }
  }
  this->m_empnum=0;
  this->m_emparry=NULL;
  this->m_fileempty=true;
  cout<<"delete success"<<endl;

}
workermanager::~workermanager()
{
	if(this->m_emparry!=NULL)
	{
		delete[] this->m_emparry;
	}
}
