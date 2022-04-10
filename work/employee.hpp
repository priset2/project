#pragma once 
#include<iostream>
using namespace std;
#include"worker.h"
class employee:public worker
{

   public:
   

 employee(int id,string name,int did);
   
 void showinfo();
string getdepartname();
   
};


employee::employee(int id ,string name ,int did)
{
    this->m_name=name;
    this->m_id=id;
    this->m_departid=did;
}
void employee::showinfo()
{
   cout << "职工编号： " << this->m_id
		<< " \t职工姓名:" << this->m_name
		<< " \t岗:" << this->getdepartname()
		<< " \t岗位职责:干活" << endl;
}
string employee::getdepartname()
{
    return  string ("worker");
}