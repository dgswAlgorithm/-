#include <stdio.h>

int slove_left_sum(int arr[], int index) {
	if (index == -1)
		return 0;
	return arr[index] + slove_left_sum(arr, index - 1);
}

int slove_right_sum(int arr[], int index, int last) {
	if (index == last)
		return 0;
	return arr[index] + slove_right_sum(arr, index + 1, last);
}

int main() {
	int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
	int left_sum = 0, right_sum = 0;
	for (int i = 0; i < sizeof(A) / sizeof(int); i++) {
		left_sum = slove_left_sum(A, i - 1);
		right_sum = slove_right_sum(A, i + 1, sizeof(A) / sizeof(int));
		if (left_sum == right_sum)
			printf("%d ", i);
	}
}