class MaxProductNN {
public:
    int maxProduct(int A[], int n) {
        int maxp = A[0];
        for (int i = 0; i < n; ++i) {
            int temp = 1;
            for (int j = i; j < n; ++j) {
                temp *= A[j];
                if (temp > maxp) maxp = temp;
            }
        }
        return maxp;
    }
};