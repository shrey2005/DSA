void sort012(int arr[], int n)
{
    //Write your code here
    int currentIndex0 = 0;
    int currentIndex2 = n - 1;
    int temp[n];
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            temp[currentIndex0] = 0;
            currentIndex0++;
        }
        if(arr[i] == 2){
            temp[currentIndex2] = 2;
            currentIndex2--;
        }
    }
    for(int i = currentIndex0; i <=currentIndex2;i++ ){
        temp[i] = 1;
    }
    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}