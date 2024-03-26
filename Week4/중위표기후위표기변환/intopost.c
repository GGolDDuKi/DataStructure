#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100		//스택의 최대 크기

typedef char element;		//char형 자료형에 element라는 별명 부여

typedef struct {		//스택 구조체
	element data[SIZE];		//element형 데이터를 SIZE만큼 저장하는 스택 공간
	int top;		//스택의 가장 윗부분을 가르키는 변수
}Stack;

void init_stack(Stack* s) {		//스택 초기화
	s->top = -1;
}

int is_empty(Stack* s) {		//스택이 비어있는지 검사하는 함수
	return (s->top == -1);		//비어있다면 1반환
}

int is_full(Stack* s) {		//스택이 가득 차있는지 검사하는 함수
	return (s->top == (SIZE - 1));		//차있다면 1반환
}

void push(Stack* s, element n) {		//스택s에 n값을 저장하는 함수
	if (is_full(s)) {		//스택이 가득 차있을 경우
		printf("스택이 가득 찼습니다.\n");
		return;		//함수 종료
	}
	else
		s->data[++(s->top)] = n;		//data[top+1]에 n값 저장, top의 값 1증가
}

element pop(Stack* s) {			//스택s에서 값을 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");		
		return -1;		//-1 반환
	}
	else		//비어있지 않을 경우
		return s->data[(s->top)--];		//data[top]의 값을 반환한 뒤, top의 값을 1감소
}

element peek(Stack* s) {		//현재 스택의 가장 위에있는 값을 반환하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		fprintf(stderr, "스택이 비어 있습니다.\n");	
		return -1;		//-1반환
	}
	else		//비어있지 않을 경우
		return s->data[s->top];		//data[top]의 값 반환
}

int prec(char op) {		//우선순위를 정하는 함수
	switch (op) {		//op의 값이
	case '(': case ')':		//괄호일 경우
		return 0;		//0반환
	case '+': case '-':		//덧셈 뺄셈일 경우
		return 1;		//1반환
	case '*': case '/':		//곱셈 나눗셈일 경우
		return 2;		//2반환
	}
	return -1;		//모두 해당하지 않을 경우 -1반환
}

void infix_to_postfix(char exp[]) {		//exp문자열을 중위표기법에서 후위표기법으로 변환하는 함수
	int i = 0;		//반복횟수를 나타낼 변수
	char ch, top_op;		//exp의 현재 값을 저장할 ch, 스택에 저장된 부호를 추출해 저장할 top_op
	int len = strlen(exp);		//exp의 길이를 저장

	Stack* s;		//스택 s생성
	init_stack(&s);		//스택 s 초기화

	for (i = 0; i < len; i++) {		//exp의 길이만큼 반복
		ch = exp[i];		//ch에 exp[i]의 값 대입

		switch (ch) {		//ch에 다른 조건문
		case '+': case '-': case '*': case '/':		//사칙연산일 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))		//스택s가 비어있지 않고, 스택에 저장된 우선순위가 ch보다 높거나 같을 경우
				printf("%c", pop(&s));		//스택 s의 값 추출
			push(&s, ch);		//ch를 스택 s에 저장
			break;		//스위치문 탈출
		case '(':		//여는 괄호일 경우
			push(&s, ch);		//ch의 값 스택 s에 저장
			break;		//스위치문 탈출
		case ')':		//닫는 괄호일 경우
			top_op = pop(&s);		//스택의 값 top_op에 저장
			while (top_op != '(') {		//스택에서 여는 괄호가 나올 때까지 반복
				printf("%c", top_op);		//top_op값 출력
				top_op = pop(&s);		//top_op에 스택s의 값 추출
			}
			break;		//스위치문 탈출
		default:		//연산자가 아닐 경우(피연산자)
			printf("%c", ch);		//그대로 출력
			break;		//스위치문 탈출
		}
	}
	while (!is_empty(&s)) {		//스택s를 비울 때까지 반복
		printf("%c", pop(&s));		//스택 s에서 추출해 출력
	}
}




int main() {
	FILE* file = NULL;		//파일주소를 저장할 FILE포인터 변수
	char array[SIZE] = { 0 };		//파일에서 불러올 문자열을 저장할 배열

	printf("20194339 김민욱\n\n");		//제가 작성했습니다.

	file = fopen("data.txt", "r");		//data.txt의 주소를 file에 저장하고 읽기 모드로 불러옴
	while (!feof(file)) {		//file의 끝까지 반복
		fscanf(file, "%s", array);		//file의 문자열을 array에 저장
		infix_to_postfix(array);		//array의 문자열을 중위표기법에서 후위표기법으로 변환
		printf("\n");		
	}
}