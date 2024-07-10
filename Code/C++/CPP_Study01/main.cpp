// 비트 연산자를 이용해서 플레이어 상태 전환
// 각 비트가 1일때 해당 상태 ON, 0이면 OFF
#include <stdio.h>

#define Hungry		0x1
#define Thirsty		0x2
#define Tired		0x4
#define Hurt		0x8

#define Eating		0x10
#define Drinking	0x20
#define Sleeping	0x40
#define Healing		0x80

#define Starved		(0x1 | 0x2)
#define rest		(0x40 | 0x80)

int main() 
{
	unsigned int State = 0;

	State |= Hungry;
	State |= Thirsty;
	//State |= Tired;
	//State |= Hurt;

	printf("%d %d %d\n", Hungry, Thirsty, Starved);

	while (State) {
		int input = 0;
		printf("State: %d\n", State);
		if (State == Starved) {		printf("배고프고 목마른 상태입니다.\n"); }	//&로 하면 비트가 하나만 1이여도 true가 되어버림
		else {
			if (State & Hungry)		printf("배고픈 상태입니다.\n");
			if (State & Thirsty)	printf("목마른 상태입니다.\n");
		}
		if (State & Tired)		printf("피곤한 상태입니다.\n");
		if (State & Hurt)		printf("다친 상태입니다.\n");

		printf("실행할 행동을 고르세요 1. 식사, 2. 물마시기, 3. 자기, 4. 치료: ");
		scanf_s(" %d", &input);

		switch (input)
		{
		case 1:
			State |= Eating; break;
		case 2:
			State |= Drinking; break;
		case 3:
			State |= Sleeping; break;
		case 4:
			State |= Healing; break;
		default:
			break;
		}
		
		if (State & Eating)		{ printf("식사 중 입니다.\n"); State &= ~(Eating | Hungry); }
		if (State & Drinking)	{ printf("물 마시는 중 입니다.\n"); State &= ~(Drinking | Thirsty); }
		if (State & Sleeping)	{ printf("자는 중 입니다.\n"); State &= ~(Sleeping | Tired); }
		if (State & Healing)	{ printf("치료받는 중 입니다.\n"); State &= ~(Healing | Hurt); }
		printf("==== State: %d ====\n", State);
	}

	return 0;
}