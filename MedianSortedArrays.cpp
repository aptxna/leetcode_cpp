/*
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 */

class MedianSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) return 0;
        vector<int> num;
        if (nums1.empty()) num = nums2;
        if (nums2.empty()) num = nums1;
        if (!num.empty()) {
            if (num.size() % 2 == 0)
                return (num[num.size()/2-1] + num[num.size()/2]) / 2.0;
            else
                return num[num.size()/2];
        }
        
        int len = nums1.size() + nums2.size();
        //偶数个元素
        if (len % 2 == 0)
            return (findKth(nums1, 0, nums2, 0, len/2) + findKth(nums1, 0, nums2, 0, len/2+1)) / 2.0;
        //奇数个元素
        else
            return findKth(nums1, 0, nums2, 0, len/2+1);
    }
    
    //find the Kth large number
    int findKth(vector<int>& a, int astart, vector<int>& b, int bstart, int k) {
        if (astart >= a.size()) return b[bstart + k - 1];
        if (bstart >= b.size()) return a[astart + k - 1];
        
        //k=1时，不可能再分了
        if (k == 1) return a[astart] < b[bstart] ? a[astart] : b[bstart];
        
        int key1 = (astart + k/2 - 1) < a.size() ? a[astart + k/2 - 1] : INT_MAX;
        int key2 = (bstart + k/2 - 1) < b.size() ? b[bstart + k/2 - 1] : INT_MAX;
        
        if (key1 < key2)
            //注意这里k-k/2而不是k/2，因为丢弃了k/2个元素，整除是截断不是四舍五入
            return findKth(a, astart+k/2, b, bstart, k-k/2);
        else
            return findKth(a, astart, b, bstart+k/2, k-k/2);
    }
};