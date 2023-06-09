﻿// 47.Destructer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test 
{
public:
    int Value;

public:
    // 소멸자라고 불리며
    // 객체의 메모리가 파괴될때 호출됩니다.
    ~Test() 
    {
    }
};

void Funct() 
{

}

Test NewTest0 = Test();

int main()
{
    // 함수의 정의와 구현은 => 이 함수를 실행하면 무슨일이 생길거야.
    // 코드영역에 들어가 있어.

    // 그 내용에 따라서 실행할때는 스택영에 메모리가 만들어 집니다.

    int Value;
    Test NewTest = Test();

    // 직접호출이 되는데 이걸 직접 호출하는 프로그램이나 회사는 일단 본적이 없다.
    Funct();

  // NewTest.~Test();  
} 

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
