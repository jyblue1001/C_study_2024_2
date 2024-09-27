
#include <stdio.h>

/*
프로그램: 피라미드 모양 별 찍기
설명: 입력한 숫자만큼 피라미드 모양으로 별을 쌓는 C 프로그램
입력: 사용자로부터 입력 받을 "열"의 숫자 (양의 정수)
출력: 입력받은 숫자만큼, 행으로 "*"모양의 피라미드 출력
*/


// 사용자로부터 입력을 받는 함수
int get_UserInput() {
    int row_num = 0;
    while (row_num <= 0) {
        printf("몇번째 줄까지 별을 출력할까요? (자연수를 입력하시오): ");
        scanf("%d", &row_num);

        // 자연수가 아닌 입력이 오면, 경고 문구를 출력하고 다시 scanf 실행
        if (row_num <= 0) {
             printf("자연수를 입력해주세요.\n\n");
        }
    }
    return row_num;
}


// 사용자 입력에 따른 피라미드 모양의 "*" 출력 함수
void make_pyramid(int num_rows) {
    
    // nested loop(중첩 루프) 중 바깥 루프, 열(row) 방향
    for (int i = 0; i < num_rows; i++) {
        
        // nested loop(중첩 루프) 중 안쪽 루프, 행(column) 방향으로의 출력
        
        // 행의 맨 왼쪽부터 빈칸 출력
        for (int j = num_rows - 1; j > i; j--) {
            printf("@");
        }
        
        // 행의 맨 왼쪽부터 빈칸 출력 후, 별 출력
        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        // 열 바꿈 용도의 printf문, 그 다음 열이 시작되도록 함
        printf("\n");
    }
}


int main(void)
{   

    // num_rows는 사용자로부터 입력을 받는 함수의 반환 값을 저장하는 변수임
    int num_rows = get_UserInput();
    
    // num_rows 변수를, make_pyramid 함수의 파라미터로 전달함.
    make_pyramid(num_rows);

    return 0;
}
