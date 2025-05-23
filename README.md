# 음료 자판기 프로그램

## 멤버
대구가톨릭대학교 컴퓨터소프트웨어학부 21113038 고기현

## 서	론
이 보고서는 C언어로 작성된 음료 자판기 프로그램에 대한 설계 및 구현, 동작과 결과, 결구 분석 및 토의, 결론을 다룸. 사용자가 음료를 선택하고 금액을 투입하여 음료를 구매할 수 있는 자판기 프로그램을 제공함.

## 관련 연구
이 음료 자판기 프로그램은 여러 C언어 기초 교재 및 전공지식을 알려주는 블로그, 유튜브를 참고한 자료들을 기반으로 개발하였음. 관련한 이론은, ‘배열’이 중심이 되고, 반복문의 ‘무한 반복분’ ‘반복문 for’, ‘사용자 정의 함수’, ‘기타 헤더 파일’을 사용한 기술을 바탕으로 제작하였음. 다양한 참고 자료를 통해 프로그램을 효과적으로 설계하고 구현할 수 있었음.

## 프로그램 설계
콘솔 창을 사용하여 사용자의 입력 값을 받아들이고, 음료의 재고, 가격, 종류 등을 배열을 통하여 관리함. 각 기능은 함수로 모듈화 하여 가독성 및 유지보수성을 높였음. 사용자에겐 투입 금액, 음료 선택, 거스름돈 반환, 자판기 매출 보기, 자판기 매출 초기화, 프로그램 종류의 기능이 제공되게 설계하였음.

## 프로그램 구현
프로그램은 음료 자판기의 동작을 나타내는 모듈화 된 함수로 구성되어 있음. 주요 함수는 머리 부분의 ‘title’, ‘menu’, 선택 부분을 출력하는 ‘selectMenu’, 동전 투입 메뉴 ‘insertMoney’, 음료를 선택하는 ‘buyDrink’, 제품을 구매 후 출력하는 ‘afterBuy’, 세부 옵션의 동작부인 ‘option’으로 구성됨.
주요 기능의 소스 코드 부분을 소개하자면,

1.	동전 투입 메뉴 함수 ‘insertMoney’
```
// 동전 투입 메뉴
int insertMoney(char choose) {
    if(choose == 'a' || choose == 'A') { // 10원 투입
        money += 10;
    }
    else if(choose == 'b' || choose == 'B') { // 50원 투입
        money +=50;
    }
    else if(choose == 'c' || choose == 'C') { // 100원 투입
        money +=100;
    }
    else if(choose == 'd' || choose == 'D') { // 500원 투입
        money +=500;
    }
}
```
위 소스에서 조건문을 통해, 사용자가 입력하는 문자를 파악, 그 문자에 해당하는 조건문의 금액만큼 투입 금액의 변수 ‘money’에 값을 더하게 함.

음료를 선택하는 함수 ‘buyDrink’
```
// 음료 선택
int buyDrink(char choose) {
    if(choose == '1') { // 코카콜라 (1000원) 구입
        if(money >= price[0] && drink[0] > 0) {
            money -= price[0]; // -1000원 (금액)
            drink[0] -= 1; // -1개 (재고)
            sale += price[0]; // +1000원 (매출)
            printf("\"코카콜라\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[0] > 0) { // 재고만 만족할 시
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else { // 금액, 재고 둘다 만족 못할 시
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
```
사용자가 선택한 음료의 번호의 음료를 구매하도록 구현하였으며, 조건문의 조건에 따라 사용자의 투입 금액, 현재 재고를 통해 음료를 구매할 수 있는지, 구매 조건이 불만족하는 경우, 어떤 부분에서 조건이 만족되지 않는지 구분하여 사용자의 가독성과 프로그램 동작이 어떻게 되는지를 파악하기 쉽게 제작하였음.

음료를 구매하게 된다면, 투입 금액 ‘money’에서 해당 음료의 금액만큼 제하고, 해당 음료의 재고의 개수 1개 빼기, 자판기 매출의 변수 ‘sale’에 해당 음료의 가격만큼 더함.
```
else if(choose == '2') { // 레쓰비 (800원) 구입
        if(money >= price[1] && drink[1] > 0) {
            money -= price[1]; // -800원 (금액)
            drink[1] -= 1; // -1개 (재고)
            sale += price[1]; // +800원 (매출)
            printf("\"레쓰비\"를 선택하셨습니다.\n\n");
            afterBuy();
        }
        else if(drink[1] > 0) { // 재고만 만족할 시
            printf("투입 금액이 부족합니다.\n");
            Sleep(1500);
        }
        else { // 금액, 재고 둘다 만족 못할 시
            printf("상품의 재고가 부족합니다.\n");
            Sleep(1500);
        }
    }
```
이외의 다른 음료의 코드도 else if문을 통해, 위의 코드의 설명과 같이 제작되었단 걸 알 수 있음.

