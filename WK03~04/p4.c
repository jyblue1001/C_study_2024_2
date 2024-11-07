
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���α׷�: �ϳ��� Ÿ�� ����
����: ����ڷκ��� ���� �ϳ��� ž ������ �ް�, �ű�� Ƚ���� ���� ���
�Է�: �ϳ��� ž ��꿡 ���� ���� ������ �Է����� ����
���: ��꿡 �ʿ��� �� �̵� Ƚ��, �̵� ����(20�� �ʰ��� ��)
*/


// �ϳ��� ž ���� ����ϴ� ��� �Լ�
// Call by Value�� �������� ���
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


// �ϳ��� ž ������ Ǯ�� ���� �Űܾ� �Ǵ� Ƚ�� ����ϴ� �Լ� 
// �ϳ��� ž ���� ����ϴ� �Լ� ȣ�� (num�� 20������ ��)
// Call by Value�� �������� ���
void hanoi_top(int num){
    
    // ���� ��� ����ϱ� ���� <math.h> ���
    // pow()�Լ��� pow(double, double) �����̶�,
    // (float)num�� �ڷ��� ��ġ������(������ ���� ���ص� �Ǳ���)
    printf("%.0f\n", (pow(2.0, (float)num) - 1));

    // num_plates�� 20 �̻��� ��, �ű� Ƚ���� ���
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
    
    // �ϳ��� ž ���� ���� �Է¹ޱ�
    printf("Enter the numbers of plates: ");
    scanf("%d", &num_plates); printf("\n");

    // ���� ������ �ϳ��� ž ��� �Լ��� ����
    hanoi_top(num_plates);

    return 0;
}
