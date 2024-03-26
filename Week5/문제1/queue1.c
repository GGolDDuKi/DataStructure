#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 오류를 무시하기 위해 추가
#include <stdio.h>		//표준 입출력을 담당하는 헤더
#include <stdlib.h>		//문자열 변환, 난수생성, 동적할당 등을 담당하는 표준 헤더

#define MAX_QUEUE_SIZE 100		//큐의 최대 크기

typedef int element;		//int형 자료형에 element라는 별명 부여
element queue[MAX_QUEUE_SIZE];		//[MAX_QUEUE_SIZE]의 크기를 가지는 큐
int front, rear;		//큐의 front, rear 선언

void initialize() {		//큐를 초기화하는 함수
	//원형큐의 초기화 front, rear = 0
	//선형큐의 초기화 front, rear = -1
	front = rear = 0;
}

int isEmpty() {		//큐가 비어있으면 1을 반환하는 함수
	return (front == rear);
}

int isFull() {		//큐가 포화상태면 1을 반환하는 함수
	//rear + 1에서 + 1은 원형큐에서 항상 비워두는 한칸을 스킵하는 절차
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

int addq(element item) {		//큐에 item을 삽입하는 함수
	if (isFull()) {		//큐가 포화상태면 탈출
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear에 1을 더해준 뒤, 큐의 크기를 벗어나지 않도록 MAX_QUEUE_SIZE로 나눠줌
	queue[rear] = item;		//queue[rear]에 item을 삽입
}

element deleteq() {		//큐에서 element를 삭제하는 함수
	if (isEmpty()) {		//큐가 비어있을 시 탈출
		printf("Queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front에 1을 더해준 뒤, 큐의 크기를 벗어나지 않도록 MAX_QUEUE_SIZE로 나눠줌
	return queue[front];	//queue[front]를 반환
}

void main() {
	FILE* fp;		//파일 주소를 저장할 변수
	int temp;		//파일에서 불러온 정수를 저장할 변수
	int i, nCount;		//반복문에서 조건으로 사용할 변수

	fp = fopen("data.txt", "r");		//프로젝트 내의 data.txt 파일을 읽기 형태로 불러옴

	if (fp == NULL) {		//fp의 주소가 NULL일 경우 종료
		printf("file open error\n");
		exit(0);
	}

	nCount = 0;		//nCount변수 0으로 초기화

	while (!feof(fp)) {		//fp의 끝까지 반복
		fscanf(fp, "%d", &temp);		//fp의 정수형 데이터를 temp에 저장
		addq(temp);		//큐에 temp를 저장
		nCount++;		//nCount에 1을 더함

		printf("front = %d rear = %d\n", front, rear);		//큐의 front와 rear이 어디를 가리키는지 출력
	}

	for (i = 0; i < nCount; i++) {		//큐의 개수만큼 반복
		printf("deleteq() = %d\n", deleteq());		//큐의 element를 출력하면서 삭제
	}

	printf("front = %d rear = %d\n", front, rear);		//큐의 front와 rear이 가리키는 위치 출력

	fclose(fp);		//파일을 닫음
}