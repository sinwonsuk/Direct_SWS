#pragma once
// #include "ClassA.h"

// ���漱��
// �������̶�� �ؼ� �ƹ��͵� �����൵ �Ǵ°� �ƴϰ�
// Ŭ������ ����� �˷���� �Ѵ�.
class ClassA;
class ClassB
{
public:
	// constrcuter destructer
	ClassB();
	~ClassB();

	// delete Function
	ClassB(const ClassB& _Other) = delete;
	ClassB(ClassB&& _Other) noexcept = delete;
	ClassB& operator=(const ClassB& _Other) = delete;
	ClassB& operator=(ClassB&& _Other) noexcept = delete;

	void BFunction()
	{

	}

protected:

private:
	ClassA* Object;
};

