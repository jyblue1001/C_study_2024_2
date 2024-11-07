#include <stdio.h>
#include <windows.h>

/*
프로그램: 구조체를 활용한 게임 프로그램 문제
설명: 사용자로부터 몬스터와 유저의 정보 입력받고, 결투 진행
입력: 몬스터의 이름, 체력, 공격력 / 유저의 이름, 체력, 공격력
출력: 유닛이 쓰러질때마다 출력, 최종 결과 출력 
*/

typedef struct monster {
    /* 
    설명:
    monster 구조체를, 사용자 정의 Monster 자료형으로 선언

    멤버 :
    name = 이름 저장용 멤버
    health = 체력 값 저장용 멤버
    attack = 공격력 값 저장용 멤버
    
    출력:
    없음
    
     */
    char name[20];
    int health;
    int attack;
} Monster;


typedef struct user {
    /* 
    설명:
    user 구조체를, 사용자 정의 User 자료형으로 선언

    멤버 :
    name = 이름 저장용 멤버
    health = 체력 값 저장용 멤버
    attack = 공격력 값 저장용 멤버
    
    출력:
    없음
    
     */
    char name[20];
    int health;
    int attack;
} User;


void getMonsterInfo(Monster arr_Monster[], int num_Monster)
{
    /* 
    설명:
    이름 멤버, 체력 멤버, 공격력 멤버를 사용자로부터 입력받음

    입력 :
    arr_Monster = Monster형 배열
    num_Monster = 임의로 정한 몬스터 수
    
    반환:
    없음
    
     */
    int i;

    // 각 배열당 멤버들 입력받음
    for (i = 0; i < num_Monster; i++)
    {
        printf("Monster %d의 name, health, attack : ", i);
        scanf("%s %d %d", arr_Monster[i].name, &arr_Monster[i].health, &arr_Monster[i].attack);
    }
}

void getUserInfo(User arr_User[], int num_User)
{
    /* 
    설명:
    이름 멤버, 체력 멤버, 공격력 멤버를 사용자로부터 입력받음

    입력 :
    arr_User = Monster형 배열
    num_User = 임의로 정한 몬스터 수
    
    반환:
    없음
    
     */
    int i;

    // 각 배열당 멤버들 입력받음
    for (i = 0; i < num_User; i++)
    {
        printf("User %d의 name, health, attack : ", i);
        scanf("%s %d %d", arr_User[i].name, &arr_User[i].health, &arr_User[i].attack);
    }
}

void battleResult(int monster_death, int user_death)
{
    /* 
    설명:
    쓰러진 몬스터와 쓰러진 유저 수를 비교하여 승, 패, 무승부 문구 출력

    입력 :
    monster_death = 쓰러진 몬스터 수
    user_death = 쓰러진 유저 수
    
    반환:
    없음
    
     */
    if (monster_death > user_death)
    {
        printf("\n유저 팀이 승리했습니다!\n");
    }
    else if (monster_death < user_death)
    {
        printf("\n몬스터 팀이 승리했습니다!\n");
    } 
    else
    {
        printf("\n비겼습니다!\n");
    }
}


void battle(Monster monster_in_battle[], User user_in_battle[], int num_Monster, int num_User)
{
    /* 
    설명:
    (몬스터 체력 - 유저 공격력)
    (유저 체력 - 몬스터 공격력)
    위와 같은 형태로 결투하는 방식의 함수


    입력 :
    monster_in_battle = 현재 몬스터
    user_in_battle = 현재 유저
    
    변수 :
    current_Monster = 현재 결투 중인 몬스터 번호
    current_User = 현재 결투 중인 유저 번호
    
    반환:
    없음
    
     */

    // 첫 번째 몬스터와 유저
    int current_Monster = 0, current_User = 0;

    // (현재 결투 중인 몬스터 번호)가 (몬스터의 수)보다 커지면 종료
    //                          혹은
    // (현재 결투 중인 유저 번호)가 (유저의 수)보다 커지면 종료
    while ((current_Monster < num_Monster) && (current_User < num_User))
    {
        // 현재의 몬스터와 유저가 비길 시, 번호 동시 증가
        if ((monster_in_battle[current_Monster].health <= 0) && (user_in_battle[current_User].health <= 0))
        {
            printf("%s이(가) 쓰러졌습니다!\n", monster_in_battle[current_Monster].name);
            printf("%s이(가) 쓰러졌습니다!\n", user_in_battle[current_User].name);
            current_Monster++;
            current_User++;
        }
        // 유저가 몬스터 쓰러뜨렸을 시, 다음 몬스터 불러옴
        else if (monster_in_battle[current_Monster].health <= 0)
        {
            printf("%s이(가) 쓰러졌습니다!\n", monster_in_battle[current_Monster].name);
            current_Monster++;
        } 
        // 몬스터가 유저 쓰러뜨렸을 시, 다음 유저 불러옴
        else if (user_in_battle[current_User].health <= 0)
        {
            printf("%s이(가) 쓰러졌습니다!\n", user_in_battle[current_User].name);
            current_User++;
        }
        // 결투
        else
        {
            monster_in_battle[current_Monster].health -= user_in_battle[current_User].attack;
            user_in_battle[current_User].health -= monster_in_battle[current_Monster].attack;
        }
    }

    // (현재 몬스터,유저 수 - 1) = 쓰러뜨린 몬스터,유저 수이므로,
    // battleResult 호출하여 결과 출력
    battleResult(current_Monster, current_User);

}

int main(void) {
    /* 
    설명 :
    사용자 정의 함수들 호출하여 사용

    변수 :
    number_Monster = 임의로 정한 몬스터 수
    number_User = 임의로 정한 유저 수
    array_Monster[] : Monster형 배열 (사용자 정의 자료형: Monster)
    arr_User[] : User형 배열 (사용자 정의 자료형: User)
     */

    int number_Monster = 2, number_User = 2;
    Monster array_Monster[number_Monster];
    User array_User[number_User];

    // 터미널 한글 출력 가능케 해줌, UTF-8 인코딩 시켜줌
    system("chcp 65001");

    // 첫번째 사용자 정의 함수 getArraySize
    getMonsterInfo(array_Monster, number_Monster);

    // 두번째 사용자 정의 함수 getUserInfo
    getUserInfo(array_User, number_User);

    // 세번째 사용자 정의 함수 battle
    battle(array_Monster, array_User, number_Monster, number_User);

    return 0;
}
