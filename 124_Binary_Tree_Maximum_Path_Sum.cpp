/*
124. Binary Tree Maximum Path Sum (Hard)

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can 
only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
      1
     / \
    2   3
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
    -10
    /  \
    9  20
      /  \
     15   7
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 
Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000


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
    The goal is to find the maximum path sum in a binary tree where the path can start and end at any node.

    Recursive Traversal:
    The function helper() performs a post-order traversal (left, right, root) to compute the maximum gain from each subtree.

    Prune Negative Paths:
    For each node, if a subtree contributes a negative gain, it is ignored by taking max(subtree, 0).

    Calculate Local Maximum Path:
    At each node, we calculate the local maximum path sum which includes the node and the maximum gains from both left and right subtrees:
    localSum = node->val + leftGain + rightGain

    Update Global Maximum:
    We keep track of the global maximum path sum (ans) and update it with the local sum if it's larger.

    Return to Parent:
    The function returns the maximum gain that can be obtained by including the current node and either its left or right subtree, used to continue the path upward.


Steps:
    1. Define the TreeNode structure representing nodes in the binary tree.
    2. Create a recursive helper function that:
        - Returns 0 for null nodes (base case).
        - Recursively computes the maximum gain from the left and right subtrees.
        - Prunes negative contributions using max(subtreeGain, 0).

    3. For each node, calculate the local path sum as: node->val + left + right
    4. Update the global ans variable with the maximum of current ans and local path sum.
    5. Return to the parent: node->val + max(left, right) so the parent can extend the path with the highest single-branch contribution.
    6. Call the helper function from maxPathSum() and return the global maximum ans.


---------------------------------------------------------------------------------------------------------------------------------------------
*/


class Solution {
public:
    int ans = INT_MIN;

    int helper(TreeNode* node) {
        if (!node) return 0;
        int left = max(helper(node->left), 0);
        int right = max(helper(node->right), 0);
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};