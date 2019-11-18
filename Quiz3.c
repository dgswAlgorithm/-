#include <stdio.h>

int check_left(int arr[], int index) {
	if (index == -1 || arr[index] == 0)
		return 0;
	return 1 + check_left(arr, index - 1);
}

int check_right(int arr[], int index, int max_index) {
	if (index == max_index || arr[index] == 0)
		return 0;
	return 1 + check_right(arr, index + 1, max_index);
}

int check_all(int arr[], int max_index) {
	int berfor_max = 0, now_max = 0, index;
	for (int i = 0; i < max_index; i++) {
		if (arr[i] != 1) {
			now_max = check_left(arr, i - 1) + check_right(arr, i + 1, max_index) + 1;
			if (berfor_max < now_max) {
				berfor_max = now_max;
				index = i;
			}
		}
	}
	return index;
}

int main() {
	int arr[] = { 0,0,1,0,1,1,1,0,1,1 };
	printf("change %d index is max", check_all(arr, sizeof(arr) / sizeof(int)));
	return 0;
}