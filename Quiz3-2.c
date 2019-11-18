#include <stdio.h>
#include <stdlib.h>
#define List_Max 14

void Make_Compression_List(int arr[], int Compression_List[]) {
	int input_list_top = 0, count = 1, check_start_index = 0;
	for (int i = 1; i < List_Max; i++) {
		if (arr[i] != arr[check_start_index]) {
			if (arr[check_start_index] == 0)
				Compression_List[input_list_top++] = count * -1;
			else
				Compression_List[input_list_top++] = count;
			count = 0;
			check_start_index = i;
		}
		count++;
	}
	Compression_List[input_list_top] = 0;
}

int Find_Max_Index(int arr[], int Compression_List[]) {
	int Max = 0, Start_Index = 0, Input_List_Index = 0, Input_List_Max_Index;
	if (Compression_List[0] == 0) {
		if (arr[0] == 1)
			printf("No Way change index");
		else
			printf("change 0 index is max");
		return 0;
	}
	for (int i = Start_Index; Compression_List[i] != 0; i++) {
		Input_List_Index += abs(Compression_List[i]);
		if (Compression_List[i] == -1 && (Compression_List[i - 1] + Compression_List[i + 1]) > Max) {
			Max = Compression_List[i - 1] + Compression_List[i + 1];
			Input_List_Max_Index = Input_List_Index;
		}
	}
	printf("change %d index is max", Input_List_Max_Index - 1);
}

int main() {
	int arr[List_Max] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1 };
	int Compression_List[List_Max];
	Make_Compression_List(arr, Compression_List);
	Find_Max_Index(arr, Compression_List);
	return 0;
}