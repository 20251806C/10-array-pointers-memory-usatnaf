#include <stdio.h>
#include <conio.h>
#define rows 3
#define cols 5

void printfarr(char arr[rows][cols]) {
	printf("배열의 상태:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(void) {
	char data[rows][cols] = { 0 };
	char(*p)[cols];
	p = data;

	printf("시작전:\n");
	printfarr(data);

	(*p)[1] = 3;
	(*(p + 1))[2] = 4;
	(*(p + 2))[4] = 5;
	printf("press any key to continue...:\n");
	getchar();
	printfarr(data);

	printf("초기 배열의 상태:\n");
	printfarr(data);
	printf("press any key to continue...:\n");
	getchar();

	p = data;
	p++;
	(*p)[0] = 7;
	(*p)[4] = 8;
	(*(p - 1))[3] = 9;

	printf("두번째 수정 후 배열의 상태:\n");
	printfarr(data);
	printf("press any key to continue...:\n");
	getchar();

	char* ptr = &data[0][0];
	*(ptr + 6) = 10;
	*(ptr + 10) = 11;
	*(ptr + 14) = 28;
	*(ptr + 15) = 100;

	printf("포인터 산술 연산 후 배열의 상태:\n");
	printfarr(data);
	printf("press any key to continue...:\n");
	getchar();

	char temp[cols];
	for (int i = 0; i < cols; i++) {
		temp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = data[i];
	}
	printf("첫 번쨰 항과 세 번째 항 교환 후 배열의 상태:\n");
	printfarr(data);
	printf("press any key to continue...:\n");
	getchar();
	return 0;
}