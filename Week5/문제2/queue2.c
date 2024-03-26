#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ������ �����ϱ� ���� �߰�
#include <stdio.h>		//ǥ�� ������� ����ϴ� ���
#include <stdlib.h>		//���ڿ� ��ȯ, ��������, �����Ҵ� ���� ����ϴ� ǥ�� ���

#define MAX_QUEUE_SIZE 100		//ť�� �ִ� ũ��

typedef struct {		//nPriority�� �����ϴ� ť ����ü
	int nPriority;
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

void addq(int item, int nItems) {		//ť�� item�� �����ϴ� �Լ�
	int j;

	if (isFull()) {		//ť�� ��ȭ���¸� ����
		printf("Queue is full\n");
		exit(0);
	}

	if (nItems == 0)		//ó������ �����ϴ� item�� ���
		queue[nItems++].nPriority = item;		//queue[nItems].nPriority�� item�� ���� �� nItems�� 1�� ������
	else {
		for (j = nItems - 1; j >= 0; j--) {		//ť�� �� ��Ҹ�ŭ �ݺ�
			if (item < queue[j].nPriority) {		//�����Ϸ��� ���� ���� ť�� ������ ���� ���
				queue[j + 1].nPriority = queue[j].nPriority;		//ť�� ���� ��ġ�� ���� ��ġ�� �� ����
			}
			else {
				break;
			}
		}
		queue[j + 1].nPriority = item;		//�˸��� ������ item�� ����
	}	
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear���� 1 �ø�
}

QueueObject deleteq() {		//ť�� ��Ҹ� ��ȯ�ϸ� ����
	if (isEmpty()) {		//ť�� ��������� ����
		printf("queue is empty\n");
		exit(0);
	}
	else {		//������� ������ front�� 1���ϰ� �ش� ��ġ�� ��Ҹ� ��ȯ
		front = (front + 1) % MAX_QUEUE_SIZE;
		return queue[front];
	}
}

void main() {
	FILE* fp;		//���� �ּҸ� ������ ����
	int nCount;		//�ݺ������� �������� ����� ����
	int nTemp;		//���Ͽ��� �ҷ��� ������ ������ ����
	int i;		//�ݺ������� ����� ����
	QueueObject qobject;		//ť ����ü ����

	fp = fopen("data.txt", "r");		//������Ʈ ���� data.txt ������ �б� ���·� �ҷ���
	if (fp == NULL) {		//fp�� �ּҰ� NULL�� ��� ����
		printf("file open error\n");
		exit(0);
	}

	nCount = 1;		//nCount���� 1���� �ʱ�ȭ

	while (!feof(fp)) {		//fp�� ������ �ݺ�
		fscanf(fp, "%d", &nTemp);		//fp�� ������ �����͸� nTemp�� ����
		addq(nTemp, nCount);		//ť�� nTemp�� ����
		nCount++;		//nCount�� 1�� ����
	}

	for (i = 0; i < nCount - 1; i++) {		//ť�� ������ŭ �ݺ�
		qobject = deleteq();
		printf("%d -> ", qobject.nPriority);
	}
	printf("\n");

	fclose(fp);		//������ ����
}