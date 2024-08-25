#include <iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	unordered_map<int, int> frq;
	int count = 0;

	for(int i = 0; i < n; i++){
		frq[arr[i]]++;
	}
	
	if(k != 0){
		for(int i = 0; i < n ; i++){ 
		   if(frq.count(arr[i] - k ) > 0){
				   count = count + frq[arr[i] - k];
		   }
		}
	}
	else if(k == 0){
		for(int i = 0; i < n; i++){
			if(frq.count(arr[i]) > 0){
				count = count + frq[arr[i]];
				frq[arr[i]]--;
			}
			count--;
		}
	}
	
	return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}