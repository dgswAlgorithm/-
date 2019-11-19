#include<stdio.h>
#define List_Max 9

void change_list(int arr[], int finish_arr[]) {
	int count = 0, finish_arr_top = 0;
	for (int i = 0; i < List_Max; i++) {
		if (arr[i] == 0)
			count++;
		else
			finish_arr[finish_arr_top++] = arr[i];
	}
	for (int i = 0; i < count; i++) {
		finish_arr[finish_arr_top++] = 0;
	}
}

int main() {
	int arr[9] = { 6,0,8,2,3,0,4,0,1 };
	int finish_arr[9] = { 0, };
	change_list(arr, finish_arr);
	for(int i = 0; i < List_Max;i++)
		printf("%d ", finish_arr[i]);
	return 0;
}