#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    //write your code here
    int *highest = ar;
    for(int i = 0; i < n; i++){
        if(*(ar + i) > *highest){
            highest = (ar+i);
        }
    }
    return highest;
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
   int *ans =findmax(ar,n);
   cout<<*ans;
    
}