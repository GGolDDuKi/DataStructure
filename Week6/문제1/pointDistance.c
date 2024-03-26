#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 오류를 무시하기 위해 추가
#include <stdio.h>		//표준 입출력을 담당하는 헤더
#include <math.h>

#define MAX_QUEUE_SIZE 100		//큐의 최대 크기

typedef struct {		//int형 배열을 저장하는 Point 큐
	int xy[2];		//x, y좌표를 저장할 큐의 요소
}Point;

Point point[MAX_QUEUE_SIZE];		//point구조체의 배열
int front, rear;		//큐의 front, rear 선언

void initialize() {		//큐를 초기화하는 함수
	front = rear = -1;
}

int isEmpty() {		//큐가 비어있으면 1을 반환하는 함수
	return (front == rear);
}

int isFull() {		//큐가 포화상태면 1을 반환하는 함수
	//rear + 1에서 + 1은 원형큐에서 항상 비워두는 한칸을 스킵하는 절차
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(Point item) {		//큐에 item을 삽입하는 함수
	if (isFull()) {		//큐가 포화상태면 종료
		printf("Queue is full\n");
		exit(0);
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;		//rear의 값을 1더해준다
	point[rear] = item;		//rear위치에 item을 삽입
}

Point deleteq() {		//큐의 요소를 반환
	if (isEmpty()) {		//큐가 비어있으면 종료
		printf("queue is empty\n");
		exit(0);
	}
	front = (front + 1) % MAX_QUEUE_SIZE;		//front의 값을 1더해줌
	return point[front];		//front위치의 값을 반환
}

void GetDistance() {		//큐의 요소들간 거리를 구해 출력하는 함수
	int i = 0;		//반복문에 사용할 변수
	int cnt = 1;		//출력 번호로 사용할 변수
	while (front < rear) {		//front가 rear보다 작을 경우 반복
		int x1, x2, y1, y2 = 0;		//큐에 저장된 좌표를 저장할 변수들
		double distance = 0;		//좌표간 거리를 저장할 변수
		deleteq();		//front를 1 올려줌
		i = front + 1;		//front의 요소와 i위치의 요소간의 거리를 구할 생각
		while (i <= rear) {		//i가 rear보다 작거나 같을 경우 반복
			if (i <= rear) {		
				x1 = point[front].xy[0];		//front의 x좌표를 x1에 저장
				y1 = point[front].xy[1];		//front의 y좌표를 y1에 저장
				x2 = point[i].xy[0];		//i의 x좌표를 x2에 저장
				y2 = point[i].xy[1];		//i의 y좌표를 y2에 저장

				double x3 = x2 - x1;		//x좌표간의 거리를 x3에 저장
				double y3 = y2 - y1;		//y좌표간의 거리를 y3에 저장
				distance = sqrt(x3 * x3 + y3 * y3);		//sqrt함수를 사용하여 거리 구하기
			}
			printf("%d. (%d, %d)와 (%d, %d)의 사이의 거리는 %.5f 입니다.\n", cnt++, x1, y1, x2, y2, distance);
			//구한 내용들 출력 결과에 맞춰 출력
			i++;		//i를 증가시킴
		}
	}
}

void main() {
	initialize();
	FILE* fp;		//파일 주소를 저장할 변수
	Point dot = { 0 };		//파일에서 불러온 좌표값을 임시로 저장할 버퍼

	fp = fopen("data01.txt", "r");		//프로젝트 내의 data01.txt 파일을 읽기 형태로 불러옴

	if (fp == NULL) {		//fp의 주소가 NULL일 경우 종료
		printf("file open error\n");
		exit(0);
	}

	while (!feof(fp)) {		//fp의 끝까지 반복
		fscanf(fp, "%d %d", &dot.xy[0], &dot.xy[1]);		//txt파일에 저장된 x, y값을 dot에 저장
		addq(dot);		//dot의 요소를 point 큐에 추가
	}

	GetDistance();		//거리를 구하는 함수 호출
}