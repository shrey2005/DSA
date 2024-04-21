#include <iostream>
using namespace std;

int pairSum(int A[], int size, int K)
{
     // Write your code here.
     int sum = 0;
     int i = 0; 
     int j = size;
     while(i < j){
       if (A[i] + A[j] == K) {
         sum++;
         i++;
         j--;
       }
       else if(A[i] + A[j] < K){
            i++;
       }
        else if(A[i]+A[j] > K) {
            j--;
        }
    }
     return sum;
}

int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int k;
    cin>>k;
    int ans = pairSum(input, n, k);
    cout<<ans;
    return 0;
}
