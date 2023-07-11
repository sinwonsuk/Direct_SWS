#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineCore\GameEngineCore.h>
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "giantStageLevel.h"
#include "DogAirplaneLevel.h"
#include "OverWorld.h"
#include "Crown_Bepi_Level.h"
#include <GameEngineCore/GameEngineCoreWindow.h>

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::ContentsResourcesCreate()
{
	// �ؽ�ó �ε常 �� �������� �ϰ� �����ϴ� ������ ���̼���.


}

void ContentsCore::GameStart() 
{
	// ������ �Ž��� ������� �־�� �Ѵ�.
	
	new int();

	GameEngineGUI::GUIWindowCreate<GameEngineCoreWindow>("CoreWindow");

	

	ContentsResourcesCreate();

	//GameEngineCore::CreateLevel<OverWorld>();
	//GameEngineCore::CreateLevel<Crown_Bepi_Level>();
	//GameEngineCore::CreateLevel<TitleLevel>();
	//GameEngineCore::CreateLevel<PlayLevel>();
	//GameEngineCore::CreateLevel<giantStageLevel>();
	GameEngineCore::CreateLevel<DogAirplaneLevel>();
	GameEngineCore::ChangeLevel("DogAirplaneLevel");
}

void ContentsCore::GameEnd() 
{

}