# 조건문

## if문
```
if(조건)
{
  실행할 내용
}
```
조건의 값이 false(0)가 아닐 경우 실행

```
if(조건)
{ }
else if(조건)
{ }
else
{ }
```
위의 if 값이 false일 경우 else if, else 순차적으로 진행
1. if 값이 false가 아님 > 실행 후 else보다 밑으로, false임 > else if문으로
2. else if 값이 false가 아님 > 실행 후 else보다 밑으로, false임 > 뒤의 else if문 또는 없으면 else문으로
3. 위에 조건이 다 아니면 else 실행

## switch문
```
switch(변수)
{
case 1:
case 2:
  break;    //1, 2일 경우
...
default:    //다 아닐경우
  break;
}
```
변수에 해당하는 case를 실행
1. 케이스 여러개를 붙이면 한번에 실행
2. 모든 경우가 아닐경우 default케이스 실행
3. 각 조건은 break로 끝내줘야 함

## enum
enum 열거형 > 4바이트 정수
```
enum STATE    //STATE라는 이름의 열거형 생성
{
  A,  // 0
  B,  // 1
  C,  // 2
}

int main()
{
  STATE 변수명 = A  // 변수명 STATE에 A라는 값 할당
}
```

enum 내부 내용들은 0부터 시작이지만 원하는 값을 넣어 설정 가능
```
enum STATE
{
  A = 3,   // 3
  B,       // 4
  C, = 10  // 10
}
```

초기화 시 STATE:: 부분을 생략할 수 있지만 다른 enum에서 동일한 이름으로 선언 시 중복되서 문제가 생길 수 있음
```
enum class STATE
{
  A,
  B,
  C,
}

int i = (int)STATE::A;
```
enum 과 변수명 사이에 class를 넣어서 방지 가능

class를 넣을 시 앞에 ::(Scope)를 통해 지정해주어야 함

enum class로 선언한 열거형은 일반 정수 변수에 값을 대입할 수 없어 강제 캐스팅 해줘야 함.
