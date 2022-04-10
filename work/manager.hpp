#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
class manager:public worker
{
 public:
 manager(int id,string name ,int did);

  void showinfo ();
  string getdepartname();

};

manager::manager(int id,string name ,int did)
{
    this->m_id=id;
    this->m_name=name;
    this->m_departid=did;
}
void manager::showinfo()
{
    cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getdepartname()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}
string manager::getdepartname()
{
return  string("manager");
}