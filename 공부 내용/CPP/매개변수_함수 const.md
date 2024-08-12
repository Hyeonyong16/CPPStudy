# const 
## 변수의 const
[const 관련 내용](https://github.com/Hyeonyong16/CPPStudy/blob/master/%EA%B3%B5%EB%B6%80%20%EB%82%B4%EC%9A%A9/CPP/%ED%8F%AC%EC%9D%B8%ED%84%B0%202.md)

## 함수의 const
```
class CData
{
private:
	int			  m_i;
	long long	m_ll;

public:
	void SetInt(int _i) { m_i = _i; }
	int GetInt() const { return m_i; }
  long long GetLongLong() { return m_ll; }

public:
	CData operator+(const CData& _Other) const	
	{											
		CData data;								
		data.m_i = m_i + _Other.m_i;
		data.m_ll = m_ll + _Other.m_ll;

		return data;
	}
~~~
};

bool operator==(int _Data, const CData& _Inst)
{
	return _Data == _Inst.GetInt();
}
```

### 함수명 뒤에 const
  - 객체 내부에 속한 함수에만 붙일수 있다.
  - 해당 키워드가 붙은 함수는 해당 멤버함수를 호출한 객체의 멤버 변수를 수정할 수 없다.

```
CData operator+(const CData& _Other) const	
{											
  CData data;								
  data.m_i = m_i + _Other.m_i;
  data.m_ll = m_ll + _Other.m_ll;

	return data;
}
```
CData 객체 내 해당 const 함수를 보면 내부에서 멤버변수의 값을 바꿀수 없다.

그래서 CData 객체를 하나 생성해서 해당 객체의 값을 넘겨주는 형태

### 매개변수로의 const
  - 해당 매개변수의 값을 바꿀 수 없다.
  - 객체를 const & 로 받을 시 해당 객체의 const 멤버함수만 호출이 가능
```
bool operator==(int _Data, const CData& _Inst)
{
  long long ll = _Inst.GetLongLong();  // 컴파일 에러
	return _Data == _Inst.GetInt();
}
```
해당 함수에서 CData를 const & 형태로 매개변수로 받아왔기에 CData 의 const 멤버함수만 호출이 가능하다.

GetLongLong 함수는 const 멤버함수가 아니기 때문에 컴파일 에러가 발생한다.
