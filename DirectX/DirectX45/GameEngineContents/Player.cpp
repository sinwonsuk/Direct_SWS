#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "TutorialMap.h"
#include "IdleWeapon.h"
#include "EnumClass.h"
Player* Player::MainPlayer;
Player::Player()
{
	
}

Player::~Player()
{
}


void Player::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("Start"))
	{
		GameEngineTime::GlobalTime.SetGlobalTimeScale(1.0f);
	}
	MainPlayer = this;
	//Collision->GetTransform()->SetLocalRotation({Render0->GetTransform()->GetLocalRotation() });
	//Collision->GetTransform()->SetLocalPosition(Render0->GetTransform()->GetWorldPosition());
	

	if (Gravity == true && StateValue != PlayerState::Dash)
	{
		GetTransform()->AddLocalPosition({ 0, -GravitySpeed * _DeltaTime });
	}


	HitTime += _DeltaTime;
	BulletTime += _DeltaTime;
	RunTime += _DeltaTime; 
	ExBulletTime += _DeltaTime; 

	float RotSpeed = 180.0f;

	float Speed = 200.0f;

	float ScaleSpeed = 10.0f;

	if (TuritualCheck == false)
	{
		CheckCamera = false;
	}


	if (TuritualCheck == true)
	{
		CheckCamera = true;
		std::shared_ptr<GameEngineTexture> testMap = GameEngineTexture::Find("Tutorial_ColMap.png");
		//2009,368

			//GameEnginePixelColor Pixel = testMap->GetPixel( 2009,368 );
		GameEnginePixelColor Pixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x + 640.0f, -GetTransform()->GetLocalPosition().y + 360.0 + 80.0f);
		GameEnginePixelColor RightPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x + 40.0f + 640.0f, -GetTransform()->GetLocalPosition().y + 360.0f + 65.0f);
		GameEnginePixelColor LeftPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x - 40.0f + 640.0f, -GetTransform()->GetLocalPosition().y + 360.0f + 65.0f);

		// 마젠타색 임시 변수 
		unsigned char ColorChar[4] = { 0,0,0,255 };

		unsigned char ColorChar1[4] = { 0,0,255,255 };

	
		
		for (size_t i = 0; i < 4; i++)
		{

			if (ColorChar1[i] == Pixel.ColorChar[i])
			{
				++DownBlockCheck;
			}
			if (ColorChar[i] == Pixel.ColorChar[i])
			{
				++GravityCheck;
			}

			if (ColorChar[i] == RightPixel.ColorChar[i])
			{
				++RightCheck;
			}

			if (ColorChar[i] == LeftPixel.ColorChar[i])
			{
				++LeftCheck;
			}

		}
		if (DownBlockCheck == 4)
		{
			Gravity = false;
			Block = true; 
		}
		if (DownBlockCheck != 4)
		{
			Block = false;
		}
		if (RightCheck == 4)
		{
			RightMove = false;
			CheckCamera = false;
		}
		if (RightCheck != 4)
		{
			RightMove = true;
		}
		if (LeftCheck == 4)
		{
			LeftMove = false;
			CheckCamera = false;
		}
		if (LeftCheck != 4)
		{
			LeftMove = true;
		}

		if (GravityCheck == 4)
		{
			Gravity = false;
		}
		if (GravityCheck != 4 && DownBlockCheck !=4)
		{
			Gravity = true;
		}

		GravityCheck = 0;
		RightCheck = 0;
		LeftCheck = 0;
		DownBlockCheck = 0; 



	}
	/*Collision->GetTransform()->SetLocalPosition({ 0.0f, -30.0f, 0.0f });
	Collision->GetTransform()->SetLocalScale({ 50.0f, 100.0f, 300.0f });*/

	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 300.0f });
		Collision->GetTransform()->SetLocalPosition({ 0.0f, -60.0f, 0.0f });
	}
	
	if (GetTransform()->GetLocalScale().x > 0 && StateValue != PlayerState::Dash && StateValue != PlayerState::Ex_Straight
		&& StateValue != PlayerState::Ex_DiagonalUp && StateValue != PlayerState::Ex_Up
		)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetTransform()->SetLocalNegativeScaleX();
		}
	}
	

	if (GetTransform()->GetLocalScale().x < 0 && StateValue != PlayerState::Dash && StateValue != PlayerState::Ex_Straight
		&& StateValue != PlayerState::Ex_DiagonalUp && StateValue != PlayerState::Ex_Up	
		)


	{
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetTransform()->SetLocalPositiveScaleX();		
		}
	}
	if (HitCheck == true)
	{
		if (HitTime < 0.1f)
		{
			Render0->ColorOptionValue.MulColor = { 0.0f,0.0f,0.0f,0.001f };

		}
		if (HitTime > 0.1f)
		{
			Render0->ColorOptionValue.MulColor = { 1.0f,1.0f,1.0f,1.0f };
			HitTime = 0;
			++HitNumber;
		}


		if (HitNumber == 15)
		{
			HitCheck =false;
			HitNumber = 0;
			HitTime = 0;
		}
	}
	
	UpdateState(_DeltaTime);

//	Collision->GetTransform()->SetLocalPosition(Render0->GetTransform()->GetWorldPosition());
	

}

