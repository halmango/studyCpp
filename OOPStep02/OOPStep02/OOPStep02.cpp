/*
*   Banking System Ver 2.0
*   작성자: 김세진
*   내용:  Account 클래스 저의, 객체 포인터 배열 적용
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       // 메뉴 출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);   // 입금
void WithdrawMoney(void);  // 출금
void ShowAllAccInfo(void); // 잔액 조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
    int accID;
    int balance;
    char* cusName;
public:
    Account(int ID, int money, char* name)
        : accID(ID), balance(money)
    {
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

    int GetAccID() { return accID; }

    void Deposit(int money) {
        balance += money; 
    }

    int Withdraw(int money) {
        // 출금액 반환, 잔액보다 출금액이 클 때 0 반환
        if (balance < money)
            return 0;
        
        balance -= money;
        return money;
    }

    void ShowAccInfo() {
        cout << "계좌 ID: " << accID << endl;
        cout << "이름: " << cusName << endl;
        cout << "잔액: " << balance << endl<<endl;
    }

    ~Account() {
        delete []cusName;
    }
};


Account * accArr[100]; // Account 저장 배열
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
            cout << "잘못된 선택" << endl<<endl;
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
    int balance; // 입금액

    cout << "[계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {
    int id; // 계좌 ID
    int money; // 입금액

    cout << "[입금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "입금액: "; cin >> money;
    cout << endl;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl<<endl;
}

void WithdrawMoney(void) {
    int id; // 계좌 ID
    int money; // 출금액

    cout << "[출금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;
    cout << endl;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            if (accArr[i]->Withdraw(money) == 0) {
                cout << "잔액 부족입니다." << endl;
                cout << endl;
                return;
            }
            cout << "출금 완료" << endl << endl;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

