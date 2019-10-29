bool TernarySearch(int*arr, int x, int left, int right) {
	if (right < left)
		return false;
	int middle1 = (2 * left + right) / 3;
	int middle2 = (left + 2 * right) / 3;

	if (arr[middle1] == x || arr[middle2] == x)
		return true;
	if (arr[middle1] > x)
		return TernarySearch(arr, x, left, middle1 - 1);

	if (arr[middle2] > x)
		return TernarySearch(arr, x, middle1 + 1, middle2 - 1);

	return TernarySearch(arr, x, middle2 + 1, right);
}
