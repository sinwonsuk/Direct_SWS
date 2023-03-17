#include "Part.h"

Part::Part() 
{
}

Part::Part(wchar_t _Renderchar) 
	: ConsoleGameObject(_Renderchar)
{

}

Part::~Part() 
{
}


void Part::Update() 
{

}

void Part::RecursionFrontMove()
{
	// �ǵڿ��� ȣ��ƴٰ� ġ��.

	if (nullptr == Front)
	{
		return;
	}

	SetPos(Front->GetPos());

	return Front->RecursionFrontMove();
}

void Part::RecursionBackRender()
{
	Render();

	if (nullptr == Back)
	{
		return;
	}

	return Back->RecursionBackRender();
}