void Player::Start()
{
	

	

	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("PlayerMoveLeft", VK_LEFT);
		GameEngineInput::CreateKey("PlayerMoveRight", VK_RIGHT);
		GameEngineInput::CreateKey("PlayerMoveUp", VK_UP);
		GameEngineInput::CreateKey("PlayerMoveDown", VK_DOWN);
		GameEngineInput::CreateKey("PlayerMoveForward", 'W');
		GameEngineInput::CreateKey("PlayerMoveBack", 'S');
		GameEngineInput::CreateKey("PlayerJump", 'Z');
		GameEngineInput::CreateKey("PlayerRock", 'C');
		GameEngineInput::CreateKey("PlayerAttack", 'X');
		GameEngineInput::CreateKey("PlayerDash", VK_LSHIFT);
		GameEngineInput::CreateKey("PlayerExAttack", 'V');
		GameEngineInput::CreateKey("Start", 'B');
		GameEngineInput::CreateKey("PlayerScaleY+", 'Y');
		GameEngineInput::CreateKey("PlayerScaleY-", 'U');
		GameEngineInput::CreateKey("PlayerScaleZ+", 'H');
		GameEngineInput::CreateKey("PlayerScaleZ-", 'J');
		GameEngineInput::CreateKey("PlayerScaleX+", 'N');
		GameEngineInput::CreateKey("PlayerScaleX-", 'M');


		GameEngineInput::CreateKey("PlayerRotY+", VK_NUMPAD1);
		GameEngineInput::CreateKey("PlayerRotY-", VK_NUMPAD2);
		GameEngineInput::CreateKey("PlayerRotZ+", VK_NUMPAD4);
		GameEngineInput::CreateKey("PlayerRotZ-", VK_NUMPAD5);
		GameEngineInput::CreateKey("PlayerRotX+", VK_NUMPAD7);
		GameEngineInput::CreateKey("PlayerRotX-", VK_NUMPAD8);
		
	}

	if (nullptr == GameEngineSprite::Find("Idle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Character");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Run").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Jump").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Duck").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Parry").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalDownAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalUpAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DownAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("GroundDash").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("RunAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalUpAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalDownAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Up").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalUpRunAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DuckAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DuckAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalUpAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalDownAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DownAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DownAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Hit_Ground").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ex_DiagonalDown").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ex_DiagonalUp").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ex_Down").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ex_Straight").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ex_Up").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("tutorial_target").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("boss_explosion").GetFullPath());


		/*GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAimAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAimAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAimAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAimAttackPre").GetFullPath());*/
	}
		
	// 나는 스케일을 1로 고정해 놓는게 좋다.
	Render0 = CreateComponent<GameEngineSpriteRenderer>(100);
	
	//Render0->PushCameraRender(100);
	
	

	Render0->CreateAnimation({ .AnimationName = "Idle", .SpriteName = "Idle", .FrameInter =0.06f,.Loop = true, .ScaleToTexture = true,});
	Render0->CreateAnimation({ .AnimationName = "Run", .SpriteName = "Run",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Jump", .SpriteName = "Jump",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Duck", .SpriteName = "Duck",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Parry", .SpriteName = "Parry",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAim", .SpriteName = "IdleAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalDownAim", .SpriteName = "DiagonalDownAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalUpAim", .SpriteName = "DiagonalUpAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DownAim", .SpriteName = "DownAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAim", .SpriteName = "UpAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "GroundDash", .SpriteName = "GroundDash",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAttack", .SpriteName = "IdleAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAttackPre", .SpriteName = "IdleAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "RunAttack", .SpriteName = "RunAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalUpAttack", .SpriteName = "DiagonalUpAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalDownAttack", .SpriteName = "DiagonalDownAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Up", .SpriteName = "Up",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAttack", .SpriteName = "UpAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalUpRunAttack", .SpriteName = "DiagonalUpRunAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAttackPre", .SpriteName = "UpAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DuckAttack", .SpriteName = "DuckAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DuckAttackPre", .SpriteName = "DuckAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalDownAttackPre", .SpriteName = "DiagonalDownAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalUpAttackPre", .SpriteName = "DiagonalUpAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAimAttack", .SpriteName = "IdleAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAimAttackPre", .SpriteName = "IdleAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAimAttack", .SpriteName = "UpAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAimAttackPre", .SpriteName = "UpAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DownAttack", .SpriteName = "DownAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DownAttackPre", .SpriteName = "DownAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Hit_Ground", .SpriteName = "Hit_Ground",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });

	Render0->CreateAnimation({ .AnimationName = "Ex_DiagonalDown", .SpriteName = "Ex_DiagonalDown",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Ex_DiagonalUp", .SpriteName = "Ex_DiagonalUp",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Ex_Down", .SpriteName = "Ex_Down",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Ex_Straight", .SpriteName = "Ex_Straight",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Ex_Up", .SpriteName = "Ex_Up",. FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });



	Render0->ChangeAnimation("Idle");

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->AddLocalPosition({ 0.0f, -30.0f, 0.0f });
	Collision->GetTransform()->SetLocalScale({ 50.0f, 100.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::Player);



	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->AddLocalPosition({ 0.0f, -30.0f, 0.0f });
	Collision2->GetTransform()->SetLocalScale({ 10.0f, 10.0f, 300.0f });
	Collision2->SetOrder((int)CollisionType::PlayerDown);
	Collision2->GetTransform()->AddLocalPosition({ 0.0f,-50.0f });


}

void Player::AnimationCheck(const std::string_view& _AnimationName)
{
	Render0->ChangeAnimation(_AnimationName);
}

void Player::AnimationCheck(const std::string_view& _AnimationName, bool Force, size_t Frame)
{
	Render0->ChangeAnimation(_AnimationName, Force , Frame);
}


// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	 GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
