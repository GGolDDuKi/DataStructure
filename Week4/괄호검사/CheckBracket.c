#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100		//������ �ִ� ũ��

typedef char element;		//char���� element��� ���� �ο� -> ������ �ڷ����� �ٲ� �ڵ� ������ ���� �� �����ϴ�.

typedef struct {
	element data[SIZE];		//SIZEũ���� element�� ���� ����
	int top;		//������ ���� �� �κ�
}Stack;		//���� ����ü

void init_stack(Stack* s){		//���� �ʱ�ȭ
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
		s->data[++(s->top)] = n;		//data[top+1]�� n�� ����
}

element pop(Stack* s) {		//���ÿ��� �����͸� �����ϴ� �Լ�
	if (is_empty(s)) {		//������ ������� ���
		printf("������ ��� �ֽ��ϴ�.\n");		
		return -1;		//-1 ��ȯ
	}
	else
	{
			//������� ���� ���
	}
		return s->data[(s->top)--];		//data[top]�� ���� ��ȯ�� ��, top�� ���� 1 ����
}



int checkBracket(char* array) {		//��ȣ�� �˻��ϴ� �Լ�
	Stack s;		//���� ����
	char ch, open_ch;		//array�� ���� ���� ������ ch, ���ÿ��� ���� ���� ������ open_ch
	int length = strlen(array);		//array�� ���̸� ���� length�� ����
	init_stack(&s);		//���� s�� �ʱ�ȭ

	for (int i = 0; i < length; i++) {		//array�� ���� ��ŭ �ݺ�
		ch = array[i];		//ch�� array[i] ���� ����

		switch (ch) {		//ch�� ��쿡 ���� ����ġ��
		case '(': case '[':case '{':		//ch�� ���� ��ȣ�� ���
			push(&s, ch);		//ch�� ���� s�� ����
			break;		//����ġ�� Ż��

		case ')': case ']': case '}':		//ch�� �ݴ� ��ȣ�� ���
			if (is_empty(&s)) return 0;		//���� s�� ����ִٸ� 0��ȯ
			else {		//���� s�� ������� �ʴٸ�
				open_ch = pop(&s);		//open_ch�� ���ÿ��� ������ �� ����
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {		//open_ch(���� ��ȣ)�� ch(�ݴ� ��ȣ)�� ��ġ���� ���� �ʴ� ���
					return 0;		//0��ȯ
				}
				break;		//����ġ�� Ż��
			}
		}
	}
	if (!is_empty(&s)) return 0;		//��ȣ �˻簡 �����µ� ������ ������� ���� ���(��ȣ�� ������ ���) 0 ��ȯ
	return 1;		//1 ��ȯ
}

int main() {
	FILE* file = NULL;		//���� �ּҸ� ������ file���� ����
	char array[SIZE] = { 0 };				//���Ͽ��� �ҷ��� ���ڿ��� ������ char�� �迭 ����

	printf("20194339 ��ο�\n\n");		//���� �ۼ��߽��ϴ�

	file = fopen("data.txt", "r");		//file�� data.txt�� �ּҸ� �б���� �ҷ���
	while (!feof(file)) {		//file�� ������ �ݺ�
		fscanf(file, "%s", array);		//file���� ���ڿ��� �о� array�� ����
		if (checkBracket(array) == 1) {		//��ȣ �˻翡 ������ ���
			printf("��ȣ�˻缺�� : ");		//���ڿ� ���
		}
		else printf("��ȣ�˻���� : ");		//��ȣ �˻翡 ������ ���
		printf("%s\n", array);		//���ڿ� ���
	}
}