#include <iostream>

using namespace std;

int firstIndex(int arr[], int size, int x){
    if(size == 0){
        return -1;
    }
    if(arr[0] == x){
        return 0;
    }
    int k = firstIndex(arr+1, size-1,x);
    cout<<" K : "<<k<<endl;
    if(k == -1){
        return -1;
    }
    else{
        return k+1;
    }
}
int main() {
    int n, x;
    cin>>n>>x;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int result = firstIndex(arr, n , x);
    cout<<"Index : "<<result<<endl;
}