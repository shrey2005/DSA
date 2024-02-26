#include<iostream>
using namespace std;

int main() {
	// Write your code here

	int n;
	cin>>n;

	int elements[100000];
	for(int i = 0; i < n; i++){
		cin>>elements[i];
	}

	int min = elements[0];
	for(int i = 1 ; i < n; i++){
		if(min > elements[i]){
			min = elements[i];
		}
	}

	cout<<min;
}
