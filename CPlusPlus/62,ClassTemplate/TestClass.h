#pragma once

// ���� :
template<typename DataType>
class TestClass
{
public:
	// constrcuter destructer
	TestClass();
	~TestClass();

	// delete Function
	TestClass(const TestClass& _Other) = delete;
	TestClass(TestClass&& _Other) noexcept = delete;
	TestClass& operator=(const TestClass& _Other) = delete;
	TestClass& operator=(TestClass&& _Other) noexcept = delete;

	// ���ø� Ŭ������ �Լ��� ������� �����ؾ߸� �Ѵ�.
	void Func() {

	}

protected:

private:
	DataType Value;

};

