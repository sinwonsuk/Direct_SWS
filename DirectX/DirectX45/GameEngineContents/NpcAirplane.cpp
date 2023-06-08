#include "PrecompileHeader.h"
#include "NpcAirplane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "EnumClass.cpp"
#include "Player.h"
NpcAirplane::NpcAirplane()
{

}

NpcAirplane::~NpcAirplane()
{

}



void NpcAirplane::Start()
{
	if (nullptr == GameEngineSprite::Find("Npc_Airplane_Back"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Reg").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Spin").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("NpcIntro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Intro2").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Idle").GetFullPath());
	}



	Npc_Airplane_Back = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Ground);
	Npc_Airplane_Back->CreateAnimation({ .AnimationName = "Npc_Airplane_Back", .SpriteName = "Npc_Airplane_Back", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Back->ChangeAnimation("Npc_Airplane_Back");
	Npc_Airplane_Back->GetTransform()->AddLocalPosition({ 300,-230 });

	Npc_Airplane_Reg = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Ground);
	Npc_Airplane_Reg->CreateAnimation({ .AnimationName = "Npc_Airplane_Reg", .SpriteName = "Npc_Airplane_Reg", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Reg->ChangeAnimation("Npc_Airplane_Reg");
	Npc_Airplane_Reg->GetTransform()->AddLocalPosition({ 300,-230 });

	Npc_Airplane_Front = CreateComponent<GameEngineSpriteRenderer>(4);
	Npc_Airplane_Front->CreateAnimation({ .AnimationName = "Npc_Airplane_Front", .SpriteName = "Npc_Airplane_Front", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Front->ChangeAnimation("Npc_Airplane_Front");
	Npc_Airplane_Front->GetTransform()->AddLocalPosition({ 300,-230 });

	

	Npc_Airplane_Spin = CreateComponent<GameEngineSpriteRenderer>(5);
	Npc_Airplane_Spin->CreateAnimation({ .AnimationName = "Npc_Airplane_Spin", .SpriteName = "Npc_Airplane_Spin", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc_Airplane_Spin->ChangeAnimation("Npc_Airplane_Spin");
	Npc_Airplane_Spin->GetTransform()->AddLocalPosition({ 300,-230 });


	Npc = CreateComponent<GameEngineSpriteRenderer>(3);
	Npc->CreateAnimation({ .AnimationName = "NpcIntro", .SpriteName = "NpcIntro", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc->CreateAnimation({ .AnimationName = "Npc_Intro2", .SpriteName = "Npc_Intro2", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Npc->CreateAnimation({ .AnimationName = "Npc_Idle", .SpriteName = "Npc_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc->ChangeAnimation("NpcIntro");
	Npc->GetTransform()->AddLocalPosition({ 0,-230 });

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 350.0f, 100.0f, 100.0f });
	Collision->SetOrder((int)CollisionType::NpcAirPlane);

	CurPos.x = Npc->GetTransform()->GetLocalPosition().x;

}

void NpcAirplane::Update(float _Delta)
{
	if (GetTransform()->GetLocalRotation().z > 90)
	{
		GetTransform()->AddLocalRotation({ 0,0,-1 });
		GetTransform()->AddLocalPosition({ -3,0,0 });
	}
	/*GetTransform()->AddLocalRotation({ 0,0,1 });
	GetTransform()->AddLocalPosition({ 3,0,0 });*/



	CurPos.x = Npc->GetTransform()->GetLocalPosition().x;
	Collision->GetTransform()->SetLocalPosition({ Npc->GetTransform()->GetLocalPosition() });
	Collision->GetTransform()->SetLocalRotation({ Npc->GetTransform()->GetLocalRotation() });
	
	
	if (Collision->Collision((int)CollisionType::Player) == nullptr)
	{
		Player::MainPlayer->SetGravity(false);
	}
	else if (Collision->Collision((int)CollisionType::Player,ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->SetGravity(true);
	}

	
	if (Collision->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{


		if (CurPos.x < Player::MainPlayer->GetTransform()->GetLocalPosition().x)
		{
			Speed = CurPos.x - Player::MainPlayer->GetTransform()->GetLocalPosition().x;
			Speed *= -1;
		}

		else if (CurPos.x > Player::MainPlayer->GetTransform()->GetLocalPosition().x)
		{
			Speed = CurPos.x - Player::MainPlayer->GetTransform()->GetLocalPosition().x;
			Speed *= -1;
		}

		Npc->GetTransform()->SetLocalRotation({ 0,0,(-Speed) * SpeedControll });
		Npc_Airplane_Back->GetTransform()->SetLocalRotation({ 0,0,(-Speed) * SpeedControll });
		Npc_Airplane_Reg->GetTransform()->SetLocalRotation({ 0,0,(-Speed) * SpeedControll });
		Npc_Airplane_Front->GetTransform()->SetLocalRotation({ 0,0,(-Speed) * SpeedControll });
		Npc_Airplane_Spin->GetTransform()->SetLocalRotation({ 0,0,(-Speed) * SpeedControll });



		Npc->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
		Npc_Airplane_Back->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
		Npc_Airplane_Reg->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
		Npc_Airplane_Front->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
		Npc_Airplane_Spin->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
		Player::MainPlayer->GetTransform()->AddLocalPosition({ (Speed * _Delta) * 0.7f,0,0 });
	}

	UpdateState(_Delta); 

}

void NpcAirplane::Render(float _Delta)
{
}

void NpcAirplane::AnimationCheck(const std::string_view& _AnimationName)
{
	Npc->ChangeAnimation(_AnimationName);
}


