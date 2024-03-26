#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100		//스택의 최대 크기

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

element peek(LinkedStackType* s) {		//스택의 가장 윗부분 값을 확인하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		fprintf(stderr, "스택이 비어 있습니다.\n");		//문자열 출력
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->top->data;		//스택의 top의 값 반환
}

int prec(char op) {		//우선 순위를 반환하는 함수
	switch (op) {		//op에 따른 조건문
	case '(': case ')':		//괄호일 경우
		return 0;		//0반환
	case '+': case '-':		// +- 연산자일 경우
		return 1;		//1반환
	case '*': case '/':		// */ 연산자일 경우
		return 2;		//2반환
	}
	return -1;		//그 외의 경우 -1반환
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

void infix_to_postfix(char exp[], char* inpost) {		//exp의 중위표기법을 후위표기법으로 변환해 inpost에 저장하는 함수
	int i = 0;		//반복횟수를 나타내는 변수
	int cnt = 0;		//inpost의 인덱스를 나타내는 변수
	char ch, top_op;		//exp의 값을 저장하는 ch, 스택에 저장된 연산자를 저장하는 top_op
	int len = strlen(exp);		//exp의 길이를 len에 반환하여 저장

	LinkedStackType s;		//리스트스택 s생성
	init(&s);		//스택 s초기화

	for (i = 0; i < len; i++) {		//exp의 길이만큼 반복
		ch = exp[i];		//exp[i]의 값을 ch에 저장

		switch (ch) {		//ch에 따른 스위치 조건문
		case '+': case '-': case '*': case '/':		//연산자일 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))		//스택이 비어있지 않고, 스택에 저장된 값의 우선순위가 ch의 우선순위보다 높을 경우
				inpost[cnt++] = pop(&s);		//스택 s의 값을 추출하여 inpost[cnt]에 저장한 뒤, cnt의 값 1증가
			//printf("%c", pop(&s));
			push(&s, ch);		//ch를 스택 s에 저장
			break;		//스위치문 탈출
		case '(':		//여는 괄호일 경우
			push(&s, ch);		//ch를 스택 s에 저장
			break;		//스위치문 탈출
		case ')':		//닫는 괄호일 경우
			top_op = pop(&s);		//스택 s의 값을 추출해 top_op에 저장
			while (top_op != '(') {		//스택 s에서 여는 괄호가 나올 때까지 반복
				inpost[cnt++] = top_op;		//top_op의 값을 inpost[cnt]에 저장한 뒤, cnt의 값 1증가
				//printf("%c", top_op);
				top_op = pop(&s);		//top_op에 스택s에서 값을 추출해 저장
			}
			break;		//스위치문 탈출
		default:		//그 외의 경우(피연산자일 경우)
			inpost[cnt++] = ch;		//ch의 값을 inpost[cnt]에 저장한 뒤, cnt의 값 1증가
			//printf("%c", ch);
			break;		//스위치문 탈출
		}
	}
	while (!is_empty(&s)) {		//스택을 비울 때까지 반복
		inpost[cnt++] = pop(&s);		//스택 s의 값을 추출하여 inpost[cnt]에 저장한 뒤, cnt의 값 1증가
		//printf("%c", pop(&s));
	}
}

int calculate(char exp[]) {		//exp(후위표기법)을 계산하는 함수
	int op1, op2, value, i = 0;		//피연산자 op1, op2, 정수값을 저장하는 value, 반복횟수를 나타내는 i
	int len = strlen(exp);		//exp의 길이를 반환해 len에 저장
	char ch;		//연산자를 저장하는 변수
	LinkedStackType s;		//리스트 스택 s생성
	init(&s);		//스택 s 초기화

	for (int i = 0; i < len; i++) {		//exp의 길이만큼 반복
		ch = exp[i];		//exp[i]의 값 ch에 저장
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {		//연산자가 아닐 경우
			value = ch - '0';		//정수형으로 변환하여
			push(&s, value);		//스택 s에 저장
		}
		else {		//연산자일 경우
			op2 = pop(&s);		//스택s에서 피연산자를 불러와 저장
			op1 = pop(&s);		//스택s에서 피연산자를 불러와 저장
			switch (ch) {		//ch에 따른 조건문
			case '+':		// + 연산자일 경우
				push(&s, op1 + op2);		//op1 + op2를 스택 s에 저장
				break;		//스위치문 탈출
			case '-':		// - 연산자일 경우
				push(&s, op1 - op2);		//op1 - op2를 스택 s에 저장
				break;		//스위치문 탈출
			case '*':		// * 연산자일 경우
				push(&s, op1 * op2);		//op1 * op2를 스택 s에 저장
				break;		//스위치문 탈출
			case '/':		// / 연산자일 경우
				push(&s, op1 / op2);		//op1 / op2를 스택 s에 저장
				break;		//스위치문 탈출
			}
		}
	}
	return pop(&s);		//스택s의 값을 추출하여 반환
}

int main() {
	FILE* file = NULL;		//파일 주소를 저장하는 변수
	char array[SIZE] = { 0 };		//중위표기법을 저장할 문자열
	char inpost[SIZE] = { 0 };		//후위표기법을 저장할 문자열

	printf("20194339 김민욱\n");

	file = fopen("data.txt", "r");		//data.txt를 읽기모드로 불러옴
	while (!feof(file)) {		//file의 끝까지 반복
		fscanf(file, "%s", array);		//file의 문자열을 array에 저장
		printf("중위표기식은 %s\n", array);		//문자열 출력
		printf("후위표기식은 ");		//문자열 출력
		infix_to_postfix(array, inpost);		//중위표기법을 후위표기법으로 변환
		printf("%s", inpost);		//후위표기법 문자열 출력
		printf("\n");		//문자열 출력
		printf("결과값은 %d\n\n", calculate(inpost));		//후위표기법 계산 후 출력
	}
}