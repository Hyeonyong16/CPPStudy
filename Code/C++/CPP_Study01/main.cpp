// ��Ʈ �����ڸ� �̿��ؼ� �÷��̾� ���� ��ȯ
// �� ��Ʈ�� 1�϶� �ش� ���� ON, 0�̸� OFF
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
		if (State == Starved) {		printf("������� �񸶸� �����Դϴ�.\n"); }	//&�� �ϸ� ��Ʈ�� �ϳ��� 1�̿��� true�� �Ǿ����
		else {
			if (State & Hungry)		printf("����� �����Դϴ�.\n");
			if (State & Thirsty)	printf("�񸶸� �����Դϴ�.\n");
		}
		if (State & Tired)		printf("�ǰ��� �����Դϴ�.\n");
		if (State & Hurt)		printf("��ģ �����Դϴ�.\n");

		printf("������ �ൿ�� ������ 1. �Ļ�, 2. �����ñ�, 3. �ڱ�, 4. ġ��: ");
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
		
		if (State & Eating)		{ printf("�Ļ� �� �Դϴ�.\n"); State &= ~(Eating | Hungry); }
		if (State & Drinking)	{ printf("�� ���ô� �� �Դϴ�.\n"); State &= ~(Drinking | Thirsty); }
		if (State & Sleeping)	{ printf("�ڴ� �� �Դϴ�.\n"); State &= ~(Sleeping | Tired); }
		if (State & Healing)	{ printf("ġ��޴� �� �Դϴ�.\n"); State &= ~(Healing | Hurt); }
		printf("==== State: %d ====\n", State);
	}

	return 0;
}