int totalSum(int input[][501], int n)
{
    //Write your code here
    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || (i + j) == n - 1){
                sum += input[i][j];
            }
            else if(i == 0 || j == 0 || i == n - 1 || j == n - 1){
                sum += input[i][j];
            }
        }
    }
    return sum;
}