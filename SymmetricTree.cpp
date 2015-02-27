/**
 * Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself
 * ie, eymmetric around its center
 *
 * Definition for binary tree
 * struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
 */

class SymmetricTree {
public:
	bool isSymmetric(TreeNode *root) {
		if (!root)
			return true;
		vector<TreeNode* > symtr;
		symtr.push_back(root);
		int currentLevelNodes = 1;
		while(!symtr.empty()) {
			int i = 0;
			while (i < currentLevelNodes) {
				TreeNode *temp = symtr[i];
				i++;
				if (temp == NULL)
					continue;
				symtr.push_back(temp->left);
				symtr.push_back(temp->right);
			}
			int start = 0;
			int end = currentLevelNodes - 1;
			while (start < end) {
				TreeNode *currentLeft = symtr[start];
				TreeNode *currentRight = symtr[end];
				int left = currentLeft == NULL ? INT_MIN : currentLeft->val;
				int right = currentRight == NULL ? INT_MIN : currentRight->val;
				if (left != right)
					return false;
				start++;
				end--;
			}
			symtr.erase(symtr.begin(), symtr.begin()+currentLevelNodes);
			currentLevelNodes = symtr.size();
		}

		return true;
	}
};