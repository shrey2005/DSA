int findSecondLargest(int arr[], int n)
{
    //Write your code here
     for(int i = 0; i < n; i++){
       int maxEle = arr[i];
       int maxIndex = i;
       for(int j = i; j < n; j++){
           if(arr[j]>maxEle){
               maxEle = arr[j];
               maxIndex = j;
           }
       }
       arr[maxIndex] = arr[i];
       arr[i] = maxEle;
       
       if(i == 1){
          return maxEle;
       }
   }
}