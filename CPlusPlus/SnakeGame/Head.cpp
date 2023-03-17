#include "Head.h"
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Body.h"

#include <conio.h>

// 1. ���ο� ������ ��������� ����� ������.
// 2. �Ӹ��� ���뿡 ������ ���� ������ �ǰ� ������.
// 3. q�� ������ ���������� ���� ���δ� ���ֿ�����/

Head::Head()
	: Part(L'��')
{
}

Head::~Head() 
{
}

void Head::Update() 
{
	if (true == GameEngineInput::GetIsInput())
	{
		int a = 0;
	}

	if (true == GameEngineInput::GetIsInput())
	{
		int Input = GameEngineInput::GetKey();
		int4 NextPos = GetPos();

		switch (Input)
		{

		case 'a':
		case 'A':
		{
			NextPos += {-1, 0};
			break;
		case 'd':
		case 'D':
		{
			NextPos += {1, 0 };
		}
		break;
		case 's':
		case 'S':
		{
			NextPos += { 0, 1 };
		}
		break;
		case 'w':
		case 'W':
		{
			NextPos += { 0, -1 };
		}
		break;
		break;
		case 'q':
		case 'Q':
			return;
		default:
			break;
		}
		}

		bool IsMove = true;

		// �÷��̾ ȭ�� �ٱ����� �����ٸ� �̵����� ���ϰ� �Ѵ�.
		// ȭ�� �ٱ����� �����ٸ�
		if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
		{
			// �̵��Ұ�
			IsMove = false;
		}

		// ���� 1, 1
		// ���� 2, 1

		if (true == IsMove)
		{
			// ���� �̵������ϱ� ���ֵ��� ����;���.
			Part* LastPart = GetLastPart();
			int4 PrevPos = LastPart->GetPos();

			LastPart->RecursionFrontMove();

			SetPos(NextPos);


			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				Body::GetCurBody()->SetPos(PrevPos);
				Body::GetCurBody()->SetRenderChar(L'��');
				LastPart->SetBack(Body::GetCurBody());
				Body::CreateBody();
			}
		}
	}



}