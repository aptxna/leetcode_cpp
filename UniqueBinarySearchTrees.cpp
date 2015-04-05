/* 
 * Unique Binary Search Trees
 * 
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 * This is a Dynamic Programming problem
 * 
 * 参考：
 * 
 * http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
 * 
 * http://yucoding.blogspot.com/2013/04/leetcode-question-114-unique-binary.html
 * 
 */

class UniqueBinarySearchTree {
public:
    int numTrees(int n) {
        vector<int> count(n+1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                count[i] += count[j] * count[i-j-1];
            }
        }
        
        return count[n];
    }
};