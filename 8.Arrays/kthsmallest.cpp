int kthSmallest(int arr[], int n, int k)
{
    //Write your code here

    int temp = 0;
    int countIterate = 0;
    for(int i = 0 ; i < n; i++){
        countIterate++;
        int min = arr[i], minIndex = i;
        for(int j = i; j < n ; j++){
            if(min > arr[j]){
                min = arr[j];
                minIndex = j;
            }
        } 
        temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
        if(countIterate == k){
            return min;
        }
    }

    return 0;
}