#include <cmath>
int binarySearchClosest(int arr[], int left, int right, int target)
{
    //Write your code here
    
    while(left + 1 <right){     
         int mid = (left + right) /2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            right = mid;
        } else {
            left = mid;
        }
    }
        if(arr[right] - target < target - arr[left]){
            return right;
        }
        else{
            return left;
        }

}