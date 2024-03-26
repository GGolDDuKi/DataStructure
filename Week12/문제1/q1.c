#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;	//int자료형에 element라는 이름 부여

typedef struct StackNode {		//StackNode구조체 선언 및 정의
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {		//스택의 top이 되는 LinkedStackType 구조체 선언 및 정의
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {		//스택을 초기화하는 함수
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {		//스택이 비어있는지 확인하는 함수
	return (s->top == NULL);
}

int is_full(LinkedStackType* s) {		//스택이 가득 찼는지 확인하는 함수
	return 0;
}

void push(LinkedStackType* s, element item) {		//스택 s에 item을 삽입하는 함수
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	//temp->data에 item을 삽입한 뒤, s->top이 가리키던 곳을 temp->link가 가리키게 하고, s->top이 temp를 가리키게 함
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType* s) {		//스택을 출력하는 함수
	printf("-- 출력 --\n");
	for (StackNode* p = s->top; p != NULL; p = p->link) {		//StackNode형 포인터 변수 p에 s->top의 주소를 저장한 뒤, p가 NULL이 될 때까지 반복
		printf("|(%3d)|\n", p->data);
	}
	printf("-------\n");
}

element pop(LinkedStackType* s) {		//스택의 요소를 pop하는 함수
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		//temp->data를 따로 저장해준 뒤, temp 메모리 해제
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

void clear(LinkedStackType* s) {		//스택을 비우는 함수
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	printf("-- 클리어 --\n");
	while (s->top != NULL) {		//temp가 s->top을 가리키게 한뒤, s->top은 link를 연결해주고 temp가 가리키는 s->top위치 메모리 해제
		StackNode* temp = s->top;
		s->top = s->top->link;
		free(temp);
	}
}

int main() {
	LinkedStackType s;
	init(&s);
	
	//스택에 요소 삽입
	push(&s, 15);
	push(&s, 62);
	push(&s, 35);
	push(&s, 52);
	push(&s, 37);
	push(&s, 55);
	
	//문제와 같이 출력
	print_stack(&s);
	printf("\n\n");
	
	clear(&s);
	printf("\n");
	print_stack(&s);

}