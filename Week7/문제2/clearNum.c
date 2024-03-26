#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10		//������ �ִ� ũ��

typedef char element;

typedef struct {
	int top;		//������ ���� ���� ����Ű�� ����
	element array[SIZE];
}Stack;		//���� ����ü
Stack stack1;

void init_stack(Stack* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

int is_empty(Stack* s) {		//������ ������� ���
	return (s->top == -1);		//1��ȯ
}

int is_full(Stack* s) {		//������ ���� á�� ���
	return (s->top == (SIZE - 1));		//1��ȯ
}

void push(Stack* s, element n) {		//���ÿ� �����͸� �ִ� �Լ�
	if (is_full(s)) {		//������ ���� á�� ���
		printf("������ ���� á���ϴ�.\n");
		return;		//�Լ�����
	}
	else
		s->array[++(s->top)] = n;		//array[top+1]�� n�� ����
}

element pop(Stack* s) {		//���ÿ��� �����͸� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;		//-1 ��ȯ
	}
	return s->array[(s->top)--];		//array[top]�� ���� ��ȯ�� ��, top�� ���� 1 ����
}

int checkNum(Stack stack, char num) {		//���� ���� �ش� ���ڰ� �ִٸ� 0, ���ٸ� 1 ��ȯ
	int cnt = 0;
	for (int i = 0; i <= stack.top; i++) {
		if (stack.array[i] == num) {
			cnt++;
		}
	}
	if (cnt == 0) return 1;		//���� ���� �ش� ���ڰ� ����
	else return 0;			//����
}

int main() {
	init_stack(&stack1);		//�ݺ��Ǵ� ���ڸ� ������ ���ڿ��� �����ϱ� ���� ����
	char arr[SIZE] = { 0 };		//�Է¹��� ������ ������ ���ڿ�
	printf("������ �Է��Ͻÿ� : ");
	scanf("%s", arr);		//arr�� ���ڿ� �Է�
	int size = strlen(arr);		//arr�� ���̸� size�� ��ȯ

	printf("��� : ");
	for (int i = 0; i < size; i++) {		//arr�� ���̸�ŭ �ݺ��Ͽ� stack1�� arr[i]��Ұ� �ִ��� Ȯ���� ��, ���ٸ� Ǫ�� �� ���
		if (checkNum(stack1, arr[i])) {
			push(&stack1, arr[i]);
			printf("%c", arr[i]);
		}
	}
	return 0;
}
