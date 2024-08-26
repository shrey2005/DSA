#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
	// Write your code here .
	int *result = new int[n+1];
	result[0] = 0;
	result[1] = 1;

	for(int i = 2; i <= n; i++){
		if(i - x >= 0 && result[i-x] == 0){
			result[i] = 1;
		}
		else if(i - y >= 0 && result[i-y] == 0){
			result[i] = 1;
		}
		else if(i -1 >= 0 && result[i-1] == 0){
			result[i] = 1;
		}
		else{
			result[i] = 0;
		}
	}

	if(result[n] == 0){
		return "Whis";
	}
	return "Beerus";
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}