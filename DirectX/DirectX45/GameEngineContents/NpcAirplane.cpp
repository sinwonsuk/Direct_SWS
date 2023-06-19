#include "PrecompileHeader.h"
#include "NpcAirplane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "EnumClass.cpp"
#include "Player.h"
#include "ph3_DogAirPlane.h"
#include "DogAirplane.h"
#include "DogAirplaneLevel.h"
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



	Npc_Airplane_Back = CreateComponent<GameEngineSpriteRenderer>();
	Npc_Airplane_Back->CreateAnimation({ .AnimationName = "Npc_Airplane_Back", .SpriteName = "Npc_Airplane_Back", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Back->ChangeAnimation("Npc_Airplane_Back");
	Npc_Airplane_Back->GetTransform()->AddLocalPosition({ 0,-230,20 });

	Npc_Airplane_Reg = CreateComponent<GameEngineSpriteRenderer>();
	Npc_Airplane_Reg->CreateAnimation({ .AnimationName = "Npc_Airplane_Reg", .SpriteName = "Npc_Airplane_Reg", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Reg->ChangeAnimation("Npc_Airplane_Reg");
	Npc_Airplane_Reg->GetTransform()->AddLocalPosition({ 0,-230,20 });

	Npc_Airplane_Front = CreateComponent<GameEngineSpriteRenderer>();
	Npc_Airplane_Front->CreateAnimation({ .AnimationName = "Npc_Airplane_Front", .SpriteName = "Npc_Airplane_Front", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Npc_Airplane_Front->ChangeAnimation("Npc_Airplane_Front");
	Npc_Airplane_Front->GetTransform()->AddLocalPosition({ 0,-230,17});

	

	Npc_Airplane_Spin = CreateComponent<GameEngineSpriteRenderer>();
	Npc_Airplane_Spin->CreateAnimation({ .AnimationName = "Npc_Airplane_Spin", .SpriteName = "Npc_Airplane_Spin", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc_Airplane_Spin->ChangeAnimation("Npc_Airplane_Spin");
	Npc_Airplane_Spin->GetTransform()->AddLocalPosition({ 0,-230,16 });


	Npc = CreateComponent<GameEngineSpriteRenderer>();
	Npc->CreateAnimation({ .AnimationName = "NpcIntro", .SpriteName = "NpcIntro", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc->CreateAnimation({ .AnimationName = "Npc_Intro2", .SpriteName = "Npc_Intro2", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Npc->CreateAnimation({ .AnimationName = "Npc_Idle", .SpriteName = "Npc_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Npc->ChangeAnimation("NpcIntro");
	Npc->GetTransform()->AddLocalPosition({ 0,-230,19 });

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 450.0f, 100.0f, 100.0f });
	Collision->SetOrder((int)CollisionType::NpcAirPlane);

	CurPos.x = Npc->GetTransform()->GetLocalPosition().x;

}
void NpcAirplane::collision(float _Delta)
{
	



	if (Collision->Collision((int)CollisionType::Player) == nullptr)
	{
		Player::MainPlayer->SetGravity(true);
	}
	else if (Collision->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (Player::MainPlayer->GetTransform()->GetLocalPosition().y > Player_Pos_Y_Check)
		{
			Player::MainPlayer->SetGravity(false);
		}
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
	
}

void NpcAirplane::Update(float _Delta)
{
	CurPos.x = Npc->GetTransform()->GetLocalPosition().x;
	Collision->GetTransform()->SetLocalPosition({ Npc->GetTransform()->GetLocalPosition().x, Npc->GetTransform()->GetLocalPosition().y - 20.0f,Npc->GetTransform()->GetLocalPosition().z });
	Collision->GetTransform()->SetLocalRotation({ Npc->GetTransform()->GetLocalRotation().x, Npc->GetTransform()->GetLocalRotation().y,Npc->GetTransform()->GetLocalRotation().z });
	

	if (DogAirplane::Finish ==true)
	{
		float4 a = { 0,-60.0f };
		float4  ad = { Npc->GetTransform()->GetLocalPosition().x, Npc->GetTransform()->GetLocalPosition().y };
		float4 b = a - ad;
		test = b.NormalizeReturn();

		Npc->GetTransform()->AddLocalPosition({ test *1.3f });
		Npc_Airplane_Back->GetTransform()->AddLocalPosition({ test * 1.3f });
		Npc_Airplane_Reg->GetTransform()->AddLocalPosition({ test * 1.3f });
		Npc_Airplane_Front->GetTransform()->AddLocalPosition({ test * 1.3f });
		Npc_Airplane_Spin->GetTransform()->AddLocalPosition({ test * 1.3f });
		Player::MainPlayer->GetTransform()->AddLocalPosition({ test * 1.3f });

		Player_Pos_Y_Check += test.y * 1.3f;
	}
	
	TransformData date = Npc->GetTransform()->GetTransDataRef(); 

	if (DogAirplane::Finish == true && Npc->GetTransform()->GetLocalPosition().y > -75.0f)
	{
		DogAirplane::Finish = false;
		DogAirplaneLevel* A = (DogAirplaneLevel*)GetLevel();
		A->ad = 1;
	}


	if (DogAirplane::Finish == false)
	{
		collision(_Delta);
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


