#define _CRT_SECURE_NO_WARNINGS		//입출력에서 발생하는 경고를 무시하기 위해 추가했습니다.
#include <stdio.h>		//표준 입출력을 지원하는 헤더입니다

int factorial(int n) {		//n의 팩토리얼을 구하는 함수입니다.
	if (n <= 1)
		return 1;		//0!과 1!은 1입니다.
	else
		return n * factorial(n - 1);		//n-1을 매개변수로 넘기면서 함수를 다시 호출해 팩토리얼을 수행합니다
}

int main() {
	int n = 0;		//정수를 입력받아 저장하기 위해 변수를 하나 만들었습니다.

	printf("숫자를 입력하세요 : ");		//문자열을 출력합니다.
	scanf("%d", &n);		//정수를 입력받아 n에 저장합니다.
	printf("%d의 팩토리얼은 %d입니다", n, factorial(n));		//문자열을 출력합니다.
}