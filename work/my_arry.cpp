#include"my_arry.hpp"
#include<string>

void test01()
{
    my_arry <int > arr(5);
    my_arry<int>arr2(arr);
    my_arry<int> arr3(100);
    arr3=arr2;
}
int main()
{

    test01();
    my_arry<int> arr(6);
    for(int i=0;i<6;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}