#define _CRT_SECURE_NO_WARNINGS		//����� �� �߻��ϴ� ��� �����ϱ� ���� �߰�������ϴ�.
#include <stdio.h>		//ǥ�� ������� ����ϴ� ����Դϴ�.

void StrPrint(char str[], int index) {		//���ڿ��� ����ϴ� �Լ��Դϴ�.
	if (str[index] == NULL) {		//str�� [index]��° ���ڰ� NULL�� ���
		return;		//�Լ��� �����մϴ�.
	}
	else {		//�ƴ� ���
		printf("%c", str[index]);		//index��° ���Ҹ� ����մϴ�.
		return StrPrint(str, ++index);		//index�� �ϳ� �߰��ϰ� �Ű������� �Ѱ� �Լ��� ��ȯ�մϴ�.
	}
}

void ReversePrint(char str[], int maxIndex) {		//���ڿ��� ������ϴ� �Լ��Դϴ�.
	if (maxIndex < 0) {		//index���� 0�̸��� ���
		return;		//�Լ��� �����մϴ�.
	}
	else {		//�ƴ� ���(0���� ������ ���)
		printf("%c", str[maxIndex--]);		//maxIndex��° ���ڸ� ����� ��, maxIndex�� 1 ���� ��ŵ�ϴ�.
		return ReversePrint(str, maxIndex);		//���ҵ� maxIndex�� �Ű������� �ѱ�� �Լ��� ��ȯ�մϴ�.
	}
}

int main() {
	int index = 0;		//���ڿ��� ����� ��, �ε����� ����� �����Դϴ�.
	int maxIndex = 0;		//���ڿ� ����¿���, �ε����� ����� �����Դϴ�.
	char str[] = "Hello World";		//���, ������� ���ڿ��Դϴ�.

	while (str[maxIndex] != NULL) {		//����� �� ���ڿ��� ������ ó���� ���ؾ� �ϱ� ������ ���ڿ� ���̸� �ε����� �������־����ϴ�.
		maxIndex += 1;
	}

	StrPrint(str, index);		//���ڿ��� ����մϴ�.
	printf("\n");
	ReversePrint(str, maxIndex);		//���ڿ��� ������մϴ�.
}