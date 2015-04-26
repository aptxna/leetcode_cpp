/*
 * Two Sum
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 * 复杂度为O(n*n)的暴力法会time exceeded，需要用hash map达到O(n)的复杂度
 *
 */

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> indexNumber;
        
        for (int i=0; i<nums.size(); i++) {
            //用hash map来映射数组值到下标，确保了唯一的值
            //因为hash map会忽略后面相同值的插入，确保了只保留相同值中最小的i
            indexNumber[nums[i]] = i;
        }
        
        for (int i=0; i<nums.size(); i++) {
            //如果hash map中找到了target－nums[i]的键值，则可以找到这两个数相加为target
            if (indexNumber.find(target - nums[i]) != indexNumber.end()) {
                if (i < indexNumber[target - nums[i]]) {
                    //将下标按序存入result
                    result.push_back(i + 1);
                    result.push_back(indexNumber[target - nums[i]] + 1);
                    return result;
                }
                if (i > indexNumber[target - nums[i]]) {
                    result.push_back(indexNumber[target - nums[i]] + 1);
                    result.push_back(i + 1);
                    return result;
                }
            }
        }
    }
};