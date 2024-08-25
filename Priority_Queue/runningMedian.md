You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

Print only the integer part of the median.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
#include <queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n == 0){
        return;
    }
    priority_queue<int, vector<int>, greater<int>> maxpq;
    priority_queue<int> minpq;
    
…        if(i % 2 == 0){
            cout<<" "<<minpq.top();
        }
        else{
            int calMed = (minpq.top() + maxpq.top()) / 2;
            cout<<" "<<calMed;
        }
    }
}
