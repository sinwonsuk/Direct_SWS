#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class DogAirplaneState
{
	BossIntro,
	BossIntroRock,
	BossIntroDust,
	BossIdle,
	BossIdleHand,
	noumIntro,


};

class DogAirplane : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplane();
	~DogAirplane();

	// delete Function
	DogAirplane(const DogAirplane& _Other) = delete;
	DogAirplane(DogAirplane&& _Other) noexcept = delete;
	DogAirplane& operator=(const DogAirplane& _Other) = delete;
	DogAirplane& operator=(DogAirplane&& _Other) noexcept = delete;
	void ChangeState(DogAirplane _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	void ChangeState(DogAirplaneState _State);

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	std::vector<int> a;
	float DownSpeed = 200;
	DogAirplaneState StateValue = DogAirplaneState::BossIntro;

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> GirlDog;
	std::shared_ptr<class GameEngineSpriteRenderer> dogcopter;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldog;
	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneSpin;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro1;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro2;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;
	
};
