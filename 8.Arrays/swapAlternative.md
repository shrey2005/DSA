ou have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array.

You don't need to print or return anything, just change in the input array itself.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
First line of contains an integer 'N' representing the size of the array.

Second line contains 'N' single space separated integers representing the elements in the array.
Output Format :
First line contains the elements of the resulting array in a single row separated by a single space.
Constraints :
0 <= N <= 10^5
Time Limit: 1sec
Sample Input 1:
6
9 3 6 12 4 32
Sample Output 1 :
3 9 12 6 32 4
Sample Input 2:
9
9 3 6 12 4 32 5 11 19
Sample Output 2 :
3 9 12 6 32 4 11 5 19 
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

