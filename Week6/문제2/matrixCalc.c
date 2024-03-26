#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Add_Matrix(int** A, int** B, int** C, int row, int col) {      //����� ������ �����ϴ� �Լ�
    int i, j = 0;
    for (i = 0; i < row; i++) {     //����� �ุŭ �ݺ�
        for (j = 0; j < col; j++) {     //����� ����ŭ �ݺ�
            C[i][j] = A[i][j] + B[i][j];
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

void Sub_Matrix(int** A, int** B, int** C, int row, int col) {      //����� ������ �����ϴ� �Լ�
    int i, j = 0;   
    for (i = 0; i < row; i++) {     //����� �ุŭ �ݺ�
        for (j = 0; j < col; j++) {     //����� ����ŭ �ݺ�
            C[i][j] = A[i][j] - B[i][j];
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

void Mul_Matrix(int** A, int** B, int** C, int row1, int col1, int row2, int col2) {    //����� ������ �����ϴ� �Լ�
    int i, j, k = 0;        
    for (i = 0; i < row1; i++) {        //ù����� �ุŭ �ݺ�
        for (j = 0; j < col2; j++) {        //�ι�° ����� ����ŭ �ݺ�
            C[i][j] = 0;
            for (k = 0; k < col1; k++) {        //ù��° ����� ����ŭ �ݺ�
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //����� ���
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE* file;     //������ �ּҸ� ������ �����ͺ���
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;     //�� ����� ��� ���� ���� ������ ����   
    int** Matrix1 = { 0 };      //ù��° ����� ������ 2���� �迭
    int** Matrix2 = { 0 };      //�ι�° ����� ������ 2���� �迭
    int** Matrix3 = { 0 };      //�� ����� ���� ����� ������ 2���� �迭

    file = fopen("data02.txt", "r");        //data02.txt�� ������ �б���� �ҷ���

    if (file == NULL) {     //������ �ҷ����� ���ϸ� ����
        printf("������ �ҷ����� ���߽��ϴ�.\n");
        return 0;
    }

    while (!feof(file)) {       //������ ������ �ݺ�
        fscanf(file, "%d %d", &row1, &col1);        //ù��° ����� ��� ���� ����
        Matrix1 = (int **)malloc(sizeof(int*) * row1);      //�迭�� ������ 2���� �迭�� �����Ҵ�
        for (int i = 0; i < row1; i++) {        //2���� �迭�� �� ���ҿ� 1���� �迭 �Ҵ�
            Matrix1[i] = (int*)malloc(sizeof(int) * col1);
        }
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                fscanf(file, "%d ", &Matrix1[i][j]);        //�Ҵ��� 2���� �迭�� ���� ����
            }
        }

        fscanf(file, "%d %d", &row2, &col2);        //�ι�° ����� ��� ���� ����
        Matrix2 = (int**)malloc(sizeof(int*) * row2);       //�迭�� ������ 2���� �迭�� �����Ҵ�
        for (int i = 0; i < row2; i++) {        //2���� �迭�� �� ���ҿ� 1���� �迭 �Ҵ�
            Matrix2[i] = (int*)malloc(sizeof(int) * col2);
        }
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                fscanf(file, "%d ", &Matrix2[i][j]);        //�Ҵ��� 2���� �迭�� ���� ����
            }
        }
    }
    Matrix3 = (int**)malloc(sizeof(int*) * row1);     //�迭�� ������ 2���� �迭�� �����Ҵ�
    for (int i = 0; i < row1; i++) {        //2���� �迭�� �� ���ҿ� 1���� �迭 �Ҵ�
        Matrix3[i] = (int*)malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            Matrix3[i][j] = 0;      //�Ҵ��� 2���� �迭 �ʱ�ȭ
        }
    }

    Add_Matrix(Matrix1, Matrix2, Matrix3, row1, col1);      //����� ���� ����
    printf("\n\n");
    Sub_Matrix(Matrix1, Matrix2, Matrix3, row1, col1);      //����� ���� ����
    printf("\n\n");
    Mul_Matrix(Matrix1, Matrix2, Matrix3, row1, col1, row2, col2);      //����� ���� ����

    for (int i = 0; i < row1; i++) {        //�����Ҵ� ����
        free(Matrix1[i]);
        free(Matrix2[i]);
        free(Matrix3[i]);
    }
    free(Matrix1);
    free(Matrix2);
    free(Matrix3);

    return 0;
}