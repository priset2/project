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
    cout<<"worker numumber:  "<<this->m_id<<endl<<"worker's name:   "<<this->m_name
    <<endl<<"depart:  "<<this->getdepartname()<<endl<<"what to do"<<endl;

}
string employee::getdepartname()
{
    return string("worker");
}