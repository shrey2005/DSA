#include <iostream>
#include<unordered_map>
using namespace std;


int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int, int> frq;
	int pairSum = 0;
	for(int i = 0; i < n ; i++){
		frq[arr[i]]++;

		if(frq.count(-arr[i])){
			pairSum += frq[-arr[i]]; 
			if(arr[i] == 0){
				pairSum--;
			}
		}
	}

	return pairSum;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}