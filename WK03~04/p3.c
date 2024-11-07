
#include <stdio.h>
#include <stdlib.h>

/*
프로그램: 배열 정렬 문제
설명: 오름차순 정렬, 중복된 값 제외하고 출력하는 프로그램
입력: 동적 할당 배열 크기, 검사에 쓰일 숫자들을 입력으로 받음
출력: 오름차순 이후, 중복 제외된 숫자들
*/


// 오름차순 정렬하고, 중복은 제외하고 출력하는 함수, Call by Value로 지역변수 사용
void ascending_rm_duplicate(int arr_before_ascending[], int arr_size_param){
    int temp = 0; 
    int j, k, l;
    int arr_after_ascending[arr_size_param]; // 중복 검사에 쓰일 배열

    // 버블 ascending 형식 오름 차순 정렬
    for (j = 0; j < arr_size_param ; j++){
        for (k = j; k < arr_size_param; k++){
            if (arr_before_ascending[j] > arr_before_ascending[k]){
                // 두 배열 값 위치 바꿈
                temp = arr_before_ascending[j];
                arr_before_ascending[j] = arr_before_ascending[k];
                arr_before_ascending[k] = temp;
            }
        }
        // 새로운 배열에 값을 받음
        arr_after_ascending[j] = arr_before_ascending[j];
    }

    // 오름 차순 정렬 후, 뒷 순위 배열 값과 다를 때만 출력    
    for (l = 0; l < arr_size_param; l++){
        if (arr_after_ascending[l] != arr_after_ascending[l+1]){
            printf("%d ", arr_after_ascending[l]);
        }
    }
}


int main(void)
{
    int arr_size = 1;
    int i;
    
    printf("\n");
    // 동적 할당하기 위해 배열 크기를 사용자로부터 입력받음
    printf("Enter the amount of numbers you want to enter: ");
    scanf("%d", &arr_size);
    printf("\n");

    // 입력받은 크기로 다시 동적 할당
    int * arr = (int *)malloc(sizeof(int)*arr_size);


    printf("Enter numbers, but no more than %d nubmers.\n", arr_size);
    printf("Anything more than that will be depricated\n\n", arr_size);

    // 배열 한 자리당 scanf로 입력받음
    for (i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

    // 오름차순 정렬하고, 중복은 제외하고 출력하는 함수 호출
    ascending_rm_duplicate(arr, arr_size);

    // 할당된 메모리 공간 해제
    free(arr);
    return 0;
}
