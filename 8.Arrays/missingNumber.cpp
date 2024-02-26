int missingNumber(int arr[], int n)
{
    //Write your code here
    int tempCpy[n+1];
    int i = 0;
    for(; i < n ; i++){
        int minIndex = i;
        int minValue = arr[i];
        for(int j = i; j < n; j++){
            if(minValue > arr[j]){
                minIndex = j;
                minValue = arr[j];
            }
        }
        tempCpy[i] = minValue;
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
    tempCpy[i] = 0;
    for(int i = 0 ; i <= n; i++){
        int sub = tempCpy[i+1] - tempCpy[i];
        if(sub != 1){
            return i+1;
        }
    }
}