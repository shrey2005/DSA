int sum(int *ar , int n)
{
    //write your code here
    int sum = 0;
    for(int i = 0; i < n ; i++){
        sum += *(ar+i);
    }
    return sum;
}