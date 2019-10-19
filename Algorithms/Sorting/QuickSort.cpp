template<class T>
void swap(T*arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
template<class T>
int partition(T*arr, int low, int high) {
	T pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr, j, i);
		}
	}
	swap(arr, i + 1, high);
	return i + 1;
}

template<class T>
int partition_rand(T*arr, int low, int high) {
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr, high, random);
	return partition(arr, low, high);
}

template<class T>
void QuickSort(T*arr, int low, int high) {
	if (low < high) {
		int pivotind = partition_rand(arr, low, high);
		QuickSort(arr, low, pivotind - 1);
		QuickSort(arr, pivotind + 1, high);
	}
}
