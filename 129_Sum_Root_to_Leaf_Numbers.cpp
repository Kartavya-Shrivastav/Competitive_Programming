/*
129. Sum Root to Leaf Numbers (Medium)

You are given the root of a binary tree containing digits from 0 to 9 only. Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123. Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:
          1
         / \
        2   3
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
         4
        / \
       9   0
      / \
     5   1
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


Constraints:
The number of nodes in the tree is in the rang[1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.


Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

---------------------------------------------------------------------------------------------------------------------------------------------

Approach:
    We use Depth-First Search (DFS) to traverse all root-to-leaf paths in the binary tree. While traversing, we maintain the current path 
    number by appending each node's value to a running total (treating it like building digits of a number). Once a leaf is reached, the 
    current number is returned. The sum of all such numbers is accumulated and returned as the final result.
    This uses recursive DFS with backtracking to explore all paths and construct numbers from the root to each leaf.

Steps:
    1. Start DFS traversal from the root node with an initial path sum of 0.
    2. At each node, multiply the current path by 10 and add the node’s value to simulate digit formation.
    3. Check if the node is a leaf node (both children are null):
        - If it is, return the formed number as one complete root-to-leaf number.
    4. If not a leaf, recursively call DFS on the left and right children and accumulate the result.
    5. Return the sum of all root-to-leaf numbers after the traversal completes.

---------------------------------------------------------------------------------------------------------------------------------------------

*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int path) {
        if (!node) return 0;
        path = path * 10 + node->val;
        if (!node->left && !node->right) return path;
        return dfs(node->left, path) + dfs(node->right, path);
    }
};