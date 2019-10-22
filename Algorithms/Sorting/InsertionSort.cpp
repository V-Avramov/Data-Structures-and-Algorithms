void InsertionSort(int arr[], int size) {
	for (size_t i = 1; i < size; i++) {
		int element = arr[i];
		int position = i - 1;
		while (position >= 0 && arr[position] > element) {
			arr[position + 1] = arr[position];
			position--;
		}
		arr[position + 1] = element;
	}
}
