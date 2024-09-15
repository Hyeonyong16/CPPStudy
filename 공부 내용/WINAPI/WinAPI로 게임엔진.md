# WinAPI 게임 엔진 로직

1. main
    - 메시지 처리
    - CEngine - Progress
2. CEngine - Progress
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
      4. SecondBitmap에 있는 장면을 MainWindowBitmap 으로 복사
    - TaskMgr 동작
      1. CTaskMgr - Tick
