#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
	sort(arr, arr+n);
	
    int count = 0;
    
	for(int i = 0; i < n - 3; i++){
    	int low = i + 1;
    	int high = n - 1;
    	cout<<" J : "<<low <<" : K "<<high<<endl;
    	while(low < high){
    	    int checkSum = arr[i] + arr[j] + arr[high];
    	    cout<<"Check sum : "<<checkSum<<endl;
    	    if(checkSum == num){
    	        count = count + 1;
    	        int tempK = high - 1;
    	        while(tempK > low){
    	            if(arr[high]= arr[tempK]){
    	                tempK--;
    	                count++;
    	            }
    	            else{
    	                break;
    	            }
    	            low++;
    	        }
    	    }
    	    else if(checkSum > num){
    	        high--;
    	    }
    	    else if(checkSum < num){
    	        low++;
    	    }
    	}
	}
	return count;
}

int main() {
    int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}