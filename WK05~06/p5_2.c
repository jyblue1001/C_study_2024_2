#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 배열 A와 배열 B의 값을 교환하는 함수
// 1. 배열 A와 배열 B의 크기 비교
// 2. 배열 A와 배열 B의 크기가 같을 때의 경우를 교환하기
// 3. 배열 A의 크기가 더 클 때 남는 값들을 옮김
// 4. 배열 B의 크기가 더 클 때 남는 값들을 옮김

void reallocation(int **array_A, int **array_B, int size_A, int size_B){
    int i;

    if (size_A > size_B){
        *array_B = (int *)realloc(*array_B, sizeof(int) * size_A);
        for (i = size_B; i < size_A; i++){
            (*array_B)[i] = 0; // Initialize new elements to 0
        }
    }
    else if (size_B > size_A){
        *array_A = (int *)realloc(*array_A, sizeof(int) * size_B);
        for (i = size_A; i < size_B; i++){
            (*array_A)[i] = 0; // Initialize new elements to 0
        }
    }
}

void swap(int **array_A, int **array_B, int size_A, int size_B) {
    int temp_array;
    int larger_size, j;

    // Adjust sizes and initialize extra elements to zero if needed
    reallocation(array_A, array_B, size_A, size_B);

    // Find the larger size for swapping
    larger_size = (size_A > size_B) ? size_A : size_B;

    // Swap elements
    for (j = 0; j < larger_size; j++){
        temp_array = (*array_A)[j];
        (*array_A)[j] = (*array_B)[j];
        (*array_B)[j] = temp_array;
    }
}

void print_value(int *array_A, int *array_B, int size_A, int size_B){
    int m;
    printf("== Swap 이후의 배열 ==\n");

    printf("Array A: ");
    for (m = 0; m < size_A; m++) {
        printf("%d ", array_A[m]);
    }

    printf("\nArray B: ");
    for (m = 0; m < size_B; m++) {
        printf("%d ", array_B[m]);
    }
    printf("\n");
}

int main(void)
{
    int arr_A_size = 0, arr_B_size = 0;
    int i;

    system("chcp 65001");

    // 동적 할당하기 위해 배열 크기를 사용자로부터 입력받음
    while (arr_A_size == 0 || arr_B_size == 0){
        printf("두 배열의 크기를 입력하세요. : ");
        scanf("%d %d", &arr_A_size, &arr_B_size);

        if (arr_A_size == 0 || arr_B_size == 0){
            printf("배열의 크기는 0이 될 수 없습니다.\n");
        }       
    }

    // 입력받은 크기로 동적 할당
    int *arr_A = (int *)malloc(sizeof(int) * arr_A_size);
    int *arr_B = (int *)malloc(sizeof(int) * arr_B_size);
    
    printf("배열 A를 입력하세요 : ");
    for (i = 0; i < arr_A_size; i++){
        scanf("%d", &arr_A[i]);
    }

    printf("배열 B를 입력하세요 : ");
    for (i = 0; i < arr_B_size; i++){
        scanf("%d", &arr_B[i]);
    }

    printf("arr_A_size is %d, arr_B_size is %d\n", arr_A_size, arr_B_size);

    // 배열 A와 배열 B의 값을 교환하는 함수
    swap(&arr_A, &arr_B, arr_A_size, arr_B_size);
    print_value(arr_A, arr_B, arr_A_size, arr_B_size);

    // 할당된 메모리 공간 해제
    free(arr_A);
    free(arr_B);
    return 0;
}


