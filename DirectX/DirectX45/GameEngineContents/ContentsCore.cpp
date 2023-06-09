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
	// 텍스처 로드만 각 레벨별로 하고 정리하는 습관을 들이세요.


}

void ContentsCore::GameStart() 
{
	// 이전에 매쉬는 만들어져 있어야 한다.
	
	new int();

	GameEngineGUI::GUIWindowCreate<GameEngineCoreWindow>("CoreWindow");

	

	ContentsResourcesCreate();

	//GameEngineCore::CreateLevel<OverWorld>();
	//GameEngineCore::CreateLevel<Crown_Bepi_Level>();
	//GameEngineCore::CreateLevel<TitleLevel>();
	GameEngineCore::CreateLevel<PlayLevel>();
	//GameEngineCore::CreateLevel<giantStageLevel>();
	GameEngineCore::CreateLevel<DogAirplaneLevel>();
	GameEngineCore::ChangeLevel("DogAirplaneLevel");
}

void ContentsCore::GameEnd() 
{

}