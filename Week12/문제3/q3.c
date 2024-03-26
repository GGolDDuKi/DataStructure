#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {		//QueueNode ����ü ���� �� ����
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {		//ť�� front, rear�� Ȱ���� LinkedQueueType ���� �� ����
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {		//ť�� front�� rear�� NULL�� �ʱ�ȭ�ϴ� �Լ�
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {		//ť�� ����ִ��� Ȯ���ϴ� �Լ�
	if (q->front == NULL && q->rear == NULL) {		//front�� rear�� NULL�� ��� �������
		return 1;
	}
	else
		return 0;
}

void enqueue(LinkedQueueType* q, element data) {		//ť�� data�� �����ϴ� �Լ�
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL) {
		printf("�޸� �Ҵ翡 �����߽��ϴ�\n");
		exit(1);
	}
	//temp->data�� data�� ������ ��, temp->link�� NULL�� ����
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {		//ť�� ���������, front�� rear�� temp�� ����Ű�� ��
		q->front = temp;
		q->rear = temp;
	}		
	else {		//ť�� ������� ������, rear�� rear�� link�� temp�� ����Ű�� ��
		q->rear->link = temp;
		q->rear = temp;
	}
}

void dequeue(LinkedQueueType* q) {		//ť�� ��Ҹ� �ϳ� ����
	QueueNode* temp = q->front;
	element data;
	if (is_empty(&q)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL) {		//ť ���� ó��
			q->rear = NULL;
		}
		free(temp);
	}
}

void print_queue(LinkedQueueType* q) {		//ť�� ����ϴ� �Լ�
	QueueNode *temp = q->front;
	if (is_empty(&q)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	for (; temp != NULL; temp = temp->link) {		//temp�� NULL�� �� ������ �ݺ�
		printf("%d->", temp->data);
	}
	printf("NULL\n");
}

int main() {
	LinkedQueueType q;
	init(&q);
	//ť�� ��Ҹ� ����, �����ϸ� ���
	enqueue(&q, 1);
	print_queue(&q);
	enqueue(&q, 2);
	print_queue(&q);
	enqueue(&q, 3);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
}