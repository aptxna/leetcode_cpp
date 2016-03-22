/**
 * Move Zeroes
 *
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * http://fisherlei.blogspot.com/2015/10/leetcode-move-zeroes-solution.html
 */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index0;
        int index1;
        int temp;
        for (index0=0, index1=0; index0<nums.size() && index1<nums.size(); ) {
            if (nums[index0]!=0) {
                index0++;
                index1 = index0; //这句很重要，否则0将会排在前面而不是往后换位
                continue;
            }
            
            if (nums[index1]==0) {
                index1++;
                continue;
            }
            
            temp = nums[index0];
            nums[index0] = nums[index1];
            nums[index1] = temp;
            
            index0++;
            index1++;
        }
    }
};