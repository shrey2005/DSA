#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int noOfCols,noOfRows;
    
    cin>>noOfRows>>noOfCols;
    
    vector<vector<int>> arr(noOfRows, vector<int>(noOfCols,0));
    
    for(int i = 0; i < noOfRows ; i++){
        for(int j = 0; j < noOfCols; j++){
            cin>>arr[i][j];
        }
    }
    
    // for(int i = 0; i < noOfRows ; i++){
    //     for(int j = 0; j < noOfCols; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int sum = 0;
    
    for(int i = 0; i < noOfRows; i++){
        sum+= arr[i][i];
    }
    
    for(int i = 0; i < noOfRows; i++){
        int col = noOfCols - 1 - i;
        sum+= arr[i][col];
    }
    cout<<"Sum : "<<sum<<endl;
}