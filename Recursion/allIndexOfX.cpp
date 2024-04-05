#include <iostream>

using namespace std;

int findIndex(int input[], int start, int end, int x){
    int index = -1;
    cout<<"---------->Start : "<<start<<"End : "<<end<<endl;
    for(int i = start; i <= end; i++){
        // cout<<"ele : "<<input[i]<<" : "<<x<<endl;
        if(input[i] == x){
            index = i;
            break;
        }
    }
    int actuallyIndex = index;
    if(index != -1){
        actuallyIndex = start + index;
    }
    return actuallyIndex;
}

int start = 0;
// int outputIndex = 0;

int allIndexes(int input[], int size, int x, int output[]) {
    
    int outputIndex = 0;
    for(int i = 0; i < size; i++){
        bool isZero = output[i] == 0;
        cout<<"Output : "<<output[i]<<" "<<isZero<<"   ";
        if(input[i] != 0){
            outputIndex++;
        }
    }
    cout<<"total elements : "<<outputIndex<<endl;
    if(start == (size - 1)){
        return outputIndex;
    }
    int index = findIndex(input, start, size ,x);
    cout<<"Index : "<<index<<endl;
    if(index != -1){
        output[outputIndex] = index;
    }
    start = start + 1;
    cout<<"Start : "<<start<<"Size : "<<size<<endl;
    cout<<"-----------------"<<endl;
    return allIndexes(input+1, size, x, output);
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
    cout<<"Size : "<<size<<endl;
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
}