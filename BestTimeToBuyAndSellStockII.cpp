/*
 * Best Time to Buy and Sell Stock II
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * 
 * http://yucoding.blogspot.com/2012/12/leetcode-question-9-best-time-to-buy.html
 */

class BestTimeToBuyAndSellStockII {
public:
    int maxProfit(vector<int> &prices) {
        int maxprofit = 0;
        if (prices.size() < 2)
            return maxprofit;
            
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                maxprofit += prices[i] - prices[i-1];
            }
        }
        
        return maxprofit;
    }
};