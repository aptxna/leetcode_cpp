/**
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than
 * ⌊n/2⌋ times.
 * You may assume that the array is non-empty and the majority element
 * always exist in the array.
 */

class MajorityElement {
public:
	int majorityElement(vector<int> &num) {
		//注意这里的num.end是数组最后一个数之后的一个位置
		//不是最后一个数的下标，这和vector.end()一样
		sort(num.begin(), num.end());
		return num[num.size()/2];
	}
};
