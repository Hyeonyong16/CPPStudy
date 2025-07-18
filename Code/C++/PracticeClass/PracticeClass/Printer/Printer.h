#pragma once

// Printer 는 두 가지 기능 제공
// 1. 문자열을 설정
// 2. 설정된 문자열 출력
// 2-1. 문자열이 설정되지 않았으면 ‘Can’t show the string value’이라는 오류를 발생
class Printer
{
public:
	Printer();
	~Printer();

	void ShowString();						// 문자열 출력
	void SetString(const char* _str);		// 문자열 설정

private:
	char* str;
};

