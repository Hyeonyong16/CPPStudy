# CEngine
게임의 최상위 관리자

게임 내 요소의 초기화 및 메인 Progress 를 진행

싱글톤 패턴을 사용해서 하나만 생성되도록 한다.

## 변수
```
HINSTANCE    m_hInst;
HWND         m_hWnd;
Vec2         m_Resolution;
HDC          m_hDC;

HDC          m_hSecondDC;
HBITMAP      m_hSecondBitmap;

HPEN         m_Pen[(UINT)PEN_TYPE::END];
HBRUSH       m_Brush[(UINT)BRUSH_TYPE::END];
```

- m_hInst
  - 메인 윈도우 생성 시 인스턴스 주소를 저장하기 위한 변수
- m_hWnd
  - 메인 윈도우 생성 후 윈도우 핸들을 저장
- m_Resolution
  - 메인 윈도우의 해상도
  - Vec2 는 float형 변수 두개(x, y) 로 이루어진 변수
- m_hDC
  - Main DC(Device Context) 를 저장
- m_hSecondDC
  - 더블 버퍼링으로 생성된 두번째 버퍼에 그림을 그리도록 한 DC
- m_hSecondBitmap
  - 더블 버퍼링을 위한 두번째 비트맵 버퍼
- m_Pen[(UINT)PEN_TYPE::END]
- m_Brush[(UINT)BRUSH_TYPE::END]
  - GDI Object 로 생성한 Pen 과 Brush 를 저장해둘 변수
  - 각 Pen, Brush의 Type 을 enum으로 생성하고 마지막에 END 로 두어 총 펜의 개수를 END 로 표시
    
## 함수
```
public:
	HWND GetMainWndHwnd()
	Vec2 GetResolution()
	HPEN GetPen(PEN_TYPE _Type)
	HBRUSH GetBrush(BRUSH_TYPE _Type)
	HDC GetMainDC()
	HDC GetSecondDC()

	void ChangeWindowSize(Vec2 _vResolution);

public:
	int Init(HINSTANCE _Inst, POINT _Resolution);
	void Progress();

private:
	void CreateGDIObject();
	void CreateSecondBuffer();
```
- HWND GetMainWndHwnd()
  - 메인 윈도우의 핸들을 반환해주는 함수
- Vec2 GetResolution()
  - 화면 해상도를 반환해주는 함수
- HPEN GetPen(PEN_TYPE _Type)
- HBRUSH GetBrush(BRUSH_TYPE _Type)
  - 입력 변수로 들어온 Type의 Pen, Brush을 반환해주는 함수
- HDC GetMainDC()
- HDC GetSecondDC()
  - Main, Second DC 를 반환해주는 함수

### void ChangeWindowSize(Vec2 _vResolution)
### void CreateGDIObject()
### void CreateSecondBuffer()
### int Init(HINSTANCE _Inst, POINT _Resolution)
### void Progress()
