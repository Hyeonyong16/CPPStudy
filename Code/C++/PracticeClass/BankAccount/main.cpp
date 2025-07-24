// 은행 계좌 관리 프로그램
// 요구되는 기능
// 1. 계좌 개설(CreateAccount) 2. 입금(Deposit) 3. 출금(Withdraw) 4. 전체 고객 잔액 조회(Inquire)
//
// 제한사항
//- ID(계좌번호)는 중복되지 않는다. (계좌 개설 시 중복되는 계좌 번호의 입력이 없을 것이라고 가정한다)
//- 입금 및 출금액은 항상 0보다 크다(고객이 항상 0 이상의 값만 입력 할 것이라고 가정한다)
//- 고객 계좌에 대한 정보에는 계좌번호(int id), 고객 이름(char* name), 고객의 잔액(int balance), 이렇게 3가지 정보만 저장 및 관리한다.
//- 계좌 정보 관리를 위한 자료구조는 배열(Array)을 사용한다. 배열의 크기는 적당히 설정한다(예: 100)
//- 배열에 저장되는 타입은 클래스 포인터를 사용한다.
//- 계좌 정보 저장을 위한 클래스의 이름은 Account로 하고, 계좌 관리를 담당하는 클래스의 이름은 Bank로 하자.

#include <iostream>
#include "Bank.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(216);

	Bank bank;
	bank.Run();

	std::cin.get();
}