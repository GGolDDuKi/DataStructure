#define _CRT_SECURE_NO_WARNINGS		//입출력시 발생하는 오류들을 방지하고자 추가했습니다.
#include <stdio.h>		//표준 입출력을 담당하는 헤더

typedef struct {		//Grade타입의 구조체
	char id[9];		//학번을 저장할 id 변수
	int korean;		//국어 점수를 저장할 korean 변수
	int english;		//영어 점수를 저장할 english 변수		// -> Grade 구조체의 멤버 변수들
	int math;		//수학 점수를 저장할 math 변수
	int total;		//총점을 저장할 total 변수
	float avg;		//평균을 저장할 avg 변수, 나눗셈 과정에서 실수가 발생할 수 있기 때문에 float형으로 만들었습니다.
}Grade;

int main() {
	FILE* file = NULL;		//파일의 주소를 저장할 FILE포인터 변수
	Grade student[5];		//5명 학생의 점수를 저장할 student 구조체의 배열

	if ((file = fopen("data.txt", "r")) != NULL) {		//file에 열고자 하는 파일의 주소(이름)을 넘겨주고, 읽기 모드로 불러옵니다. 파일 주소가 NULL일 경우 else로 이동
		for (int i = 0; i < 5; i++) {		//학생이 5명이므로 5번 반복해주는 반복문을 사용했습니다.
			fscanf(file, "%s\t%d %d %d", student[i].id, &student[i].korean, &student[i].english, &student[i].math);		//fscanf를 사용하여 data.txt에 저장된 학번, 국어점수, 영어점수, 수학점수를 student구조체의 멤버 변수들에 넣어줍니다.
			student[i].total = student[i].korean + student[i].english + student[i].math;		//위에서 저장한 각 과목의 점수의 합을 total멤버변수에 넣어줍니다.
			student[i].avg = student[i].total / 3;		//total멤버변수를 과목 수로 나눠 avg멤버변수에 평균을 넣어줍니다.
		}
		fclose(file);		//파일을 닫아줍니다.
	}
	else {
		printf("파일 열기 실패\n");
	}

	int kSum = 0, eSum = 0, mSum = 0, tSum = 0;
	float aSum = 0;									//모든 학생의 국어, 영어, 수학, 총점, 평균의 값을 더한 값을 저장할 변수를 만듭니다.
	for (int i = 0; i < 5; i++) {		//학생 수 만큼 반복문을 돌려 각 값의 합을 구합니다
		kSum += student[i].korean;		//kSum변수에 각 학생의 국어점수를 더해줍니다.
		eSum += student[i].english;		//eSum변수에 각 학생의 영어점수를 더해줍니다.
		mSum += student[i].math;		//mSum변수에 각 학생의 수학점수를 더해줍니다.
		tSum += student[i].total;		//tSum변수에 각 학생의 총점을 더해줍니다.
		aSum += student[i].avg;		//aSum변수에 각 학생의 평균을 더해줍니다.
	}

	printf("ㅣ===================================================ㅣ\n");		//입력된 문자열을 출력합니다.
	printf("ㅣ 학  번 ㅣ 국어 ㅣ 영어 ㅣ 수학 ㅣ 총 점 ㅣ 평  균 ㅣ\n");		//입력된 문자열을 출력합니다.
	for (int i = 0; i < 5; i++) {		//학생 수(5) 만큼 반복문을 돌려줍니다.
		printf("ㅣ%sㅣ  %d  ㅣ  %d  ㅣ  %d  ㅣ  %d  ㅣ  %.2f ㅣ\n", student[i].id, student[i].korean, student[i].english, student[i].math, student[i].total, student[i].avg);
		//학생별 학번, 국어점수, 영어점수, 수학점수, 총점, 평균을 출력합니다.
	}
	printf("ㅣ========ㅣ======ㅣ======ㅣ======ㅣ=======ㅣ========ㅣ\n");		//입력된 문자열을 출력합니다.
	printf("ㅣ 평  균 ㅣ %.2fㅣ %.2fㅣ %.2fㅣ %.2fㅣ  %.2f ㅣ\n", (float)kSum/5, (float)eSum/5, (float)mSum/5, (float)tSum/5, aSum/5);		//각 점수 별 평균을 구해주는데, aSum을 제외한 변수는 int형이므로 float형으로 형변환을 해줍니다.
	printf("ㅣ===================================================ㅣ\n");		//입력된 문자열을 출력합니다.
}