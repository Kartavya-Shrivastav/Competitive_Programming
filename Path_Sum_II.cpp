/*
113. Path Sum II (Medium)

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path 
equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children. 

Example 1:
          5
         / \
        4   8
       /   / \
     11  13   4
    /  \     / \
   7    2   5   1

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22


Example 2:
         1
        / \
       2   3

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: [] 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000


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
    The goal is to find all root-to-leaf paths in a binary tree such that the sum of node values in each path equals a given target sum.

    Recursive Traversal:
    The function compute() performs a pre-order traversal of the tree (current node, then left and right subtrees).

    Path Construction:
    It keeps track of the current path (path) and the cumulative sum (sum) as it traverses down the tree.

    Path Validation:
    When a leaf node is reached and the sum matches target, the current path is valid and added to the result.

    Backtracking:
    After exploring both left and right children, the last node is removed from path to allow correct path tracking for sibling branches.


Steps:
    1. Define the TreeNode structure representing nodes in the binary tree.

    2. Create a recursive helper function compute() that:
        - Takes current node, path, running sum, and target sum as input.
        - Returns immediately if the current node is null.

    3. At each node:
        - Add the node's value to the current sum.
        - Add the node to the current path.

    4. If the current node is a leaf and the running sum equals the target sum:
        - Add the current path to the final answer list.

    5. Recursively call the helper function on the left and right children.
    6. Backtrack by removing the last element from the path after visiting both subtrees.
    7. From pathSum(), initialize the result container and invoke the recursive function with the root and initial values.
    8. Return the list of all valid paths.

---------------------------------------------------------------------------------------------------------------------------------------------

 */
class Solution {
public:

    void compute(vector<vector<int>>& ans, vector<int>& path, TreeNode* node, int sum, int target){
        if(!node) return;
        sum += node->val;
        path.push_back(node->val);
        
        if(target == sum && !node->left && !node->right)
            ans.push_back(path);

        compute(ans, path, node->left, sum, target);
        compute(ans, path, node->right, sum, target);
        
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        compute(ans, path, root, 0, targetSum);
        return ans;
    }
};