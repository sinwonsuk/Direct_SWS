#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "ph3_Laser.h"
#include "ph3_Dog_Npc.h"
#include "ph3_food_bowl.h"

void Ph3_DogAirplane::ChangeState(Ph3_DogAirPlaneState _State)
{
	Ph3_DogAirPlaneState NextState = _State;
	Ph3_DogAirPlaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph3_DogAirPlaneState::Intro:
		//AnimationCheck("ph2_dog_a_intro");
		break;

	case Ph3_DogAirPlaneState::Idle:
	//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Rotation:
	
		break;
	case Ph3_DogAirPlaneState::Rotation_Attack:
		
		break;
	case Ph3_DogAirPlaneState::Rotation_Laser_Idle:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack:

		break;

	default:
		break;
	}


}


void Ph3_DogAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph3_DogAirPlaneState::Intro:
		IntroUpdate(_Time);
		break;

	case Ph3_DogAirPlaneState::Idle:
		IdleUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack:
		Pase1_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack_Reverse:
		Pase1_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack:
		Pase2_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack_Reverse:
		Pase2_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack:
		Pase3_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack_Reverse:
		Pase3_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation:
		Rotation_Update(_Time); 
		break;
	case Ph3_DogAirPlaneState::Rotation_Attack:
		Rotation_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Laser_Idle:
		Rotation_Laser_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack:
		Rotation_Laser_Attack_Update(_Time);
		break;
	default:
		break;
	}
}



void Ph3_DogAirplane::IntroUpdate(float _Time)
{
	if (Ph3_Boss_Intro->IsAnimationEnd())
	{
		Ph3_Boss_Intro->Off(); 

		Idle_Arom->On();
		Idle_Body->On();
		Idle_Arom_Hand->On();
		ph3_paw_merge->On();

		ChangeState(Ph3_DogAirPlaneState::Idle);
		return;
	}
}

void Ph3_DogAirplane::IdleUpdate(float _Time)
{
	if (GetLiveTime() > 1)
	{
		ph3_left_paw_hole_top->On(); 
		ph3_left_paw_hole_top_backer->On(); 
		ph3_laser_Left_top_paw_pad_opens->On(); 

		ph3_left_paw_hole_mid->On();
		ph3_left_paw_hole_mid_backer->On(); 
		ph3_laser_Left_mid_paw_pad_opens->On(); 

		ChangeState(Ph3_DogAirPlaneState::Pase1_Attack);
		return; 
	}
	
}

void Ph3_DogAirplane::Pase1_AttackUpdate(float _Time)
{
	if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_top->On(); 
		
	}
	if (ph3_laser_Left_mid_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_mid->On();		
	}

	if (ph3_Left_laser_top->IsAnimationEnd())
	{
		if (TopLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Top;
			TopLaserCheck = true;

			ChangeState(Ph3_DogAirPlaneState::Pase1_Attack_Reverse);
			ResetLiveTime();
		}		
	}



	if (ph3_Left_laser_mid->IsAnimationEnd())
	{
		if (MidLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Mid;
			MidLaserCheck = true;
			
			return;
		}
	}
	
}

void Ph3_DogAirplane::Pase1_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Left_laser_top->Off();
		ph3_Left_laser_mid->Off(); 
		ph3_Left_laser_top_Reverse->On();
		ph3_Left_laser_mid_Reverse->On();
	}

	if (ph3_Left_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_top_Reverse->Off(); 
		ph3_laser_Left_top_paw_pad_opens->Off(); 
		ph3_laser_Left_top_paw_pad_opens_Reverse->On();
	}

	if (ph3_Left_laser_mid_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_mid_Reverse->Off();
		ph3_laser_Left_mid_paw_pad_opens->Off(); 
		ph3_laser_Left_mid_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Left_mid_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_left_paw_hole_mid_backer->Off();
		ph3_left_paw_hole_mid->Off(); 
		ph3_laser_Left_mid_paw_pad_opens_Reverse->Off();
	}

	if (ph3_laser_Left_top_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_left_paw_hole_top_backer->Off(); 
		ph3_left_paw_hole_top->Off(); 
		ph3_laser_Left_top_paw_pad_opens_Reverse->Off(); 


		ph3_Right_paw_hole_mid->On();
		ph3_Right_paw_hole_mid_backer->On();
		ph3_laser_Right_mid_paw_pad_opens->On();

		TopLaserCheck = false;
		MidLaserCheck = false;

		ChangeState(Ph3_DogAirPlaneState::Pase2_Attack);
		return; 
	}


}

