#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int smallCount = 0;
	for(int i = start + 1; i <= end; i++){
	    if(input[i]<=input[start]){
	        smallCount++;
	    }
	}
	
	int temp = input[smallCount + start];
	input[smallCount + start] = input[start];
	input[start] = temp;
	
	int i = start;
	int j = end;
	
	int partionIndex = smallCount + start;
    int x = input[partionIndex];
	
	while(i < partionIndex && j > partionIndex){
	    if(input[i] <= x){
	        i++;
	    }
	    else if(input[j] > x){
	        j--;
	    }
	    else{
	        int swap = input[i];
	        input[i] = input[j];
	        input[j] = swap;
	        i++;
	        j--;
	    }
	}
	return partionIndex;
}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
    if(start >= end){
        return;
    }
    int pivort = partitionArray(input, start, end);
    quickSort(input, start, pivort - 1);
    quickSort(input, pivort + 1, end);
}

class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        free(input);
    }

    void executeAndPrintOutput() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << input[i] << ' ';
        cout << '\n';

        free(input);
    }
};

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
