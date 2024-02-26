Problem statement
You have been provided with an empty array (ARR) and its size N. The user will only input the value of N, and you don't need to be concerned about the array itself.

Your objective is to fill the array using integer values from 1 to N (inclusive), following the specific order: 1, 3, 5, ..., 6, 4, 2.

Note:
Printing the array is not required. Your task is solely to fill it.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^4
Time Limit: 1sec
Sample Input 1 :
6
Sample Output 1 :
1 3 5 6 4 2
Explanation of Sample Input 1 :
Since the value of N is 6, the number will be stored in the array in such a fashion that 1 will appear at 0th index, then 2 at the last index, in a similar fashion 3 is stored at index 1. Hence the array becomes 1 3 5 6 4 2.
Sample Input 2 :
9
Sample Output 2 :
1 3 5 7 9 8 6 4 2
void arrange(int arr[], int n)
{
    int evenIndex = n - 1;
    int oddIndex = 0;
     for(int i = 0; i < n; i++){
        if(i%2 == 0){
            arr[oddIndex] = i + 1;
            oddIndex++;
        }
        else{

