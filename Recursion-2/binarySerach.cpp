#include <iostream>
// input - input array
// size - length of input array
// element - value to be searched
int binarySerachHelper(int input[], int start, int end, int element){
    if(start > end){
        return -1;
    }
    int mid = (start + end) / 2;
    if(input[mid] == element){
        return mid;
    }
    if(input[mid] < element){
        return binarySerachHelper(input, mid + 1, end, element);
    }
    else{
         return binarySerachHelper(input, start, mid -1, element);
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    int startIndex = 0;
    int endIndex = size - 1;
    int result = binarySerachHelper(input, startIndex, endIndex, element);
    return result;
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
