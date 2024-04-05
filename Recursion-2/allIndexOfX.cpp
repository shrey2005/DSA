#include <iostream>
using namespace std;

int findIndex(int input[], int size, int x, int output[], int index, int currentIndex){
   if(index > size){
       return currentIndex;
   }
   if(input[index] == x){
       output[currentIndex++] = index;
   }
   return findIndex(input, size, x, output, index+1, currentIndex);
}

int allIndexes(int input[], int size, int x, int output[]) {
    
    int result = findIndex(input, size, x, output, 0, 0);
    return result;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    
}


