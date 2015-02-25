/**
 * 解题思路一：
 * 1. 将整个数组反转
 * 2. 将由分割点分割的两个数组分别反转
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

class RotateArraySol1 {
public:
	void rotate(int nums[], int n, int k) {
		k = k % n;
		reverse(nums, 0, n-1);
		reverse(nums, 0, k-1);
		reverse(nums, k, n-1);
	}

	void reverse(int array[], int left, int right) {
		while (left < right) {
			int temp = array[left];
			array[left++] = array[right];
			array[right--] = temp;
		}
	}
};

/**
 * 解题思路二：
 * 将数组看成一个环，每个元素每次往前一步
 * 循环k次，每次循环需移动n个元素
 * 时间复杂度：O(k*n)
 * 空间复杂度：O(1)
 */

class RotateArraySol2 {
public:
	void rotate(int nums[], int n, int k) {
		k = k % n;
		while (k--) {
			int temp = nums[n-1];
			for (int i = n-1; i > 0; i--) {
				nums[i] = nums[i-1];
			}
			nums[0] = temp;
		}
	}
};

/**
 * 解题思路三：
 * 复制一个新数组
 * 对每一个元素，找到新旧数组元素的映射关系
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

 class RotateArraySol3 {
 public:
 	void rotate(int nums[], int n, int k) {
 		int *temp = new int[n];
 		memcpy(temp, nums, n*sizeof(int));

 		k = k % n;
 		for (int i = 0; i < n; i++) {
 			nums[i] = temp[(n-k+i)%n];
 		}

 		delete[] temp;
 	}
 };