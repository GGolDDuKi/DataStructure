#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ��� �����ϱ� ���� �߰��߽��ϴ�.
#include <stdio.h>		//ǥ�� ������� ����ϴ� ����Դϴ�.

int StrLength(char * str, int length) {		//���ڿ��� ����(����)�� �Ű������� �޴� �Լ��Դϴ�.
	if (str[length] == NULL)		//length��° �ε����� NULL�� ���(���ڿ��� ������ ���)
			return length;		//length�� ��ȯ�մϴ�.
	else		//�ƴ� ���(���ڿ��� ������ �ʾ��� ���)
		return StrLength(str, ++length);		//length(�ε���, ����)�� 1�� �����ָ� �Ű������޴� �Լ��� ��ȯ�մϴ�.
}
		
int main() {
	int length = 0;		//���ڿ��� ���̸� ������ ������ �����Դϴ�.
	char str[] = "Hello World";		//Hello World�� ������ ���ڿ��Դϴ�.
	printf(str);		//���ڿ��� �������� ����մϴ�.
	printf("\n");
	printf("���ڿ��� ���̴� %d�Դϴ�.", StrLength(str, length));		//���ڿ��� ���̸� ����մϴ�.
}