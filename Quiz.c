#include <stdio.h>

int main() {
	int list_len, data, max_index, temp, stop = 1;
	int input_list[101] = { 0, };
	do {
		printf("\n�迭�� ���� �Է����ּ���. (1~99) : ");
		scanf_s("%d", &list_len);
		if (list_len <= 0 || list_len >= 100) {
			printf("\n�迭 ���̸� �߸� �Է��߽��ϴ�.\n�����Ͻðڽ��ϱ�?\n����Ű�� ���� 1�Դϴ�.\n���Ῡ�� : ");
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