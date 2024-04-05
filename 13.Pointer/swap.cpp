#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        swap(&a , &b);
        cout<<a<<" "<<b;
        cout<<endl;
    }
}