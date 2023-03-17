#pragma once
#include "ContentsMath.h"

class Player 
{
public:
	// �ٲٱ� ���� ���
	void SetPos(const Int4& _Pos) 
	{
		Pos = _Pos;
	}

	void Move(const Int4& _Dir)
	{
		Pos += _Dir;
	}
	
	// �ܺο� �˷��ֱ⸸ �ϴ� ����� ��Ȯ�ϰ� ����
	Int4 GetPos()
	{
		return Pos;
	}

	wchar_t GetDisplayChar()
	{
		return DisplayChar;
	}

	void Update();

private:
	wchar_t DisplayChar = L'��';
	Int4 Pos;
};