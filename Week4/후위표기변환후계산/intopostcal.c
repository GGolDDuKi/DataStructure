#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100		//스택의 최대 크기

typedef int element;		//int자료형에 element라는 별명 부여

typedef struct {		//구조체로 스택 구현
	element data[SIZE];		//element형 data를 SIZE만큼 저장하는 스택 공간
	int top;		//스택의 가장 윗부분을 가르키는 변수
}Stack;

void init_stack(Stack* s) {		//스택 초기화
	s->top = -1;
}

int is_empty(Stack* s) {		//스택이 비어있는지 확인하는 함수
	return (s->top == -1);		//비어있으면 1반환
}

int is_full(Stack* s) {		//스택이 가득한지 확인하는 함수
	return (s->top == (SIZE - 1));		//가득하면 1반환
}

void push(Stack* s, element n) {		//스택s에 n을 저장하는 함수
	if (is_full(s)) {		//스택이 가득하면
		printf("스택이 가득 찼습니다.\n");
		return;		//함수 종료
	}
	else		//가득하지 않으면
		s->data[++(s->top)] = n;		//data[top+1]에 n을 저장하고, top의 값 1증가
}

element pop(Stack* s) {		//스택s의 값을 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");		//문자열출력
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->data[(s->top)--];		//data[top]의 값을 반환한 뒤, top의 값 1감소
}

element peek(Stack* s) {		//스택의 가장 윗부분 값을 확인하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		fprintf(stderr, "스택이 비어 있습니다.\n");		//문자열 출력
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->data[s->top];		//data[top]의 값 반환
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

void infix_to_postfix(char exp[], char* inpost) {		//exp의 중귀표기법을 후위표기법으로 변환해 inpost에 저장하는 함수
	int i = 0;		//반복횟수를 나타내는 변수
	int cnt = 0;		//inpost의 인덱스를 나타내는 변수
	char ch, top_op;		//exp의 값을 저장하는 ch, 스택에 저장된 연산자를 저장하는 top_op
	int len = strlen(exp);		//exp의 길이를 len에 반환하여 저장

	Stack s;		//스택 s생성
	init_stack(&s);		//스택 s초기화

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
	Stack s;		//스택 s생성

	init_stack(&s);		//스택 s 초기화
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

	printf("20194339 김민욱\n\n");		//직접 작성했습니다.

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