#define _CRT_SECURE_NO_WARNINGS		//입출력 중 발생하는 경고를 무시하기 위해 추가했습니다.
#include <stdio.h>		//표준 입출력을 담당하는 헤더입니다.

int power(int x, int n) {		//x의 n승을 구해야 하기 때문에, 정수 x와 n을 매개변수로 받는 함수를 만들었습니다
	if (n <= 0)		//지수가 0이하일 경우
		return 1;		//1을 반환합니다.
	else           //지수가 1이상일 경우
	{
		return x * power(x, n - 1);		//x와 x의 n-1승을 곱해줍니다.
	}
		
}

int main() {
	int x = 0; int n = 0;		//x는 밑이고, n은 지수가 됩니다.
	printf("숫자를 입력하세요(ex. 2의 3승 -> 2 3) : ");		//문자열을 출력합니다.
	scanf("%d %d", &x, &n);		//입력받은 정수를 각각 x n에 넣습니다.
	printf("%d의 %d승은 %d 입니다.", x, n, power(x, n));		//문자열을 출력합니다
}