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

void delete_pre(ListNode* pre) {		//pre�� ����Ű�� ����� ���� ��带 �����ϴ� �Լ�
	ListNode* removed;		//������ ����� ��� ����
	removed = pre->link;		//removed�� pre�� ����Ű�� ���� �ּҸ� �� ��
	pre->link = removed->link;		//pre�� ����Ű�� ���� �ּҸ� removed�� ����Ű�� ���� ����� �ּ�(pre�� ���� ���� �ּ�)�� ����
	free(removed);		//removed���(pre�� ���� ���� ���)�� �Ҵ� ����
}

void print_list(ListNode* head) {		//���� ��带 ��� ���
	printf("( ");
	for (ListNode* p = head; p != NULL; p = p->link)		//��尡 NULL�� ����ų �� ���� ���
		printf("%d ", p->data);
	printf(")\n");		//�������� NULL�� ���
}

void count_num(ListNode* head) {		//�Է¹��� ���� ���Ḯ��Ʈ ���� �� �� �ִ��� ����ϴ� �Լ�
	int value = 1;		//�Է¹��� ���� ������ ����
	int cnt = 0;		//������ �� ����

	while (value != 0) {		//0�� �Է¹ޱ� ������ �ݺ�
		printf("���� �Է��ϼ���(0 : ����) : ");
		scanf("%d", &value);

		for (ListNode* p = head; p != NULL; p = p->link) {		//���Ḯ��Ʈ ������ �ݺ�
			if (p->data == value)
				cnt++;
		}
		if (value != 0) {		//0�� �Է��ϸ� ���α׷� ����
			printf("%d�� ����Ʈ�� %d�� �ֽ��ϴ�.\n", value, cnt);
			cnt = 0;
		}
	}
}

ListNode* delete_even(ListNode* head) {		//���Ḯ��Ʈ�� ¦�� �ε����� �����ϴ� �Լ�
	head = delete_first(head);		//0��° �ε��� ����
	for (ListNode* p = head; p != NULL; p = p->link) {		//¦�� �ε��� ����
		delete_pre(p);
	}
	return head;		//head��ȯ
}

void find_maxmin(ListNode* head) {		//���Ḯ��Ʈ���� �ִ밪, �ּҰ��� ã�� ����ϴ� �Լ�
	int max = head->data;		//�ִ밪�� ������ ����, head->data�� �ʱ�ȭ
	int min = head->data;		//�ּҰ��� ������ ����, head->data�� �ʱ�ȭ
	for (ListNode* p = head; p != NULL; p = p->link) {		//���Ḯ��Ʈ ������ ���� �����Ͽ� ���ǿ� ���� ��� ������ ����
		if (p->data >= max)
			max = p->data;
		if (p->data <= min)
			min = p->data;
	}
	printf("�ִ밪�� %d\n", max);		//�ִ�, �ּҰ� ���
	printf("�ּҰ��� %d", min);
}

int main() {
	ListNode* head = NULL;		//����� ������ �� head ����
	FILE* file = NULL;
	int value = 0;

	file = fopen("data.txt", "r");

	while (!feof(file)) {		//data.txt���� ��� �����͸� �о�� �� ���� �ݺ�
		fscanf(file, "%d", &value);
		head = insert_last(head, value);		//�ҷ��� ���� ���Ḯ��Ʈ�� ���� �߰�
	}

	print_list(head);		//����1 ���Ḯ��Ʈ ���
	//count_num(head);		//����2 �Է��� ���� ���� Ȯ��
	//head = delete_even(head);		//����3 ¦�� �ε��� ����
	//print_list(head);			//����3
	//find_maxmin(head);		//����4 ���Ḯ��Ʈ �ִ밪 �ּҰ� ���
}