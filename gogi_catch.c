#include <stdio.h>
#include <stdlib.h>
#define N 100
#define W rand() % 11
#define turn (N - W + 1)

int main() {
	int river[N], Max = 0, max_list[N], max_list_top = -1;
	for (int i = 0; i < 100; i++)
		river[i] = rand() % 11;
	for (int i = 0; i < turn; i++) {
		if (Max < river[i] + river[i + 1] + river[i + 2]) {
			Max = river[i] + river[i + 1] + river[i + 2];
			while (max_list_top != -1)
				max_list[max_list_top--] = 0;
			max_list[++max_list_top] = i;
		}
		else if (Max == river[i] + river[i + 1] + river[i + 2])
			max_list[++max_list_top] = i;
	}
	for (int i = 0; i < max_list_top + 1; i++)
		printf("%d备开俊 带咙 : %d付府\n", max_list[i], Max);
}