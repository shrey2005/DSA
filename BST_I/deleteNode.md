You have been given a Binary Search Tree of integers with ‘N’ nodes. You are also given data of a node of this tree. Your task is to delete the given node from the BST.

A binary search tree (BST) is a binary tree data structure that has the following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.
Example:
For the given BST, if we want to delete the node with data 5 :
Input

The modified BST will be:
Ouput

Please notice that another valid answer is:
Output

Note :

1. The node which we want to delete will always be present in the given tree.

2. If after deletion the tree becomes empty, print -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <=5000
0<= data <=10^5
Where ‘N’ is the number of nodes in the binary search tree and ‘data' denotes data contained in the node of the binary search tree.

Time limit: 1 sec
Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12 15 16 20 25 
Explanation of Sample output 1:
The tree can be represented as follows:
Example

After the deletion of the node with data 10 the BST will be:
Output

The inorder traversal of this modified BST is 8 12 15 16 20 25.

Another valid modified BST can be:
Output

The inorder traversal of this modified BST is also 8 12 15 16 20 25.
Sample Input 2:
6 4 -1 -1 5
6
Sample output 2:
4 5
Explanation of Sample Output 2:
The tree can be represented as follows:
Example

After the deletion of the node with data 6 the BST will be:
Output

The inorder traversal of this modified BST is 4 5.

