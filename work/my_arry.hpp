#pragma once
#include<iostream>

using namespace std;
template<class T>
class  my_arry
{
private:
   T* p_address;
   int size;
   int capacity;
  
public:
    my_arry(int capacity)
    {
        this->capacity=capacity;
        this->size=0;
        this->p_address= new T[this->capacity];

    }

    my_arry(const my_arry& arr )
    {
        this->capacity=arr.capacity;
        this->size=arr.size;
        this->p_address=new T[arr.capacity];
        for(int i=0;i<this->size;i++)
        {
            this->p_address[i]=arr.p_address[i];
        }
    }

    //kaobei 
   my_arry& operator= (const my_arry& arr)
   {
       if(this->p_address!=NULL)
       {
           delete[] this->p_address;
           this->p_address=NULL;
           this->capacity=0;
           this->size=0;
      }
      this->capacity=arr.capacity;
      this->size=arr.size;
      this->p_address= new T[this->size];
      for(int i=0;i<this->size;i++)
      {
          this->p_address[i]=arr.p_address[i];
      }
      return *this;
   }
   void push_back(const T& val)
   {
       if(this->size==this->capacity)
       {
           return ;
       }
       this->p_address[this->size]=val;
       this->size++;

   }
   void delete_back()
   {
       if(this->size==0)
       {
           return;
       }
       this->size--;
       delete this->p_address[this->size];
       this->p_address[this->size]=NULL;

   }
   
   T & operator [](int index)
	{
		return this->p_address[index]; //不考虑越界，用户自己去处理
	}
 
   int get_capacity()
   {
       return this->capacity;
   }
   int get_size()
   {
       return this->size;
   }
    ~my_arry()
    {
        if(this->p_address!=NULL)
        {
            delete[] this->p_address;
            this->p_address=NULL;
        }
    }
    
};

