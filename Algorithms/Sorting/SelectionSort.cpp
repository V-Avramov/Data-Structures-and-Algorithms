void swap(int*arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void SelectionSort(int arr[], int size) {
	for (size_t i = 0; i < size; i++) {
		int minind = i;
		for (size_t j = i; j < size; j++) {
			if (arr[minind] > arr[j])
				minind = j;
		}
		if (i != minind)
			swap(arr, minind, i);
	}
}
