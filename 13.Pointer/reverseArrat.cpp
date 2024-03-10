void reverse(int *ar,int n)
{
	//write your code here
    int i = 0;
    int j = n - 1;
    
    while(i<j){
        int temp = *(ar+i);
        *(ar+i) = *(ar+j);
        *(ar+j) = temp;
        i++;
        j--;
    }
}