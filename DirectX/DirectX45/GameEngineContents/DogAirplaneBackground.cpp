#include "PrecompileHeader.h"
#include "DogAirplaneBackground.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "EnumClass.cpp"

DogAirplaneBackground::DogAirplaneBackground()
{
}

DogAirplaneBackground::~DogAirplaneBackground()
{
}

void DogAirplaneBackground::Start()
{
	if (nullptr == GameEngineSprite::Find("Background"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Background").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Sky").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("A_clouds").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("B_clouds").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("C_clouds").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("D_clouds").GetFullPath());
	}




	Sky = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Sky);
	Sky->SetScaleToTexture("background_sky_0001.png");

	BackGround = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Ground);
	BackGround->CreateAnimation({ .AnimationName = "Background", .SpriteName = "Background", .FrameInter = 0.04f,.Loop = true, .ScaleToTexture = true, });
	BackGround->ChangeAnimation("Background");
	BackGround->GetTransform()->AddLocalPosition({ 0,-400 });
	


	A_Left_Clouds = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Cloulds);
	A_Left_Clouds->CreateAnimation({ .AnimationName = "A_clouds", .SpriteName = "A_clouds", .FrameInter = 0.04f,.Loop = true, .ScaleToTexture = true, });
	A_Left_Clouds->ChangeAnimation("A_clouds");
	
	

	B_Left_Clouds = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Cloulds);
	B_Left_Clouds->CreateAnimation({ .AnimationName = "B_clouds", .SpriteName = "B_clouds", .FrameInter = 0.04f,.Loop = true, .ScaleToTexture = true, });
	B_Left_Clouds->ChangeAnimation("B_clouds");


	C_Left_Clouds = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Cloulds);
	C_Left_Clouds->CreateAnimation({ .AnimationName = "C_clouds", .SpriteName = "C_clouds", .FrameInter = 0.04f,.Loop = true, .ScaleToTexture = true, });
	C_Left_Clouds->ChangeAnimation("C_clouds");
	C_Left_Clouds->Off();


	D_Left_Clouds = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Cloulds);
	D_Left_Clouds->CreateAnimation({ .AnimationName = "D_clouds", .SpriteName = "D_clouds", .FrameInter = 0.04f,.Loop = true, .ScaleToTexture = true, });
	D_Left_Clouds->ChangeAnimation("D_clouds");
	
	







	
}

void DogAirplaneBackground::Update(float _Delta)
{
	if (C_Left_Clouds->IsAnimationEnd())
	{
		C_Left_Clouds->Off();
	}


}

void DogAirplaneBackground::Render(float _Delta)
{
}
