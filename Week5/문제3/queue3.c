#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ������ �����ϱ� ���� �߰�
#include <stdio.h>		//ǥ�� ������� ����ϴ� ���
#include <stdlib.h>		//���ڿ� ��ȯ, ��������, �����Ҵ� ���� ����ϴ� ǥ�� ���

#define MAX_QUEUE_SIZE 100		//ť�� �ִ� ũ��

typedef struct {		//int, char �ڷ����� �����ϴ� ť ����ü
	int nNum;
	char name[100];
}QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];		//QueueObject����ü�� �迭
int front, rear;		//ť�� front, rear ����

void initialize() {		//ť�� �ʱ�ȭ�ϴ� �Լ�
	//����ť�� �ʱ�ȭ front, rear = 0
	front = rear = 0;
}

int isEmpty() {		//ť�� ��������� 1�� ��ȯ�ϴ� �Լ�
	return (front == rear);
}

int isFull() {		//ť�� ��ȭ���¸� 1�� ��ȯ�ϴ� �Լ�
	//rear + 1���� + 1�� ����ť���� �׻� ����δ� ��ĭ�� ��ŵ�ϴ� ����
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item) {		//ť�� item�� �����ϴ� �Լ�
	if (isFull()) {		//ť�� ��ȭ���¸� ����
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear�� ���� 1�����ش�
	queue[rear] = item;		//rear��ġ�� item�� ����
}

QueueObject deleteq() {		//ť�� ��Ҹ� ��ȯ�ϸ� ����
	if (isEmpty()) {		//ť�� ��������� ����
		printf("queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front�� ���� 1������
	return queue[front];		//front��ġ�� ���� ��ȯ
}

void main() {
	FILE* fp;		//���� �ּҸ� ������ ����
	int nCount;		//�ݺ������� �������� ����� ����
	int i;		//�ݺ������� ����� ����
	QueueObject temp;		//ť ����ü ����

	fp = fopen("data.txt", "r");		//������Ʈ ���� data.txt ������ �б� ���·� �ҷ���

	if (fp == NULL) {		//fp�� �ּҰ� NULL�� ��� ����
		printf("file open error\n");
		exit(0);
	}

	nCount = 0;		//nCount���� 1���� �ʱ�ȭ

	while (!feof(fp)) {		//fp�� ������ �ݺ�
		fscanf(fp, "%d%s", &temp.nNum, temp.name);		//fp�� ������ �����͸� nTemp�� ����
		addq(temp);		//ť�� nTemp�� ����
		nCount++;		//nCount�� 1�� ����
	}

	printf("front = %d rear = %d\n", front, rear);

	for (i = 0; i < nCount; i++) {		//ť�� ������ŭ �ݺ�
		temp = deleteq();
		printf("%d | %s\n", temp.nNum, temp.name);
	}

	printf("front = %d rear = %d\n", front, rear);

	fclose(fp);		//������ ����
}