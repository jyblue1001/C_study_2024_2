#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 배열 A와 배열 B의 값을 교환하는 함수
// 1. 배열 A와 배열 B의 크기 비교
// 2. 배열 A와 배열 B의 크기가 같을 때의 경우를 교환하기
// 3. 배열 A의 크기가 더 클 때 남는 값들을 옮김
// 4. 배열 B의 크기가 더 클 때 남는 값들을 옮김

void getArraySize(int * f1_array_A_size, int * f1_array_B_size){
    (*f1_array_A_size) = 0;
    (*f1_array_B_size) = 0;

    // 동적 할당하기 위해 배열 크기를 사용자로부터 입력받음
    while ((*f1_array_A_size) == 0 || (*f1_array_B_size) == 0){
        printf("두 배열의 크기를 입력하세요. : ");
        scanf("%d %d", f1_array_A_size, f1_array_B_size);

        if ((*f1_array_A_size) == 0 || (*f1_array_B_size) == 0){
            printf("배열의 크기는 0이 될 수 없습니다.\n");
        }       
    }
}



void memory_allocation(int ** f2_array_A, int ** f2_array_B, int f2_array_A_size, int f2_array_B_size){
    int i;

    // 입력받은 크기로 동적 할당
    int *f2_array_A = (int *)malloc(sizeof(int) * f2_array_A_size);
    int *f2_array_B = (int *)malloc(sizeof(int) * f2_array_B_size);
    
    printf("배열 A를 입력하세요 : ");
    for (i = 0; i < f2_array_A_size; i++){
        scanf("%d", f2_array_A[i]);
    }

    printf("배열 B를 입력하세요 : ");
    for (i = 0; i < f2_array_B_size; i++){
        scanf("%d", f2_array_B[i]);
    }

    printf("f2_array_A_size is %d, f2_array_B_size is %d\n", f2_array_A_size, f2_array_B_size);
}


int reallocation_max(int ** f3_array_A, int ** f3_array_B, int f3_array_A_size, int f3_array_B_size){
    int i;
    int max_size = (f3_array_A_size > f3_array_B_size) ? f3_array_A_size : f3_array_B_size;
    
    printf("%d\n", max_size);

    (*f3_array_A) = (int *)realloc((*f3_array_A), sizeof(int)*max_size);
    (*f3_array_B) = (int *)realloc((*f3_array_B), sizeof(int)*max_size);

    for (i = f3_array_A_size; i < max_size; i++) {
        (*f3_array_A)[i] = 0;
    }

    for (i = f3_array_B_size; i < max_size; i++) {
        (*f3_array_B)[i] = 0;
    }

    return max_size;
}


void swap(int ** f4_array_A, int ** f4_array_B) {
    int i;
    int * temp_array_ptr;

    temp_array_ptr = *f4_array_A;
    *f4_array_A = *f4_array_B;
    *f4_array_B = temp_array_ptr;
    
}


void print_value(int * f5_array_A, int * f5_array_B, int f5_max_size){
    int i;

    printf("=== SWAP 이후의 배열 ===\n배열 A : ");

    for (i = 0; i < f5_max_size; i++){
        printf("%d ", f5_array_A[i]);
    }

    printf("\n배열 B : ");

    for (i = 0; i < f5_max_size; i++){
        printf("%d ", f5_array_B[i]);
    }
}


int main(void)
{
    int arr_A_size, arr_B_size;
    int * arr_A;
    int * arr_B;
    int max_size;

    system("chcp 65001");

    getArraySize(&arr_A_size, &arr_B_size);
    memory_allocation(&arr_A, &arr_B, arr_A_size, arr_B_size);
    max_size = reallocation_max(&arr_A, &arr_B, arr_A_size, arr_B_size);
    swap(&arr_A, &arr_B);
    print_value(arr_A, arr_B, max_size);

    // 할당된 메모리 공간 해제
    free(arr_A);
    free(arr_B);

    return 0;
}
