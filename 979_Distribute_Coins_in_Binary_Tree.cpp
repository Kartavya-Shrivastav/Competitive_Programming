/*
979. Distribute Coins in Binary Tree (Medium)

You are given the root of a binary tree with n nodes where each node in the tree has node->val coins. There are n coins in total throughout 
the whole tree. In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child,
or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin. 

Example 1:
      3
     / \
    0   0
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
      0
     / \
    3   0
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the 
tree to the right child.
 

Constraints:
The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node->val is n.


* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

*/


/* -------------------------------------------------------------------------------------------------------------------------------------------

Approach: 
At each node, the number of coins that need to be moved to or from its children is determined by the difference between the coins present 
and the coins needed (which is 1 per node).

Recursive Traversal:
    The function traverse() recursively visits each node in post-order (left, right, root).

Calculate Excess/Deficit:
    For each node, it calculates:
    left: the net coins to move from the left subtree.
    right: the net coins to move from the right subtree.

Count Moves:
    The number of moves needed at the current node is the sum of the absolute values of left and right (because each coin moved between
    nodes counts as one move).

Return Net Coins:
    The function returns root->val + left + right - 1, which is:

    The total coins at this node and its subtrees, Minus the number of coins needed (1 for this node),
    This value is passed up to the parent to indicate how many coins need to be moved in or out of this subtree.

Final Answer:
    The total number of moves is accumulated in the moves variable that is the final answer.

Steps:
    1. Define the TreeNode structure.
    2. Implement a recursive function to traverse the tree.
    3. Calculate the number of moves required to balance the coins at each node.
    4. Use the absolute value of the left and right subtree results to count moves.
    5. Return the total moves after traversing the entire tree.

-------------------------------------------------------------------------------------------------------------------------------------------- */


class Solution {
public:
    int traverse(TreeNode* root, int &moves) {
        if (root == nullptr) return 0;
        int left = traverse(root->left, moves);
        int right = traverse(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traverse(root, moves);
        return moves;
    }
};
