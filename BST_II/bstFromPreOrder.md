You are given a preorder traversal of a binary search tree. Your task is to find the postorder from the preorder.



Return the root of the BST constructed from the given preorder. The driver code will then use this root to print the post-order traversal.



For example:
You are given preOrder = [10, 5, 1, 7, 40, 50], the binary search tree from the given preorder traversal is 
sample1

Hence the answer is [1, 7, 5, 50, 40, 10].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1
6
8 5 1 7 10 12
Sample Output 1:
1 7 5 12 10 8 
Explanation:
preOrder = [8, 5, 1, 7, 10, 12], the binary search tree from the given preorder traversal is 
sample2

Hence the answer is [1, 5, 7, 10, 40, 50].
Sample Input 2:
3
1 3 2
Sample Output 2:
2 3 1 
Constraints:
 1 <= N <= 10^5
 1 <= preorder[i] <= 10^6

Time Limit: 1 sec.
