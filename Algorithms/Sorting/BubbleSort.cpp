void swap(int*arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void BubbleSort(int arr[], int size) {
	for (size_t i = 0; i < size; i++) {
		bool isSwapped = false;
		for (size_t j = 0; j < size-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;
	}
}
