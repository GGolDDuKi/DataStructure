#define _CRT_SECURE_NO_WARNINGS		//����°������� �߻��ϴ� ����� �����ϱ� ���� �߰��մϴ�.
#include <stdio.h>		//ǥ�� ����� ����Դϴ�.

void Find(int maze[][10], int i, int j) {		//�̷�, i(����ϴ� ����� �� ��ġ), j(����ϴ� ����� �� ��ġ) �Դϴ�.
	//�������� �̵� ���� �ľ�
	if (i == 0 && j == 0) {		//���� �̷ο� ���� �ʾ��� ��
		for (i = 0; i < 8; i++) {		//ù��° ������ �Ա��� ã���ϴ�
			if (maze[i][j] == 0) {		//������ ���� 0�� ���� �Ա��Դϴ�.
				return Find(maze, i, j);		//�Ա��� ã���� �Ա��� ��ġ�� �Ű������� �ѱ�� �Լ��� �ٽ� ȣ���մϴ�
			}
		}
	}

	maze[i][j] = 2;		//���� ������ ���� 2�� �ٲߴϴ�.

	for (int x = 0; x < 8; x++) {		//�̷θ� ����ϴ� ���� ��ü�� ����ϱ� ���� �߰��߽��ϴ�.
		for (int y = 0; y < 10; y++) {
			printf("%d ", maze[x][y]);
		}
		printf("\n");
	}
	printf("\n\n");

	if (i < 8 && j + 1 < 10) {		//���� ���� ���� ��
		if (maze[i - 1][j] == 0) {		//���� �̵��� �� �ִ��� Ȯ���մϴ�.
			return Find(maze, --i, j);		//�̵��� �� �ִٸ� �ش� ��ġ�� �Ű������� �ѱ�� �Լ��� �ٽ� ȣ���մϴ�.
		}
		else if (maze[i][j + 1] == 0) {		//���������� �̵��� �� �ִ��� Ȯ���մϴ�.
			return Find(maze, i, ++j);		//�̵��� �� �ִٸ� �ش� ��ġ�� �Ű������� �ѱ�� �Լ��� �ٽ� ȣ���մϴ�.
		}
		else if (maze[i + 1][j] == 0) {		//�Ʒ��� �̵��� �� �ִ��� Ȯ���մϴ�.
			return Find(maze, ++i, j);		//�̵��� �� �ִٸ� �ش� ��ġ�� �Ű������� �ѱ�� �Լ��� �ٽ� ȣ���մϴ�.
		}
		else if (maze[i][j - 1] == 0) {		//�������� �̵��� �� �ִ��� Ȯ���մϴ�.
			return Find(maze, i, --j);		//�̵��� �� �ִٸ� �ش� ��ġ�� �Ű������� �ѱ�� �Լ��� �ٽ� ȣ���մϴ�.
		}
	}
}

int main() {
	int i = 0;		//�̷θ� ����ϴ� ����� �� ��ġ
	int j = 0;		//�̷θ� ����ϴ� ����� �� ��ġ

	int maze[8][10] =		//�̷��Դϴ�
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1}
	};

	Find(maze, i, j);		//�̷θ� ���������� �Լ��� ȣ���մϴ�.
}