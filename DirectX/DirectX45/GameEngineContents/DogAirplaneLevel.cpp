#include "PrecompileHeader.h"
#include "DogAirplaneLevel.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "DogAirplane.h"
#include "Player.h"
#include "NpcAirplane.h"
#include "Ph2_DogAirpalne.h"
#include "DogAirplaneBackground.h"
#include "ph3_DogAirPlane.h"
#include "ph3_Laser.h"
DogAirplaneLevel::DogAirplaneLevel()
{
}

DogAirplaneLevel::~DogAirplaneLevel()
{
}

void DogAirplaneLevel::Update(float _DeltaTime)
{
}

void DogAirplaneLevel::Start()
{
	
	GetMainCamera()->SetSortType(0,SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	//{
	//	std::shared_ptr<DogAirplane> Object = CreateActor<DogAirplane>();
	//}
	//{
	//	std::shared_ptr<DogAirplaneBackground> Object = CreateActor<DogAirplaneBackground>();
	//}
	//{
	//	std::shared_ptr<NpcAirplane> Object = CreateActor<NpcAirplane>(2);
	//}
	//{
	//	std::shared_ptr<Player> Object = CreateActor<Player>(4);
	//	Object->GetTransform()->AddLocalPosition({ -350,0,0 });
	//}
	//{
	//	std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
	//	//Object->GetTransform()->AddLocalPosition({ -350,0,0 });
	//}
	

	{
		std::shared_ptr<Ph3_DogAirplane> Object = CreateActor<Ph3_DogAirplane>(3);		
	}
	
		
	
}

void DogAirplaneLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}


void DogAirplaneLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}

void DogAirplaneLevel::PlayerCreate()
{
}
