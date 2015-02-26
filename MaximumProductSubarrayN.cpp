class MaxProductN {
public:
	int maxProduct(int A[], int n) {
		int localMax = A[0];
		int localMin = A[0];
		int globalMax = A[0];
		for (int i = 1; i < n; ++i) {
			int temp1 = localMax * A[i];
			int temp2 = localMin * A[i];
			localMax = max(max(temp1, temp2), A[i]);
			localMin = min(min(temp1, temp2), A[i]);
			globalMax = max(globalMax, localMax);
		}
		return globalMax;
	}
};
