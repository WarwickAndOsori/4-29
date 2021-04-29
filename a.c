#include <stdio.h>

void swap(int* a, int* b) { //�ٲٱ� �Լ� *�����͸� �̿��Ͽ� ��ȯ ���� ���� ��ȯ
	int temp = *a; //a�ּҿ� �ִ°��� temp�� ����
	*a = *b; //a�ּҿ� b�ּҸ� �ٲ� ������ �ٲ۰Ͱ� ����
	*b = temp; //temp�� ������ a���� b�� ����
}
void heapify(int arr[], int root, int size) {
	int left = root * 2 + 1;
	int right = left + 1;
	int max = root;
	if (left < size && arr[left] > arr[max]) {
		max = left;
	}
	if (right < size && arr[right] > arr[max]) {
		max = right;
	}

	if (max != root) {
		swap(&arr[root], &arr[max]);
		heapify(arr, max, size);
	}
}

void buildHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, i, size);
	}
}

void printfArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
}

void heapSort(int arr[], int size) {
	int treeSize = size;
	buildHeap(arr, size);
	while (size > 1) {
		buildHeap(arr, size);
		swap(&arr[0], &arr[size - 1]);
		size--;
	}
}

int main() {
	int arr[] = { 5,3,4,1,6,10,2,9,11,22,33,66,23,14,18,15 };
	int size = sizeof(arr) / sizeof(int);
	heapSort(arr, size);
	printfArray(arr, size);
}