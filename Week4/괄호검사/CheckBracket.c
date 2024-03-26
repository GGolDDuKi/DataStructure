#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100		//스택의 최대 크기

typedef char element;		//char형에 element라는 별명 부여 -> 원소의 자료형이 바뀌어도 코드 수정이 편한 것 같습니다.

typedef struct {
	element data[SIZE];		//SIZE크기의 element형 스택 공간
	int top;		//스택의 가장 윗 부분
}Stack;		//스택 구조체

void init_stack(Stack* s){		//스택 초기화
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
		s->data[++(s->top)] = n;		//data[top+1]에 n을 대입
}

element pop(Stack* s) {		//스택에서 데이터를 추출하는 함수
	if (is_empty(s)) {		//스택이 비어있을 경우
		printf("스택이 비어 있습니다.\n");		
		return -1;		//-1 반환
	}
	else
	{
			//비어있지 않을 경우
	}
		return s->data[(s->top)--];		//data[top]의 값을 반환한 뒤, top의 값을 1 낮춤
}



int checkBracket(char* array) {		//괄호를 검사하는 함수
	Stack s;		//스택 생성
	char ch, open_ch;		//array의 현재 값을 가지는 ch, 스택에서 꺼낸 값을 저장할 open_ch
	int length = strlen(array);		//array의 길이를 변수 length에 저장
	init_stack(&s);		//스택 s를 초기화

	for (int i = 0; i < length; i++) {		//array의 길이 만큼 반복
		ch = array[i];		//ch에 array[i] 값을 대입

		switch (ch) {		//ch의 경우에 따른 스위치문
		case '(': case '[':case '{':		//ch가 여는 괄호일 경우
			push(&s, ch);		//ch를 스택 s에 저장
			break;		//스위치문 탈출

		case ')': case ']': case '}':		//ch가 닫는 괄호일 경우
			if (is_empty(&s)) return 0;		//스택 s가 비어있다면 0반환
			else {		//스택 s가 비어있지 않다면
				open_ch = pop(&s);		//open_ch에 스택에서 추출한 값 저장
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {		//open_ch(여는 괄호)와 ch(닫는 괄호)가 일치하지 하지 않는 경우
					return 0;		//0반환
				}
				break;		//스위치문 탈출
			}
		}
	}
	if (!is_empty(&s)) return 0;		//괄호 검사가 끝났는데 스택이 비어있지 않을 경우(괄호가 남았을 경우) 0 반환
	return 1;		//1 반환
}

int main() {
	FILE* file = NULL;		//파일 주소를 저장할 file변수 생성
	char array[SIZE] = { 0 };				//파일에서 불러올 문자열을 저장할 char형 배열 생성

	printf("20194339 김민욱\n\n");		//제가 작성했습니다

	file = fopen("data.txt", "r");		//file에 data.txt의 주소를 읽기모드로 불러옴
	while (!feof(file)) {		//file의 끝까지 반복
		fscanf(file, "%s", array);		//file에서 문자열을 읽어 array에 저장
		if (checkBracket(array) == 1) {		//괄호 검사에 성공할 경우
			printf("괄호검사성공 : ");		//문자열 출력
		}
		else printf("괄호검사실패 : ");		//괄호 검사에 실패할 경우
		printf("%s\n", array);		//문자열 출력
	}
}