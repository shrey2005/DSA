#include <iostream>
using namespace std;

void merge(int arr[], int l, int r){
   int mid = (l + r)/2;
   int *temp = new int[r - l +1];

   int i = l;
   int j = mid +1;
   int k = 0;

   while(i <= mid && j <= r){
       if(arr[i] <= arr[j]){
           temp[k] = arr[i];
           i++;
           k++;
       }
       else{
           temp[k] = arr[j];
           j++;
           k++;
       }
   }

   while(i <= mid){
       temp[k] = arr[i];
       i++;
       k++;
   }

   while(j <= r){
       temp[k] = arr[j];
       j++;
       k++;
   }

   int m = 0;
   while(m < k){
       arr[l + m] = temp[m];
       m++;
   }

    delete[] temp;
}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    if(l >= r){
        return;
    }
    int mid = (l + r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}