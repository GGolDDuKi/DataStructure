#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100		//������ �ִ� ũ��

typedef int element;		//int�ڷ����� element��� ���� �ο�

typedef struct {		//����ü�� ���� ����
	element data[SIZE];		//element�� data�� SIZE��ŭ �����ϴ� ���� ����
	int top;		//������ ���� ���κ��� ����Ű�� ����
}Stack;

void init_stack(Stack* s) {		//���� �ʱ�ȭ
	s->top = -1;
}

int is_empty(Stack* s) {		//������ ����ִ��� Ȯ���ϴ� �Լ�
	return (s->top == -1);		//��������� 1��ȯ
}

int is_full(Stack* s) {		//������ �������� Ȯ���ϴ� �Լ�
	return (s->top == (SIZE - 1));		//�����ϸ� 1��ȯ
}

void push(Stack* s, element n) {		//����s�� n�� �����ϴ� �Լ�
	if (is_full(s)) {		//������ �����ϸ�
		printf("������ ���� á���ϴ�.\n");
		return;		//�Լ� ����
	}
	else		//�������� ������
		s->data[++(s->top)] = n;		//data[top+1]�� n�� �����ϰ�, top�� �� 1����
}

element pop(Stack* s) {		//����s�� ���� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");		//���ڿ����
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->data[(s->top)--];		//data[top]�� ���� ��ȯ�� ��, top�� �� 1����
}

element peek(Stack* s) {		//������ ���� ���κ� ���� Ȯ���ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		fprintf(stderr, "������ ��� �ֽ��ϴ�.\n");		//���ڿ� ���
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->data[s->top];		//data[top]�� �� ��ȯ
}

int prec(char op) {		//�켱 ������ ��ȯ�ϴ� �Լ�
	switch (op) {		//op�� ���� ���ǹ�
	case '(': case ')':		//��ȣ�� ���
		return 0;		//0��ȯ
	case '+': case '-':		// +- �������� ���
		return 1;		//1��ȯ
	case '*': case '/':		// */ �������� ���
		return 2;		//2��ȯ
	}
	return -1;		//�� ���� ��� -1��ȯ
}

void infix_to_postfix(char exp[], char* inpost) {		//exp�� �߱�ǥ����� ����ǥ������� ��ȯ�� inpost�� �����ϴ� �Լ�
	int i = 0;		//�ݺ�Ƚ���� ��Ÿ���� ����
	int cnt = 0;		//inpost�� �ε����� ��Ÿ���� ����
	char ch, top_op;		//exp�� ���� �����ϴ� ch, ���ÿ� ����� �����ڸ� �����ϴ� top_op
	int len = strlen(exp);		//exp�� ���̸� len�� ��ȯ�Ͽ� ����

	Stack s;		//���� s����
	init_stack(&s);		//���� s�ʱ�ȭ

	for (i = 0; i < len; i++) {		//exp�� ���̸�ŭ �ݺ�
		ch = exp[i];		//exp[i]�� ���� ch�� ����

		switch (ch) {		//ch�� ���� ����ġ ���ǹ�
		case '+': case '-': case '*': case '/':		//�������� ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))		//������ ������� �ʰ�, ���ÿ� ����� ���� �켱������ ch�� �켱�������� ���� ���
				inpost[cnt++] = pop(&s);		//���� s�� ���� �����Ͽ� inpost[cnt]�� ������ ��, cnt�� �� 1����
				//printf("%c", pop(&s));
			push(&s, ch);		//ch�� ���� s�� ����
			break;		//����ġ�� Ż��
		case '(':		//���� ��ȣ�� ���
			push(&s, ch);		//ch�� ���� s�� ����
			break;		//����ġ�� Ż��
		case ')':		//�ݴ� ��ȣ�� ���
			top_op = pop(&s);		//���� s�� ���� ������ top_op�� ����
			while (top_op != '(') {		//���� s���� ���� ��ȣ�� ���� ������ �ݺ�
				inpost[cnt++] = top_op;		//top_op�� ���� inpost[cnt]�� ������ ��, cnt�� �� 1����
				//printf("%c", top_op);
				top_op = pop(&s);		//top_op�� ����s���� ���� ������ ����
			}
			break;		//����ġ�� Ż��
		default:		//�� ���� ���(�ǿ������� ���)
			inpost[cnt++] = ch;		//ch�� ���� inpost[cnt]�� ������ ��, cnt�� �� 1����
			//printf("%c", ch);
			break;		//����ġ�� Ż��
		}
	}
	while (!is_empty(&s)) {		//������ ��� ������ �ݺ�
		inpost[cnt++] = pop(&s);		//���� s�� ���� �����Ͽ� inpost[cnt]�� ������ ��, cnt�� �� 1����
		//printf("%c", pop(&s));
	}
}

int calculate(char exp[]) {		//exp(����ǥ���)�� ����ϴ� �Լ�
	int op1, op2, value, i = 0;		//�ǿ����� op1, op2, �������� �����ϴ� value, �ݺ�Ƚ���� ��Ÿ���� i
	int len = strlen(exp);		//exp�� ���̸� ��ȯ�� len�� ����
	char ch;		//�����ڸ� �����ϴ� ����
	Stack s;		//���� s����

	init_stack(&s);		//���� s �ʱ�ȭ
	for (int i = 0; i < len; i++) {		//exp�� ���̸�ŭ �ݺ�
		ch = exp[i];		//exp[i]�� �� ch�� ����
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {		//�����ڰ� �ƴ� ���
			value = ch - '0';		//���������� ��ȯ�Ͽ�
			push(&s, value);		//���� s�� ����
		}
		else {		//�������� ���
			op2 = pop(&s);		//����s���� �ǿ����ڸ� �ҷ��� ����
			op1 = pop(&s);		//����s���� �ǿ����ڸ� �ҷ��� ����
			switch (ch) {		//ch�� ���� ���ǹ�
			case '+':		// + �������� ���
				push(&s, op1 + op2);		//op1 + op2�� ���� s�� ����
				break;		//����ġ�� Ż��
			case '-':		// - �������� ���
				push(&s, op1 - op2);		//op1 - op2�� ���� s�� ����
				break;		//����ġ�� Ż��
			case '*':		// * �������� ���
				push(&s, op1 * op2);		//op1 * op2�� ���� s�� ����
				break;		//����ġ�� Ż��
			case '/':		// / �������� ���
				push(&s, op1 / op2);		//op1 / op2�� ���� s�� ����
				break;		//����ġ�� Ż��
			}
		}
	}
	return pop(&s);		//����s�� ���� �����Ͽ� ��ȯ
}


int main() {
	FILE* file = NULL;		//���� �ּҸ� �����ϴ� ����
	char array[SIZE] = { 0 };		//����ǥ����� ������ ���ڿ�
	char inpost[SIZE] = { 0 };		//����ǥ����� ������ ���ڿ�

	printf("20194339 ��ο�\n\n");		//���� �ۼ��߽��ϴ�.

	file = fopen("data.txt", "r");		//data.txt�� �б���� �ҷ���
	while (!feof(file)) {		//file�� ������ �ݺ�
		fscanf(file, "%s", array);		//file�� ���ڿ��� array�� ����
		printf("����ǥ����� %s\n", array);		//���ڿ� ���
		printf("����ǥ����� ");		//���ڿ� ���
		infix_to_postfix(array, inpost);		//����ǥ����� ����ǥ������� ��ȯ
		printf("%s", inpost);		//����ǥ��� ���ڿ� ���
		printf("\n");		//���ڿ� ���
		printf("������� %d\n\n", calculate(inpost));		//����ǥ��� ��� �� ���
	}
}