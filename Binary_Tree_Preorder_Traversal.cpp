/**
 * Binary Tree Preorder Traversal
 * 
 * Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},
       1
        \
         2
        /
       3
    return [1,2,3].

    Note: Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rs;
        if (!root) return rs;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            rs.push_back(temp->val);
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        return rs;
    }
};