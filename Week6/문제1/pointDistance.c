#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ������ �����ϱ� ���� �߰�
#include <stdio.h>		//ǥ�� ������� ����ϴ� ���
#include <math.h>

#define MAX_QUEUE_SIZE 100		//ť�� �ִ� ũ��

typedef struct {		//int�� �迭�� �����ϴ� Point ť
	int xy[2];		//x, y��ǥ�� ������ ť�� ���
}Point;

Point point[MAX_QUEUE_SIZE];		//point����ü�� �迭
int front, rear;		//ť�� front, rear ����

void initialize() {		//ť�� �ʱ�ȭ�ϴ� �Լ�
	front = rear = -1;
}

int isEmpty() {		//ť�� ��������� 1�� ��ȯ�ϴ� �Լ�
	return (front == rear);
}

int isFull() {		//ť�� ��ȭ���¸� 1�� ��ȯ�ϴ� �Լ�
	//rear + 1���� + 1�� ����ť���� �׻� ����δ� ��ĭ�� ��ŵ�ϴ� ����
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(Point item) {		//ť�� item�� �����ϴ� �Լ�
	if (isFull()) {		//ť�� ��ȭ���¸� ����
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear�� ���� 1�����ش�
	point[rear] = item;		//rear��ġ�� item�� ����
}

Point deleteq() {		//ť�� ��Ҹ� ��ȯ
	if (isEmpty()) {		//ť�� ��������� ����
		printf("queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front�� ���� 1������
	return point[front];		//front��ġ�� ���� ��ȯ
}

void GetDistance() {		//ť�� ��ҵ鰣 �Ÿ��� ���� ����ϴ� �Լ�
	int i = 0;		//�ݺ����� ����� ����
	int cnt = 1;		//��� ��ȣ�� ����� ����
	while (front < rear) {		//front�� rear���� ���� ��� �ݺ�
		int x1, x2, y1, y2 = 0;		//ť�� ����� ��ǥ�� ������ ������
		double distance = 0;		//��ǥ�� �Ÿ��� ������ ����
		deleteq();		//front�� 1 �÷���
		i = front + 1;		//front�� ��ҿ� i��ġ�� ��Ұ��� �Ÿ��� ���� ����
		while (i <= rear) {		//i�� rear���� �۰ų� ���� ��� �ݺ�
			if (i <= rear) {		
				x1 = point[front].xy[0];		//front�� x��ǥ�� x1�� ����
				y1 = point[front].xy[1];		//front�� y��ǥ�� y1�� ����
				x2 = point[i].xy[0];		//i�� x��ǥ�� x2�� ����
				y2 = point[i].xy[1];		//i�� y��ǥ�� y2�� ����

				double x3 = x2 - x1;		//x��ǥ���� �Ÿ��� x3�� ����
				double y3 = y2 - y1;		//y��ǥ���� �Ÿ��� y3�� ����
				distance = sqrt(x3 * x3 + y3 * y3);		//sqrt�Լ��� ����Ͽ� �Ÿ� ���ϱ�
			}
			printf("%d. (%d, %d)�� (%d, %d)�� ������ �Ÿ��� %.5f �Դϴ�.\n", cnt++, x1, y1, x2, y2, distance);
			//���� ����� ��� ����� ���� ���
			i++;		//i�� ������Ŵ
		}
	}
}

void main() {
	initialize();
	FILE* fp;		//���� �ּҸ� ������ ����
	Point dot = { 0 };		//���Ͽ��� �ҷ��� ��ǥ���� �ӽ÷� ������ ����

	fp = fopen("data01.txt", "r");		//������Ʈ ���� data01.txt ������ �б� ���·� �ҷ���

	if (fp == NULL) {		//fp�� �ּҰ� NULL�� ��� ����
		printf("file open error\n");
		exit(0);
	}

	while (!feof(fp)) {		//fp�� ������ �ݺ�
		fscanf(fp, "%d %d", &dot.xy[0], &dot.xy[1]);		//txt���Ͽ� ����� x, y���� dot�� ����
		addq(dot);		//dot�� ��Ҹ� point ť�� �߰�
	}

	GetDistance();		//�Ÿ��� ���ϴ� �Լ� ȣ��
}