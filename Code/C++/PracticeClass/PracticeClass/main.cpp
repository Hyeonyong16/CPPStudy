#include <iostream>
#include "Calculator/Calculator.h"
#include "Printer/Printer.h"
#include "Diagram/Rectangle.h"
#include "Diagram/Circle.h"
#include "NameCard/NameCard.h"

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

	int qNum = 1;

	// 1�� ���� ����
	if (1 == qNum)
	{
		Calculator calculator;

		std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
		std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
		std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
		std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

		calculator.ShowOperationCount();
	}

	// 2�� Printer ����
	if (2 == qNum)
	{
		Printer printer;
		printer.ShowString();

		printer.SetString("Hello C++");
		printer.ShowString();

		printer.SetString("I Want to be a Good Developer");
		printer.ShowString();
	}

	// 3�� �簢��, �� ����
	if (3 == qNum)
	{
		Rectangle rect = Rectangle(3, 4);    // Rectangle(���α���, ���α���)
		std::cout << "����: " << rect.GetArea() << "\n";
		std::cout << "�ѷ�: " << rect.GetGirth() << "\n";

		Circle circle = Circle(5);    // Circle(���� ������)
		std::cout << "����: " << circle.GetArea() << "\n";
		std::cout << "�ѷ�: " << circle.GetGirth() << "\n";
	}

	// 4�� ���� ���� ���� ����
	if (4 == qNum)
	{
		//NameCard* nameCards[3];
		//char* input = nullptr;
		//for (int i = 0; i < 3; ++i)
		//{
		//	//std::cout
		//	//nameCards
		//}
		// NameCard (�̸�, ��ȭ��ȣ, �̸���, ����)
		NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
		NameCard jang2 = NameCard(jang);
		jang2.ShowData();
	}

	std::cin.get();
}