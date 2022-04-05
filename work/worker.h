#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
    public:
    virtual void showinfo ()=0;
    virtual string getdepartname()=0;
    int m_id;
    string m_name;
   int m_departid;
};