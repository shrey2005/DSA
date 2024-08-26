#include<iostream>
#include<queue>
using namespace std;
 
int minCost(int arr[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 

	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

	int result = 0;

	while(pq.size() > 1){
		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		result+= first + second;
		pq.push(first + second);
	}
	return result;
}

int main()
{
	int n=0;
	int k=0;
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<minCost(arr,n);
	
}

