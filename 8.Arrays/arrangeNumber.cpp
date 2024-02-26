void arrange(int arr[], int n)
{
    int evenIndex = n - 1;
    int oddIndex = 0;
     for(int i = 0; i < n; i++){
        if(i%2 == 0){
            arr[oddIndex] = i + 1;
            oddIndex++;
        }
        else{
            arr[evenIndex] = i + 1;
            evenIndex--;
        }
    }
    
}