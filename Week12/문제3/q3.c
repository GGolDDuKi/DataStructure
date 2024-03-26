#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {		//QueueNode 구조체 선언 및 정의
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {		//큐의 front, rear로 활용할 LinkedQueueType 선언 및 정의
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {		//큐의 front와 rear를 NULL로 초기화하는 함수
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {		//큐가 비어있는지 확인하는 함수
	if (q->front == NULL && q->rear == NULL) {		//front와 rear가 NULL일 경우 비어있음
		return 1;
	}
	else
		return 0;
}

void enqueue(LinkedQueueType* q, element data) {		//큐에 data를 삽입하는 함수
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL) {
		printf("메모리 할당에 실패했습니다\n");
		exit(1);
	}
	//temp->data에 data를 삽입한 뒤, temp->link가 NULL을 삽입
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {		//큐가 비어있으면, front와 rear가 temp를 가리키게 함
		q->front = temp;
		q->rear = temp;
	}		
	else {		//큐가 비어있지 않으면, rear와 rear의 link가 temp를 가리키게 함
		q->rear->link = temp;
		q->rear = temp;
	}
}

void dequeue(LinkedQueueType* q) {		//큐의 요소를 하나 삭제
	QueueNode* temp = q->front;
	element data;
	if (is_empty(&q)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL) {		//큐 공백 처리
			q->rear = NULL;
		}
		free(temp);
	}
}

void print_queue(LinkedQueueType* q) {		//큐를 출력하는 함수
	QueueNode *temp = q->front;
	if (is_empty(&q)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	for (; temp != NULL; temp = temp->link) {		//temp가 NULL이 될 때까지 반복
		printf("%d->", temp->data);
	}
	printf("NULL\n");
}

int main() {
	LinkedQueueType q;
	init(&q);
	//큐에 요소를 삽입, 삭제하며 출력
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