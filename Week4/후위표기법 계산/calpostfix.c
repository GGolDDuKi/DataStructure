#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100		//������ �ִ� ũ��

typedef int element;		//int�ڷ����� element��� ���� �ο�

typedef struct {		//���� ����ü
	element data[SIZE];		//element�� data�� SIZE��ŭ �����ϴ� ���ð���
	int top;		//������ ���� ���κ��� ����Ű�� ����
}Stack;

void init_stack(Stack* s) {		//������ �ʱ�ȭ�ϴ� �Լ�
	s->top = -1;
}

int is_empty(Stack* s) {		//������ ����ִ��� Ȯ���ϴ� �Լ�
	return (s->top == -1);		//������� ��� 1��ȯ
}

int is_full(Stack* s) {		//������ �������� Ȯ���ϴ� �Լ�
	return (s->top == (SIZE - 1));		//������ ��� 1��ȯ
}

void push(Stack* s, element n) {		//����s�� n�� �����ϴ� �Լ�
	if (is_full(s)) {		//������ ������ ���
		printf("������ ���� á���ϴ�.\n");
		return;		//�Լ�����
	}
	else		//������ �������� ���� ���
		s->data[++(s->top)] = n;		//data[top+1]�� n�� ������ ��, top�� �� 1����
}

element pop(Stack* s) {		//����s�� ���� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");		
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->data[(s->top)--];		//data[top]�� ���� ��ȯ�� ��, top�� �� 1����
}

element peek(Stack* s) {		//������ ���� �����ִ� ���� Ȯ���ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		fprintf(stderr, "������ ��� �ֽ��ϴ�.\n");
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->data[s->top];		//data[top]�� �� ��ȯ
}

int calculate(char exp[]) {		//exp���ڿ��� ����ǥ����� ����ϴ� �Լ�
	int op1, op2, value, i = 0;		//�ǿ����ڸ� �����ϴ� op1, op2, ������� ������ value, �ݺ����� Ƚ���� ������ i
	int len = strlen(exp);		//exp�� ���̸� len�� ��ȯ
	char ch;		//�����ڸ� ������ ����
	Stack s;		//���� s����

	init_stack(&s);		//���� s�ʱ�ȭ
	for (i = 0; i < len; i++) {		//exp�� ���̸�ŭ �ݺ�
		ch = exp[i];		//exp[i]�� ���� ch�� ����
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {		//ch�� �����ڰ� �ƴ� ���
			value = ch - '0';		//ch�� ���� ���������� ��ȯ�� value�� ����
			push(&s, value);		//value�� ���� ����s�� ����
		}
		else {		//ch�� �������� ���
			op2 = pop(&s);		//����s�� ���� ������ op2�� ����
			op1 = pop(&s);		//����s�� ���� ������ op1�� ����
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
	return pop(&s);		//���� s�� �� �����Ͽ� ��ȯ
}


int main() {
	FILE* file = NULL;		//�����ּҸ� ������ ����
	char array[SIZE] = { 0 };		//���Ͽ��� �ҷ��� ���ڿ��� ������ �迭

	printf("20194339 ��ο�\n\n");		//���� �ۼ��߽��ϴ�.

	file = fopen("data.txt", "r");		//data.txt�� �ּҸ� �б���� �ҷ���
	while (!feof(file)) {		//file�� ������ �ݺ�
		fscanf(file, "%s", array);		//file�� ���ڿ��� array�� ����
		printf("����ǥ����� %s", array);		//���ڿ� ���
		printf("\n");
		printf("������� %d\n\n", calculate(array));		//��� ���
	}
}