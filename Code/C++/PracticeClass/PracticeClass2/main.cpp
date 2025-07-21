#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Person
{
public:
	Person()
		: age(0), name(nullptr)
	{
	}

	Person(int _age, const char* _name)
		: age(_age)
	{
		size_t length = strlen(_name) + 1;
		name = new char[length];
		strcpy_s(name, length, _name);
	}

	~Person()
	{
		if (nullptr != name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	int GetAge() const { return age; }
	const char* GetName() const { return name; }

	void ShowData()
	{
		std::cout << "이름: " << name << "\n"
			<< "나이: " << age << "\n";
	}

private:
	int age = 0;
	char* name = nullptr;
};

class Student : public Person
{
public:
	Student()
		: Person(), major(nullptr)
	{ 
	}

	Student(int _age, const char* _name, const char* _major)
		: Person(_age, _name)
	{
		size_t length = strlen(_major) + 1;
		major = new char[length];
		strcpy_s(major, length, _major);
	}

	Student(const Student& _origin)
		:Person(_origin.GetAge(), _origin.GetName())
	{
		size_t length = strlen(_origin.major) + 1;
		major = new char[length];
		strcpy_s(major, length, _origin.major);
	}

	~Student()
	{
		if (nullptr != major)
		{
			delete[] major;
			major = nullptr;
		}
	}

	void ShowData()
	{
		std::cout << "이름: " << GetName() << "\n"
			<< "나이: " << GetAge() << "\n"
			<< "전공: " << major << "\n";
	}

private:
	char* major = nullptr;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(216);

	Student Jang1 = Student(20, "Jang Se Yun", "Computer Science");
	Jang1.ShowData();

	Student Jang2 = Jang1;
	Jang2.ShowData();

	std::cin.get();
}