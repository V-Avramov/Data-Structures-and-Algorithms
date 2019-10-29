bool BinarySearch(int*arr, int x, int start, int end) {		//usable only on sorted arrays!
	if (start > end)
		return false;
	int middle = (end + start) / 2;
	if (arr[middle] == x)
		return true;
	if (arr[middle] > x)
		return BinarySearch(arr, x, start, middle - 1);
	if (arr[middle] < x)
		return BinarySearch(arr, x, middle + 1, end);
}
