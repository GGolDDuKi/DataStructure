#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100		//������ �ִ� ũ��

typedef char element;		//char�� �ڷ����� element��� ���� �ο�

typedef struct {		//���� ����ü
	element data[SIZE];		//element�� �����͸� SIZE��ŭ �����ϴ� ���� ����
	int top;		//������ ���� ���κ��� ����Ű�� ����
}Stack;

void init_stack(Stack* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

int is_empty(Stack* s) {		//������ ����ִ��� �˻��ϴ� �Լ�
	return (s->top == -1);		//����ִٸ� 1��ȯ
}

int is_full(Stack* s) {		//������ ���� ���ִ��� �˻��ϴ� �Լ�
	return (s->top == (SIZE - 1));		//���ִٸ� 1��ȯ
}

void push(Stack* s, element n) {		//����s�� n���� �����ϴ� �Լ�
	if (is_full(s)) {		//������ ���� ������ ���
		printf("������ ���� á���ϴ�.\n");
		return;		//�Լ� ����
	}
	else
		s->data[++(s->top)] = n;		//data[top+1]�� n�� ����, top�� �� 1����
}

element pop(Stack* s) {			//����s���� ���� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");		
		return -1;		//-1 ��ȯ
	}
	else		//������� ���� ���
		return s->data[(s->top)--];		//data[top]�� ���� ��ȯ�� ��, top�� ���� 1����
}

element peek(Stack* s) {		//���� ������ ���� �����ִ� ���� ��ȯ�ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		fprintf(stderr, "������ ��� �ֽ��ϴ�.\n");	
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->data[s->top];		//data[top]�� �� ��ȯ
}

int prec(char op) {		//�켱������ ���ϴ� �Լ�
	switch (op) {		//op�� ����
	case '(': case ')':		//��ȣ�� ���
		return 0;		//0��ȯ
	case '+': case '-':		//���� ������ ���
		return 1;		//1��ȯ
	case '*': case '/':		//���� �������� ���
		return 2;		//2��ȯ
	}
	return -1;		//��� �ش����� ���� ��� -1��ȯ
}

void infix_to_postfix(char exp[]) {		//exp���ڿ��� ����ǥ������� ����ǥ������� ��ȯ�ϴ� �Լ�
	int i = 0;		//�ݺ�Ƚ���� ��Ÿ�� ����
	char ch, top_op;		//exp�� ���� ���� ������ ch, ���ÿ� ����� ��ȣ�� ������ ������ top_op
	int len = strlen(exp);		//exp�� ���̸� ����

	Stack* s;		//���� s����
	init_stack(&s);		//���� s �ʱ�ȭ

	for (i = 0; i < len; i++) {		//exp�� ���̸�ŭ �ݺ�
		ch = exp[i];		//ch�� exp[i]�� �� ����

		switch (ch) {		//ch�� �ٸ� ���ǹ�
		case '+': case '-': case '*': case '/':		//��Ģ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))		//����s�� ������� �ʰ�, ���ÿ� ����� �켱������ ch���� ���ų� ���� ���
				printf("%c", pop(&s));		//���� s�� �� ����
			push(&s, ch);		//ch�� ���� s�� ����
			break;		//����ġ�� Ż��
		case '(':		//���� ��ȣ�� ���
			push(&s, ch);		//ch�� �� ���� s�� ����
			break;		//����ġ�� Ż��
		case ')':		//�ݴ� ��ȣ�� ���
			top_op = pop(&s);		//������ �� top_op�� ����
			while (top_op != '(') {		//���ÿ��� ���� ��ȣ�� ���� ������ �ݺ�
				printf("%c", top_op);		//top_op�� ���
				top_op = pop(&s);		//top_op�� ����s�� �� ����
			}
			break;		//����ġ�� Ż��
		default:		//�����ڰ� �ƴ� ���(�ǿ�����)
			printf("%c", ch);		//�״�� ���
			break;		//����ġ�� Ż��
		}
	}
	while (!is_empty(&s)) {		//����s�� ��� ������ �ݺ�
		printf("%c", pop(&s));		//���� s���� ������ ���
	}
}




int main() {
	FILE* file = NULL;		//�����ּҸ� ������ FILE������ ����
	char array[SIZE] = { 0 };		//���Ͽ��� �ҷ��� ���ڿ��� ������ �迭

	printf("20194339 ��ο�\n\n");		//���� �ۼ��߽��ϴ�.

	file = fopen("data.txt", "r");		//data.txt�� �ּҸ� file�� �����ϰ� �б� ���� �ҷ���
	while (!feof(file)) {		//file�� ������ �ݺ�
		fscanf(file, "%s", array);		//file�� ���ڿ��� array�� ����
		infix_to_postfix(array);		//array�� ���ڿ��� ����ǥ������� ����ǥ������� ��ȯ
		printf("\n");		
	}
}