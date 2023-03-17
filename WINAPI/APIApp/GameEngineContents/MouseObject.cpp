#include "MouseObject.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

MouseObject::MouseObject() 
{
}

MouseObject::~MouseObject() 
{
}

void MouseObject::Start() 
{
	MouseRender = CreateRender();
	MouseCollision = CreateCollision();

	if (nullptr == MouseRender)
	{
		MsgAssert("�������� ��������� �ʾҽ��ϴ�.");
	}

	if (nullptr == MouseCollision)
	{
		MsgAssert("�ݸ����� ��������� �ʾҽ��ϴ�.");
	}
}

void MouseObject::Update(float _DeltaTime) 
{
	SetPos(GetLevel()->GetMousePos());
}