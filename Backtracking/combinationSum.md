You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.



Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.



Elements in each combination must be in non-decreasing order.



For example:
Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 8
2 3 5
Sample Output 1:
Yes
Explanation Of Sample Input 1 :
All possible valid combinations are:
2 2 2 2
2 3 3
3 5
Sample Input 2 :
3 5
1 2 3 
Sample Output 2:
Yes
Constraints:
1 <= 'N' <= 15
1 <= 'B' <= 20
1 <= 'ARR[i]' <= 20

Time Limit: 1sec
