#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ��� �����ϱ� ���� �߰��մϴ�.
#include <stdio.h>		//ǥ�� ������� ����ϴ� ����Դϴ�.

int BS(int data[],int index, int n) {		//�����Ͱ� ����ִ� data�迭, Ž���ϴ� �ε����� ��Ÿ���� index, ã�� �� n�� �Ű������� �޽��ϴ�.
	if (data[index] == n)		//index��° data�� ã�� n�� ���
		return index;		//index�� ��ȯ�մϴ�.
	else		//�ƴ� ���
		return BS(data, ++index, n);		//index�� �ϳ� ������Ű�� �Ű������� �Ѱ� �Լ��� ��ȯ�մϴ�.
}

int main() {
	int index = 0;		//Ž�� ���� �ε����� ��Ÿ�� ����
	int n = 0;		//ã�� ���� ������ ����
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };		//�����Ͱ� ����� �迭

	printf("ã�� ���ڸ� �Է��ϼ��� : ");		//���ڿ��� ����մϴ�.
	scanf("%d", &n);		//����ڿ��� �Է��� �޾� n�� �����մϴ�.
	printf("ã�� ���ڴ� %d ��°�� �ֽ��ϴ�.", BS(data, index, n) + 1);		//���ڿ��� ����մϴ�.
}