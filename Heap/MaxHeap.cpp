class MaxHeap { //The top element is the maximum
private:
	std::vector<int>harr;

	int getLeftIndex(int index) {
		return 2 * index + 1;
	}

	int getRightIndex(int index) {
		return 2 * index + 2;
	}

	int getParIndex(int index) {
		return (index - 1) / 2;
	}

	bool hasLeft(int index) {
		return getLeftIndex(index) < harr.size();
	}

	bool hasRight(int index) {
		return getRightIndex(index) < harr.size();
	}

	bool hasPar(int index) {
		return getLeftIndex(index) >= 0;
	}

	void swap(int&i, int&j) {
		int temp = i;
		i = j;
		j = temp;
	}
                         //Can be switched to MinHeap by changing up the code here
	void siftUp(int pos) {
		int par = getParIndex(pos);
		while (harr[pos] > harr[par]) {
			swap(harr[pos], harr[par]);
			if (par <= 0) {
				return;
			}
			par = getParIndex(par);
			pos = getParIndex(pos);
		}
	}

	void siftDown(int pos) {
		if (hasRight(pos) && (harr[pos] < harr[getLeftIndex(pos)] || harr[pos] < harr[getRightIndex(pos)])) {
			int swapWith = -1;
			if (harr[getLeftIndex(pos)] < harr[getRightIndex(pos)]) {
				swapWith = getRightIndex(pos);
			}
			else {
				swapWith = getLeftIndex(pos);
			}
			swap(harr[swapWith], harr[pos]);
			siftDown(swapWith);
		}
		else if (hasLeft(pos) && harr[pos] < harr[getLeftIndex(pos)]) {
			swap(harr[pos], harr[getLeftIndex(pos)]);
			siftDown(getLeftIndex(pos));
		}
	}

public:
	MaxHeap() {}

	bool isEmpty() {
		return harr.size() == 0;
	}

	bool contains(int element) {
		for (int i = 0; i < harr.size(); i++) {
			if (harr[i] == element) {
				return true;
			}
		}
		return false;
	}

	void add(int element) {
		harr.push_back(element);
		siftUp(harr.size() - 1);
	}

	void removeTop() {
		if (isEmpty()) {
			return;
		}
		harr[0] = harr[harr.size() - 1];
		harr.pop_back();
		siftDown(0);
	}
  
  void print() {
		for (int i = 0; i < harr.size(); i++) {
			std::cout << harr[i] << " ";
		}
	}
};
