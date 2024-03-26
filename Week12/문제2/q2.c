#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100		//������ �ִ� ũ��

typedef int element;	//int�ڷ����� element��� �̸� �ο�

typedef struct StackNode {		//StackNode����ü ���� �� ����
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {		//������ top�� �Ǵ� LinkedStackType ����ü ���� �� ����
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {		//������ �ʱ�ȭ�ϴ� �Լ�
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {		//������ ����ִ��� Ȯ���ϴ� �Լ�
	return (s->top == NULL);
}

int is_full(LinkedStackType* s) {		//������ ���� á���� Ȯ���ϴ� �Լ�
	return 0;
}

void push(LinkedStackType* s, element item) {		//���� s�� item�� �����ϴ� �Լ�
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	//temp->data�� item�� ������ ��, s->top�� ����Ű�� ���� temp->link�� ����Ű�� �ϰ�, s->top�� temp�� ����Ű�� ��
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType* s) {		//������ ����ϴ� �Լ�
	printf("-- ��� --\n");
	for (StackNode* p = s->top; p != NULL; p = p->link) {		//StackNode�� ������ ���� p�� s->top�� �ּҸ� ������ ��, p�� NULL�� �� ������ �ݺ�
		printf("|(%3d)|\n", p->data);
	}
	printf("-------\n");
}

element pop(LinkedStackType* s) {		//������ ��Ҹ� pop�ϴ� �Լ�
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		//temp->data�� ���� �������� ��, temp �޸� ����
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

element peek(LinkedStackType* s) {		//������ ���� ���κ� ���� Ȯ���ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		fprintf(stderr, "������ ��� �ֽ��ϴ�.\n");		//���ڿ� ���
		return -1;		//-1��ȯ
	}
	else		//������� ���� ���
		return s->top->data;		//������ top�� �� ��ȯ
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

void clear(LinkedStackType* s) {		//������ ���� �Լ�
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	printf("-- Ŭ���� --\n");
	while (s->top != NULL) {		//temp�� s->top�� ����Ű�� �ѵ�, s->top�� link�� �������ְ� temp�� ����Ű�� s->top��ġ �޸� ����
		StackNode* temp = s->top;
		s->top = s->top->link;
		free(temp);
	}
}

void infix_to_postfix(char exp[], char* inpost) {		//exp�� ����ǥ����� ����ǥ������� ��ȯ�� inpost�� �����ϴ� �Լ�
	int i = 0;		//�ݺ�Ƚ���� ��Ÿ���� ����
	int cnt = 0;		//inpost�� �ε����� ��Ÿ���� ����
	char ch, top_op;		//exp�� ���� �����ϴ� ch, ���ÿ� ����� �����ڸ� �����ϴ� top_op
	int len = strlen(exp);		//exp�� ���̸� len�� ��ȯ�Ͽ� ����

	LinkedStackType s;		//����Ʈ���� s����
	init(&s);		//���� s�ʱ�ȭ

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
	LinkedStackType s;		//����Ʈ ���� s����
	init(&s);		//���� s �ʱ�ȭ

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

	printf("20194339 ��ο�\n");

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