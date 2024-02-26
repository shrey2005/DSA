	#include<iostream>
using namespace std;
int binarySearch(int nums[], int left, int right, int target) {
    
 int mid = (left + right) /2;
      // Write your code !!!!
    
    while(left<=right){        
        if(nums[mid] >= target){
            left = 0;
            right = mid - 1;
        }
        else if(nums[mid] <= target){
            left = mid + 1;
            right = right;
        }
        
        if(nums[mid] == target){
            return mid;
        }
        mid = (left + right) / 2;
    }
   return -1;  
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left = 0;
    int right =n-1;
    int target;
    cin>>target;


    int ans = binarySearch(arr, 0, n-1, target);


    cout<<ans;




    return 0;
}