#include <stdio.h>

int main(void) {
	int ch, row, col, i, j, row1, row2, col1, col2, choice;
	char name[10][20], temp[10][20];
	col = 0;

	printf("�������������ƴ����");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;

		for (row = 0; row < 10; row++) {
			name[row][col] = ch;
		}
		col++;
	}

	//while(getchar() != '\n');

	printf("��ѡ���û��ķ�ʽ��\n1.���û�\t2.���û�\tq.�˳�\n");
	while (scanf_s("%d", &choice) == 1) {
		if (choice == 1) {
			printf("������Ҫ�û��������У�");	//������û�û�ã���Ϊÿ�ж�һ��
			while (scanf_s("%d %d", &row1, &row2) == 2) {
				for (i = 0; i < 10; i++) {
					temp[row1 - 1][i] = name[row1 - 1][i];
					name[row1 - 1][i] = name[row2 - 1][i];
					name[row2 - 1][i] = temp[row1 - 1][i];
				}
				printf("���ٴ�����Ҫ�û��������У�q�˳�����");
			}
		}
		else if (choice == 2) {
			printf("������Ҫ�û��������У�");
			while (scanf_s("%d %d", &col1, &col2) == 2) {
				for (i = 0; i < 10; i++) {
					temp[i][col1 - 1] = name[i][col1 - 1];
					name[i][col1 - 1] = name[i][col2 - 1];
					name[i][col2 - 1] = temp[i][col1 - 1];
				}
				printf("���ٴ�����Ҫ�û��������У�q�˳�����");
			}
		}
		else
			printf("��������ȷ��ѡ�");
		while (getchar() != '\n');
		printf("��ѡ���û��ķ�ʽ��\n1.���û�\t2.���û�\tq.�˳�\n");
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < col; j++) {
			printf("%c", name[i][j]);
		}
		printf("\n");
	}

	return 0;
}