#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Add_Matrix(int** A, int** B, int** C, int row, int col) {      //행렬의 덧셈을 수행하는 함수
    int i, j = 0;
    for (i = 0; i < row; i++) {     //행렬의 행만큼 반복
        for (j = 0; j < col; j++) {     //행렬의 열만큼 반복
            C[i][j] = A[i][j] + B[i][j];
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

void Sub_Matrix(int** A, int** B, int** C, int row, int col) {      //행렬의 뺄셈을 수행하는 함수
    int i, j = 0;   
    for (i = 0; i < row; i++) {     //행렬의 행만큼 반복
        for (j = 0; j < col; j++) {     //행렬의 열만큼 반복
            C[i][j] = A[i][j] - B[i][j];
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

void Mul_Matrix(int** A, int** B, int** C, int row1, int col1, int row2, int col2) {    //행렬의 곱셈을 수행하는 함수
    int i, j, k = 0;        
    for (i = 0; i < row1; i++) {        //첫행렬의 행만큼 반복
        for (j = 0; j < col2; j++) {        //두번째 행렬의 열만큼 반복
            C[i][j] = 0;
            for (k = 0; k < col1; k++) {        //첫번째 행렬의 열만큼 반복
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //결과를 출력
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE* file;     //파일의 주소를 저장할 포인터변수
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;     //각 행렬의 행과 열의 수를 저장할 변수   
    int** Matrix1 = { 0 };      //첫번째 행렬을 저장할 2차원 배열
    int** Matrix2 = { 0 };      //두번째 행렬을 저장할 2차원 배열
    int** Matrix3 = { 0 };      //두 행렬의 연산 결과를 저장할 2차원 배열

    file = fopen("data02.txt", "r");        //data02.txt의 내용을 읽기모드로 불러옴

    if (file == NULL) {     //파일을 불러오지 못하면 종료
        printf("파일을 불러오지 못했습니다.\n");
        return 0;
    }

    while (!feof(file)) {       //파일의 끝까지 반복
        fscanf(file, "%d %d", &row1, &col1);        //첫번째 행렬의 행과 열을 저장
        Matrix1 = (int **)malloc(sizeof(int*) * row1);      //배열을 저장할 2차원 배열을 동적할당
        for (int i = 0; i < row1; i++) {        //2차원 배열의 각 원소에 1차원 배열 할당
            Matrix1[i] = (int*)malloc(sizeof(int) * col1);
        }
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                fscanf(file, "%d ", &Matrix1[i][j]);        //할당한 2차원 배열에 원소 저장
            }
        }

        fscanf(file, "%d %d", &row2, &col2);        //두번째 행렬의 행과 열을 저장
        Matrix2 = (int**)malloc(sizeof(int*) * row2);       //배열을 저장할 2차원 배열을 동적할당
        for (int i = 0; i < row2; i++) {        //2차원 배열의 각 원소에 1차원 배열 할당
            Matrix2[i] = (int*)malloc(sizeof(int) * col2);
        }
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                fscanf(file, "%d ", &Matrix2[i][j]);        //할당한 2차원 배열에 원소 저장
            }
        }
    }
    Matrix3 = (int**)malloc(sizeof(int*) * row1);     //배열을 저장할 2차원 배열을 동적할당
    for (int i = 0; i < row1; i++) {        //2차원 배열의 각 원소에 1차원 배열 할당
        Matrix3[i] = (int*)malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            Matrix3[i][j] = 0;      //할당한 2차원 배열 초기화
        }
    }

    Add_Matrix(Matrix1, Matrix2, Matrix3, row1, col1);      //행렬의 덧셈 수행
    printf("\n\n");
    Sub_Matrix(Matrix1, Matrix2, Matrix3, row1, col1);      //행렬의 뺄셈 수행
    printf("\n\n");
    Mul_Matrix(Matrix1, Matrix2, Matrix3, row1, col1, row2, col2);      //행렬의 곱셈 수행

    for (int i = 0; i < row1; i++) {        //동적할당 해제
        free(Matrix1[i]);
        free(Matrix2[i]);
        free(Matrix3[i]);
    }
    free(Matrix1);
    free(Matrix2);
    free(Matrix3);

    return 0;
}