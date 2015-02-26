/**
 * Minimum Depth of Binary Tree
 * Given a binary tree, find its minimum depth
 * the minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
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

  class MinDepthSol1 {
  public:
  	int minDepth(TreeNode *root) {
  		if (!root) return 0;
  		int lmin = minDepth(root->left);
  		int rmin = minDepth(root->right);

  		if (lmin==0 && rmin==0) return 1;

  		if (lmin==0) lmin = INT_MAX;
  		if (rmin==0) rmin = INT_MAX;

  		return min(lmin, rmin) + 1;
  	}
  };

  /**
   * 非递归
   * lastLevelNodes表示上一层结点数
   * currentLevelNodes表示当前层结点数
   * currentLevel表示当前层数
   */

   class MinDepthSol2 {
   public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode* > minDep;
        minDep.push(root);
        int lastLevelNodes = 1;
        int currentLevelNodes = 0;
        int currentLevel = 1;
        
        while(!minDep.empty()) {
            TreeNode *temp = minDep.front();
            minDep.pop();
            lastLevelNodes--;
            
            if (temp->left==NULL && temp->right==NULL)
                return currentLevel;
                
            if (temp->left!=NULL) {
                minDep.push(temp->left);
                currentLevelNodes++;
            }
            
            if (temp->right!=NULL) {
                minDep.push(temp->right);
                currentLevelNodes++;
            }
            
            if (lastLevelNodes==0) {
                lastLevelNodes = currentLevelNodes;
                currentLevelNodes = 0;
                currentLevel++;
            }
        }
        
        return 0;
    }
   };

   /**
    * 非递归
    * 用了两个queue
    * 一个用来存父结点
    * 一个用来存子结点
    * 分开的好处是好计算层
    * 父结点queue空的时候，层数加一
    * 令父结点queue等于自结点queue，子结点queue清空
    * 如此循环
    */

    class MinDepthSol3 {
    public:
      int minDepth(TreeNode *root) {  
        if(root == NULL) return 0;  
          
        queue<TreeNode*> Current;  
        Current.push(root);  
        queue<TreeNode*> Next;  
        //初始深度若根结点非空，为1 注意和Maximum Depth of Binary Tree构造的区别，算法不一样。  
        int depth = 1;  
          
        while(!Current.empty())  
        {  
            while(!Current.empty())  
            {  
                TreeNode* node = Current.front();  
                Current.pop();  
                if(node->left == NULL && node->right == NULL)   return depth;  
                if(node->left) Next.push(node->left);  
                if(node->right) Next.push(node->right);  
            }  
              
            queue<TreeNode*> t;   //初始化Next,并将Next赋给Current.总是保存当前这一层节点。  
            Current = Next;  
            Next = t;  
            depth++;  
        }  
          
        return depth;
      }
    };