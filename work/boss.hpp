#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class boss : public worker
{

    public:
    boss (int id,string name ,int did);
     
      void showinfo();
  string getdepartname();

};
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_departid = did;

}

void boss::showinfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名:" << this->m_name
		<< " \t岗:" << this->getdepartname()
		<< " \t岗位职责:管理公司所有事务" << endl;
}

string boss::getdepartname()
{
	return string("总裁");
}
