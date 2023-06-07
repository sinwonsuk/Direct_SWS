#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ph3_Laser.h"
Ph3_DogAirplane::Ph3_DogAirplane()
{
}

Ph3_DogAirplane::~Ph3_DogAirplane()
{
}

void Ph3_DogAirplane::AnimationCheck(const std::string_view& _AnimationName)
{

}


void Ph3_DogAirplane::Start()
{

	if (nullptr == GameEngineSprite::Find("ph3_Intro"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_low_paw_pad_opens").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_mid_paw_pad_opens").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_top_paw_pad_opens").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_low").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_low_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_mid_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_merge").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Idle_body").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Idle_Arom").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph3_Idle_Arom_Hand").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_low").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_ring_top").GetFullPath());


		/*GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_hole_top_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_hole_top").GetFullPath());*/

	}




	Ph3_Boss_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Ph3_Boss_Intro->CreateAnimation({ .AnimationName = "ph3_Intro", .SpriteName = "ph3_Intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph3_Boss_Intro->ChangeAnimation("ph3_Intro");

	
	{
		Idle_Arom = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Arom->CreateAnimation({ .AnimationName = "ph3_Idle_Arom", .SpriteName = "ph3_Idle_Arom", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true,  . FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,10,9,8,7,6,5,4,3,2,1,0} });
		Idle_Arom->ChangeAnimation("ph3_Idle_Arom");
		Idle_Arom->Off();

		Idle_Body = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Body->CreateAnimation({ .AnimationName = "ph3_Idle_body", .SpriteName = "ph3_Idle_body", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		Idle_Body->ChangeAnimation("ph3_Idle_body");
		Idle_Body->Off();

		Idle_Arom_Hand = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Arom_Hand->CreateAnimation({ .AnimationName = "Ph3_Idle_Arom_Hand", .SpriteName = "Ph3_Idle_Arom_Hand", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		Idle_Arom_Hand->ChangeAnimation("Ph3_Idle_Arom_Hand");
		Idle_Arom_Hand->Off();

		ph3_paw_merge = CreateComponent<GameEngineSpriteRenderer>();
		ph3_paw_merge->CreateAnimation({ .AnimationName = "ph3_right_paw_merge", .SpriteName = "ph3_right_paw_merge", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_paw_merge->ChangeAnimation("ph3_right_paw_merge");
		ph3_paw_merge->GetTransform()->AddLocalPosition({ 0,0,55 });
		//ph3_paw_merge->Off(); 
	}

	{	
		ph3_left_paw_hole_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_top->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top", .SpriteName = "ph3_left_paw_hole_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_top->ChangeAnimation("ph3_left_paw_hole_top");
		//ph3_left_paw_hole_top->Off(); 

		ph3_left_paw_hole_top_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_top_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top_backer", .SpriteName = "ph3_left_paw_hole_top_backer", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_top_backer->ChangeAnimation("ph3_left_paw_hole_top_backer");
		//ph3_left_paw_hole_top_backer->Off(); 

		ph3_laser_Left_top_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_top_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens",.FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_Left_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Left_top_paw_pad_opens->Off(); 
	}
	
	{
		ph3_left_paw_hole_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_mid->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid", .SpriteName = "ph3_left_paw_hole_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_mid->ChangeAnimation("ph3_left_paw_hole_mid");
		ph3_left_paw_hole_mid->GetTransform()->AddLocalPosition({ 0,0,52 });
		//ph3_left_paw_hole_mid->Off(); 

		

		ph3_left_paw_hole_mid_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_mid_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid_backer", .SpriteName = "ph3_left_paw_hole_mid_backer", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_mid_backer->ChangeAnimation("ph3_left_paw_hole_mid_backer");
		ph3_left_paw_hole_mid_backer->GetTransform()->AddLocalPosition({ -0,0,50 }); 

		//ph3_left_paw_hole_mid_backer->Off(); 

	


		ph3_laser_Left_mid_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_mid_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_laser_Left_mid_paw_pad_opens->ChangeAnimation("ph3_laser_mid_paw_pad_opens");

		ph3_laser_Left_mid_paw_pad_opens->Off();

		/*ph3_laser_mid_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_mid_backer->CreateAnimation({ .AnimationName = "ph3_laser_mid_backer", .SpriteName = "ph3_laser_mid_backer", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_mid_backer->ChangeAnimation("ph3_laser_mid_backer");
		ph3_laser_mid_backer->GetTransform()->AddLocalPosition({ 30,0,0 });
		ph3_laser_mid_backer->GetTransform()->AddLocalPosition({ 30,0,51 });*/


	}
	{
		ph3_left_paw_hole_low_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_low_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low_backer", .SpriteName = "ph3_left_paw_hole_low_backer", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_left_paw_hole_low_backer->ChangeAnimation("ph3_left_paw_hole_low_backer");
		ph3_left_paw_hole_low_backer->GetTransform()->AddLocalPosition({ 0,5 });
		//ph3_left_paw_hole_low_backer->Off();

		ph3_left_paw_hole_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_low->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low", .SpriteName = "ph3_left_paw_hole_low", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_left_paw_hole_low->ChangeAnimation("ph3_left_paw_hole_low");
		ph3_left_paw_hole_low->GetTransform()->AddLocalPosition({ 0,5 });
		//ph3_left_paw_hole_low->Off(); 

		ph3_laser_Left_low_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_low_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_laser_Left_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Left_low_paw_pad_opens->GetTransform()->AddLocalPosition({ 0,5 });
		ph3_laser_Left_low_paw_pad_opens->Off();
	}

	{
		ph3_Right_paw_hole_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_top->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top", .SpriteName = "ph3_left_paw_hole_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_top->ChangeAnimation("ph3_left_paw_hole_top");
		ph3_Right_paw_hole_top->GetTransform()->AddLocalRotation({ 0,-165,0 }); 
		ph3_Right_paw_hole_top->GetTransform()->AddLocalPosition({ -3,7,0 });
		ph3_Right_paw_hole_top->Off(); 

		ph3_Right_paw_hole_top_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_top_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top_backer", .SpriteName = "ph3_left_paw_hole_top_backer", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_top_backer->ChangeAnimation("ph3_left_paw_hole_top_backer");
		ph3_Right_paw_hole_top_backer->GetTransform()->AddLocalRotation({ 0,-165,0 });
		ph3_Right_paw_hole_top_backer->GetTransform()->AddLocalPosition({ -3,7,0 });
		ph3_Right_paw_hole_top_backer->Off(); 

		ph3_laser_Right_top_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_top_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_laser_Right_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Right_top_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-165,0 });
		ph3_laser_Right_top_paw_pad_opens->GetTransform()->AddLocalPosition({ -3,7,0 });
		ph3_laser_Right_top_paw_pad_opens->Off(); 
	}

	{
		ph3_Right_paw_hole_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_mid->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid", .SpriteName = "ph3_left_paw_hole_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_mid->ChangeAnimation("ph3_left_paw_hole_mid");
		ph3_Right_paw_hole_mid->GetTransform()->AddLocalRotation({ 0,-180,0 }); 
		ph3_Right_paw_hole_mid->GetTransform()->AddLocalPosition({ -20,0 ,0 });
		ph3_Right_paw_hole_mid->Off(); 

		ph3_Right_paw_hole_mid_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_mid_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid_backer", .SpriteName = "ph3_left_paw_hole_mid_backer", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_mid_backer->ChangeAnimation("ph3_left_paw_hole_mid_backer");
		ph3_Right_paw_hole_mid_backer->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_paw_hole_mid_backer->GetTransform()->AddLocalPosition({ -20,0,0 });
		ph3_Right_paw_hole_mid_backer->Off(); 

		ph3_laser_Right_mid_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_mid_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_laser_Right_mid_paw_pad_opens->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
		ph3_laser_Right_mid_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_laser_Right_mid_paw_pad_opens->GetTransform()->AddLocalPosition({ -20,0,0 });
		ph3_laser_Right_mid_paw_pad_opens->Off();

	}
	{
		ph3_Right_paw_hole_low_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_low_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low_backer", .SpriteName = "ph3_left_paw_hole_low_backer", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_Right_paw_hole_low_backer->ChangeAnimation("ph3_left_paw_hole_low_backer");
		ph3_Right_paw_hole_low_backer->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_Right_paw_hole_low_backer->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_Right_paw_hole_low_backer->Off(); 

		ph3_Right_paw_hole_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_low->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low", .SpriteName = "ph3_left_paw_hole_low", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_Right_paw_hole_low->ChangeAnimation("ph3_left_paw_hole_low");
		ph3_Right_paw_hole_low->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_Right_paw_hole_low->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_Right_paw_hole_low->Off(); 

		ph3_laser_Right_low_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_low_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
		ph3_laser_Right_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Right_low_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_laser_Right_low_paw_pad_opens->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_laser_Right_low_paw_pad_opens->Off();
		
		
	}
	{
		ph3_Left_laser_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_mid->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,13,13,12,11,10,9,8,7,6,5,4,3,2,1,0} }); 
		ph3_Left_laser_mid->ChangeAnimation("ph3_laser_mid");
		ph3_Left_laser_mid->GetTransform()->AddLocalPosition({ 30,0,0 });

		ph3_Left_laser_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_top->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14} });
		ph3_Left_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_Left_laser_top->GetTransform()->AddLocalPosition({ 30,0,0 });
		
		ph3_Left_laser_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_low->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Left_laser_low->ChangeAnimation("ph3_laser_low");
		ph3_Left_laser_low->GetTransform()->AddLocalPosition({ 30,0,0 });
	}
	{
		ph3_Right_laser_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_mid->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,13,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Right_laser_mid->ChangeAnimation("ph3_laser_mid");
		ph3_Right_laser_mid->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_mid->GetTransform()->AddLocalPosition({ -30,0,0 });
		
		ph3_Right_laser_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_top->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Right_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_Right_laser_top->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_top->GetTransform()->AddLocalPosition({- 30,0,0 });
		
		ph3_Right_laser_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_low->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Right_laser_low->ChangeAnimation("ph3_laser_low");
		ph3_Right_laser_low->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_low->GetTransform()->AddLocalPosition({ -30,0,0 });
	}
	




}

void Ph3_DogAirplane::Update(float _Delta)
{
	if (ph3_Left_laser_top->IsAnimationEnd())
	{
		if (test == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(4);
			//Object->GetTransform()->SetLocalPosition({ ph3_Left_laser_mid->GetTransform()->GetLocalPosition() });
			test = true;
		}



	}





	//UpdateState(_Delta);
}

void Ph3_DogAirplane::Render(float _Delta)
{

}
