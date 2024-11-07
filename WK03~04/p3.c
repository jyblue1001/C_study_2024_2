
#include <stdio.h>
#include <stdlib.h>

/*
���α׷�: �迭 ���� ����
����: �������� ����, �ߺ��� �� �����ϰ� ����ϴ� ���α׷�
�Է�: ���� �Ҵ� �迭 ũ��, �˻翡 ���� ���ڵ��� �Է����� ����
���: �������� ����, �ߺ� ���ܵ� ���ڵ�
*/


// �������� �����ϰ�, �ߺ��� �����ϰ� ����ϴ� �Լ�, Call by Value�� �������� ���
void ascending_rm_duplicate(int arr_before_ascending[], int arr_size_param){
    int temp = 0; 
    int j, k, l;
    int arr_after_ascending[arr_size_param]; // �ߺ� �˻翡 ���� �迭

    // ���� ascending ���� ���� ���� ����
    for (j = 0; j < arr_size_param ; j++){
        for (k = j; k < arr_size_param; k++){
            if (arr_before_ascending[j] > arr_before_ascending[k]){
                // �� �迭 �� ��ġ �ٲ�
                temp = arr_before_ascending[j];
                arr_before_ascending[j] = arr_before_ascending[k];
                arr_before_ascending[k] = temp;
            }
        }
        // ���ο� �迭�� ���� ����
        arr_after_ascending[j] = arr_before_ascending[j];
    }

    // ���� ���� ���� ��, �� ���� �迭 ���� �ٸ� ���� ���    
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
    // ���� �Ҵ��ϱ� ���� �迭 ũ�⸦ ����ڷκ��� �Է¹���
    printf("Enter the amount of numbers you want to enter: ");
    scanf("%d", &arr_size);
    printf("\n");

    // �Է¹��� ũ��� �ٽ� ���� �Ҵ�
    int * arr = (int *)malloc(sizeof(int)*arr_size);


    printf("Enter numbers, but no more than %d nubmers.\n", arr_size);
    printf("Anything more than that will be depricated\n\n", arr_size);

    // �迭 �� �ڸ��� scanf�� �Է¹���
    for (i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

    // �������� �����ϰ�, �ߺ��� �����ϰ� ����ϴ� �Լ� ȣ��
    ascending_rm_duplicate(arr, arr_size);

    // �Ҵ�� �޸� ���� ����
    free(arr);
    return 0;
}
