#include <limits.h>
bool findMax(int arr[], int n, int extracandies){
    int max = INT_MIN ;
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
           max = arr[i];
        }
    }
    if(max <= extracandies){
        return true;
    }
    return false;
}

void maximum_candy(int n, int arr[],int extraCandies,bool output[]){
   //Write your code

   int calHighestCalndies = 0;
   for(int i = 0; i < n ; i ++){
      calHighestCalndies = arr[i] + extraCandies;
      bool isFindMax = findMax(arr, n, calHighestCalndies);
      if(isFindMax){
         output[i] = 1;
      }
      else{
         output[i] =0;
      }
   }
}