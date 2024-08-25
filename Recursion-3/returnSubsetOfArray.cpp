#include <iostream>
using namespace std;

int subsetHelper(int input[], int n, int output[][20]){
    if(n == 0){
        output[0][0] = 0;
        return 1;
    }
    
    int smallN = n - 1;
    int smallOutputSize = subsetHelper(input + 1, smallN, output);

    for(int i = 0; i < smallOutputSize; i++){
        int col = output[i][0] + 1;
        output[smallOutputSize+i][0] = col;
        output[smallOutputSize+i][1] = input[0];
        
        for(int j = 1; j <= col - 1; j++){
            output[smallOutputSize+i][j+1] = output[i][j];
        }
    }
    return 2 * smallOutputSize;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    int size = subsetHelper(input, n, output);
    return size;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
