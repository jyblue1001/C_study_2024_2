
#include <stdio.h>
#include <string.h>

/*
���α׷�: �ð� ��� ���α׷�
����: "��/��"�� ����� ��, "���ϱ�/����"�� ����� ��, �ڿ����� ����ڷκ��� �Է� �޾� �ð��� ���� �����
�Է�: ��/��, ���ϱ�/����, �ڿ���
���: ���� �Է¿� ���� �ð� ���
*/


int main(void)
{
    // ��, �� ����
    int hour = 0;
    int minute = 0;

    // switch ��ɾ ���Ǳ� ���� int ����
    int hr_min = 0;
    int add_sub = 0;

    // �ڿ��� ����
    int nat_num = 0;

    // "��/��" �Է� ���� ����
    // "���ϱ�/����" �Է� ���� ����
    char which_num[10];
    char which_calc[10];


    printf("�ÿ� ���� �Է��ϼ���\n");
    scanf("%d %d", &hour, &minute);
    printf("\n");


    printf("��/�� �� � ���� �Է� �������?\n");
    scanf("%s", which_num);
    printf("\n");
    
    
    // which_num�� "��" �Ǵ� "��"�� ��ġ�ϴ� Ȯ���ϴ� if-else ����
    if (strcmp(which_num, "��") != 0 && strcmp(which_num, "��") != 0) {
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }
    else if (strcmp(which_num, "��") == 0){
        hr_min=1;
    }
    else if (strcmp(which_num, "��") == 0){
        hr_min=2;
    }
    else{
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }


    printf("��� ����ұ��? : 1. ���ϱ�, 2. ����\n");
    scanf("%s", which_calc);
    printf("\n");

    // which_calc�� "���ϱ�" �Ǵ� "����"�� ��ġ�ϴ� Ȯ���ϴ� if-else ����
    if (strcmp(which_calc, "���ϱ�") == 0){
        add_sub=1;
    }
    else if (strcmp(which_calc, "����") == 0){
        add_sub=3;
    }
    else{
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }


    printf("�ڿ����� �Է��ϼ���\n");
    scanf("%d", &nat_num);

    // �ڿ����� �ƴ� �Է��� ����, ��� ������ ����ϰ� ���α׷� ����
    if (nat_num <= 0) {
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }



    /*
    hr_min: ��=1, ��=2
    add_sub: add=1, sub=3

    hr_min + add_sub�� �Ʒ��� ���� ����� ���� �����ؼ� switch�� ���
    = 2: �� ���ϱ�
    = 3: �� ���ϱ�
    = 4: �� ����
    = 5: �� ����
    */

    switch (hr_min + add_sub){
        
        // �� ���ϱ�
        case 2:
            hour = (hour + ((minute + nat_num) / 60)) % 24;
            minute = (minute + nat_num) % 60;
        break;

        // �� ���ϱ�
        case 3:
            hour = (hour + nat_num) % 24;
        break;

        // �� ����
        case 4:
            hour = (hour + (24 - ((nat_num / 60) % 24))) % 24;
            hour = ((minute - nat_num) <= 0) && (nat_num < 60) ? ((24 + hour - 1) % 24) : hour;
            minute = (minute + (60 - (nat_num % 60))) % 60;
        break;
 
        // �� ����
        case 5:
            hour = (hour + (24 - (nat_num % 24))) % 24;
        break;

        // �� �ܿ� �ٸ� �Է��� ������ ���α׷� ����
        default:
            printf("�߸��� �Է��Դϴ�");
            return 1;
    }

    printf("%02d %02d", hour, minute);

    return 0;
}
