
#include <stdio.h>

/*
���α׷�: �Ƕ�̵� ��� �� ���
����: �Է��� ���ڸ�ŭ �Ƕ�̵� ������� ���� �״� C ���α׷�
�Է�: ����ڷκ��� �Է� ���� "��"�� ���� (���� ����)
���: �Է¹��� ���ڸ�ŭ, ������ "*"����� �Ƕ�̵� ���
*/


// ����ڷκ��� �Է��� �޴� �Լ�
int get_UserInput() {
    int row_num = 0;
    while (row_num <= 0) {
        printf("���° �ٱ��� ���� ����ұ��? (�ڿ����� �Է��Ͻÿ�): ");
        scanf("%d", &row_num);

        // �ڿ����� �ƴ� �Է��� ����, ��� ������ ����ϰ� �ٽ� scanf ����
        if (row_num <= 0) {
             printf("�ڿ����� �Է����ּ���.\n\n");
        }
    }
    return row_num;
}


// ����� �Է¿� ���� �Ƕ�̵� ����� "*" ��� �Լ�
void make_pyramid(int num_rows) {
    
    // nested loop(��ø ����) �� �ٱ� ����, ��(row) ����
    for (int i = 0; i < num_rows; i++) {
        
        // nested loop(��ø ����) �� ���� ����, ��(column) ���������� ���
        
        // ���� �� ���ʺ��� ��ĭ ���
        for (int j = num_rows - 1; j > i; j--) {
            printf("@");
        }
        
        // ���� �� ���ʺ��� ��ĭ ��� ��, �� ���
        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        // �� �ٲ� �뵵�� printf��, �� ���� ���� ���۵ǵ��� ��
        printf("\n");
    }
}


int main(void)
{   

    // num_rows�� ����ڷκ��� �Է��� �޴� �Լ��� ��ȯ ���� �����ϴ� ������
    int num_rows = get_UserInput();
    
    // num_rows ������, make_pyramid �Լ��� �Ķ���ͷ� ������.
    make_pyramid(num_rows);

    return 0;
}