3. 세부 옵션 부분 ‘option’
```
// 세부 옵션
int option(char choose) { // 거스름돈 반환
    if(choose == 'q' || choose == 'Q') {
        printf("거스름돈: %d원\n", money);
        money = 0;
        Sleep(2500);
    }
    if (choose == 'w' || choose == 'W') { // 자판기 매출 보기
        printf("자판기 총 매출 현황 : %d원\n", sale);
        printf("판매한 상품 현황\n");
        for(int i = 0; i < 5; i++) {
            printf("%s : %d개\n", drinkName[i], 10 - drink[i]);
        }
        Sleep(5000);
    }
    if(choose == 'e' || choose == 'E') { // 자판기 매출 초기화
        sale = 0;
        puts("매출 초기화 완료");
        Sleep(2500);
    }
}
```

세부 옵션의 거스름돈 반환, 자판기 매출 보기, 자판기 매출을 초기화하는 구성으로 설계하였음. 거스름돈은 거스름돈 반환에 해당하는 문자가 입력되면, ‘money’ 변수의 금액을 표시하고 ‘money’ 변수의 값을 0으로 초기화 시킴.

자판기 매출 보기 부분은 자판기 매출 보기에 해당하는 문자가 입력되면, 자판기 내의 총 매출 금액인 ‘sale’의 금액을 출력하고, 반복문을 통해, 음료의 이름, 처음 재고에서 얼마나 판매되었는지를 판매하는 음료의 개수만큼 출력함.

자판기 매출 초기화 부분은 총 매출 금액 변수 ‘sale’의 금액의 변수 값을 0으로 초기화하는 걸로 설계함.

## 프로그램의 동작과 결과
 [초기 화면]
  
[D를 선택하여 500원 두 번 투입 후, 1번 상품 코카콜라 선택하여 구매]
[코카콜라 구매하여 코카콜라의 재고가 1개 줄어든 값 출력]






 
[500원 투입 후, 투입 금액 반환으로 투입 금액을 반환]
  
[매출 보기 함수를 표시, 왼쪽은 코카콜라 1개 판매 후, 매출 현황. 오른쪽은 판매 매출 초기화로 총 매출 초기화 후의 매출 보기의 화면을 표시한 화면]
  
[자판기에 투입 금액이 부족하면 투입 금액이 부족하다고 출력, 자판기의 구매하려는 음료의 개수가 부족한데 구매하려고 한다면 재고가 부족하다고 출력]

## 결과 분석 및 토의
프로그램의 동작 결과가 설계한 대로 정상적으로 수행되었으며, 컴파일 시에도 오류가 발생하지 않았고, 금액 부족과, 재고 부족 시에 의도한 대로 출력되었음. 프로그램 동작은 잘 되었으나, 사용자 가독성이 더 뛰어나면 좋겠다는 아쉬움도 있었음. 추후에 UI를 가독성 있게 설계하거나, 콘솔의 창의 크기를 지정하여 사용자가 더 보기 편하게 하는 것도 좋은 방안이라고 생각함.

## 결론
이 프로젝트를 하면서 C언어의 음료 자판기 프로그램의 동작이 잘 구현되어서 매우 기쁘고, 프로젝트를 하면서 막히는 부분도 많았으며, “어디서부터 해결해야 할까?”라는 생각을 하며 알고리즘 사고를 더욱 키우게 된 좋은 프로젝트였다고 생각함. 향후 이 프로젝트를 통해 습득한 계획적인 설계를 바탕으로, 프로그래밍의 설계에 대한 중요성을 더욱 알게 되어서 계획적인 설계의 무게감을 두고 설계해야겠단 생각을 하였음.

## 참고문헌
[1] 서동만, 전수빈, 전공자의 첫 C언어 프로그래밍, 인피니티북스, 2022.

[2] 윤성우, 윤성우의 열혈 C 프로그래밍, 오렌지미디어, 2010.

[3] 이재윤, C언어 기본 – 6 / if문 응용하기 – 자판기, 네이버 블로그, 2018년 1월 13일, https://blog.naver.com/sosow0212/221184456657, 2023년 12월 15일 접속.

[4] fkrtmxk, [C] 자판기 프로그램, 티스토리 블로그, 2021년 11월 20일, https://sunset-of-ocean.tistory.com/entry/C-%EC%9E%90%ED%8C%90%EA%B8%B0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8, 2023년 12월 15일 접속.

[5] 문지원, c언어를 이용한 자판기, 유튜브, 2021년 1월 8일, https://youtu.be/aIcu9Olnb3A?si=KIupBLIFy25Ff3Z5, 2023년 12월 15일 접속.
