#pragma once
// #include "ClassB.h"
// #include "ClassA.cpp"


// ���漱��
// �̷� Ŭ������ �����ž�....
class ClassB;
class ClassA
{
public:
	// constrcuter destructer
	ClassA();
	~ClassA();

	// delete Function
	ClassA(const ClassA& _Other) = delete;
	ClassA(ClassA&& _Other) noexcept = delete;
	ClassA& operator=(const ClassA& _Other) = delete;
	ClassA& operator=(ClassA&& _Other) noexcept = delete;

	ClassB* ReturnBObject();

	void AFunction();
	//{
	//	// ����� �� �־�� �Ѵ�. 
	//	// Object->BFunction();
	//}

protected:

private:
	// �������� ������ �ֱ� ������.
	// ���������� ������ 
	ClassB* Object;

};

