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

	// 1번 계산기 문제
	if (1 == qNum)
	{
		Calculator calculator;

		std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
		std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
		std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
		std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

		calculator.ShowOperationCount();
	}

	// 2번 Printer 문제
	if (2 == qNum)
	{
		Printer printer;
		printer.ShowString();

		printer.SetString("Hello C++");
		printer.ShowString();

		printer.SetString("I Want to be a Good Developer");
		printer.ShowString();
	}

	// 3번 사각형, 원 문제
	if (3 == qNum)
	{
		Rectangle rect = Rectangle(3, 4);    // Rectangle(가로길이, 세로길이)
		std::cout << "면적: " << rect.GetArea() << "\n";
		std::cout << "둘레: " << rect.GetGirth() << "\n";

		Circle circle = Circle(5);    // Circle(원의 반지름)
		std::cout << "면적: " << circle.GetArea() << "\n";
		std::cout << "둘레: " << circle.GetGirth() << "\n";
	}

	// 4번 명함 정보 저장 문제
	if (4 == qNum)
	{
		//NameCard* nameCards[3];
		//char* input = nullptr;
		//for (int i = 0; i < 3; ++i)
		//{
		//	//std::cout
		//	//nameCards
		//}
		// NameCard (이름, 전화번호, 이메일, 직업)
		NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
		NameCard jang2 = NameCard(jang);
		jang2.ShowData();
	}

	std::cin.get();
}