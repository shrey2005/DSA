Given two values, n and r, write a function to calculate the permutation (nPr) for n ≥ r ≥ 0. The function should return -1 if n < r or if n or r are negative. The program should include two functions: one to calculate the factorial of a number and another to calculate the permutation.

Function Input:
n (int): The total number of objects.
r (int): The number of objects taken at a time for the permutation.
Output:
The function will return the calculated permutation (nPr) in integer format. 
Handle input cases where r is greater than n. The function will return "please enter n >= r >= 0".
Sample Input 1
6 5 
Sample Output 1
720
Sample Input 2
5 6
Sample Output 2
please enter n >= r >= 0