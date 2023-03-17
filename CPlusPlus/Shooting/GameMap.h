#pragma once
#include "ContentsMath.h"

class GameMap 
{

public:
	void Clear();
	void Render();
	void Init(const wchar_t _BaseChar);
	void SetTile(const Int4& _Pos, wchar_t _Char);

private:
	// ������ 2����Ʈ ¥�� ���ڶ�� ������ �̴ϴ�.
	wchar_t BaseChar;
	wchar_t ArrTile[5][6];
	
};
