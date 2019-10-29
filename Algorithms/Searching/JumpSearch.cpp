bool JumpSearch(int*arr, int x, int size) {
	int step = (int)floor(sqrt(size));

	int prev = 0;
	int next = prev + step;
	while (arr[std::min(next, size) - 1] < x) {
		prev = next;
		next += step;
		if (prev >= size)
			return false;
	}
	while (arr[prev] < x) {
		prev++;
		if (prev == std::min(step, size))
			return false;
	}
	if (arr[prev] == x)
		return true;
	return false;
}
