#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];	//int자료형에 element라는 이름 부여

typedef struct DListNode {		//DListNode구조체 선언 및 정의
	element data;
	struct DListNode* llink;		//왼쪽 link의 주소를 저장할 포인터변수
	struct DListNode* rlink;		//오른쪽 link의 주소를 저장할 포인터변수
}DListNode;

DListNode* current;		//현재 선택된 곡을 가리키는 DListNode형 포인터변수

void init(DListNode* head) {		//리스트 초기화
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element data) {		//before의 오른쪽에 노드 삽입
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));		//새롭게 추가될 노드 동적할당
	strcpy(newnode->data, data);		//새로운 노드에 data삽입
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
		if(p->data == current->data)
			printf("<-| | #%s# | |-> ", p->data);		//p->data 출력
		else
			printf("<-| |%s| |-> ", p->data);		//p->data 출력
	}
	printf("\n");		//개행
}

int main() {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));		//리스트의 시작이 되는 head포인터 변수 선언
	init(head);		//head 초기화

	dinsert(head, "Mamamia");		//리스트의 처음에 Mamamia삽입
	dinsert(head, "Dancing Queen");		//리스트의 처음에 Dancing Queen삽입
	dinsert(head, "Fernando");		//리스트의 처음에 Fernando삽입

	current = head->rlink;		//현재 곡이 첫번째 곡을 가리킴
	print_dlist(head);		//리스트 출력

	do {		//한 번은 실행
		printf("\n명령어를 입력하시오(<, >, q) : ");
		ch = getchar();		//사용자에게 문자를 입력받아 변수에 저장
		if (ch == '<') {		//사용자가 <를 입력했을 경우
			current = current->llink;		//왼쪽 곡을 선택
			if (current == head)		//현재 곡의 왼쪽 노드가 head일 경우
				current = current->llink;		//한 번더 왼쪽 노드로 이동
		}
		else if (ch == '>') {		//사용자가 >를 입력했을 경우
			current = current->rlink;		//오른쪽 곡을 선택
			if (current == head)		//현재 곡의 오른쪽 노드가 head일 경우
				current = current->rlink;		//한 번더 오른쪽 노드로 이동
		}
		print_dlist(head);		//리스트 출력
		getchar();		//ch버퍼 삭제?
	} while (ch != 'q');		//사용자가 q를 입력할 때 까지 반복

	free(head);		//리스트 메모리 반환
	return 0;
}