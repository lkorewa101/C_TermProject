#include <stdio.h>
#include <windows.h>

int console() {
    system("mode con cols = 43 line = 33");
}
int drink[5] = {10,10,10,10,10};
int price[5] = {1000,800,900,1000,1000};
char *drinkName[5] = {"코카콜라","레쓰비","암바사","스프라이트","환타"};
int money = 0, sale = 0;
char choose = ' ';

int title();
int menu();
int selectMenu();
int insertMoney(char choose);
int buyDrink(char choose);
int afterBuy();
int option(char choose);

int all() {
    title();
    menu();
    selectMenu();
}

int title() {
    puts("======================");
    puts("=======음료 자판기=======");
    puts("======================");
    puts("-------------------------------");
    puts("제품 또는 메뉴를 선택하시오");
    puts("-------------------------------");
}

int menu() {
    for(int i = 0; i < 5; i++) {
        if(drink[i] > 0) {
            printf("%d번 : [%d] %s -%d원-\n", i + 1, drink[i], drinkName[i], price[i]);
        }
        else {
            printf("%d번 : [%d] %s -%d원-\n", i + 1, drinkName[i], price[i]);
        }
    }
}

int selectMenu() {
    printf("-------------------------------\n");
    printf("현재 투입한 총 금액 : %d원\n", money);
    printf("-------------------------------\n");
    printf("금액 투입\n");
    printf("\"A\" : 10원 투입\n");
    printf("\"B\" : 50원 투입\n");
    printf("\"C\" : 100원 투입\n");
    printf("\"D\" : 500원 투입\n");
    printf("-------------------------------\n");
    printf("세부 메뉴\n");
    printf("-------------------------------\n");
    printf("\"Q\" : 투입 금액 반환\n");
    printf("\"W\" : 판매 매출 보기\n");
    printf("\"E\" : 판매 매출 초기화\n");
    printf("-------------------------------\n");
    printf("\"X\" : 종료\n");
    printf("-------------------------------\n");
    printf("====================\n");
    printf("입력 하기: \n");
}

int main(void) {
    while(1) {
        all();
        scanf("%c", &choose);
        insertMoney(choose);
        buyDrink(choose);
        option(choose);
        if(choose == 'x' || choose == 'X') {
            puts("종료 중");
            Sleep(2000);
            break;
        }
    }
    return 0;
}

int insertMoney(char choose) {
    if(choose == 'a' || choose == 'A') {
        money += 10;
    }
    else if(choose == 'b' || choose == 'B') {
        money +=50;
    }
    else if(choose == 'c' || choose == 'C') {
        money +=100;
    }
    else if(choose == 'd' || choose == 'D') {
        money +=500;
    }
}

int buyDrink(char choose) {
    if(choose == '1') {
        if(money >= price[0] && drink[0] > 0) {
            money -= price[0];
            drink[0] -= 1;
            sale += price[0];
            printf("\"코카콜라\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[0] > 0) {
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else {
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
    else if(choose == '2') {
        if(money >= price[1] && drink[1] > 0) {
            money -= price[1];
            drink[1] -= 1;
            sale += price[1];
            printf("\"레쓰비\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[1] > 0) {
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else {
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
    else if(choose == '3') {
        if(money >= price[2] && drink[2] > 0) {
            money -= price[2];
            drink[2] -= 1;
            sale += price[2];
            printf("\"암바사\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[2] > 0) {
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else {
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
    else if(choose == '4') {
        if(money >= price[3] && drink[3] > 0) {
            money -= price[3];
            drink[3] -= 1;
            sale += price[3];
            printf("\"스프라이트\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[3] > 0) {
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else {
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
    else if(choose == '5') {
        if(money >= price[4] && drink[4] > 0) {
            money -= price[4];
            drink[4] -= 1;
            sale += price[4];
            printf("\"환타\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[4] > 0) {
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else {
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
}

int afterBuy() {
    Sleep(1500);
    printf("선택하신 제품을 구매하였습니다.\n");
    Sleep(2500);
}

int option(char choose) {
    if(choose == 'q' || choose == 'Q') {
        printf("거스름돈: %d원\n", money);
        money = 0;
        Sleep(2500);
    }
    if (choose == 'w' || choose == 'W') {
        printf("자판기 총 매출 현황 : %d원\n", sale);
        printf("판매한 상품 현황\n");
        for(int i = 0; i < 5; i++) {
            printf("%s : %d개\n", drinkName[i], 10 - drink[i]);
        }
        Sleep(5000);
    }
    if(choose == 'e' || choose == 'E') {
        sale = 0;
        puts("매출 초기화 완료");
        Sleep(2500);
    }
}