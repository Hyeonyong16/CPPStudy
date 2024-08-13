# 중첩 클래스 (inner class)
클래스의 내부에 선언된 또 하나의 클래스

새로운 클래스에 사용범위를 제공

## 선언 방법
```
class Out
{
private:
  int m_Out;

public:
  class In      // inner class
  {
  private:
    int m_In; 
  };
};

int main()
{
  Out     out;
  In      in1;  // 컴파일 에러
  Out::In in2;  // 중첩 클래스로 객체 생성
}
```
클래스의 내부에 추가로 클래스 생성

inner class 에 대한 접근 제한 지정자의 영향도 동일하게 받는다.(private, protected, public)

단 public일 경우 외부에 inner class 로 객체를 생성할 시 포함된 클래스에 범위지정 연산자(::)로 접근하여 생성하여야 함.

위 class 에서 확인 시 In 클래스의 선언이 Out 클래스의 안에 있을 뿐 각각 크기는 4바이트이다 (각각 int 형 자료형 1개씩 있음)

## 특징
- 해당 클래스를 접근하기 위해서는 포함클래스의 이름을 적고 범위지정 연산자로 접근하여야 함
- 클래스 명이 다른 클래스명과 겹치지 않을 수 있음.
  - 각 클래스마다 동일한 이름의 inner class 를 가질 수 있음. (ex - iterator)
- 이너 클래스가 포함되어있는 클래스와 연관이 있다는 것을 알 수 있다.
- 이너 클래스가 포함되어있는 클래스의 private 멤버에 접근이 가능하다.
  - 반대로 포함하고 있는 클래스가 포함되어있는 클래스에 대해 특별한 접근 권한이 부여되지는 않는다.
