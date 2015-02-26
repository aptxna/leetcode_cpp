/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m+n)
 * to hold additional elements from B. The number of elements initialized in A
 * and B are m and n respectively.
 * 思路一：从前向后比较A和B，较小的先放入动态数组内，
 * 其中一组比较完后，继续存入另一数组余下的数字，
 * 最后将动态数组复制给A，释放动态数组内存。
 */

class MergeSortedArray {
public:
	void merge(int A[], int m, int B[], int n) {
		int* p = (int*)malloc(sizeof(int)*(m+n));
		int i=0, j=0, k=0;
		while (i<m && j<n) {
			p[k++]=A[i]<B[j]?A[i++]:B[j++];
		}
		while (i<m) {
			p[k++]=A[i++];
		}
		while (j<n) {
			p[k++]=B[j++];
		}
		for (k=0; k<m+n; k++) {
			A[k]=p[k];
		}
		free(p);
	}
};

/**
 * 思路二：从后向前填充A数组，比较A和B，较大的数放入A数组尾端，
 * 直到其中一个数组比较完，如果B数组先比较完，则A数组前端不需改变，
 * 若A数组先比较完，则将B数组余下的数字填入A数组前端。
 */

class MergeSortedArray {
public:
	void merge(int A[], int m, int B[], int n) {
		int i=m-1, j=n-1, k=m+n-1;
		while (i>=0 && j>=0) {
			A[k--]=A[i]>B[j]?A[i--]:B[j--];
		}
		while (j>=0) {
			A[k--]=B[j--];
		}
	}
};
