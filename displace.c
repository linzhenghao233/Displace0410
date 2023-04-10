#include <stdio.h>

int main(void) {
	int ch, row, col, i, j, row1, row2, col1, col2, choice;
	char name[10][20], temp[10][20];
	col = 0;

	printf("请输入你的名字拼音：");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;

		for (row = 0; row < 10; row++) {
			name[row][col] = ch;
		}
		col++;
	}

	//while(getchar() != '\n');

	printf("请选择置换的方式：\n1.行置换\t2.列置换\tq.退出\n");
	while (scanf_s("%d", &choice) == 1) {
		if (choice == 1) {
			printf("请输入要置换的两个行：");	//这个行置换没用，因为每行都一样
			while (scanf_s("%d %d", &row1, &row2) == 2) {
				for (i = 0; i < 10; i++) {
					temp[row1 - 1][i] = name[row1 - 1][i];
					name[row1 - 1][i] = name[row2 - 1][i];
					name[row2 - 1][i] = temp[row1 - 1][i];
				}
				printf("请再次输入要置换的两个列（q退出）：");
			}
		}
		else if (choice == 2) {
			printf("请输入要置换的两个列：");
			while (scanf_s("%d %d", &col1, &col2) == 2) {
				for (i = 0; i < 10; i++) {
					temp[i][col1 - 1] = name[i][col1 - 1];
					name[i][col1 - 1] = name[i][col2 - 1];
					name[i][col2 - 1] = temp[i][col1 - 1];
				}
				printf("请再次输入要置换的两个列（q退出）：");
			}
		}
		else
			printf("请输入正确的选项！");
		while (getchar() != '\n');
		printf("请选择置换的方式：\n1.行置换\t2.列置换\tq.退出\n");
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < col; j++) {
			printf("%c", name[i][j]);
		}
		printf("\n");
	}

	return 0;
}