#include<iostream>

template<class T>
void PrintArr(T arr[], int size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

template<class T>
void CountingSort(T*arr, int size) {
	T maxElem = arr[0];
	for (int i = 1; i < size; i++) {
		if (maxElem < arr[i])
			maxElem = arr[i];
	}
	int*countingArr = new int[maxElem + 1];
	for (int i = 0; i < maxElem + 1; i++)
		countingArr[i] = 0;
	for (int i = 0; i < size; i++)
		countingArr[arr[i]]++;
	int sortedIndex = 0;
	for (int i = 0; i < size; i++) {
		while (countingArr[sortedIndex] == 0)
			sortedIndex++;
		arr[i] = sortedIndex;
		countingArr[sortedIndex]--;
	}
	delete[]countingArr;
}

int main(){

  int arr[] = { 5,4,3,2,1 };
  char str[] = "ABBBCVFSDBAA";

  CountingSort<int>(arr, 5);
  PrintArr<int>(arr, 5);
  std::cout<<std::endl;
  CountingSort<char>(str, 12);
  PrintArr<char>(str, 13);

  return 0;
}
