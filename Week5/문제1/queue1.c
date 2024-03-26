#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ������ �����ϱ� ���� �߰�
#include <stdio.h>		//ǥ�� ������� ����ϴ� ���
#include <stdlib.h>		//���ڿ� ��ȯ, ��������, �����Ҵ� ���� ����ϴ� ǥ�� ���

#define MAX_QUEUE_SIZE 100		//ť�� �ִ� ũ��

typedef int element;		//int�� �ڷ����� element��� ���� �ο�
element queue[MAX_QUEUE_SIZE];		//[MAX_QUEUE_SIZE]�� ũ�⸦ ������ ť
int front, rear;		//ť�� front, rear ����

void initialize() {		//ť�� �ʱ�ȭ�ϴ� �Լ�
	//����ť�� �ʱ�ȭ front, rear = 0
	//����ť�� �ʱ�ȭ front, rear = -1
	front = rear = 0;
}

int isEmpty() {		//ť�� ��������� 1�� ��ȯ�ϴ� �Լ�
	return (front == rear);
}

int isFull() {		//ť�� ��ȭ���¸� 1�� ��ȯ�ϴ� �Լ�
	//rear + 1���� + 1�� ����ť���� �׻� ����δ� ��ĭ�� ��ŵ�ϴ� ����
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

int addq(element item) {		//ť�� item�� �����ϴ� �Լ�
	if (isFull()) {		//ť�� ��ȭ���¸� Ż��
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear�� 1�� ������ ��, ť�� ũ�⸦ ����� �ʵ��� MAX_QUEUE_SIZE�� ������
	queue[rear] = item;		//queue[rear]�� item�� ����
}

element deleteq() {		//ť���� element�� �����ϴ� �Լ�
	if (isEmpty()) {		//ť�� ������� �� Ż��
		printf("Queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front�� 1�� ������ ��, ť�� ũ�⸦ ����� �ʵ��� MAX_QUEUE_SIZE�� ������
	return queue[front];	//queue[front]�� ��ȯ
}

void main() {
	FILE* fp;		//���� �ּҸ� ������ ����
	int temp;		//���Ͽ��� �ҷ��� ������ ������ ����
	int i, nCount;		//�ݺ������� �������� ����� ����

	fp = fopen("data.txt", "r");		//������Ʈ ���� data.txt ������ �б� ���·� �ҷ���

	if (fp == NULL) {		//fp�� �ּҰ� NULL�� ��� ����
		printf("file open error\n");
		exit(0);
	}

	nCount = 0;		//nCount���� 0���� �ʱ�ȭ

	while (!feof(fp)) {		//fp�� ������ �ݺ�
		fscanf(fp, "%d", &temp);		//fp�� ������ �����͸� temp�� ����
		addq(temp);		//ť�� temp�� ����
		nCount++;		//nCount�� 1�� ����

		printf("front = %d rear = %d\n", front, rear);		//ť�� front�� rear�� ��� ����Ű���� ���
	}

	for (i = 0; i < nCount; i++) {		//ť�� ������ŭ �ݺ�
		printf("deleteq() = %d\n", deleteq());		//ť�� element�� ����ϸ鼭 ����
	}

	printf("front = %d rear = %d\n", front, rear);		//ť�� front�� rear�� ����Ű�� ��ġ ���

	fclose(fp);		//������ ����
}