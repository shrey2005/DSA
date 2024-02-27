void wavePrint(int input[][1001], int nRows, int mCols)
{

   for(int i = 0; i < mCols; i++){
       for(int j = 0; j < nRows; j++){
           int count = 0;
           if(i % 2 == 0){
               count = j;
           }
           else{
               count = nRows - j - 1;
           }
           cout<<input[count][i]<<" ";
       }
   }
}