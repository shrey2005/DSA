#include <iostream>
#include<cmath>
using namespace std;
int getAllWaysHelper(int a, int b, int n){
	int val = (a - pow(n, b));
	if(val == 0){
		return 1;
	}
	if(val < 0){
		return 0;
	}
	return getAllWaysHelper(val, b, n + 1) + getAllWaysHelper(a, b, n + 1);
}

int getAllWays(int a, int b) {
	// Write your code here
	return getAllWaysHelper(a, b, 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}