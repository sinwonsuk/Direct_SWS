#pragma once


// ���� :
class Monster
{
private:
	// ������Ʈ���� �и��Ǿ� �ְ� �����Ϳ����� ���������.
	static int AllMonsterCount;

public:
	static int /*__stdcall*/ GetAllMonsterCount()
	{
		// this�� �����Ҽ� �����ϴ�.
		// this;

		return AllMonsterCount;
	}

public:
	// constrcuter destructer
	Monster();
	~Monster();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void __thiscall Func() {

	}

protected:

private:
	int Hp;

};

