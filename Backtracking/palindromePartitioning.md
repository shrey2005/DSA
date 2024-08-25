You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

Note: A substring is a contiguous segment of a string.

For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= |S|<= 15
where |S| denotes the length of string 'S'.

Time Limit: 1 sec.
Sample Input 1:
aaC
Sample Output 1:
["C", "a", "a"]
["C", "aa"]
Explanation for input 1:
For the given string "aaC" there are two partitions in which all substring of partition is a palindrome.
Sample Input 2:
BaaB
Sample Output 2:
["B", "B", "a", "a"]
["B", "B", "aa"]
["BaaB"]
Explanation for input 2:
For the given string "BaaB", there are 3 partitions that can be made in which every substring is palindromic substrings.