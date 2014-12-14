/**
 * Definition for binary tree
 * struct TreeNode {
 * 	int val;
 * 	TreeNode *left;
 * 	TreeNode *right;
 * 	TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeLevelOrderTraversalI {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		queue<TreeNode*> queueNode;
		vector<vector<int> > res;
		vector<int> levelNode;
		if (root == NULL) return res;
		queueNode.push(root);
		queueNode.push(NULL);
		while (!queueNode.empty()) {
			TreeNode *p = queueNode.front();
			queueNode.pop();
			if (p != NULL) {
				levelNode.push_back(p->val);
				if (p->left) queueNode.push(p->left);
				if (p->right) queueNode.push(p->right);
			}
			else {
				res.push_back(levelNode);
				// 如果此时队列不为空，则清空一维向量并为队列加入层分隔符
				// 如果此时队列为空，则不需要再加NULL分隔符
				if (!queueNode.empty()) {
					levelNode.clear();
					queueNode.push(NULL);
				}
			}
		}
		return res;
	}
};
