#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;	//int자료형에 element라는 이름 부여

typedef struct DListNode {		//DListNode구조체 선언 및 정의
	element data;
	struct DListNode* llink;		//오른쪽 link의 주소를 저장할 포인터변수
	struct DListNode* rlink;		//왼쪽 link의 주소를 저장할 포인터변수
}DListNode;

void init(DListNode* head) {		//리스트 초기화
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element data) {		//before의 오른쪽에 노드 삽입
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));		//새롭게 추가될 노드 동적할당
	newnode->data = data;		//새로운 노드에 data삽입
	newnode->llink = before;		//새로운 노드의 왼쪽 link가 before을 가르키게 함
	newnode->rlink = before->rlink;		//새로운 노드의 오른쪽 link가 before의 오른쪽link을 가르키게 함
	before->rlink->llink = newnode;		//before의 오른쪽에 있던 리스트의 왼쪽 link가 새로운 노드를 가르키게 함
	before->rlink = newnode;		//before의 오른쪽 link가 새로운 노드를 가르키게 함
}

void ddelete(DListNode* head, DListNode* removed) {		//리스트노드를 삭제하는 함수
	if (removed == head) return;		//리스트가 비어있을 경우 종료
	removed->llink->rlink = removed->rlink;		//removed의 왼쪽 리스트의 오른쪽 link에 removed의 오른쪽 link에 저장된 주소를 대입
	removed->rlink->llink = removed->llink;		//removed의 오른쪽 리스트의 왼쪽 link에 removed의 왼쪽 link에 저장된 주소를 대입
	free(removed);		//removed 메모리 삭제
}

void print_dlist(DListNode* head) {		//리스트를 출력하는 함수
	DListNode* p;		//DListNode의 주소를 저장할 포인터변수 선언
	for (p = head->rlink; p != head; p = p->rlink) {		//p가 head가 되기 전까지 반복
		printf("<-| |%d| |-> ", p->data);		//p->data 출력
	}
	printf("\n");		//개행
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));		//리스트의 시작이 되는 head포인터 변수 선언
	init(head);		//head 초기화
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {		//0부터 4까지 리스트에 삽입하는 과정을 출력
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {		//0부터 4까지 리스트에서 삭제하는 과정을 출력
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);		//head메모리 해제
	return 0;
}