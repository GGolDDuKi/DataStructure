#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10		//스택의 최대 크기

typedef char element;

typedef struct {
	int top;		//스택의 가장 위를 가르키는 변수
	element array[SIZE];
}Stack;		//스택 구조체
Stack stack1;

void init_stack(Stack* s) {		//스택 초기화
	s->top = -1;
}

int is_empty(Stack* s) {		//스택이 비어있을 경우
	return (s->top == -1);		//1반환
}

int is_full(Stack* s) {		//스택이 가득 찼을 경우
	return (s->top == (SIZE - 1));		//1반환
}

void push(Stack* s, element n) {		//스택에 데이터를 넣는 함수
	if (is_full(s)) {		//스택이 가득 찼을 경우
		printf("스택이 가득 찼습니다.\n");
		return;		//함수종료
	}
	else
		s->array[++(s->top)] = n;		//array[top+1]에 n을 대입
}

element pop(Stack* s) {		//스택에서 데이터를 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");
		return -1;		//-1 반환
	}
	return s->array[(s->top)--];		//array[top]의 값을 반환한 뒤, top의 값을 1 낮춤
}

int checkNum(Stack stack, char num) {		//스택 내에 해당 숫자가 있다면 0, 없다면 1 반환
	int cnt = 0;
	for (int i = 0; i <= stack.top; i++) {
		if (stack.array[i] == num) {
			cnt++;
		}
	}
	if (cnt == 0) return 1;		//스택 내에 해당 숫자가 없음
	else return 0;			//있음
}

int main() {
	init_stack(&stack1);		//반복되는 숫자를 제거한 문자열을 저장하기 위한 스택
	char arr[SIZE] = { 0 };		//입력받은 정수를 저장할 문자열
	printf("정수를 입력하시오 : ");
	scanf("%s", arr);		//arr에 문자열 입력
	int size = strlen(arr);		//arr의 길이를 size에 반환

	printf("출력 : ");
	for (int i = 0; i < size; i++) {		//arr의 길이만큼 반복하여 stack1에 arr[i]요소가 있는지 확인한 후, 없다면 푸시 후 출력
		if (checkNum(stack1, arr[i])) {
			push(&stack1, arr[i]);
			printf("%c", arr[i]);
		}
	}
	return 0;
}
