#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 오류를 무시하기 위해 추가
#include <stdio.h>		//표준 입출력을 담당하는 헤더
#include <stdlib.h>		//문자열 변환, 난수생성, 동적할당 등을 담당하는 표준 헤더

#define MAX_QUEUE_SIZE 100		//큐의 최대 크기

typedef struct {		//int, char 자료형을 저장하는 큐 구조체
	int nNum;
	char name[100];
}QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];		//QueueObject구조체의 배열
int front, rear;		//큐의 front, rear 선언

void initialize() {		//큐를 초기화하는 함수
	//원형큐의 초기화 front, rear = 0
	front = rear = 0;
}

int isEmpty() {		//큐가 비어있으면 1을 반환하는 함수
	return (front == rear);
}

int isFull() {		//큐가 포화상태면 1을 반환하는 함수
	//rear + 1에서 + 1은 원형큐에서 항상 비워두는 한칸을 스킵하는 절차
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item) {		//큐에 item을 삽입하는 함수
	if (isFull()) {		//큐가 포화상태면 종료
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear의 값을 1더해준다
	queue[rear] = item;		//rear위치에 item을 삽입
}

QueueObject deleteq() {		//큐의 요소를 반환하며 삭제
	if (isEmpty()) {		//큐가 비어있으면 종료
		printf("queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front의 값을 1더해줌
	return queue[front];		//front위치의 값을 반환
}

void main() {
	FILE* fp;		//파일 주소를 저장할 변수
	int nCount;		//반복문에서 조건으로 사용할 변수
	int i;		//반복문에서 사용할 변수
	QueueObject temp;		//큐 구조체 변수

	fp = fopen("data.txt", "r");		//프로젝트 내의 data.txt 파일을 읽기 형태로 불러옴

	if (fp == NULL) {		//fp의 주소가 NULL일 경우 종료
		printf("file open error\n");
		exit(0);
	}

	nCount = 0;		//nCount변수 1으로 초기화

	while (!feof(fp)) {		//fp의 끝까지 반복
		fscanf(fp, "%d%s", &temp.nNum, temp.name);		//fp의 정수형 데이터를 nTemp에 저장
		addq(temp);		//큐에 nTemp를 저장
		nCount++;		//nCount에 1을 더함
	}

	printf("front = %d rear = %d\n", front, rear);

	for (i = 0; i < nCount; i++) {		//큐의 개수만큼 반복
		temp = deleteq();
		printf("%d | %s\n", temp.nNum, temp.name);
	}

	printf("front = %d rear = %d\n", front, rear);

	fclose(fp);		//파일을 닫음
}