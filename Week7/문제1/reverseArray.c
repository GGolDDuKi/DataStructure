#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10		//스택의 최대 크기

typedef struct {
	int top;		//스택의 가장 위를 가르키는 변수
	int array[SIZE];
}Stack;		//스택 구조체
Stack stack;

void init_stack(Stack* s) {		//스택 초기화
	s->top = -1;
}

int is_empty(Stack* s) {		//스택이 비어있을 경우
	return (s->top == -1);		//1반환
}

int is_full(Stack* s) {		//스택이 가득 찼을 경우
	return (s->top == (SIZE - 1));		//1반환
}

void push(Stack* s, int n) {		//스택에 데이터를 넣는 함수
	if (is_full(s)) {		//스택이 가득 찼을 경우
		printf("스택이 가득 찼습니다.\n");
		return;		//함수종료
	}
	else
		s->array[++(s->top)] = n;		//array[top+1]에 n을 대입
}

int pop(Stack* s) {		//스택에서 데이터를 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");
		return -1;		//-1 반환
	}
	else
	{
		//비어있지 않을 경우
	}
	return s->array[(s->top)--];		//array[top]의 값을 반환한 뒤, top의 값을 1 낮춤
}

int main() {
	int array[SIZE];
	int size = 0;

	printf("정수 배열의 크기 : ");
	scanf("%d", &size);
	printf("정수를 입력하시오 : ");
	for (int i = 0; i < size; i++) {		//size의 크기만큼 array에 입력 -> stack에 삽입을 반복
		scanf("%d", &array[i]);
		push(&stack, array[i]);
	}
	printf("반전된 정수 배열 : ");
	for (int i = 0; i < size; i++) {		//stack의 요소들을 pop
		printf("%d ", pop(&stack));
	}
}