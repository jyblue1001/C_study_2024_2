
#include <stdio.h>
#include <windows.h>

/*
프로그램: 배열 교환 문제
설명: 사용자로부터 배열을 입력받아 교환하는 프로그램
입력: 배열 A크기, 배열 B크기, 배열 A값, 배열 B값
출력: 바뀐 배열 출력
*/



void getArraySize(int *arr_A_size, int *arr_B_size)
{
    /* 
    설명: 
    사용자로부터 배열 A와 B의 크기를 입력받는 함수

    입력 :
    *arr_A_size = 사용자가 설정할 배열 A 크기
    *arr_B_size = 사용자가 설정할 배열 B 크기
    
    반환 :
    없음

     */

    // 아직 배열을 안 받았다고 가정하여 최초 크기를 0으로 초기화
    (*arr_A_size) = 0;
    (*arr_B_size) = 0;

    // 동적 할당하기 위해 배열 크기를 사용자로부터 입력받음, 0이 아닌 크기를 입력할 때까지 입력받음
    while ((*arr_A_size) == 0 || (*arr_B_size) == 0)
    {
        printf("두 배열의 크기를 입력하세요. : ");
        scanf("%d %d", arr_A_size, arr_B_size);

        // 두 배열 중 하나의 크기라도 0이라면 오류 문구 출력 
        if ((*arr_A_size) == 0 || (*arr_B_size) == 0)
        {
            printf("배열의 크기는 0이 될 수 없습니다.\n");
        }       
    }
}



void memory_allocation_getArray(int **arr_A, int **arr_B, int *arr_A_size, int *arr_B_size)
{
    /* 
    설명: 
    1. getArraySize함수에서 받은 값으로, 배열 A와 B의 크기를 동적 할당함
    2. 배열 A와 B의 값을 사용자로부터 입력받음

    입력 :
    **arr_A = 배열 A
    **arr_B = 배열 B
    *arr_A_size = 배열 A 크기
    *arr_B_size = 배열 B 크기
    
    반환:
    없음

     */

    int i;

    // 1. getArraySize함수에서 받은 값으로, 배열 A와 B의 크기를 동적 할당함
    *arr_A = (int *)malloc(sizeof(int) * (*arr_A_size));
    *arr_B = (int *)malloc(sizeof(int) * (*arr_B_size));
    

    // 2. 배열 A와 B의 값을 사용자로부터 입력받음
    printf("배열 A를 입력하세요 : ");
    for (i = 0; i < *arr_A_size; i++)
    {
        scanf("%d", &(*arr_A)[i]);
    }
    printf("배열 B를 입력하세요 : ");
    for (i = 0; i < *arr_B_size; i++)
    {
        scanf("%d", &(*arr_B)[i]);
    }
}


void reallocation_fill_zero(int **arr_A, int **arr_B, int *arr_A_size, int *arr_B_size)
{
    /* 
    설명:
    1. 작은 크기를 가진 배열을, 큰 크기를 가진 배열의 크기로 재차 동적할당 함, 크기 같을 시 즉시 반환
    2. 재차 동적할당된 배열 중 빈 요소들을 0값으로 초기화
    3. 작은 배열 크기를 큰 배열 크기 값으로 초기화

    입력 :
    **arr_A = 배열 A
    **arr_B = 배열 B
    *arr_A_size = 배열 A 크기
    *arr_B_size = 배열 B 크기
    
    반환:
    없음
    
     */

    int i;

    // 배열 A의 크기가 배열 B의 크기보다 클 때
    if ((*arr_A_size) > (*arr_B_size))
    {   
        // 1. 작은 크기를 가진 배열을, 큰 크기를 가진 배열의 크기로 재차 동적할당 함
        (*arr_B) = (int *)realloc((*arr_B), sizeof(int) * (*arr_A_size));
        
        // 2. 재차 동적할당된 배열 중 빈 요소들을 0값으로 초기화
        for (i = (*arr_B_size); i < (*arr_A_size); i++)
        {
            (*arr_B)[i] = 0;
        }
        // 3. 작은 배열 크기를 큰 배열 크기 값으로 초기화
        (*arr_B_size) = (*arr_A_size);
    }

    // 위와 동일
    else if ((*arr_A_size) < (*arr_B_size))
    {
        (*arr_A) = (int *)realloc((*arr_A), sizeof(int) * (*arr_B_size));

        for (i = (*arr_A_size); i < (*arr_B_size); i++)
        {
            (*arr_A)[i] = 0;
        }

        (*arr_A_size) = (*arr_B_size);
    }

    // 두 배열의 크기가 같을 시, 즉시 반환
    else
    {
        return;
    }
}


void swap(int **arr_A, int **arr_B)
{
    /* 
    설명 :
    배열 A와 배열 B의 값을 바꾸는 함수

    입력 :
    **arr_A = 배열 A
    **arr_B = 배열 B
    *arr_A_size = 배열 A 크기
    *arr_B_size = 배열 B 크기
    
    반환:
    없음
    
     */

    int i;
    int * temp_array_ptr;

    temp_array_ptr = *arr_A;
    *arr_A = *arr_B;
    *arr_B = temp_array_ptr;
    
}


void print_value(int *arr_A, int *arr_B, int *arr_A_size, int *arr_B_size)
{
    /* 
    설명 :
    배열 A와 배열 B의 값을 출력하는 함수

    입력 :
    **arr_A = 배열 A
    **arr_B = 배열 B
    *arr_A_size = 배열 A 크기
    *arr_B_size = 배열 B 크기
    
    반환:
    없음
    
     */

    int i;

    printf("=== SWAP 이후의 배열 ===\n배열 A : ");

    for (i = 0; i < (*arr_A_size); i++)
    {
        printf("%d ", arr_A[i]);
    }

    printf("\n배열 B : ");

    for (i = 0; i < (*arr_B_size); i++)
    {
        printf("%d ", arr_B[i]);
    }
}


int main(void)
{
    /* 
    설명 :
    사용자 정의 함수들 호출하여 사용

    변수 :
    array_A_size = 배열 A의 크기
    array_B_size = 배열 B의 크기
    *array_A : 배열 A
    *array_B : 배열 B
     */

    int array_A_size, array_B_size;

    // 임의의 값으로 배열 A와 배열 B초기화, 주소 생성 용도
    int *array_A = 0;
    int *array_B = 0;

    // 터미널 한글 출력 가능케 해줌, UTF-8 인코딩 시켜줌
    system("chcp 65001");
    

    // 첫번째 사용자 정의 함수 getArraySize
    getArraySize(&array_A_size, &array_B_size);

    // 두번째 사용자 정의 함수 memory_allocation_getArray
    memory_allocation_getArray(&array_A, &array_B, &array_A_size, &array_B_size);

    // 세번째 사용자 정의 함수 reallocation_fill_zero
    reallocation_fill_zero(&array_A, &array_B, &array_A_size, &array_B_size);

    // 네번째 사용자 정의 함수 swap
    swap(&array_A, &array_B);

    // 다섯번째 사용자 정의 함수 print_value
    print_value(array_A, array_B, &array_A_size, &array_B_size);
    

    // 할당된 메모리 공간 해제
    free(array_A);
    free(array_B);

    return 0;
}
