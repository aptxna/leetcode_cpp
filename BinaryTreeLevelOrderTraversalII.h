/**
 * Dfinition for binary tree
 * struct TreeNode {
 * 	int val;
 * 	TreeNode *left;
 * 	TreeNode *right;
 * 	TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeLevelOrderTraversalII {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res; // 定义一个二维向量，用来输出倒序后的层结点值
		vector<int> levelNode; // 定义一个一维向量，用来暂存每层结点值
		queue<TreeNode*> queueNode; // 定义一个队列，用来存结点
		if (root == NULL) return res;
		queueNode.push(root); // 输入根结点
		queueNode.push(NULL); // NULL是层分隔符
		while (!queueNode.empty()) { // 如果队列不为空
			TreeNode *p = queueNode.front(); // 让指针p指向队列头结点
			queueNode.pop(); // 从队列里删除该结点
			if (p != NULL) { // 若p非空
				levelNode.push_back(p->val); // 向一维向量levelNode添加p的值
				if (p->left) queueNode.push(p->left); // p结点的左孩子入队列
				if (p->right) queueNode.push(p->right); // p结点的右孩子入队列
			}
			else { // 若p为空
				res.push_back(levelNode); // 将一维向量值push到二维向量组
				// 若队列不为空，清空一维向量levelNode并给队列queueNode插入一个层分隔符
				// 否则会进入死循环
				if (!queueNode.empty()) {
					levelNode.clear();
					queueNode.push(NULL);
				}
			}
		}
		reverse(res.begin(),res.end());   // std::reverse()
		return res;
	}
};
