#define _CRT_SECURE_NO_WARNINGS		//입출력 시 발생하는 경고를 무시하기 위해 추가합니다.
#include <stdio.h>		//표준 입출력을 담당하는 헤더입니다.

int BS(int data[],int index, int n) {		//데이터가 들어있는 data배열, 탐색하는 인덱스를 나타내는 index, 찾는 값 n을 매개변수로 받습니다.
	if (data[index] == n)		//index번째 data가 찾는 n일 경우
		return index;		//index를 반환합니다.
	else		//아닐 경우
		return BS(data, ++index, n);		//index를 하나 증가시키고 매개변수로 넘겨 함수를 반환합니다.
}

int main() {
	int index = 0;		//탐색 중인 인덱스를 나타낼 변수
	int n = 0;		//찾는 값을 저장할 변수
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };		//데이터가 저장된 배열

	printf("찾는 숫자를 입력하세요 : ");		//문자열을 출력합니다.
	scanf("%d", &n);		//사용자에게 입력을 받아 n에 저장합니다.
	printf("찾는 숫자는 %d 번째에 있습니다.", BS(data, index, n) + 1);		//문자열을 출력합니다.
}