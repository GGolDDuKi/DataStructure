#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 오류를 무시하기 위해 추가
#include <stdio.h>		//표준 입출력을 담당하는 헤더
#include <stdlib.h>		//문자열 변환, 난수생성, 동적할당 등을 담당하는 표준 헤더

#define MAX_QUEUE_SIZE 100		//큐의 최대 크기

typedef struct {		//nPriority를 저장하는 큐 구조체
	int nPriority;
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

void addq(int item, int nItems) {		//큐에 item을 삽입하는 함수
	int j;

	if (isFull()) {		//큐가 포화상태면 종료
		printf("Queue is full\n");
		exit(0);
	}

	if (nItems == 0)		//처음으로 삽입하는 item일 경우
		queue[nItems++].nPriority = item;		//queue[nItems].nPriority에 item을 삽입 후 nItems에 1을 더해줌
	else {
		for (j = nItems - 1; j >= 0; j--) {		//큐에 들어간 요소만큼 반복
			if (item < queue[j].nPriority) {		//삽입하려는 값이 기존 큐의 값보다 작을 경우
				queue[j + 1].nPriority = queue[j].nPriority;		//큐의 다음 위치에 기존 위치의 값 삽입
			}
			else {
				break;
			}
		}
		queue[j + 1].nPriority = item;		//알맞은 순서에 item값 삽입
	}	
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear값을 1 올림
}

QueueObject deleteq() {		//큐의 요소를 반환하며 삭제
	if (isEmpty()) {		//큐가 비어있으면 종료
		printf("queue is empty\n");
		exit(0);
	}
	else {		//비어있지 않으면 front를 1더하고 해당 위치의 요소를 반환
		front = (front + 1) % MAX_QUEUE_SIZE;
		return queue[front];
	}
}

void main() {
	FILE* fp;		//파일 주소를 저장할 변수
	int nCount;		//반복문에서 조건으로 사용할 변수
	int nTemp;		//파일에서 불러온 정수를 저장할 변수
	int i;		//반복문에서 사용할 변수
	QueueObject qobject;		//큐 구조체 변수

	fp = fopen("data.txt", "r");		//프로젝트 내의 data.txt 파일을 읽기 형태로 불러옴
	if (fp == NULL) {		//fp의 주소가 NULL일 경우 종료
		printf("file open error\n");
		exit(0);
	}

	nCount = 1;		//nCount변수 1으로 초기화

	while (!feof(fp)) {		//fp의 끝까지 반복
		fscanf(fp, "%d", &nTemp);		//fp의 정수형 데이터를 nTemp에 저장
		addq(nTemp, nCount);		//큐에 nTemp를 저장
		nCount++;		//nCount에 1을 더함
	}

	for (i = 0; i < nCount - 1; i++) {		//큐의 개수만큼 반복
		qobject = deleteq();
		printf("%d -> ", qobject.nPriority);
	}
	printf("\n");

	fclose(fp);		//파일을 닫음
}