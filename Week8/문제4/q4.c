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

void print_list(ListNode* head) {		//현재 노드를 모두 출력
	for (ListNode* p = head; p != NULL; p = p->link)		//노드가 NULL을 가리킬 때 까지 출력
		printf("%d->", p->data);
	printf("NULL\n");		//마지막에 NULL을 출력
}

int list_length(ListNode* head) {		//노드의 개수를 구하는 함수
	int length = 0;
	for (ListNode* p = head; p != NULL; p = p->link)		//노드가 NULL을 가리킬 때 까지 length증가
		length++;
	return length;		//노드의 개수(length)를 반환
}

int list_sum(ListNode* head) {		//노드의 데이터의 총합을 구하는 함수
	int result = 0;
	for (ListNode* p = head; p != NULL; p = p->link)		//노드가 NULL을 가리킬 때 까지 result에 p->data를 덧셈
		result = result + p->data;
	return result;		//노드의 데이터의 총합 반환
}

int list_find(ListNode* head, element value) {		//노드에 value가 몇개 있는지 찾는 함수
	int cnt = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {		//노드가 NULL을 가리킬 때 까지 p->data의 값이 value와 같으면 cnt++
		if (p->data == value)
			cnt++;
	}		
	return cnt;
}

int main() {
	ListNode* head = NULL;		//노드의 시작이 될 head 생성
	int size = 0;		//노드의 개수를 저장할 size변수
	int value = 0;		//입력받은 요소 값을 저장할 value변수
	int find = 0;

	printf("노드의 개수 : ");
	scanf("%d", &size);

	for (int i = 1; i <= size; i++) {		//입력받은 노드의 개수만큼 반복
		printf("노드 #%d 데이터: ", i);
		scanf("%d", &value);
		head = insert_last(head, value);		//입력받은 값을 마지막 요소에 삽입
	}

	printf("탐색할 값을 입력하시오 : ");
	scanf("%d", &find);
	printf("%d는 연결 리스트에서 %d번 나타납니다.", find, list_find(head, find));		//노드에 find가 몇 개인지 출력

	return 0;
}