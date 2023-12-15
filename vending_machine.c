#include <stdio.h>
#include <windows.h>

int drink[5] = {10,10,10,10,10}; // ���Ǳ� �� ���� ��� ����
int price[5] = {1000,800,900,1000,1000}; // ������ ����
char *drinkName[5] = {"��ī�ݶ�","������","�Ϲٻ�","��������Ʈ","ȯŸ"}; // ���� ����
int money = 0, sale = 0; // money : ���Ե� ��, sale = �� ����
char choose = ' '; // �޴� ����

// �Լ� ������Ÿ�� ����
int title();
int menu();
int selectMenu();
int insertMoney(char choose);
int buyDrink(char choose);
int afterBuy();
int option(char choose);

// ���Ǳ� ���̾ƿ�
int all() {
    title();
    menu();
    selectMenu();
}

// Head �κ�
int title() {
    puts("======================");
    puts("=======���� ���Ǳ�=======");
    puts("======================");
    puts("-------------------------------");
    puts("��ǰ �Ǵ� �޴��� �����Ͻÿ�");
    puts("-------------------------------");
}

// Head �κ�
int menu() {
    for(int i = 0; i < 5; i++) { // ��� 1�� �̻� �� �� ���� ���� ǥ��
        if(drink[i] > 0) {
            printf("%d�� : [%d] %s -%d��-\n", i + 1, drink[i], drinkName[i], price[i]);
        }
        else { // �ƴ� �� ��� ���� ǥ��
            printf("%d�� : [��� ����] %s -%d��-\n", i + 1, drinkName[i], price[i]);
        }
    }
}

// ���� �κ� ���
int selectMenu() {
    printf("-------------------------------\n");
    printf("���� ������ �� �ݾ� : %d��\n", money);
    printf("-------------------------------\n");
    printf("�ݾ� ����\n");
    printf("\"A\" : 10�� ����\n");
    printf("\"B\" : 50�� ����\n");
    printf("\"C\" : 100�� ����\n");
    printf("\"D\" : 500�� ����\n");
    printf("-------------------------------\n");
    printf("���� �޴�\n");
    printf("-------------------------------\n");
    printf("\"Q\" : ���� �ݾ� ��ȯ\n");
    printf("\"W\" : �Ǹ� ���� ����\n");
    printf("\"E\" : �Ǹ� ���� �ʱ�ȭ\n");
    printf("-------------------------------\n");
    printf("\"X\" : ����\n");
    printf("-------------------------------\n");
    printf("====================\n");
    printf("�Է� �ϱ�: \n");
}

int main(void) {
    while(1) { // ���α׷� ���� �޴� ���� �ñ��� �ݺ�
        all();
        scanf("%c", &choose);
        insertMoney(choose);
        buyDrink(choose);
        option(choose);
        if(choose == 'x' || choose == 'X') { // ���α׷� ����
            puts("���� ��");
            Sleep(2000);
            break;
        }
    }
    return 0;
}

// ���� ���� �޴�
int insertMoney(char choose) {
    if(choose == 'a' || choose == 'A') { // 10�� ����
        money += 10;
    }
    else if(choose == 'b' || choose == 'B') { // 50�� ����
        money +=50;
    }
    else if(choose == 'c' || choose == 'C') { // 100�� ����
        money +=100;
    }
    else if(choose == 'd' || choose == 'D') { // 500�� ����
        money +=500;
    }
}

