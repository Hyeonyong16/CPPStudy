# 비트 연산자

```
n << m    //n의 비트를 왼쪽으로 m 만큼 밀기
ex) 12 << 3 -> 0000 1100 -> 0110 0000

n >> m    //n의 비트를 오른쪽으로 m 만큼 밀기
```
MSB(부호 판별 비트)는 밀리지 않는다

---
```
n & m    //n, m 둘 다 같은 위치 비트가 1일 경우 1
ex) 12 & 20 -> 0000 1100 & 0001 0100 -> 0000 0100 == 4

n | m    //n, m 둘 중 같은 위치 비트가 하나라도 1일 경우 1
ex) 12 | 20 == 0000 1100 | 0001 0100 -> 0001 1100 == 28

n ^ m    //n, m 둘 중 같은 위치 비트가 다를경우 1
ex) 12 ^ 20 == 0000 1100 ^ 0001 0100 -> 0001 1000 == 24

~n       //각 자리 비트 반전
ex) ~12 == ~ 0000 1100 -> 1111 0011 == -13
```
