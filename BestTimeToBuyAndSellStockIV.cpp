/*
 * Best Time to Buy and Sell Stock IV
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;
        priority_queue<int> profit;
        stack<pair<int,int>> vp;
        int valley, peak=0, result=0;
        
        while (peak < n) {
            //valley是当前上升序列的第一个数，即当前上升序列的极小值
            for (valley = peak; valley < n - 1 && prices[valley] > prices[valley+1]; valley++);
            //peak是当前上升序列最末之后的一个数，即当前上升序列极大值之后的数值，比当前极大值小
            for (peak = valley + 1; peak < n && prices[peak] >= prices[peak-1]; peak++);
            
            //如果前一个序列的极小值比当前序列的极小值大
            //则将前一个序列的max profit入队列
            while (!vp.empty() && prices[vp.top().first] > prices[valley]) {
                profit.push(prices[vp.top().second-1] - prices[vp.top().first]);
                vp.pop();
            }
            
            //如果前一个上升序列的极大值比当前序列的极大值小
            //则将前一个序列的极大值与当前极小值的差价入队列
            while (!vp.empty() && prices[vp.top().second-1] < prices[peak-1]) {
                profit.push(prices[vp.top().second-1] - prices[valley]);
                valley = vp.top().first; //当前极小值的下标要移动到前一序列的极小值处，两序列合并
                vp.pop();
            }
            
            vp.push(make_pair(valley, peak));
        }
        
        while (!vp.empty()) {
            //各上升序列的max profit入队列
            profit.push(prices[vp.top().second-1] - prices[vp.top().first]);
            vp.pop();
        }
        
        for (int i = 0; i < k && !profit.empty(); i++) {
            result += profit.top();
            profit.pop();
        }
        
        return result;
    }
};


/*
 * 动态规划解法
 *
 * http://www.cnblogs.com/grandyang/p/4295761.html
 *
 * http://blog.csdn.net/linhuanmars/article/details/23236995
 *
 */

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return quickSolve(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int quickSolve(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};