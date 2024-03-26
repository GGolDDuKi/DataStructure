#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 경고를 무시하기 위해 추가해줬습니다.
#include <stdio.h>		//표준 입출력을 담당하는 헤더입니다.

void StrPrint(char str[], int index) {		//문자열을 출력하는 함수입니다.
	if (str[index] == NULL) {		//str의 [index]번째 문자가 NULL일 경우
		return;		//함수를 종료합니다.
	}
	else {		//아닐 경우
		printf("%c", str[index]);		//index번째 원소를 출력합니다.
		return StrPrint(str, ++index);		//index를 하나 추가하고 매개변수로 넘겨 함수를 반환합니다.
	}
}

void ReversePrint(char str[], int maxIndex) {		//문자열을 역출력하는 함수입니다.
	if (maxIndex < 0) {		//index값이 0미만일 경우
		return;		//함수를 종료합니다.
	}
	else {		//아닐 경우(0보다 이하일 경우)
		printf("%c", str[maxIndex--]);		//maxIndex번째 문자를 출력한 뒤, maxIndex를 1 감소 시킵니다.
		return ReversePrint(str, maxIndex);		//감소된 maxIndex를 매개변수로 넘기며 함수를 반환합니다.
	}
}

int main() {
	int index = 0;		//문자열을 출력할 때, 인덱스로 사용할 변수입니다.
	int maxIndex = 0;		//문자열 역출력에서, 인덱스로 사용할 변수입니다.
	char str[] = "Hello World";		//출력, 역출력할 문자열입니다.

	while (str[maxIndex] != NULL) {		//역출력 시 문자열의 끝에서 처음을 향해야 하기 때문에 문자열 길이를 인덱스로 설정해주었습니다.
		maxIndex += 1;
	}

	StrPrint(str, index);		//문자열을 출력합니다.
	printf("\n");
	ReversePrint(str, maxIndex);		//문자열을 역출력합니다.
}