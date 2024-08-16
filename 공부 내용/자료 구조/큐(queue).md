# 큐(Queue)
## 큐(Queue) 란?
줄을 선것 처럼 먼저 들어온 데이터 순서대로 데이터가 나가는 구조를 가진 자료구조

## 큐의 연산
- push : 맨 뒤에 데이터를 삽입하는 연산
- pop : 맨 앞에 있는 데이터를 꺼내는 연산
- front : 가장 앞에 있는 데이터를 반환하는 연산
- back : 가장 뒤에 잇는 데이터를 반환하는 연산
- size : 큐의 크기(들어있는 데이터의 개수)를 반환하는 연산
- empty : 큐에 아무 데이터도 없는지 반환하는 연산

## 큐의 특징
1. 선입선출의 특징 (First In, First Out - FIFO)
2. Front 에서만 데이터 추출, Rear 에서만 데이터 삽입이 가능하다.

### 선입선출(FIFO)
![queue drawio](https://github.com/user-attachments/assets/a0cbfe8a-ee0f-48e2-96fb-783c1e2c4043)

데이터가 들어오는 부분을 rear, 데이터가 나가는 부분을 front 라고 함.

데이터 넣는 것을 enqueue, 데이터 빼는 것을 dequeue 라고 함.

데이터를 여러개 push 할 시 rear 로 데이터가 순서대로 들어가면 front 부터 순서대로 데이터가 pop 된다.
