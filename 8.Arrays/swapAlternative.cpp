void swapAlternate(int arr[], int size)
{
   int count = 0;
    int oddIndex = 0, eventIndex = 1, oddVal = 0, evenVal = 0;
    for(int i = 0 ; i < size/2; i++){
        oddVal = arr[oddIndex];
        evenVal = arr[eventIndex];
        arr[count] =  evenVal;
        count = count + 1;
        arr[count] = oddVal;
        count = count + 1;
        eventIndex=eventIndex+2;
        oddIndex=oddIndex+2;
    }
    
}