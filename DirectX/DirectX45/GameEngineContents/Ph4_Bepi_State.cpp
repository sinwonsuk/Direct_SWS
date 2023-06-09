#include "PrecompileHeader.h"
#include "Ph4_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph4_Swing_Platform.h"
#include "Ph4_Penguin.h"
#include "Crown_Bepi_Map.h"
#include "Boss_Finish.h"
void Ph4_Bepi::ChangeState(Ph4_Bepi_State _State)
{
	Ph4_Bepi_State NextState = _State;
	Ph4_Bepi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph4_Bepi_State::BossIntro:

		break;


	case Ph4_Bepi_State::BossIdle:
		AnimationCheck("Phase4_Idle");
		break;
	case Ph4_Bepi_State::BossAttackStart:
		AnimationCheck("Phase4_Attack_Start");
		break;
	case Ph4_Bepi_State::BossAttackMiddle:
		AnimationCheck("Phase4_Attack_Middle");
		break;
	case Ph4_Bepi_State::BossAttackEnd:
		AnimationCheck("Phase4_Attack_End");
		break;
	case Ph4_Bepi_State::BossFinish:
		AnimationCheck("Phase4_End");
		break;

	default:
		break;
	}


}




void Ph4_Bepi::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph4_Bepi_State::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossAttackStart:
		BossAttackStartUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossAttackMiddle:
		BossAttackMiddleUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossAttackEnd:
		BossAttackEndUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossFinish:
		BossFinsihUpdate(_Time);
		break;


	default:
		break;
	}


}
void Ph4_Bepi::BossIdleUpdate(float _Time)
{
	if (GetLiveTime() > 10 && Crown_Bepi_Map::Ph4_Check == true)
	{
		Crown_Bepi_Map::Ph4_Check = false;

		ChangeState(Ph4_Bepi_State::BossAttackStart);
		return; 
	}

	if (Hp < 0)
	{
		if (BossFinish == false)
		{
			Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
			std::shared_ptr<Boss_Finish> Object = GetLevel()->CreateActor<Boss_Finish>(50);
			BossFinish = true;
		}
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);

		ChangeState(Ph4_Bepi_State::BossFinish);
		return;
	}

}

void Ph4_Bepi::BossIntroUpdate(float _Time)
{
	if (GetTransform()->GetLocalPosition().y < -100.0f)
	{
		GetTransform()->AddLocalPosition({ float4::Up * _Time * 500.0f });
	}
	

	if (GetTransform()->GetLocalPosition().y > -100.0f)
	{
		Phase4_Intro_Texture->Off();
		Phase4_Intro->On(); 

		if (Phase4_Intro->IsAnimationEnd() && Swing_Platform_Intro == false)
		{
			Phase4_Intro->Off();
			Phase4_Intro_Spin->On();
			umbrella_bk->On();

			std::shared_ptr<Ph4_Swing_Platform> Object = GetLevel()->CreateActor<Ph4_Swing_Platform>();
			Object->GetTransform()->AddLocalPosition({ -800.0f,200.0f });

			std::shared_ptr<Ph4_Swing_Platform> Object2 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
			Object2->GetTransform()->AddLocalPosition({ -500.0f,200.0f });

			std::shared_ptr<Ph4_Swing_Platform> Object3 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
			Object3->GetTransform()->AddLocalPosition({ -200.0f,200.0f });

			std::shared_ptr<Ph4_Swing_Platform> Object4 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
			Object4->GetTransform()->AddLocalPosition({ 100.0f,200.0f });

			Swing_Platform_Intro = true;
			ResetLiveTime();
			ChangeState(Ph4_Bepi_State::BossIdle);
			return;
		}

		if (Hp < 0)
		{
			Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
			GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
			GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
			if (BossFinish == false)
			{
				std::shared_ptr<Boss_Finish> Object = GetLevel()->CreateActor<Boss_Finish>(50);
				BossFinish = true;
			}


			ChangeState(Ph4_Bepi_State::BossFinish);
			return;
		}

	}
}

void Ph4_Bepi::BossFinsihUpdate(float _Time)
{
	Collision->Off(); 

	if (Phase4_Idle->GetLiveTime() > 0.03f)
	{
		Boss_Exploision_Pos.x = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);
		Boss_Exploision_Pos.y = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);

		if (Boss_Exploision_Check == false)
		{
			Bepi_boss_explosion->ChangeAnimation("Bepi_boss_explosion");
			Bepi_boss_explosion->On();
			Bepi_boss_explosion->GetTransform()->SetLocalPosition({ Phase4_Idle->GetTransform()->GetLocalPosition().x - 80.0f + Boss_Exploision_Pos.x , Phase4_Idle->GetTransform()->GetLocalPosition().y + Boss_Exploision_Pos.y + 80.0f });
			Boss_Exploision_Check = true;
		}


		if (Bepi_boss_explosion->IsAnimationEnd())
		{
			++Boss_Exploision_Number;
			Boss_Exploision_Check = false;
			Bepi_boss_explosion->Off();
			Phase4_Idle->ResetLiveTime();
		}
	}


}

void Ph4_Bepi::BossAttackStartUpdate(float _Time)
{
	if (Phase4_Idle->IsAnimationEnd() )
	{
		ChangeState(Ph4_Bepi_State::BossAttackMiddle);
		return; 
	}
	if (Hp < 0)
	{
		Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
		if (BossFinish == false)
		{
			std::shared_ptr<Boss_Finish> Object = GetLevel()->CreateActor<Boss_Finish>(50);
			BossFinish = true;
		}
		ChangeState(Ph4_Bepi_State::BossFinish);
		return;
	}
}

void Ph4_Bepi::BossAttackMiddleUpdate(float _Time)
{
	
	switch (AttackNumber)
	{
	case 0:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Left;
			object->SetStopPos(-500.0f);
			++AttackNumber;
			ResetLiveTime(); 
		}
	}
	break; 
	case 1:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Left;
			object->SetStopPos(-200.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;
	case 2:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Right;
			object->SetStopPos(500.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;
	case 3:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Right;
			object->SetStopPos(200.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;



	default:
		break;
	}

	if (GetLiveTime() > 1 && AttackNumber==4)
	{
		AttackNumber = 0;
		ChangeState(Ph4_Bepi_State::BossAttackEnd);
		return; 
	}
	if (Hp < 0)
	{
		Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);

		if (BossFinish == false)
		{
			std::shared_ptr<Boss_Finish> Object = GetLevel()->CreateActor<Boss_Finish>(50);
			BossFinish = true;

		}
		ChangeState(Ph4_Bepi_State::BossFinish);
		return;
	}


}

void Ph4_Bepi::BossAttackEndUpdate(float _Time)
{
	if (Phase4_Idle->IsAnimationEnd())
	{
		/*Crown_Bepi_Map::Ph4_Check = false;*/
		ChangeState(Ph4_Bepi_State::BossIdle);
		return;
	}

	if (Hp < 0)
	{
		Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);

		if (BossFinish == false)
		{
			std::shared_ptr<Boss_Finish> Object = GetLevel()->CreateActor<Boss_Finish>(50);
			BossFinish = true;
		}

		ChangeState(Ph4_Bepi_State::BossFinish);
		return;
	}


}

