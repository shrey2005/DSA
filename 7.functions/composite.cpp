bool print_composite(int n)
{
    //Write your code here

    int count = 0;
 
    for(int i = 2; i <= n/2; i++){
            if( n % i == 0){
                count++;
                break;
            }
        }
        if(n != 1 && count > 0){
            return true;
        }
    return false;
}