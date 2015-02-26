/**
 * Maximum Depth of Binary Tree
 * 
 * Definitionf or binary Tree
 * struct TreeNode {
	int val'
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
 */

class MaxDepBinaryTree {
public:
	int maxDepth(TreeNode *root) {
		if (!root) return 0;
		queue<TreeNode* > maxDep;
		maxDep.push(root);
		int lastLevelNodes = 1;
		int currentLevelNodes = 0;
		int currentLevel = 0;

		while(!maxDep.empty()) {
			TreeNode *temp = maxDep.front();
			maxDep.pop();
			lastLevelNodes--;

			if (temp->left != NULL) {
				maxDep.push(temp->left);
				currentLevelNodes++;
			}

			if (temp->right != NULL) {
				maxDep.push(temp->right);
				currentLevelNodes++;
			}

			if (lastLevelNodes == 0) {
				lastLevelNodes = currentLevelNodes;
				currentLevelNodes = 0;
				currentLevel++;
			}
		}

		return currentLevel;
	}
};