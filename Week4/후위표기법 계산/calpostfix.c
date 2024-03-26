#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100		//스택의 최대 크기

typedef int element;		//int자료형에 element라는 별명 부여

typedef struct {		//스택 구조체
	element data[SIZE];		//element형 data를 SIZE만큼 저장하는 스택공간
	int top;		//스택의 가장 윗부분을 가르키는 변수
}Stack;

void init_stack(Stack* s) {		//스택을 초기화하는 함수
	s->top = -1;
}

int is_empty(Stack* s) {		//스택이 비어있는지 확인하는 함수
	return (s->top == -1);		//비어있을 경우 1반환
}

int is_full(Stack* s) {		//스택이 가득한지 확인하는 함수
	return (s->top == (SIZE - 1));		//가득할 경우 1반환
}

void push(Stack* s, element n) {		//스택s에 n을 저장하는 함수
	if (is_full(s)) {		//스택이 가득할 경우
		printf("스택이 가득 찼습니다.\n");
		return;		//함수종료
	}
	else		//스택이 가득하지 않을 경우
		s->data[++(s->top)] = n;		//data[top+1]에 n을 저장한 뒤, top의 값 1증가
}

element pop(Stack* s) {		//스택s의 값을 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");		
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->data[(s->top)--];		//data[top]의 값을 반환한 뒤, top의 값 1감소
}

element peek(Stack* s) {		//스택의 가장 위에있는 값을 확인하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		fprintf(stderr, "스택이 비어 있습니다.\n");
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->data[s->top];		//data[top]의 값 반환
}

int calculate(char exp[]) {		//exp문자열의 후위표기법을 계산하는 함수
	int op1, op2, value, i = 0;		//피연산자를 저장하는 op1, op2, 결과값을 저장할 value, 반복문의 횟수를 저장할 i
	int len = strlen(exp);		//exp의 길이를 len에 반환
	char ch;		//연산자를 저장할 변수
	Stack s;		//스택 s생성

	init_stack(&s);		//스택 s초기화
	for (i = 0; i < len; i++) {		//exp의 길이만큼 반복
		ch = exp[i];		//exp[i]의 값을 ch에 저장
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {		//ch가 연산자가 아닐 경우
			value = ch - '0';		//ch의 값을 정수형으로 변환해 value에 저장
			push(&s, value);		//value의 값을 스택s에 저장
		}
		else {		//ch가 연산자일 경우
			op2 = pop(&s);		//스택s의 값을 추출해 op2에 저장
			op1 = pop(&s);		//스택s의 값을 추출해 op1에 저장
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
	return pop(&s);		//스택 s의 값 추출하여 반환
}


int main() {
	FILE* file = NULL;		//파일주소를 저장할 변수
	char array[SIZE] = { 0 };		//파일에서 불러온 문자열을 저장할 배열

	printf("20194339 김민욱\n\n");		//직접 작성했습니다.

	file = fopen("data.txt", "r");		//data.txt의 주소를 읽기모드로 불러옴
	while (!feof(file)) {		//file의 끝까지 반복
		fscanf(file, "%s", array);		//file의 문자열을 array에 저장
		printf("후위표기식은 %s", array);		//문자열 출력
		printf("\n");
		printf("결과값은 %d\n\n", calculate(array));		//결과 출력
	}
}