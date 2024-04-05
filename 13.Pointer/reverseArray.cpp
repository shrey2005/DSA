#include <iostream>
using namespace std;

void reverse(int *ar,int n)
{
	//write your code here
    int i = 0;
    int j = n - 1;
    
    while(i<j){
        int temp = *(ar+i);
        *(ar+i) = *(ar+j);
        *(ar+j) = temp;
        i++;
        j--;
    }
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
    reverse(ar,n);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}