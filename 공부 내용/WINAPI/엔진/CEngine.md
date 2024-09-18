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
    
---
### void ChangeWindowSize(Vec2 _vResolution)
메인 윈도우의 해상도를 변경하는 입력받은 값으로 변경하는 함수

메인 윈도우에 메뉴가 있으면 해당 메뉴를 제외한 출력되는 부분의 해상도가 입력받은 해상도로 되게 값을 계산하여 설정한다.

---
### void CreateGDIObject()
사용할 GDI Object 객체들을 미리 생성해놓는 함수

Brush 와 Pen 을 미리 선언해둔 각 배열에 생성하여 미리 선언했던 brush, pen type(enum) 에 맞게 넣어준다.

---
### void CreateSecondBuffer()
더블 버퍼링을 하기 위해 Second Buffer 를 생성하는 함수

윈도우 Bitmap 과 동일한 해상도의 Second Bitmap 을 생성

Second DC를 생성한 후 해당 DC 에 SecondBitmap을 SelectObject 로 선택

SelectObject 하면서 나온 기존 Bitmap 은 삭제

---
### int Init(HINSTANCE _Inst, POINT _Resolution)
실행 시 최초 초기화 부분을 담당한다.

1. 메인 윈도우 생성 및 표시
   - 메인 윈도우 생성에 실패 시 E_FAIL 을 반환
   - E_FAIL 반환 시 main 함수에서 Engine 초기화 실패로 인해 FALSE 를 반환하여 프로그램이 종료됨
2. 메인 윈도우 해상도 변경
3. DC, GDIObject 생성
4. 각 Manager 생성 및 초기화
5. 더블 버퍼링을 위한 추가 버퍼 생성
6. 초기화 완료 시 S_OK 를 반환

---
### void Progress()
1프레임 동안 실행되는 로직
1. 각 Manager 의 Tick을 실행
   - Time : DT 를 계산
   - Key : 각 키의 현재 상태를 기록
   - Debug Render : 디버그 정보 표시 여부를 결정
2. Level Manager 를 통해 레벨 실행
3. Collision Manager 를 통해 충돌 검사 실행
4. 렌더링을 위해 현재 화면 클리어
   - 해상도보다 x, y 로 1픽셀 더 큰 사각형을 그려 화면 클리어
5. Level Manager 를 통해 레벨을 렌더링
6. Debug Render Manager 를 통해 디버그 정보를 렌더링
7. Second Bitmap에 그려진 내용을 Main Window Bitmap 으로 복사 (더블 버퍼링)
8. Task Manager 를 통해 이번 프레임에 생긴 Task 를 가장 마지막에 처리 (오브젝트 생성, 삭제, 레벨 변경 등)

#### Task Manager 를 가장 마지막에 실행하는 이유
중간에 오브젝트 생성이나 삭제가 일어난다면 오브젝트 생성 전 Tick을 실행한 오브젝트의 경우 새로 생성되거나 삭제된 오브젝트를 인식하지 못함

이러한 상황을 방지하기 위해 가장 마지막에 Task Maanger 의 Tick을 실행시켜 다음 Progress 실행 시 오브젝트가 추가된 상태에서 실행되게 한다.
