/*
1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, 
return any of them. A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
    1                       2                 3
     \                     / \               / \
      2         ->        1   3      or     1   4
       \                       \             \
        3                       4             2
         \
          4

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
    2
   / \
  1   3

Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// -------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Perform an inorder traversal of the BST to collect the nodes in sorted order.
// 2. Store the nodes in a vector.
// 3. Use the sorted nodes to build a balanced BST by recursively selecting the middle element as the root and constructing left and right subtrees.
// 4. Return the newly constructed balanced BST.

// Time Complexity: O(n) for the inorder traversal and O(n) for building the balanced BST, where n is the number of nodes in the tree.
// Space Complexity: O(n) for storing the nodes in a vector.

// -------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    void inorderTraverse(TreeNode* root) {
        if (root == NULL) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};