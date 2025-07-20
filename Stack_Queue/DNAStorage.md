For encoding an even-length binary string into a sequence of A, T, C, and G, we iterate from left to right and replace the characters as follows:

00 is replaced with A
01 is replaced with T
10 is replaced with C
11 is replaced with G
Given a binary string S of length N(N is even), find the encoded sequence.

Input: 
4
2
00
4
0011
6
101010
4
1001

Output:
A
AG
CCC
CT