# WinAPI 게임 엔진 로직

1. main
    - CEngine - Init
      1. 윈도우 생성
      2. 윈도우 출력
      3. DC, GDIObject 생성
      4. 매니저 생성 및 초기화
         - CPathMgr
         - CTimeMgr
         - CKeyMgr
         - CLevelMgr
      5. 더블 버퍼링을 위한 추가 버퍼 생성
    - 메시지 루프
    - CEngine - Progress
3. CEngine - Progress
    - 매니저의 Tick 실행
      1. CTimeMgr - Tick
      2. CKeyMgr - Tick
      3. CDbgRender - Tick
    - 레벨 실행
      1. CLevelMgr - Progress
    - 충돌 검사 실행
      1. CCollisionMgr - Tick
    - 렌더링
      1. 화면 클리어
      2. 레벨 렌더링
      3. 디버그 정보 렌더링
      4. SecondBitmap에 있는 장면을 MainWindowBitmap 으로 복사 (더블 버퍼링)
    - TaskMgr 동작
      1. CTaskMgr - Tick

메세지 입력이 없으면 Progress 과정을 반복

## CTimeMgr Tick()
링크 넣어야 함 []

프레임 간격 시간인 DT 를 구함
## CKeyMgr Tick()
링크 넣어야 함 []

키입력 처리
## CDbgRender Tick()
링크 넣어야 함 []

디버그 정보를 표시
## CLevelMgr Progress()
링크 넣어야 함 []

1. 현재 실행중인 Level의 Tick 실행
2. 현재 실행중인 Level의 FianlTick 실행
## CCollisionMgr Tick()
링크 넣어야 함 []

1. Layer 를 이용한 Layer 간 충돌 검사
2. Layer에 해당하는 현재 오브젝트 오브젝트의 충돌 검사
## 화면 클리어
링크 넣어야 함 []

Rectangle 을 이용해서 화면 Clear
## CLeveMgr Render()
링크 넣어야 함 []

1. 현재 실행중인 Level 의 Render 실행
## CDbgRender Render()
링크 넣어야 함 []

디버그 렌더링 해야할 정보에 따른 디버그 요소들 Render
## 더블 버퍼링
링크 넣어야 함 []

SecondBitmap 에 Render 한 정보들을 MainWindowBitmap 에 BitBlt를 사용해 옮김
## CTaskMgr Tick()
링크 넣어야 함 []

입력받은 TASK_TYPE에 따라 Task 처리
