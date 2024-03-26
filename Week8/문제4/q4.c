#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;	//int�ڷ����� element��� �̸� �ο�

typedef struct ListNode {		//ListNode����ü ���� �� ����
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {		//����Ʈ�� ù ��° ��ġ�� ��Ҹ� �߰��ϴ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//��Ҹ� �߰��ϱ� ���� ListNode������ ���� p ����
	if (p == NULL) {		//�����Ҵ��� ����� �Ǿ����� �˻�
		printf("�޸𸮰� ���������� �Ҵ���� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	p->data = value;	//p�� ���ϴ� ���� �ְ�
	p->link = head;		//���� head�� �ּҰ��� �Ѱ��� ��,
	head = p;		//head�� p�� ����Ű���� �����
	return head;		//head�� ��ȯ
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {		//����Ʈ pre�ڿ� ���ο� ����Ʈ�� �����ϴ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//��Ҹ� �߰��ϱ� ���� ListNode������ ���� p ����
	if (p == NULL) {		//�����Ҵ��� ����� �Ǿ����� �˻�
		printf("�޸𸮰� ���������� �Ҵ���� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	p->data = value;		//p�� ���ϴ� ���� �ְ�
	p->link = pre->link;		//pre�� ������ ����Ű�� �ּҸ� p�� ����Ű���� �� ��
	pre->link = p;		//pre�� p�� ����Ű���� �����
	return head;		//head�� ��ȯ
}

ListNode* insert_last(ListNode* head, element value) {		//����� �������� ��带 �����ϴ� �Լ�	
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//������ ��Ҹ� ������ ������ p ����
	if (p == NULL) {		//�޸𸮰� ����� �Ҵ� �Ǿ����� Ȯ��
		printf("�޸𸮰� ���������� �Ҵ���� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	p->data = value;	//p->data�� �������� ���� ����
	p->link = NULL;		//p->link�� NULL�� ����Ű���� ��(�������� ���� ����)
	if (head == NULL) {		//head�� NULL�̶��(��Ұ� ���ٸ�)
		head = p;		//head�� p�� �ּҸ� ����Ű�� ��
	}
	else {		//head�� NULL�� �ƴ϶��
		ListNode* last = head;		//������ ����� �ּҸ� ����ų ������ last�� ������ ��, head�� �ּҸ� �Ҵ�
		while (last->link != NULL)		//����� ������ ��ұ��� ã�ư�(NULL�� ����Ű�� ������)
			last = last->link;
		last->link = p;		//������ ��Ұ� p�� ����Ű�� ����
	}
	return head;		//head�� ��ȯ
}

ListNode* delete_first(ListNode* head) {		//ù ��° ��带 �����ϴ� �Լ�
	ListNode* removed;		//������ ����� ��� ����
	if (head == NULL) return NULL;		//��尡 ����Ű�� ���� ���� ��� NULL ��ȯ
	removed = head;		//removed�� head�� ���� �ּҸ� ����Ű�� �����
	head = removed->link;		//head�� removed�� ����Ű�� ���� ����� �ּҸ� ����
	free(removed);		//�Ҵ�޾Ҵ� �޸� ��ȯ
	return head;		//head��ȯ
}

ListNode* delete(ListNode* head, ListNode* pre) {		//pre�� ����Ű�� ����� ���� ��带 �����ϴ� �Լ�
	ListNode* removed;		//������ ����� ��� ����
	removed = pre->link;		//removed�� pre�� ����Ű�� ���� �ּҸ� �� ��
	pre->link = removed->link;		//pre�� ����Ű�� ���� �ּҸ� removed�� ����Ű�� ���� ����� �ּ�(pre�� ���� ���� �ּ�)�� ����
	free(removed);		//removed���(pre�� ���� ���� ���)�� �Ҵ� ����
	return head;		//head��ȯ
}

void print_list(ListNode* head) {		//���� ��带 ��� ���
	for (ListNode* p = head; p != NULL; p = p->link)		//��尡 NULL�� ����ų �� ���� ���
		printf("%d->", p->data);
	printf("NULL\n");		//�������� NULL�� ���
}

int list_length(ListNode* head) {		//����� ������ ���ϴ� �Լ�
	int length = 0;
	for (ListNode* p = head; p != NULL; p = p->link)		//��尡 NULL�� ����ų �� ���� length����
		length++;
	return length;		//����� ����(length)�� ��ȯ
}

int list_sum(ListNode* head) {		//����� �������� ������ ���ϴ� �Լ�
	int result = 0;
	for (ListNode* p = head; p != NULL; p = p->link)		//��尡 NULL�� ����ų �� ���� result�� p->data�� ����
		result = result + p->data;
	return result;		//����� �������� ���� ��ȯ
}

int list_find(ListNode* head, element value) {		//��忡 value�� � �ִ��� ã�� �Լ�
	int cnt = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {		//��尡 NULL�� ����ų �� ���� p->data�� ���� value�� ������ cnt++
		if (p->data == value)
			cnt++;
	}		
	return cnt;
}

int main() {
	ListNode* head = NULL;		//����� ������ �� head ����
	int size = 0;		//����� ������ ������ size����
	int value = 0;		//�Է¹��� ��� ���� ������ value����
	int find = 0;

	printf("����� ���� : ");
	scanf("%d", &size);

	for (int i = 1; i <= size; i++) {		//�Է¹��� ����� ������ŭ �ݺ�
		printf("��� #%d ������: ", i);
		scanf("%d", &value);
		head = insert_last(head, value);		//�Է¹��� ���� ������ ��ҿ� ����
	}

	printf("Ž���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &find);
	printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�.", find, list_find(head, find));		//��忡 find�� �� ������ ���

	return 0;
}