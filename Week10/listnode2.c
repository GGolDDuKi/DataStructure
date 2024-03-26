#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;	//int자료형에 element라는 이름 부여

typedef struct ListNode {		//ListNode구조체 선언 및 정의
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {		//리스트의 첫 번째 위치에 요소를 추가하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//요소를 추가하기 위한 ListNode포인터 변수 p 생성
	if (p == NULL) {		//동적할당이 제대로 되었는지 검사
		printf("메모리가 정상적으로 할당되지 않았습니다.\n");
		exit(1);
	}
	p->data = value;	//p에 원하는 값을 넣고
	p->link = head;		//기존 head의 주소값을 넘겨준 뒤,
	head = p;		//head가 p를 가리키도록 만든다
	return head;		//head를 반환
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {		//리스트 pre뒤에 새로운 리스트를 삽입하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//요소를 추가하기 위한 ListNode포인터 변수 p 생성
	if (p == NULL) {		//동적할당이 제대로 되었는지 검사
		printf("메모리가 정상적으로 할당되지 않았습니다.\n");
		exit(1);
	}
	p->data = value;		//p에 원하는 값을 넣고
	p->link = pre->link;		//pre가 기존에 가리키던 주소를 p가 가리키도록 한 뒤
	pre->link = p;		//pre가 p를 가리키도록 만든다
	return head;		//head를 반환
}

ListNode* insert_last(ListNode* head, element value) {		//노드의 마지막에 노드를 삽입하는 함수	
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//삽입할 요소를 저장할 포인터 p 생성
	if (p == NULL) {		//메모리가 제대로 할당 되었는지 확인
		printf("메모리가 정상적으로 할당되지 않았습니다.\n");
		exit(1);
	}
	p->data = value;	//p->data에 넣으려는 값을 대입
	p->link = NULL;		//p->link가 NULL을 가리키도록 함(마지막에 들어가기 때문)
	if (head == NULL) {		//head가 NULL이라면(요소가 없다면)
		head = p;		//head가 p의 주소를 가리키게 함
	}
	else {		//head가 NULL이 아니라면
		ListNode* last = head;		//마지막 노드의 주소를 가리킬 포인터 last를 생성한 뒤, head의 주소를 할당
		while (last->link != NULL)		//노드의 마지막 요소까지 찾아감(NULL을 가리키기 전까지)
			last = last->link;
		last->link = p;		//마지막 요소가 p를 가리키게 만듬
	}
	return head;		//head를 반환
}

ListNode* delete_first(ListNode* head) {		//첫 번째 노드를 삭제하는 함수
	ListNode* removed;		//삭제에 사용할 노드 선언
	if (head == NULL) return NULL;		//헤드가 가리키는 값이 없을 경우 NULL 반환
	removed = head;		//removed가 head와 같은 주소를 가리키게 만들고
	head = removed->link;		//head에 removed가 가리키는 다음 노드의 주소를 대입
	free(removed);		//할당받았던 메모리 반환
	return head;		//head반환
}

ListNode* delete(ListNode* head, ListNode* pre) {		//pre가 가리키는 노드의 다음 노드를 삭제하는 함수
	ListNode* removed;		//삭제에 사용할 노드 선언
	removed = pre->link;		//removed에 pre가 가리키는 다음 주소를 준 뒤
	pre->link = removed->link;		//pre가 가리키는 다음 주소를 removed가 가리키는 다음 노드의 주소(pre의 다음 다음 주소)로 변경
	free(removed);		//removed노드(pre의 기존 다음 노드)를 할당 해제
	return head;		//head반환
}

void delete_pre(ListNode* pre) {		//pre가 가리키는 노드의 다음 노드를 삭제하는 함수
	ListNode* removed;		//삭제에 사용할 노드 선언
	removed = pre->link;		//removed에 pre가 가리키는 다음 주소를 준 뒤
	pre->link = removed->link;		//pre가 가리키는 다음 주소를 removed가 가리키는 다음 노드의 주소(pre의 다음 다음 주소)로 변경
	free(removed);		//removed노드(pre의 기존 다음 노드)를 할당 해제
}

void print_list(ListNode* head) {		//현재 노드를 모두 출력
	printf("( ");
	for (ListNode* p = head; p != NULL; p = p->link)		//노드가 NULL을 가리킬 때 까지 출력
		printf("%d ", p->data);
	printf(")\n");		//마지막에 NULL을 출력
}

void count_num(ListNode* head) {		//입력받은 값이 연결리스트 내에 몇 개 있는지 출력하는 함수
	int value = 1;		//입력받은 값을 저장할 변수
	int cnt = 0;		//개수를 셀 변수

	while (value != 0) {		//0을 입력받기 전까지 반복
		printf("값을 입력하세요(0 : 종료) : ");
		scanf("%d", &value);

		for (ListNode* p = head; p != NULL; p = p->link) {		//연결리스트 끝까지 반복
			if (p->data == value)
				cnt++;
		}
		if (value != 0) {		//0을 입력하면 프로그램 종료
			printf("%d는 리스트에 %d개 있습니다.\n", value, cnt);
			cnt = 0;
		}
	}
}

ListNode* delete_even(ListNode* head) {		//연결리스트의 짝수 인덱스를 삭제하는 함수
	head = delete_first(head);		//0번째 인덱스 삭제
	for (ListNode* p = head; p != NULL; p = p->link) {		//짝수 인덱스 삭제
		delete_pre(p);
	}
	return head;		//head반환
}

void find_maxmin(ListNode* head) {		//연결리스트에서 최대값, 최소값을 찾아 출력하는 함수
	int max = head->data;		//최대값을 저장할 변수, head->data로 초기화
	int min = head->data;		//최소값을 저장할 변수, head->data로 초기화
	for (ListNode* p = head; p != NULL; p = p->link) {		//연결리스트 끝까지 값을 대입하여 조건에 맞을 경우 변수에 대입
		if (p->data >= max)
			max = p->data;
		if (p->data <= min)
			min = p->data;
	}
	printf("최대값은 %d\n", max);		//최대, 최소값 출력
	printf("최소값은 %d", min);
}

int main() {
	ListNode* head = NULL;		//노드의 시작이 될 head 생성
	FILE* file = NULL;
	int value = 0;

	file = fopen("data.txt", "r");

	while (!feof(file)) {		//data.txt에서 모든 데이터를 읽어올 때 까지 반복
		fscanf(file, "%d", &value);
		head = insert_last(head, value);		//불러온 값을 연결리스트의 끝에 추가
	}

	print_list(head);		//문제1 연결리스트 출력
	//count_num(head);		//문제2 입력한 숫자 개수 확인
	//head = delete_even(head);		//문제3 짝수 인덱스 삭제
	//print_list(head);			//문제3
	//find_maxmin(head);		//문제4 연결리스트 최대값 최소값 출력
}