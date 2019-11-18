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
	if (arr[check_start_index] == 0)
		Compression_List[input_list_top++] = count * -1;
	else
		Compression_List[input_list_top++] = count;
	Compression_List[input_list_top] = 0;
}

int Find_Max_Index(int Compression_List[]) {
	int Max = 0, Start_Index = 0, Input_List_Index = 0, Input_List_Max_Index;
	if (Compression_List[0] == 0)
		return 0;
	if (Compression_List[0] < 0) {
		Start_Index = abs(Compression_List[0]) - 1;
		Input_List_Index = abs(Compression_List[0]) - 1;
	}
	for (int i = Start_Index; Compression_List[i] != 0; i++) {
		Input_List_Index += abs(Compression_List[i]);
		if (Compression_List[i] == -1 && (Compression_List[i - 1] + Compression_List[i + 1]) > Max) {
			Max = Compression_List[i - 1] + Compression_List[i + 1];
			Input_List_Max_Index = Input_List_Index;
		}
	}
	return Input_List_Max_Index;
}

int main() {
	int arr[List_Max] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1 };
	int Compression_List[List_Max];
	Make_Compression_List(arr, Compression_List);
	printf("change %d index is max", Find_Max_Index(Compression_List));
	return 0;
}