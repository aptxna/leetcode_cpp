/**
 * Invert Binary Tree
 *
 * Invert a binary tree.

         4
       /   \
      2     7
     / \   / \
    1   3 6   9

    to

         4
       /   \
      7     2
     / \   / \
    9   6 3   1
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 翻转二叉树，递归算法
 *
 */

// Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};