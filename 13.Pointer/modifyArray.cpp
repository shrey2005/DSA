#include <iostream>
using namespace std;

void modify(int *ar,int n)
{
    //write your code here
    int *min = &ar[0];
    int *max = &ar[0];
    for(int i = 0; i < n ; i++){
        if(*min > ar[i]){
            min = &ar[i];
        }
        if(*max < ar[i]){
            max = &ar[i];
        }
    }
    *min = 0;
    *max = 100;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    modify(ar,n);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}