﻿// 01.Program.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 비주얼 스튜디오에서 F5를 누르면
// 컴파일 혹은 빌드라는 과정(지금은 몰라도 됨)이 벌어지게 되고
// .exe가 나오게 된다.
// 그렇게 하드디스크에 나와있는 파일을 프로그램이라고 합니다.

// 첫번째 프로그램의 개념
// 절대로 하드디스크에서 실행되는것이 아닙니다.
// 하드디스크 exe 파일을 더블클릭하면 프로그램이 실행됩니다.
// 프로그램이 실행되면 그 프로그램은 RAM에 복사가 되고.
// 그 복사된 프로그램이 실행된다고 하는것이고.
// 이때 이 ram에 복사되어 실행되는 프로그램을
// 프로세스라고 부릅니다.

// 이 프로그램이 프로세스가 되면 c++의 개념으로는
// 메모리등을 직접적으로 다 관리해줘야 하기 때문에 c++의 난이도가 높고
// 기본적으로 os가 

#include <iostream>
#include <conio.h>

int main()
{
	// 프로그램은 간단히 말해서
	// 이 내부의 내용을 이렇게이렇게 할거야.
	// 설계도와 같은 것.
	// 계획서와 같은 내용이다.
	// 플레이어를 만들거야.
	// 몬스터를 만들거야.
	// 스킬이 있을거야.

	// 램에 올라가면
	// 진짜 이제 cpu와 os같은 애들에게 부탁해서
	// 진짜 공장을 만들고 플레이어를 만들고 스킬을 만드는거야.
	// 그렇게 되면 당연히 진짜 공장의 부지와 공장을 만들돈(Ram메모리)등이 필요하기 때문에.
	// 무조건적으로 프로그램보다 프로세스의 메모리가 더 크게 잡힐수밖에 없는거에요.

	// 질문1.
	// 게임의 용량이 더 클때가 있는데. 왜 ram에는 다 안올라가나요?
	// 지금 유저가 경험해야할 것만 올릴수 있습니다.

	// 질문2. 하드디스크의 용량이 대체왜? 프로그램의 실행속력과 연관이 있나요?
	// 프로그램이 ram만 쓰는것은 아닙니다.
	// 하드를 쓸대가 있는데.
	// 공짜가 없어요.

	1 + 1;

	printf_s("다른 프로그램을 실행시킬수 있는 함수는 system이라고 합니다");

	_getch();

	//while (true)
	//{

	//}

	return 100002;
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
