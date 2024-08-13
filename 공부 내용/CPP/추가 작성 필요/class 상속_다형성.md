# class 상속
## 다형성
상속한 class 의 경우 한가지 타입으로 다양한 형태를 나타낼 수 있다.

### 상속 구조 + 포인터
```
class Parent { ~~~ }

class Child : public Parent { ~~~ }

int main()
{
  Parent p;
  Parent* pParent = &p;
  Child c;
  Child* pChild = &c;

  pParent = &c;
}
```
부모 클래스 포인터 타입 변수로 자식 클래스 객체의 주소를 받을 수 있다.

반대로 자식 클래스 포인터는 부모 클래스 객체를 포인터로 받을 수 없다.

- [  부모  ]
- [  부모  |  자식  ]

다음과 같이 메모리가 되어있어 부모로는 자식을 받을 수 있지만 자식이 부모를 받을 경우 할당된 메모리보다 뒤에 메모리도 참조하기 때문에 에러 발생

### 오버라이딩 + 다형성
```
class Parent
{
~~~
public:
  void Output() { cout << "Parent" << endl }
}

class Child : public Parent
{
~~~
public:
  void Output() { cout << "Child" << endl }
}

int main()
{
  Child c;
  Parent* pParent = nullptr;
  pParent = &c;

  pParent->Output();  // Parent
}
```
다음과 같이 부모 클래스의 포인터 변수로 자식 클래스 객체의 주소를 받아 함수를 호출할 시 오버라이딩한 자식 클래스의 함수가 아닌 부모클래스의 함수가 호출된다.

이 경우 가상 함수를 사용해서 부모 클래스의 함수가 아닌 오버라이딩한 자식 클래스의 함수가 호출되게 할 수 있다.

## 가상 함수 (Virtual Function)
### 가상 함수란
### 가상 함수 선언
### 순수 가상 함수
### 가상 함수의 구동 원리
### 추상 클래스
### 가상 소멸자
