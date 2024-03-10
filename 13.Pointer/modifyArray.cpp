void modify(int *ar,int n)
{
	//write your code here
	int *min = &ar[0];
    int *max = &ar[0];
    for(int i = 0; i < n ; i++){
        if(*min > ar[i]){
            min = &ar[i];
        }
        if(*max < ar[i]){
            max = &ar[i];
        }
    }
    *min = 0;
    *max = 100;
}