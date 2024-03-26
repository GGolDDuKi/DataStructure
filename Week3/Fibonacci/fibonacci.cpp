#define _CRT_SECURE_NO_WARNINGS     //입출력 중 발생하는 경고를 무시하기 위해 추가했습니다.
#include <stdio.h>      //표준 입출력을 담당하는 헤더입니다.

int fibonacci(int n)        //피보나치 수열을 계산하는 함수입니다.
{
    if (n <= 0)     //n이 0 이하일 경우
        return 0;       //0을 반환합니다.
    else if (n == 1)        //n이 1일 경우
        return 1;       //1을 반환합니다.
    return fibonacci(n - 1) + fibonacci(n - 2);     //피보나치는 n = (n-1) + (n-2)이기 때문에 공식 그대로 반환값으로 주었습니다.
}

int main() {
	int n = 0;      //몇번째 피보나치수열의 수를 구할지 저장할 변수입니다.
            
	printf("숫자를 입력하세요 : ");     //문자열을 출력합니다.
	scanf("%d", &n);        //입력받은 정수값을 n에 저장합니다.
	printf("%d번째 피보나치수열은 %d입니다",n, fibonacci(n));       //문자열을 출력합니다.
}