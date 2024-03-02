void Leaders(int arr[],int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
    for(int i = 0; i <len; i++){
        bool flag = false;
        for(int j = i+1 ; j < len; j++){
            if(arr[i] < arr[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<arr[i]<<" ";
        }
    }
}