// ���� ���� ���� ���α׷�
// �䱸�Ǵ� ���
// 1. ���� ����(CreateAccount) 2. �Ա�(Deposit) 3. ���(Withdraw) 4. ��ü �� �ܾ� ��ȸ(Inquire)
//
// ���ѻ���
//- ID(���¹�ȣ)�� �ߺ����� �ʴ´�. (���� ���� �� �ߺ��Ǵ� ���� ��ȣ�� �Է��� ���� ���̶�� �����Ѵ�)
//- �Ա� �� ��ݾ��� �׻� 0���� ũ��(���� �׻� 0 �̻��� ���� �Է� �� ���̶�� �����Ѵ�)
//- �� ���¿� ���� �������� ���¹�ȣ(int id), �� �̸�(char* name), ���� �ܾ�(int balance), �̷��� 3���� ������ ���� �� �����Ѵ�.
//- ���� ���� ������ ���� �ڷᱸ���� �迭(Array)�� ����Ѵ�. �迭�� ũ��� ������ �����Ѵ�(��: 100)
//- �迭�� ����Ǵ� Ÿ���� Ŭ���� �����͸� ����Ѵ�.
//- ���� ���� ������ ���� Ŭ������ �̸��� Account�� �ϰ�, ���� ������ ����ϴ� Ŭ������ �̸��� Bank�� ����.

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