// ���� ����
int buyDrink(char choose) {
    if(choose == '1') { // ��ī�ݶ� (1000��) ����
        if(money >= price[0] && drink[0] > 0) {
            money -= price[0]; // -1000�� (�ݾ�)
            drink[0] -= 1; // -1�� (���)
            sale += price[0]; // +1000�� (����)
            printf("\"��ī�ݶ�\"�� �����ϼ̽��ϴ�.\n\n");
            afterBuy();
        }
        else if(drink[0] > 0) { // ��� ������ ��
            printf("���� �ݾ��� �����մϴ�.\n");
            Sleep(1500);
        }
        else { // �ݾ�, ��� �Ѵ� ���� ���� ��
            printf("��ǰ�� ��� �����մϴ�.\n");
            Sleep(1500);
        }
    }
    else if(choose == '2') { // ������ (800��) ����
        if(money >= price[1] && drink[1] > 0) {
            money -= price[1]; // -800�� (�ݾ�)
            drink[1] -= 1; // -1�� (���)
            sale += price[1]; // +800�� (����)
            printf("\"������\"�� �����ϼ̽��ϴ�.\n\n");
            afterBuy();
        }
        else if(drink[1] > 0) { // ��� ������ ��
            printf("���� �ݾ��� �����մϴ�.\n");
            Sleep(1500);
        }
        else { // �ݾ�, ��� �Ѵ� ���� ���� ��
            printf("��ǰ�� ��� �����մϴ�.\n");
            Sleep(1500);
        }
    }
    else if(choose == '3') { // �Ϲٻ� (900��) ����
        if(money >= price[2] && drink[2] > 0) {
            money -= price[2]; // -900�� (�ݾ�)
            drink[2] -= 1; // -1�� (���)
            sale += price[2]; // +900�� (����)
            printf("\"�Ϲٻ�\"�� �����ϼ̽��ϴ�.\n\n");
            afterBuy();
        }
        else if(drink[2] > 0) { // ��� ������ ��
            printf("���� �ݾ��� �����մϴ�.\n");
            Sleep(1500);
        }
        else { // �ݾ�, ��� �Ѵ� ���� ���� ��
            printf("��ǰ�� ��� �����մϴ�.\n");
            Sleep(1500);
        }
    }
    else if(choose == '4') { // ��������Ʈ (1000��) ����
        if(money >= price[3] && drink[3] > 0) {
            money -= price[3]; // -1000�� (�ݾ�)
            drink[3] -= 1; // -1�� (���)
            sale += price[3]; // +1000�� (����)
            printf("\"��������Ʈ\"�� �����ϼ̽��ϴ�.\n\n");
            afterBuy();
        }
        else if(drink[3] > 0) { // ��� ������ ��
            printf("���� �ݾ��� �����մϴ�.\n");
            Sleep(1500);
        }
        else { // �ݾ�, ��� �Ѵ� ���� ���� ��
            printf("��ǰ�� ��� �����մϴ�.\n");
            Sleep(1500);
        }
    }
    else if(choose == '5') { // ȯŸ (1000��) ����
        if(money >= price[4] && drink[4] > 0) {
            money -= price[4]; // +1000�� (�ݾ�)
            drink[4] -= 1; // -1�� (���)
            sale += price[4]; // -1000�� (����)
            printf("\"ȯŸ\"�� �����ϼ̽��ϴ�.\n\n");
            afterBuy();
        }
        else if(drink[4] > 0) { // ��� ������ ��
            printf("���� �ݾ��� �����մϴ�.\n");
            Sleep(1500);
        }
        else { // �ݾ�, ��� �Ѵ� ���� ���� ��
            printf("��ǰ�� ��� �����մϴ�.\n");
            Sleep(1500);
        }
    }
}

// ��ǰ ���� �� ���
int afterBuy() {
    Sleep(1500);
    printf("�����Ͻ� ��ǰ�� �����Ͽ����ϴ�.\n");
    Sleep(2500);
}

// ���� �ɼ�
int option(char choose) { // �Ž����� ��ȯ
    if(choose == 'q' || choose == 'Q') {
        printf("�Ž�����: %d��\n", money);
        money = 0;
        Sleep(2500);
    }
    if (choose == 'w' || choose == 'W') { // ���Ǳ� ���� ����
        printf("���Ǳ� �� ���� ��Ȳ : %d��\n", sale);
        printf("�Ǹ��� ��ǰ ��Ȳ\n");
        for(int i = 0; i < 5; i++) {
            printf("%s : %d��\n", drinkName[i], 10 - drink[i]);
        }
        Sleep(5000);
    }
    if(choose == 'e' || choose == 'E') { // ���Ǳ� ���� �ʱ�ȭ
        sale = 0;
        puts("���� �ʱ�ȭ �Ϸ�");
        Sleep(2500);
    }
}