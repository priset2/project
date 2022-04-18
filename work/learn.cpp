#include <iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<deque>
//#include"learn.hpp"
using namespace std;
/*
template<typename T>
void change (T &a, T &b)
{
    T temp=0;
    temp=a;
    a=b;
    b=temp;
}


int main()

{
    int a=10;
    int b=20;
    change<int> (a,b);

    cout<<a<<" "<<b<<endl;
    return 0;
}

template<class T>
void sort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
         int max=i;
         for(int j=i+1;j<len ;j++)
         {
             if(arr[max]<arr[j])
             {
                 max=j;
             }
         }
        if(max!=i)
        {
            T temp=arr[i];
            arr[i]=arr[max];
            arr[max]=temp;
        }
    }
   


}
template<class T>
void print( T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void test01()
{
      char char_arr[]="azqwdewpkjhvzikhkfehshhvfevrsdh";
      int num=sizeof(char_arr)/sizeof(char);
      sort(char_arr,num);
      print(char_arr,num);
}
void test02()
{
    
}
int main()
{
    test01();
    return 0;
}

class person
{
    public:
    person(string name,int age )
    {
   this->age=age;
   this->name=name;
    }
   int age;
   string name;
};

template<class T>
bool compare(T &a, T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<> bool compare(person &a,person &b)
{
    if(a.age==b.age&&a.name==b.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test()
{
    person p1("tom",12);
    person p2("tom",13);
    bool ret=compare(p1,p2);
    if(ret)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}
int main()
{
    test();
    return 0;
}


template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age)
    {
        this->m_age=age;
        this->m_name=name;

    }
    void show_person()
    {
        cout<<"name:"<<this->m_name<<" "<<"age: "<<this->m_age<<endl;
    }
    T1 m_name;
    T2 m_age;
};
template<class T1,class T2>
void print (person<T1,T2> &p)
{
    p.show_person();
    cout<<endl;
     cout<<"the name of T1   "<<typeid(T1).name()<<endl;
     cout<<"the name of T2   "<<typeid(T2).name()<<endl;
}
void test01()
{

    person<string , float> p("zhangsan",18.34);
    // p.show_person(p);
    print(p);
   
}


int main()
{
    test01();
    return 0;
}



template<class T>
class base
{
  T m;

};

template<class T1,class T2>
class son : public base  <T1>
{
  public:
 son()
{
   cout<<"the type of T1"<<typeid(T1).name()<<endl;
   cout<<"the type of T2"<<typeid(T2).name()<<endl;
}  
  T1 obj;
};
void test01()
{
    son<int ,char> s01;
    //s01.son2();
}


void print(int val)
{
    cout<<val<<endl;
}
void test03()
{
    vector<int> v1 ;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    int a=0;
    cin>>a;
    v1.push_back(a);
    vector<int>::iterator it_begin =v1.begin();
    vector<int>::iterator it_end=v1.end();

    while(it_begin!=it_end)
    {
        cout<<*it_begin<<endl;
        it_begin++;
    }
    cout<<endl;
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<endl;
        
    }
    for_each(v1.begin(),v1.end(),print);
   
}

class person
{
    public:
    person( string name,int age)
    {
        this->m_age=age;
        this->m_name=name;
    }
    string m_name;
    int m_age;

};
void test02()
{
    vector<person> v_p;
    person p1("a",10);
    person p2("b",20);
    person p3("c",70);
    person p4("d",30);
    person p5("e",50);
    v_p.push_back(p1);
     v_p.push_back(p2);
      v_p.push_back(p3);
       v_p.push_back(p4);
        v_p.push_back(p5);
       
       for(vector<person>::iterator iv=v_p.begin();iv!=v_p.end();iv++)
       {
           cout<<iv->m_age<<" "<<iv->m_name<<endl;
       }

}

class person
{
    public:
    person( string name,int age)
    {
        this->m_age=age;
        this->m_name=name;
    }
    string m_name;
    int m_age;

};
void test01()
{
    vector<vector<int> > v;
    vector <int> v1;
    vector <int> v2;
    vector <int> v3;
    vector <int> v4;
    for(int i=0;i<4;i++)
    {
        v1.push_back(i);
          v2.push_back(i+1);
            v3.push_back(i+2);
              v4.push_back(i+10);


    }

    
}
 void test02()
{
    vector<person*> v_p;
    person p1("a",10);
    person p2("b",20);
    person p3("c",70);
    person p4("d",30);
    person p5("e",50);
    v
void test01()
{
   /* string s1;
    string s2("abcd");
    const char* str="hello";
    string s3(str);
    string s4(s2);
    string s5(5,'d');
    cout<<s2<<endl;
     cout<<s3<<endl;
      cout<<s4<<endl;
      cout<<s5<<endl;

      s5="abcda";
   
      cout<<s5<<endl;
      cout<<sizeof(s5)<<endl;
      int t=s5.find("a");
      cout<<t<<endl;
      int x=s5.rfind("d");
      cout<<x<<endl;   
      int c=s2.compare(s2);
      cout<<"c= :"<<c<<endl;
      vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
     vector<int> v2(v1.begin(),v1.end());
     vector <int> v3(10,100);
   vector<int> v4(v3);
   vector<int> v5;
   v5=v4;
  print_vector(v1);
  print_vector(v2);
  print_vector(v3);
  print_vector(v4);
if(v5.empty())
{
    cout<<"empty"<<endl;
}
else
{
    cout<<"no empty"<<endl;
    cout<<"v5 de rongliang  "<<v5.capacity()<<endl;
    cout<<"size"<<v5.size()<<endl;
    v5.resize(18,20);
    cout<<"v5 de rongliang  "<<v5.capacity()<<endl;
    cout<<"size"<<v5.size()<<endl;
    print_vector(v5);
}
  


}
void test011()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
    v1.push_back(i);
     } 
      vector<int> v2;
       for(int i=0;i<120;i++)
    {
    v2.push_back(i);
     } 

     print_vector(v1);
     cout<<endl;
     print_vector(v2);
cout<<endl;
cout<<"*************************"<<endl;
     v1.swap(v2);


     print_vector(v1);
     cout<<endl;
     print_vector(v2);
        
deque<int> d;
for (int i=0;i<10;i++)
{
    d.push_back(i+1);

}
print_deque(d);
deque<int>d4 (d);
print_deque(d4);

deque<int> d5;
d5=d;
d5.assign(10,100);
print_deque(d5);
bool b =d.empty();
if(b)
{
    cout<<"empty";
}
else
{
    cout<<b<<endl;
    cout<<"no empty"<<endl;
}
cout<<d.size()<<endl;
d.resize(15);
print_deque(d);
d.push_back(908);
d.push_front(809);
print_deque(d);

deque<int>::iterator i= d.begin();
++i;
i=d.insert(i+5,9765688);
print_deque(d);
sort(d.begin(),d.end());
print_deque(d);
*/


 class  person
 {
     public:
     person(string name,int score)
     {
         this->m_score=score;
         this->m_name=name;
     }
     int m_score;
     string m_name;
     void print_person(person p);
 };
 void person::print_person(person p)
 {
     cout<<p.m_name<<" "<<p.m_score<<endl;

 }
void test01()
{
    person p1("zhangsan",98);
     person p2("wda",34);
    person p3("dew",87);
    person p4("zxc",79);
    person p5("defq",99);
   
}
int main()
{
  
    return 0;
}