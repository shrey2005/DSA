


int findUnique(int arr[], int size)
{

    int uniqueNum = 0;
    int repatedCount = 0;
    for(int i = 0 ; i < size; i++){
        repatedCount = 0;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]){
                repatedCount++;
            }
        }
        if(repatedCount == 1){
            return arr[i];
        }
    }
}