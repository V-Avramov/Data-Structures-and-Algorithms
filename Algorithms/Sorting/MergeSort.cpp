template<class T>
void merge(T*arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	T*L = new T[n1];
	T*R = new T[n2];
	i = 0;
	j = 0;
	k = l;
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + j + 1];
	i = 0;
	j = 0;
	k = l;
	while (i < n1&&j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[]L;
	delete[]R;
}

template<class T>
void MergeSort(T*arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		merge<T>(arr, l, m, r);
	}
}
