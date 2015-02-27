/**
 * Same Tree
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
 * 递归
 */

 class SameTreeSol1 {
 public:
 	bool isSameTree(TreeNode *p, TreeNode *q) {
 		if (!p && !q)
 			return true;
 		if (!p || !q)
 			return false;
 		return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
 	}
 };


 /**
  * 非递归
  * 用了两个栈分别存这两棵二叉树
  */

  class SameTreeSol2 {
  public:
  	bool isSameTree(TreeNode *p, TreeNode *q) {
  		if (!p && !q)
  			return true;
  		if (!p || !q)
  			return false;

  		stack<TreeNode* > pst;
  		stack<TreeNode* > qst;
  		pst.push(p);
  		qst.push(q);

  		while (!pst.empty() && !qst.empty()) {
  			TreeNode *tp = pst.top();
  			TreeNode *tq = qst.top();

  			pst.pop();
  			qst.pop();

  			if (tp == NULL && tq == NULL)
  				continue;
  			if (tp == NULL || tq == NULL)
  				return false;
  			if (tp->val != tq->val)
  				return false;

  			pst.push(tp->left);
  			pst.push(tp->right);

  			qst.push(tq->left);
  			qst.push(tq->right);
  		}

  		if (pst.size() != 0 || qst.size != 0)
  			return false;

  		return true;
  	}
  };