void Ph3_DogAirplane::Pase2_AttackUpdate(float _Time)
{
	if (ph3_laser_Right_mid_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_mid->On();

	}
	
	if (ph3_Right_laser_mid->IsAnimationEnd())
	{
		int a = 0;
		if (MidLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Right_Mid;
			MidLaserCheck = true;

			ChangeState(Ph3_DogAirPlaneState::Pase2_Attack_Reverse);
			ResetLiveTime();
			return; 
		}
	}

}

void Ph3_DogAirplane::Pase2_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Right_laser_mid->Off();
		ph3_Right_laser_mid_Reverse->On();
	}
	if (ph3_Right_laser_mid_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_mid_Reverse->Off();
		ph3_laser_Right_mid_paw_pad_opens->Off();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Right_mid_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_Right_paw_hole_mid_backer->Off();
		ph3_Right_paw_hole_mid->Off();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->Off();

		MidLaserCheck = false;



		ph3_Right_paw_hole_top->On();
		ph3_Right_paw_hole_top_backer->On();
		ph3_laser_Right_top_paw_pad_opens->On();

		ph3_left_paw_hole_low_backer->On();
		ph3_left_paw_hole_low->On();
		ph3_laser_Left_low_paw_pad_opens->On();

		ph3_Right_paw_hole_low_backer->On();
		ph3_Right_paw_hole_low->On();
		ph3_laser_Right_low_paw_pad_opens->On();

		ChangeState(Ph3_DogAirPlaneState::Pase3_Attack);
		return; 
	}

	
}

void Ph3_DogAirplane::Pase3_AttackUpdate(float _Time)
{
	if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_top->On();

	}
	if (ph3_laser_Left_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_low->On();
	}
	if (ph3_laser_Right_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_low->On();
	}

	if (ph3_Right_laser_top->IsAnimationEnd())
	{
		if (TopLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Right_Top;
			TopLaserCheck = true;
			

		}
	}

	if (ph3_Left_laser_low->IsAnimationEnd())
	{
		if (LowLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Low;
			LowLaserCheck = true;

			ResetLiveTime();
			ChangeState(Ph3_DogAirPlaneState::Pase3_Attack_Reverse);
			return;
			
		}
	}

	
}

void Ph3_DogAirplane::Pase3_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Right_laser_top->Off();

		ph3_Right_laser_low->Off();
		ph3_Left_laser_low->Off();

		ph3_Right_laser_top_Reverse->On();

		ph3_Right_laser_low_Reverse->On();
		ph3_Left_laser_low_Reverse->On();

	}

	if (ph3_Right_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_top_Reverse->Off();
		ph3_laser_Right_top_paw_pad_opens->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->On();
	}

	if (ph3_Right_laser_low_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_low_Reverse->Off();
		ph3_laser_Right_low_paw_pad_opens->Off();
		ph3_laser_Right_low_paw_pad_opens_Reverse->On();
	}
	if (ph3_Left_laser_low_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_low_Reverse->Off();
		ph3_laser_Left_low_paw_pad_opens->Off();
		ph3_laser_Left_low_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Left_low_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_Right_paw_hole_top_backer->Off();
		ph3_Right_paw_hole_top->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->Off();

		ph3_left_paw_hole_low_backer->Off();
		ph3_left_paw_hole_low->Off();
		ph3_laser_Left_low_paw_pad_opens_Reverse->Off();

		ph3_Right_paw_hole_low_backer->Off();
		ph3_Right_paw_hole_low->Off();
		ph3_laser_Right_low_paw_pad_opens_Reverse->Off();

		TopLaserCheck = false;
		MidLaserCheck = false;


		ph3_dogcopter_rotate_camera->On();
		ChangeState(Ph3_DogAirPlaneState::Rotation);
		return;
	}
	
}


