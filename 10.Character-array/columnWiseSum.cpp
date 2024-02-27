#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  
    int m, n;
    
    cin>>m>>n;
    int arr[m][n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < m; j++){
            sum+= arr[j][i];
        }
        cout<<sum<<" ";
    }
}


