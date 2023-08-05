/*
*   Banking System Ver 1.0
*   작성자: 김세진
*   내용:  OOP 단계별 프로젝트의 기본 구성
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       // 메뉴 출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);   // 입금
void WithdrawMoney(void);  // 출금
void ShowAllAccInfo(void); // 잔액 조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct {
    int accID; // 계좌 번호
    int balance; // 잔액
    char cusName[NAME_LEN]; // 고객 이름
} Account;


Account accArr[100]; // Account 저장 배열
int accNum = 0; // 저장된 Account 개수

int main()
{
    int choice;
    
    while (1) {
        ShowMenu();
        cout << "선택: "; cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "잘못된 선택" << endl;
            cout << endl;
        }
    }
    return 0;
}

void ShowMenu(void) {
    cout << "------------- Menu -------------" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보 천제 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << endl;
}

void MakeAccount(void) {
    int id; // 계좌 ID
    char name[NAME_LEN]; // 이름
    int balace; // 입금액

    cout << "[계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balace;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balace;
    strcpy_s(accArr[accNum].cusName, name);

    accNum++;
}

void DepositMoney(void) {
    int id; // 계좌 ID
    int money; // 입금액

    cout << "[입금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "입금액: "; cin >> money;
    cout << endl;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "입금완료" << endl;
            cout << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void WithdrawMoney(void) {
    int id; // 계좌 ID
    int money; // 출금액

    cout << "[출금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;
    cout << endl;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            if (accArr[i].balance < money) {
                cout << "잔액 부족입니다." << endl;
                cout << endl;
                return;
            }
            else {
                accArr[i].balance -= money;
                cout << "출금완료" << endl;
                cout << endl;
                return;
            }
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        cout << "계좌 ID: " << accArr[i].accID << endl;
        cout << "이름: " << accArr[i].cusName << endl;
        cout << "잔액: " << accArr[i].balance << endl;
        cout << endl;
    }
}

