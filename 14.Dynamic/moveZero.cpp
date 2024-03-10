#include<iostream>
using namespace std;
int main()
{
    //write your code here

    int totalItr;
    cin>>totalItr;

    for(int i = 0; i < totalItr; i++){
        int n;
        cin>>n;
        
        int *arr = new int[n];
        
        for(int i = 0; i < n; i++){
            cin>>*(arr+i);
        }
        int start=0;
        for(int j=0; j < n; j++){
            if(*(arr+j) != 0){
                *(arr+start)=*(arr+j);
                start++;
            }
        }
        for(;start<n;start++){
            *(arr+start)=0;
        }

        for (int i = 0; i < n; i++) {
            cout << *(arr + i) << " ";
        }
        cout<<endl;
    }
}