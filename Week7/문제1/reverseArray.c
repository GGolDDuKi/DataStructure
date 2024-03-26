#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10		//������ �ִ� ũ��

typedef struct {
	int top;		//������ ���� ���� ����Ű�� ����
	int array[SIZE];
}Stack;		//���� ����ü
Stack stack;

void init_stack(Stack* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

int is_empty(Stack* s) {		//������ ������� ���
	return (s->top == -1);		//1��ȯ
}

int is_full(Stack* s) {		//������ ���� á�� ���
	return (s->top == (SIZE - 1));		//1��ȯ
}

void push(Stack* s, int n) {		//���ÿ� �����͸� �ִ� �Լ�
	if (is_full(s)) {		//������ ���� á�� ���
		printf("������ ���� á���ϴ�.\n");
		return;		//�Լ�����
	}
	else
		s->array[++(s->top)] = n;		//array[top+1]�� n�� ����
}

int pop(Stack* s) {		//���ÿ��� �����͸� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;		//-1 ��ȯ
	}
	else
	{
		//������� ���� ���
	}
	return s->array[(s->top)--];		//array[top]�� ���� ��ȯ�� ��, top�� ���� 1 ����
}

int main() {
	int array[SIZE];
	int size = 0;

	printf("���� �迭�� ũ�� : ");
	scanf("%d", &size);
	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < size; i++) {		//size�� ũ�⸸ŭ array�� �Է� -> stack�� ������ �ݺ�
		scanf("%d", &array[i]);
		push(&stack, array[i]);
	}
	printf("������ ���� �迭 : ");
	for (int i = 0; i < size; i++) {		//stack�� ��ҵ��� pop
		printf("%d ", pop(&stack));
	}
}