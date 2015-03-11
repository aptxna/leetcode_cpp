/**
 * 3Sum
 *
 * Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0 ?
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * Elements in a triplets(a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */

class ThreeSum {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	//先排序
        sort(num.begin(), num.end());
        //result用来存放solution set
        vector<vector<int> > result;

        for (int i=0; i<num.size(); i++) {
            int target = 0 - num[i];
            //一前一后两指针
            int start = i+1, end = num.size() - 1;
            while (start < end) {
                if (num[start] + num[end] == target) {
                	//solution用来存放相加为0的三个数
                    vector<int> solution;
                    solution.push_back(num[i]);
                    solution.push_back(num[start]);
                    solution.push_back(num[end]);
                    result.push_back(solution);
                    start++;
                    end--;
                    //过滤掉内层循环重复的数
                    while (start < end && num[start] == num[start-1]) start++;
                    while (start < end && num[end] == num[end+1]) end--;
                }
                else if (num[start] + num[end] < target)
                    start++;
                else
                    end--;
            }
            
            if (i < num.size() - 1) {
            	//过滤掉外层循环重复的数
                while (num[i] == num[i+1])
                    i++;
            }
        }
        
        return result;
    }
};