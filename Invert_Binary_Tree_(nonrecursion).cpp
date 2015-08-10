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
 * 翻转二叉树，非递归算法
 *
 */

// Non-Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};