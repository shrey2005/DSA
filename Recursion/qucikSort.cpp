#include <iostream>

using namespace std;

int partitionArray(int input[], int start, int end) {
    cout<<"Start : "<<start<<" End : "<<end;

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
	cout<<"Small Count : "<<smallCount<<endl;
	return partionIndex;
}

void quickSort(int input[], int start, int end) {
    cout<<"Start : "<<start<<"End : "<<end<<endl;
    if(start >= end){
        return;
    }
    int pivort = partitionArray(input, start, end);
    cout<<"Pivot : "<<pivort<<endl;
    quickSort(input, start, pivort - 1);
    quickSort(input, pivort + 1, end);
}

int main() {
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>*(arr+1);
    }
    
    quickSort(arr, 0, n-1);
    
    for(int i = 0 ; i < n; i++){
        cout<<*(arr+1);
    }
    
}