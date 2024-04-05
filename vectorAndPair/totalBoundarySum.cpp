#include <iostream>
#include<vector>
using namespace std;

int totalSum(vector<vector<int>> input, int n)
{
    if(n == 0){
        return 0;
    }

    int sum = 0;
    
    
    for(int i = 0; i < n; i++){
        sum+= input[i][i];
    }
    
    if(n %2 != 0){
        int middleval = input[n/2][n/2];
        sum -= middleval;
    }
    
    for(int i = 0; i < n; i++){
        int col = n - 1 - i;
        sum+= input[i][col];
    }
    
    int no_row = 0;
    for(int i = 1; i < n - 1; i++){
        no_row += input[0][i];
        no_row += input[n-1][i];
    }
    
    int no_col = 0;
    for(int i = 1; i < n - 1; i++){
        no_col += input[i][0];
        no_col += input[i][n-1];
    }

    int finalSum = no_col + no_row + sum;
    return finalSum;
    
}

int main()
{
	
		int n;
		cin >> n;
		vector<vector<int>> arr(n,vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	
}