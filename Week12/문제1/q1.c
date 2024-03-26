#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int main() {
	LinkedStackType s;
	init(&s);
	
	//���ÿ� ��� ����
	push(&s, 15);
	push(&s, 62);
	push(&s, 35);
	push(&s, 52);
	push(&s, 37);
	push(&s, 55);
	
	//������ ���� ���
	print_stack(&s);
	printf("\n\n");
	
	clear(&s);
	printf("\n");
	print_stack(&s);

}