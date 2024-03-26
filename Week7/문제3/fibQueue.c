#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100		//큐의 최대 크기

typedef struct {		//정수배열을 변수로 가지는 Queue구조체
	int num[SIZE];
}Queue;

Queue queue;		//Queue구조체
int front, rear;		//큐의 front, rear 선언

int isEmpty() {		//큐가 비어있으면 1을 반환하는 함수
	return (front == rear == -1);
}

int isFull() {		//큐가 포화상태면 1을 반환하는 함수
	return (rear == SIZE - 1);
}

void addq(int item) {		//큐에 item을 삽입하는 함수
	if (isFull()) {		//큐가 포화상태면 종료
		printf("Queue is full\n");
		exit(0);
	}
	queue.num[++rear] = item;		//rear위치에 item을 삽입
	printf("%d\n", item);
}

int deleteq() {		//큐의 요소를 반환
	if (isEmpty()) {		//큐가 비어있으면 종료
		printf("queue is empty\n");
		exit(0);
	}
	return queue.num[++front];		//front위치의 값을 반환
}

void initialize() {		//큐를 초기화하는 함수
	//선형큐의 초기화 front, rear = -1
	front = rear = -1;
}

void Fib(int n) {		//n번째까지의 피보나치 수열을 구하는 함수
	while (rear < n - 1) {
		if (rear == -1) addq(0);
		else if (rear == 0) addq(1);
		else addq((deleteq() + queue.num[rear]));
	}
}

int main() {
	int num = 0;		//사용자의 입력을 받아 저장할 변수
	initialize();		//큐 초기화
	printf("숫자를 입력하세요 : ");
	scanf("%d", &num);		//사용자의 입력을 받아 num에 저장
	Fib(num);		//num번째 피보나치 수를 구하는 함수를 호출
	return 0;
}