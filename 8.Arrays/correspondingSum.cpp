void correspondingPairSum(int arr[],int n,int output[]){
    //Write your code here

    int totalSize = n - 1;
    for(int i = 0; i < n; i++){
        output[i] = arr[i] + arr[totalSize];
        totalSize--;
    }
}