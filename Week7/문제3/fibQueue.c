#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100		//ť�� �ִ� ũ��

typedef struct {		//�����迭�� ������ ������ Queue����ü
	int num[SIZE];
}Queue;

Queue queue;		//Queue����ü
int front, rear;		//ť�� front, rear ����

int isEmpty() {		//ť�� ��������� 1�� ��ȯ�ϴ� �Լ�
	return (front == rear == -1);
}

int isFull() {		//ť�� ��ȭ���¸� 1�� ��ȯ�ϴ� �Լ�
	return (rear == SIZE - 1);
}

void addq(int item) {		//ť�� item�� �����ϴ� �Լ�
	if (isFull()) {		//ť�� ��ȭ���¸� ����
		printf("Queue is full\n");
		exit(0);
	}
	queue.num[++rear] = item;		//rear��ġ�� item�� ����
	printf("%d\n", item);
}

int deleteq() {		//ť�� ��Ҹ� ��ȯ
	if (isEmpty()) {		//ť�� ��������� ����
		printf("queue is empty\n");
		exit(0);
	}
	return queue.num[++front];		//front��ġ�� ���� ��ȯ
}

void initialize() {		//ť�� �ʱ�ȭ�ϴ� �Լ�
	//����ť�� �ʱ�ȭ front, rear = -1
	front = rear = -1;
}

void Fib(int n) {		//n��°������ �Ǻ���ġ ������ ���ϴ� �Լ�
	while (rear < n - 1) {
		if (rear == -1) addq(0);
		else if (rear == 0) addq(1);
		else addq((deleteq() + queue.num[rear]));
	}
}

int main() {
	int num = 0;		//������� �Է��� �޾� ������ ����
	initialize();		//ť �ʱ�ȭ
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &num);		//������� �Է��� �޾� num�� ����
	Fib(num);		//num��° �Ǻ���ġ ���� ���ϴ� �Լ��� ȣ��
	return 0;
}