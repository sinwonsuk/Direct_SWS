#include "Player.h"
#include <conio.h>

void Player::Update()
{
	// ���� 1. ȭ�� �ٱ����� �������� ���弼��.
	// ���� 2. �ܻ� ���켼��.

	// �̰� ���ص� �˴ϴ�.
	// �̰͵� ���ߴ�.
	// ���� 3. ���͸� 1���� ���弼��.
	// ���� 4. �Ѿ��� 1�� ���弼��
	// ���� 5. �Ѿ��� ���͸� ������ �Ѵ� ������� �ϼ���.

	// ������ ���� �� �������� �˷��ִ� �Լ�.
	// ��¥ ������ ��
	
	if (0 == _kbhit())
	{
		return;
	}

	// ���α׷� �Է��� �ö����� ������?
	int Input = _getch();

	Int4 NextPos = GetPos();

	switch (Input)
	{
	case 'a':
	case 'A':
		NextPos += {-1, 0};
		break;
	case 'd':
	case 'D':
		NextPos += {1, 0 };
		break;
	case 's':
	case 'S':
		NextPos += { 0, 1 };
		break;
	case 'w':
	case 'W':
		NextPos += { 0, -1 };
		break;
	default:
		break;
	}

	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]

	// ������ �ʾҴٸ�
	if (
		(NextPos.X >= 0) &&
		(NextPos.X < 5) &&
		(NextPos.Y >= 0) &&
		(NextPos.Y < 5) 
		)
	{
		SetPos(NextPos);
	}

}