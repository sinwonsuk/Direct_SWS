#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class PlayerState
{
	Idle,
	Run,
	Jump,
	Attack,
	Duck,
};
// ���� :
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);

	void IdleUpdate(float _Time);
	void RunUpdate(float _Time);
	void JumpUpdate(float _Time);
	void DuckUpdate(float _Time);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	PlayerState StateValue = PlayerState::Idle;
	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Render0;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;

	int GravityCheck = 0; 
	int RightCheck = 0;
	int LeftCheck = 0;
	float Speed = 200;
	float GravitySpeed = 400;
	float JumpSpeed = 1200;
	bool Gravity = false;
	bool RightMove = true;
	bool LeftMove = true;
	bool JumpCheck = false;
};

