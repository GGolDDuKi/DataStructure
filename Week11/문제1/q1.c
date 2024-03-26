#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;	//int�ڷ����� element��� �̸� �ο�

typedef struct ListNode {		//ListNode����ü ���� �� ����
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {		//����Ʈ�� ù ��° ��ġ�� ��Ҹ� �߰��ϴ� �Լ�
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//��Ҹ� �߰��ϱ� ���� ListNode������ ���� node ����
	if (node == NULL) {		//�����Ҵ��� ����� �Ǿ����� �˻�
		printf("�޸𸮰� ���������� �Ҵ���� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	node->data = data;		//���� ���� ��忡 data����
	if (head == NULL) {		//����Ʈ�� ������� ���
		head = node;		//head�� node�� ��
		node->link = head;		//head�� link�� ������ ����Ű���� ��
	}
	else	//����Ʈ�� ������� ���� ���
	{
		node->link = head->link;		//head�� link�� �⸮Ű�� ���� node�� link�� ����Ŵ
		head->link = node;		//head�� link�� node�� ����Ŵ
	}
	return head;		//head ��ȯ
}

ListNode* insert_last(ListNode* head, element data) {		//����� �������� ��带 �����ϴ� �Լ�	
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));		//������ ��Ҹ� ������ ������ node ����
	if (node == NULL) {		//�޸𸮰� ����� �Ҵ� �Ǿ����� Ȯ��
		printf("�޸𸮰� ���������� �Ҵ���� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	node->data = data;		//node�� data�� data ����
	if (head == NULL) {		//����Ʈ�� ������� ���
		head = node;		//head�� node�� ��
		node->link = head;		//head�� link�� ������ ����Ŵ
	}
	else {		//����Ʈ�� ������� ���� ���
		node->link = head->link;		//node�� link�� head�� link�� ����Ŵ
		head->link = node;		//head�� link�� node�� ����Ŵ
		head = node;		//head�� node�� ��
	}
	return head;		//head ��ȯ
}

void print_list(ListNode* head) {		//���� ��带 ��� ���
	ListNode* p;		//head���Լ� �ּҸ� �Ѱܹ��� ������

	if (head == NULL) return;		//����Ʈ�� ������� ��� ����
	p = head->link;		//p�� head�� link�� ����Ű�� ���� ����Ŵ
	do {		//�� ���� ����
		printf("%d->", p->data);		//p->data ���
		p = p->link;		//p�� link�� ����Ŵ
	} while (p != head->link);		//p�� head->link�� �� ���� �ݺ�
}

int main() {
	ListNode* head = NULL;		//ListNode�� ������ head ����

	head = insert_last(head, 20);		//����Ʈ�� �������� 20����
	head = insert_last(head, 30);		//����Ʈ�� �������� 30����
	head = insert_last(head, 40);		//����Ʈ�� �������� 40����
	head = insert_first(head, 10);		//����Ʈ�� ó���� 10����
	print_list(head);		//����Ʈ ���
	return 0;
}