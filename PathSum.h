/**
 * Path Sum
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Definition for binary tree
 * struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
 */

/**
 * 递归算法
 */

 class PathSumSol1 {
 public:
 	bool hasPathSum(TreeNode *root, int sum) {
 		if (root == NULL) return false;
 		if (root->left == NULL && root->right == NULL)
 			return root->val == sum;

 		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
 	}
 };

 /**
  * 非递归
  */

  class PathSumSol2 {
  public:
  	bool hasPathSum(TreeNode *root, int sum) {
  		if (root == NULL) return false;
  		stack<TreeNode* > node;
  		stack<int> temp;

  		node.push(root);
  		temp.push(root->val);

  		while(!node.empty()) {
  			TreeNode *tempNode = node.top();
  			node.pop();
  			int tempSum = temp.top();
  			temp.pop();

  			if (!tempNode->left && !tempNode->right && tempSum == sum)
  				return true;

  			if (tempNode->left) {
  				node.push(tempNode->left);
  				temp.push(tempSum + tempNode->left->val);
  			}

  			if (tempNode->right) {
  				node.push(tempNode->right);
  				temp.push(tempSum + tempNode->right->val);
  			}
  		}

  		return false;
  	}
  };