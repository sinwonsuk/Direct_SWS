#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
StudyGameCore StudyGameCore::Core;

StudyGameCore::StudyGameCore() 
{
}

StudyGameCore::~StudyGameCore() 
{
}

void StudyGameCore::Start()
{
	// GameEngineDebug::LeakPointBreak(557);
	new int();

	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
	GameEngineWindow::SettingWindowSize({1280, 960});


	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	ChangeLevel("TitleLevel");
}

void StudyGameCore::Update()
{
	
}
void StudyGameCore::End() 
{
	
}