#include "PrecompileHeader.h"
#include "Crown_Bepi_Level.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "Crown_Bepi_Map.h"
Crown_Bepi_Level::Crown_Bepi_Level()
{
}

Crown_Bepi_Level::~Crown_Bepi_Level()
{
}

void Crown_Bepi_Level::Update(float _DeltaTime)
{
}

void Crown_Bepi_Level::Start()
{
	if (nullptr == GameEngineSprite::Find("DD_Idle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("OverWorld");
		NewDir.Move("Character");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DD_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DD_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Down_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Down_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DU_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DU_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("InterAction_Win").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Side_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Side_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Up_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Up_Move").GetFullPath());
	}

	if (nullptr == GameEngineSprite::Find("Beppi_Bg"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Crown_Bepi");
	

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Beppi_Bg").GetFullPath());
	

	}



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0, SortType::ZSort);

	{
		std::shared_ptr<Crown_Bepi_Map> Object = CreateActor<Crown_Bepi_Map>();
	}

}

void Crown_Bepi_Level::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void Crown_Bepi_Level::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
}
