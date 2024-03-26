#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 경고를 무시하기 위해 추가했습니다.
#include <stdio.h>		//표준 입출력을 담당하는 헤더입니다.

int StrLength(char * str, int length) {		//문자열과 정수(길이)를 매개변수로 받는 함수입니다.
	if (str[length] == NULL)		//length번째 인덱스가 NULL일 경우(문자열이 끝났을 경우)
			return length;		//length를 반환합니다.
	else		//아닐 경우(문자열이 끝나지 않았을 경우)
		return StrLength(str, ++length);		//length(인덱스, 길이)에 1을 더해주며 매개변수받는 함수를 반환합니다.
}
		
int main() {
	int length = 0;		//문자열의 길이를 저장할 정수형 변수입니다.
	char str[] = "Hello World";		//Hello World를 가지는 문자열입니다.
	printf(str);		//문자열이 무엇인지 출력합니다.
	printf("\n");
	printf("문자열의 길이는 %d입니다.", StrLength(str, length));		//문자열의 길이를 출력합니다.
}