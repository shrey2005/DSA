void prefixSum(int arr[],int n,int output[]){
    //Write your code here

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+= arr[i];
        output[i] = sum;
    }
}