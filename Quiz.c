#include <stdio.h>

int main() {
	int list_len, data, max_index, temp, stop = 1;
	int input_list[101] = { 0, };
	do {
		printf("\n배열의 범위 입력해주세요. (1~99) : ");
		scanf_s("%d", &list_len);
		if (list_len <= 0 || list_len >= 100) {
			printf("\n배열 길이를 잘못 입력했습니다.\n종료하시겠습니까?\n종료키는 숫자 1입니다.\n종료여부 : ");
			scanf_s("%d", &stop);
			if (stop == 1)
				stop = 0;
			else
				stop = 1;
		}
		else {
			for (int i = 0; i < list_len; i++) {
				scanf_s("%d", &data);
				input_list[i + 1] = data;
			}
			for (int i = 2; i < list_len + 1; i += 2) {
				max_index = i;
				if (input_list[i + 1] > input_list[max_index])
					max_index = i + 1;
				if (input_list[i - 1] > input_list[max_index])
					max_index = i - 1;
				temp = input_list[i];
				input_list[i] = input_list[max_index];
				input_list[max_index] = temp;
			}
			for (int i = 1; i < list_len + 1; i++) {
				printf("%d ", input_list[i]);
			}
		}
	} while (stop != 0);
}