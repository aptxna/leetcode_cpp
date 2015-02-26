/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined
 * as a binary tree in which the depth of the two subtrees of
 * every node never differ by more than 1.
 * Definition for binary tree
 * struct TreeNode {
 * 	int val;
 * 	TreeNode *left;
 * 	TreeNode *right;
 * 	TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */

class BalancedBinaryTree {
public:
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;
		int val = getdep(root);
		if (val == -1) return false;
		return true;
	}

	int getdep(TreeNode *node) {
		if (node == NULL) return 0;
		int left = getdep(node->left);
		if (left == -1) return -1;
		int right = getdep(node->right);
		if (right == -1) return -1;
		if (left - right > 1 || right - left > 1) return -1;
		return left>right? left+1:right+1;
	}
};
