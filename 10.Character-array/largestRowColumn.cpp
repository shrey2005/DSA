int findLargest(int input[][1001], int nRows, int mCols)
{
   int resultarr[nRows+mCols] = {};
   
   int count = 0;
   for(int i = 0; i < nRows; i++){
       for(int j = 0; j < mCols; j++){
            resultarr[count] += input[i][j];
       }
       count++;
   }
   
   for(int i = 0; i < mCols; i++){
       for(int j = 0; j < nRows; j++){
            resultarr[count] += input[j][i];
       }
       count++;
   }
   
   int max = resultarr[0];
   for(int i = 0; i < count; i++){
       if(max < resultarr[i]){
           max = resultarr[i];
       }
   }
   
    return max;
}