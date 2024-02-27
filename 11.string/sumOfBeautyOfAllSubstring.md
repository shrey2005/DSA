You are given a string ‘S’ of length ‘N’ representing an integer.



Beauty of a string is the difference between the frequency of the most frequently occurring character and the least frequently occurring character.



You must return the sum of beauty of all substrings of string ‘S’.



Note:
A substring is a string formed after deleting zero or more characters from both ends of a string.


Example:
Input:
S = “hello"

Output:
5

Explanation: The following substring ‘hell’, ‘ell’, ‘llo’, ‘ello’, and ‘hello’ has the beauty of 1. Hence we return 5.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
aaaa


Sample Output 1:
0


Explanation Of Sample Input 1:
For test case one:

Input:
S = 'aaaa', N = 4

Output:
0

Explanation: All substrings have the same character. Hence all the substrings have a beauty of 0. 
Hence we return 0.


Sample Input 2:
8
tortoise


Sample Output 2:
9


Constraints:
1 <= N <= 500
’S’ consists of lowercase English letters.    
Time Limit: 1 sec
Follow Up:
Can you solve this in O(N) time?
