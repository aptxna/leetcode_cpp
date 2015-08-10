/**
 * Lowest Common Ancestor of a Binary Search Tree
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants
 * (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
 * Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
 * 题目求二叉查找树中给定两值的最近公共父结点
 * 根据二叉查找树的特点，这样的结点一定大于等于给定两值中的较小值，小于等于给定两值中的较大值
 * 若给定两值中的较大值小于root结点，则这样的公共结点一定在root结点的左子树
 * 若给定两值中的较小值大于root结点，则这样的公共结点一定在root结点的右子树
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minvalue = min(p->val, q->val);
        int maxvalue = max(p->val, q->val);
        while (root != NULL) {
            if (minvalue <= root->val && root->val <= maxvalue) return root;
            else if (maxvalue < root->val) root = root->left;
            else if (root->val < minvalue) root = root->right;
            else return NULL;
        }
    }
};