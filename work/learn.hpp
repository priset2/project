#pragma once
#include <iostream>
#include<string>
#include<typeinfo>
using namespace std;
template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age);
    // {
    //     this->m_age=age;
    //     this->m_name=name;
    // }

    void show();
     

    T2 m_age;
    T1 m_name;
};

template<class T1,class T2>
person<T1,T2>::person  (T1 name,T2 age)
{
     {
        this->m_age=age;
         this->m_name=name;
     }
}

template<class T1,class T2>
void person<T1,T2>::show()
{

         cout<<this->m_age<<" "<<this->m_name<<endl;
     
}
void test01()
{
    person<string ,int> p("tom",201);
p.show();
}