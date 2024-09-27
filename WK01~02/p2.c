
#include <stdio.h>
#include <string.h>

/*
프로그램: 시간 계산 프로그램
설명: "시/분"을 계산할 지, "더하기/빼기"을 계산할 지, 자연수를 사용자로부터 입력 받아 시간을 새로 계산함
입력: 시/분, 더하기/빼기, 자연수
출력: 위의 입력에 따른 시간 계산
*/


int main(void)
{
    // 시, 분 변수
    int hour = 0;
    int minute = 0;

    // switch 명령어에 사용되기 위한 int 변수
    int hr_min = 0;
    int add_sub = 0;

    // 자연수 변수
    int nat_num = 0;

    // "시/분" 입력 받을 변수
    // "더하기/빼기" 입력 받을 변수
    char which_num[10];
    char which_calc[10];


    printf("시와 분을 입력하세요\n");
    scanf("%d %d", &hour, &minute);
    printf("\n");


    printf("시/분 중 어떤 것을 입력 받을까요?\n");
    scanf("%s", which_num);
    printf("\n");
    
    
    // which_num이 "시" 또는 "분"과 일치하는 확인하는 if-else 구문
    if (strcmp(which_num, "시") != 0 && strcmp(which_num, "분") != 0) {
        printf("잘못된 입력입니다");
        return 1;
    }
    else if (strcmp(which_num, "분") == 0){
        hr_min=1;
    }
    else if (strcmp(which_num, "시") == 0){
        hr_min=2;
    }
    else{
        printf("잘못된 입력입니다");
        return 1;
    }


    printf("어떻게 계산할까요? : 1. 더하기, 2. 빼기\n");
    scanf("%s", which_calc);
    printf("\n");

    // which_calc가 "더하기" 또는 "빼기"과 일치하는 확인하는 if-else 구문
    if (strcmp(which_calc, "더하기") == 0){
        add_sub=1;
    }
    else if (strcmp(which_calc, "빼기") == 0){
        add_sub=3;
    }
    else{
        printf("잘못된 입력입니다");
        return 1;
    }


    printf("자연수를 입력하세요\n");
    scanf("%d", &nat_num);

    // 자연수가 아닌 입력이 오면, 경고 문구를 출력하고 프로그램 종료
    if (nat_num <= 0) {
        printf("잘못된 입력입니다");
        return 1;
    }



    /*
    hr_min: 분=1, 시=2
    add_sub: add=1, sub=3

    hr_min + add_sub을 아래와 같은 경우의 수로 구분해서 switch에 사용
    = 2: 분 더하기
    = 3: 시 더하기
    = 4: 분 빼기
    = 5: 시 빼기
    */

    switch (hr_min + add_sub){
        
        // 분 더하기
        case 2:
            hour = (hour + ((minute + nat_num) / 60)) % 24;
            minute = (minute + nat_num) % 60;
        break;

        // 시 더하기
        case 3:
            hour = (hour + nat_num) % 24;
        break;

        // 분 빼기
        case 4:
            hour = (hour + (24 - ((nat_num / 60) % 24))) % 24;
            hour = ((minute - nat_num) <= 0) && (nat_num < 60) ? ((24 + hour - 1) % 24) : hour;
            minute = (minute + (60 - (nat_num % 60))) % 60;
        break;
 
        // 시 빼기
        case 5:
            hour = (hour + (24 - (nat_num % 24))) % 24;
        break;

        // 그 외에 다른 입력이 들어오면 프로그램 종료
        default:
            printf("잘못된 입력입니다");
            return 1;
    }

    printf("%02d %02d", hour, minute);

    return 0;
}
