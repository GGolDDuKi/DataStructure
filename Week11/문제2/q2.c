#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];	//char자료형에 element라는 이름 부여

typedef struct ListNode {		//ListNode구조체 선언 및 정의
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {		//리스트의 첫 번째 위치에 요소를 추가하는 함수
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//요소를 추가하기 위한 ListNode포인터 변수 node 생성
	if (node == NULL) {		//동적할당이 제대로 되었는지 검사
		printf("메모리가 정상적으로 할당되지 않았습니다.\n");
		exit(1);
	}
	strcpy(node->data, data);		//새로 만든 노드에 data삽입
	if (head == NULL) {		//리스트가 비어있을 경우
		head = node;		//head가 node가 됨
		node->link = head;		//head의 link가 본인을 가리키도록 함
	}
	else	//리스트가 비어있지 않을 경우
	{
		node->link = head->link;		//head의 link가 기리키던 곳을 node의 link가 가리킴
		head->link = node;		//head의 link가 node를 가리킴
	}
	return head;		//head 반환
}

ListNode* insert_last(ListNode* head, element data) {		//노드의 마지막에 노드를 삽입하는 함수	
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//삽입할 요소를 저장할 포인터 node 생성
	if (node == NULL) {		//메모리가 제대로 할당 되었는지 확인
		printf("메모리가 정상적으로 할당되지 않았습니다.\n");
		exit(1);
	}
	strcpy(node->data, data);		//node의 data에 data 삽입
	if (head == NULL) {		//리스트가 비어있을 경우
		head = node;		//head가 node가 됨
		node->link = head;		//head의 link가 본인을 가리킴
	}
	else {		//리스트가 비어있지 않을 경우
		node->link = head->link;		//node의 link가 head의 link를 가리킴
		head->link = node;		//head의 link가 node를 가리킴
		head = node;		//head가 node가 됨
	}
	return head;		//head 반환
}

void print_list(ListNode* head) {		//현재 노드를 모두 출력
	ListNode* p;		//head에게서 주소를 넘겨받을 포인터

	if (head == NULL) return;		//리스트가 비어있을 경우 종료
	p = head->link;		//p가 head의 link가 가리키는 곳을 가리킴
	do {		//한 번은 실행
		printf("%d->", p->data);		//p->data 출력
		p = p->link;		//p가 link를 가리킴
	} while (p != head->link);		//p가 head->link일 때 까지 반복
}

int main() {
	ListNode* head = NULL;		//ListNode형 포인터 head변수 생성

	head = insert_first(head, "KIM");		//리스트의 앞에 KIM삽입
	head = insert_first(head, "PARK");		//리스트의 앞에 PARK삽입
	head = insert_first(head, "CHOI");		//리스트의 앞에 CHOI삽입

	ListNode* p = head;		//ListNode형 포인터 변수 p에 head의 주소 대입
	for (int i = 0; i < 12; i++) {		//12번 반복
		printf("현재 차례 = %s", p->data);		//p->data 출력
		printf("\n");		//개행
		p = p->link;		//p가 다음 리스트를 가리키도록 함
	}
	return 0;
}