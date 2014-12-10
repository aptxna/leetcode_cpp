class FindPeakElement {
public:
	int binarySearch(const vector<int> a, int left, int right, int size)
	{
		int mid = left + (right - left)/2;
		if ((mid == 0 || a[mid-1] < a[mid]) && (mid == size-1 || a[mid+1] < a[mid]))
			return mid;
		else if (mid > 0 && a[mid-1] > a[mid])
			return binarySearch(a, left, mid-1, size);
		else return binarySearch(a, mid+1, right, size);
	}

	int findPeakElement(const vector<int> &num) {
		int n = num.size();
		return binarySearch(num, 0, n-1, n);
	}
}
