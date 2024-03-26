#define _CRT_SECURE_NO_WARNINGS		//입출력과 관련된 경고들을 무시해주기 위해 정의했습니다.
#include <stdio.h>		//표준 입출력 관련 헤더를 추가해줬습니다.
#include <time.h>		//time 함수를 사용하기 위해 추가해줬습니다.
#include <stdlib.h>		//srand, rand 함수를 사용하기 위해 추가해줬습니다.

int CountNum(int array[], int n);	//배열 내에서 숫자를 찾아주는 함수를 먼저 선언해줬습니다.

int main() {
	int i = 0, n= 0;		//i는 Data.txt에서 읽어온 데이터를 저장할 array의 인덱스가 될 변수이고, n은 우리가 찾으려는 숫자를 저장할 변수입니다.
	int array[15] = { 0 };		//15개의 정수를 저장할 배열도 만들어 줬습니다.
	FILE* file = NULL;		//읽어올 파일의 주소를 저장할 변수도 만들어 줬습니다.

	if ((file = fopen("Data.txt", "w")) != NULL) {		//file의 주소값이 NULL일 경우 else로 이동
		srand((unsigned int)time(NULL));		//시간에 따른 난수를 발생시킴
		for (int i = 0; i < 15; i++) {		//파일에 15번 난수를 저장해줄 반복문
			fprintf(file, "%d ", rand() % 21);		//난수를 21로 나눈 나머지를 파일에 입력해 0 ~ 20까지의 값을 입력하도록 했습니다.
		}
		fclose(file);		//파일을 닫습니다.
	}
	else {
		printf("파일열기 실패\n");
	}

	if ((file = fopen("Data.txt", "r")) != NULL) {		//file이 가진 주소값이 NULL일 경우 else로 이동합니다.
		while (!feof(file)) {		//feof 함수는 파일 끝에 도달하면 0이 아닌 수를 반환하기 때문에, 파일 끝까지 루프를 돌리기 위하여 사용했습니다.
			fscanf(file, "%d", &array[i]);		//file에서 정수에 해당하는 값을 변수 단위로 가져와 array의 각 인덱스에 넣어줍니다. 작업이 끝난 뒤에 인덱스 값을 하나 올려줍니다.
		}
		fclose(file);		//파일을 닫습니다.
	}
	else {
		printf("파일 열기 실패\n");
	}
	
	printf("찾으실 숫자를 입력하세요 : ");		//""사이에 입력된 문자열을 출력해줍니다.
	scanf("%d", &n);		//만들어 뒀던 n에 입력한 값을 넣어줍니다.
	printf("입력한 %d는 %d개 있습니다.", n, CountNum(array, n));		//""사이에 입력된 문자열을 출력해줍니다.
}

int CountNum(int array[], int n) {		//위에서 선언한 함수의 정의입니다. 
	int result = 0;		//반환할 값을 저장할 변수 result 입니다.
	for (int i = 0; i < 15; i++) {		//15번 반복해줄 반복문을 만들고
		if (array[i] == n)		//우리가 찾을 값 n과 array의 i번째 인덱스의 값이 같다면,
			result++;		//result를 하나 올려줍니다.
	}
	return result;		//마지막으로 result를 반환해줍니다.
}