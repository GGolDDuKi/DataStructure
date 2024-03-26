#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;	//int�ڷ����� element��� �̸� �ο�

typedef struct DListNode {		//DListNode����ü ���� �� ����
	element data;
	struct DListNode* llink;		//������ link�� �ּҸ� ������ �����ͺ���
	struct DListNode* rlink;		//���� link�� �ּҸ� ������ �����ͺ���
}DListNode;

void init(DListNode* head) {		//����Ʈ �ʱ�ȭ
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element data) {		//before�� �����ʿ� ��� ����
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));		//���Ӱ� �߰��� ��� �����Ҵ�
	newnode->data = data;		//���ο� ��忡 data����
	newnode->llink = before;		//���ο� ����� ���� link�� before�� ����Ű�� ��
	newnode->rlink = before->rlink;		//���ο� ����� ������ link�� before�� ������link�� ����Ű�� ��
	before->rlink->llink = newnode;		//before�� �����ʿ� �ִ� ����Ʈ�� ���� link�� ���ο� ��带 ����Ű�� ��
	before->rlink = newnode;		//before�� ������ link�� ���ο� ��带 ����Ű�� ��
}

void ddelete(DListNode* head, DListNode* removed) {		//����Ʈ��带 �����ϴ� �Լ�
	if (removed == head) return;		//����Ʈ�� ������� ��� ����
	removed->llink->rlink = removed->rlink;		//removed�� ���� ����Ʈ�� ������ link�� removed�� ������ link�� ����� �ּҸ� ����
	removed->rlink->llink = removed->llink;		//removed�� ������ ����Ʈ�� ���� link�� removed�� ���� link�� ����� �ּҸ� ����
	free(removed);		//removed �޸� ����
}

void print_dlist(DListNode* head) {		//����Ʈ�� ����ϴ� �Լ�
	DListNode* p;		//DListNode�� �ּҸ� ������ �����ͺ��� ����
	for (p = head->rlink; p != head; p = p->rlink) {		//p�� head�� �Ǳ� ������ �ݺ�
		printf("<-| |%d| |-> ", p->data);		//p->data ���
	}
	printf("\n");		//����
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));		//����Ʈ�� ������ �Ǵ� head������ ���� ����
	init(head);		//head �ʱ�ȭ
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5; i++) {		//0���� 4���� ����Ʈ�� �����ϴ� ������ ���
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {		//0���� 4���� ����Ʈ���� �����ϴ� ������ ���
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);		//head�޸� ����
	return 0;
}