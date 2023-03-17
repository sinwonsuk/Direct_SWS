#pragma once
#include "ConsoleGameMath.h"

// ���� :
class ConsoleGameObject
{
public:
	// constrcuter destructer
	ConsoleGameObject();
	~ConsoleGameObject();

	// delete Function
	ConsoleGameObject(const ConsoleGameObject& _Other) = delete;
	ConsoleGameObject(ConsoleGameObject&& _Other) noexcept = delete;
	ConsoleGameObject& operator=(const ConsoleGameObject& _Other) = delete;
	ConsoleGameObject& operator=(ConsoleGameObject&& _Other) noexcept = delete;


	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(const int4& _Value)
	{
		Pos = _Value;
	}

	void SetRenderChar(wchar_t _Value)
	{
		RenderChar = _Value;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

	void Render();

	bool GetIsUpdate()
	{
		return IsUpdate;
	}

	void On() 
	{
		IsUpdate = true;
	}

	void Off() 
	{
		IsUpdate = false;
	}

private:
	bool IsUpdate = true; // true ����.
	               // false �Ⱦ���.

	int4 Pos = { 0,0 };
	wchar_t RenderChar = L'��';
};

