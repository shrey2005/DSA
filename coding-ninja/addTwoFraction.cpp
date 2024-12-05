#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>

int gcd(int a, int b){
	while(b != 0){
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
vector<long long int> addFraction(int a, int b, int c, int d)
{
	// Write your code here
	int numerator = ( a * d ) + (b * c );
	int denomenator = ( b * d );

	int gcdResult = gcd(numerator, denomenator);

	numerator = numerator / gcdResult;
	denomenator = denomenator / gcdResult;
	
	vector<long long int> ans;
	ans.push_back(static_cast<long long int>(numerator));
	ans.push_back(static_cast<long long int>(denomenator));
	return ans;
}