void Ph3_DogAirplane::Rotation_Update(float _Time)
{

	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 15)
	{
		
		if (ph3_Npc_Check == false)
		{
			++RotationCheck;
			std::shared_ptr<ph3_Dog_Npc> object = GetLevel()->CreateActor<ph3_Dog_Npc>(); 
			ph3_Npc_Check = true;
		}
	}

	if (ph3_dogcopter_rotate_camera->IsAnimationEnd())
	{

		ph3_dogcopter_rotate_camera->Off(); 
		ph3_dogcopter_rotated_idle->On(); 
		ph3_dogcopter_rotate_camera_out_blades->On(); 
		ResetLiveTime(); 
		ChangeState(Ph3_DogAirPlaneState::Rotation_Attack);
		return; 
	}
	
}

void Ph3_DogAirplane::Rotation_Attack_Update(float _Time)
{
	/*if (GetLiveTime() > 1.0)
	{
		
		if (BowlDirCheck == 0)
		{
			std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
			Object->GetBullet()->GetTransform()->AddLocalPosition({ -120,740 });
			Object->GetSfx()->GetTransform()->AddLocalPosition({ -120,760 });
			++BowlDirCheck;
		}
		else if (BowlDirCheck == 1)
		{
			std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
			Object->GetBullet()->GetTransform()->AddLocalPosition({ 120,740 });
			Object->GetSfx()->GetTransform()->AddLocalPosition({ 170,760 });
			BowlDirCheck = 0;
			Object->SetDirCheck(1);
		}
		++BowlCheck;
		ResetLiveTime();
	}*/

	if (BowlCheck == 0)
	{
		ResetLiveTime();
		ChangeState(Ph3_DogAirPlaneState::Rotation_Laser_Idle);
		return; 
	}	
}

void Ph3_DogAirplane::Rotation_Laser_Update(float _Time)
{
	if (GetLiveTime() > 3)
	{
		ph3_dogcopter_rotated_idle->Off();
		ph3_dogcopter_rotate_camera_out->On(); 
	}
	if (ph3_dogcopter_rotate_camera_out->GetCurrentFrame() == 6)
	{
		RotationCheck = 1;
	}


	if (ph3_dogcopter_rotate_camera_out->IsAnimationEnd())
	{
		ph3_dogcopter_rotate_camera_out->Off(); 
		
		GetTransform()->SetLocalRotation({ 0,0,0 });
		Idle_Arom->On();
		Idle_Body->On();
		Idle_Arom_Hand->On();
		ph3_paw_merge->On();



		ph3_left_paw_hole_top->On();
		ph3_left_paw_hole_top_backer->On();
		ph3_laser_Left_top_paw_pad_opens->On();

		ph3_Right_paw_hole_top->On();
		ph3_Right_paw_hole_top_backer->On();
		ph3_laser_Right_top_paw_pad_opens->On();
		ResetLiveTime(); 
		ChangeState(Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack);
		return;
	}

	

}

void Ph3_DogAirplane::Rotation_Laser_Attack_Update(float _Time)
{
	//GetLevel()->GetMainCamera()->GetTransform()->SetLocalRotation({ 0,0,180 });
	TransformData date = GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef();

	
		if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
		{
			ph3_Left_laser_top->On();

		}
		if (ph3_laser_Right_top_paw_pad_opens->IsAnimationEnd())
		{
			ph3_Right_laser_top->On();
		}

		if (ph3_Left_laser_top->IsAnimationEnd())
		{
			if (TopLaserCheck == false)
			{
				std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
				Object->laserDir = LaserDir::Right_Top_Reverse;
				TopLaserCheck = true;

				/*std::shared_ptr<ph3_Laser> Object1 = GetLevel()->CreateActor<ph3_Laser>(3);
				Object1->laserDir = LaserDir::Right_Top_Reverse;*/

				//ChangeState(Ph3_DogAirPlaneState::Pase1_Attack_Reverse);
				ResetLiveTime();
				return;
			}
		}
		
	
}

void Ph3_DogAirplane::Rotation_Pase2_Laser_Attack_Update(float _Time)
{


}

void Ph3_DogAirplane::Rotation_Pase2_Laser_Attack_Reverse_Update(float _Time)
{
}

void Ph3_DogAirplane::Rotation_Pase3_Laser_Attack_Update(float _Time)
{
}

void Ph3_DogAirplane::Rotation_Pase3_Laser_Attack_Reverse_Update(float _Time)
{
}
