
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
프로그램: 하노이 타워 문제
설명: 사용자로부터 받은 하노이 탑 개수를 받고, 옮기는 횟수와 과정 출력
입력: 하노이 탑 계산에 쓰일 판의 개수를 입력으로 받음
출력: 계산에 필요한 총 이동 횟수, 이동 과정(20개 초과일 때)
*/


// 하노이 탑 과정 출력하는 재귀 함수
// Call by Value로 지역변수 사용
void hanoi_top_calc(int n, int current, int target, int sub){


    if (n == 1){
        printf("%d %d\n", current, target);
    }
    else{
        hanoi_top_calc(n-1, current, sub, target);
        printf("%d %d\n", current, target);
        hanoi_top_calc(n-1, sub, target, current);
    }
}


// 하노이 탑 문제를 풀기 위해 옮겨야 되는 횟수 출력하는 함수 
// 하노이 탑 과정 출력하는 함수 호출 (num이 20이하일 시)
// Call by Value로 지역변수 사용
void hanoi_top(int num){
    
    // 제곱 기능 사용하기 위해 <math.h> 사용
    // pow()함수가 pow(double, double) 형식이라,
    // (float)num로 자료형 일치시켜줌(지금은 굳이 안해도 되긴함)
    printf("%.0f\n", (pow(2.0, (float)num) - 1));

    // num_plates가 20 이상일 시, 옮긴 횟수만 출력
    if (num > 20){
        return;
    }
    else{
        return(hanoi_top_calc(num, 1, 3, 2));
    }
}


int main(void)
{
    int num_plates;
    
    // 하노이 탑 원판 갯수 입력받기
    printf("Enter the numbers of plates: ");
    scanf("%d", &num_plates); printf("\n");

    // 원판 갯수를 하노이 탑 계산 함수에 전달
    hanoi_top(num_plates);

    return 0;
}
