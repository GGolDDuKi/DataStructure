#define _CRT_SECURE_NO_WARNINGS		//����½� �߻��ϴ� �������� �����ϰ��� �߰��߽��ϴ�.
#include <stdio.h>		//ǥ�� ������� ����ϴ� ���

typedef struct {		//GradeŸ���� ����ü
	char id[9];		//�й��� ������ id ����
	int korean;		//���� ������ ������ korean ����
	int english;		//���� ������ ������ english ����		// -> Grade ����ü�� ��� ������
	int math;		//���� ������ ������ math ����
	int total;		//������ ������ total ����
	float avg;		//����� ������ avg ����, ������ �������� �Ǽ��� �߻��� �� �ֱ� ������ float������ ��������ϴ�.
}Grade;

int main() {
	FILE* file = NULL;		//������ �ּҸ� ������ FILE������ ����
	Grade student[5];		//5�� �л��� ������ ������ student ����ü�� �迭

	if ((file = fopen("data.txt", "r")) != NULL) {		//file�� ������ �ϴ� ������ �ּ�(�̸�)�� �Ѱ��ְ�, �б� ���� �ҷ��ɴϴ�. ���� �ּҰ� NULL�� ��� else�� �̵�
		for (int i = 0; i < 5; i++) {		//�л��� 5���̹Ƿ� 5�� �ݺ����ִ� �ݺ����� ����߽��ϴ�.
			fscanf(file, "%s\t%d %d %d", student[i].id, &student[i].korean, &student[i].english, &student[i].math);		//fscanf�� ����Ͽ� data.txt�� ����� �й�, ��������, ��������, ���������� student����ü�� ��� �����鿡 �־��ݴϴ�.
			student[i].total = student[i].korean + student[i].english + student[i].math;		//������ ������ �� ������ ������ ���� total��������� �־��ݴϴ�.
			student[i].avg = student[i].total / 3;		//total��������� ���� ���� ���� avg��������� ����� �־��ݴϴ�.
		}
		fclose(file);		//������ �ݾ��ݴϴ�.
	}
	else {
		printf("���� ���� ����\n");
	}

	int kSum = 0, eSum = 0, mSum = 0, tSum = 0;
	float aSum = 0;									//��� �л��� ����, ����, ����, ����, ����� ���� ���� ���� ������ ������ ����ϴ�.
	for (int i = 0; i < 5; i++) {		//�л� �� ��ŭ �ݺ����� ���� �� ���� ���� ���մϴ�
		kSum += student[i].korean;		//kSum������ �� �л��� ���������� �����ݴϴ�.
		eSum += student[i].english;		//eSum������ �� �л��� ���������� �����ݴϴ�.
		mSum += student[i].math;		//mSum������ �� �л��� ���������� �����ݴϴ�.
		tSum += student[i].total;		//tSum������ �� �л��� ������ �����ݴϴ�.
		aSum += student[i].avg;		//aSum������ �� �л��� ����� �����ݴϴ�.
	}

	printf("��===================================================��\n");		//�Էµ� ���ڿ��� ����մϴ�.
	printf("�� ��  �� �� ���� �� ���� �� ���� �� �� �� �� ��  �� ��\n");		//�Էµ� ���ڿ��� ����մϴ�.
	for (int i = 0; i < 5; i++) {		//�л� ��(5) ��ŭ �ݺ����� �����ݴϴ�.
		printf("��%s��  %d  ��  %d  ��  %d  ��  %d  ��  %.2f ��\n", student[i].id, student[i].korean, student[i].english, student[i].math, student[i].total, student[i].avg);
		//�л��� �й�, ��������, ��������, ��������, ����, ����� ����մϴ�.
	}
	printf("��========��======��======��======��=======��========��\n");		//�Էµ� ���ڿ��� ����մϴ�.
	printf("�� ��  �� �� %.2f�� %.2f�� %.2f�� %.2f��  %.2f ��\n", (float)kSum/5, (float)eSum/5, (float)mSum/5, (float)tSum/5, aSum/5);		//�� ���� �� ����� �����ִµ�, aSum�� ������ ������ int���̹Ƿ� float������ ����ȯ�� ���ݴϴ�.
	printf("��===================================================��\n");		//�Էµ� ���ڿ��� ����մϴ�.
}