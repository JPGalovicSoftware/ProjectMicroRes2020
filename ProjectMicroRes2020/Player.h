#pragma once

#include "AnimatedGameObject.h"
#include "Direction.h"

class Player : public AnimatedGameObject
{
private:
	bool vulnerable;
	float timer;

	float invulnerable_time = 2.0f;

	Direction lastDirection;

	Entropy::Math::Vec2 heartPosition = Entropy::Math::Vec2(3.0f, 61.0f);
	Entropy::Math::Vec2 heartOffset = Entropy::Math::Vec2(4.0f, 0.0f);

	bool hurting;
	bool attacking;

	unsigned int hurtAnim;

public:
	Player(const char* spriteName = "char_player", unsigned int row = 0.0f,
		Entropy::Math::Vec2 position = Entropy::Math::Vec2(0.0f, 0.0f), Entropy::Math::Vec2 boxSize = Entropy::Math::Vec2(8.0f, 8.0f),
		Entropy::Math::Vec2 boxOffset = Entropy::Math::Vec2(4.0f, 4.0f), Entropy::Math::Vec2 textureOffset = Entropy::Math::Vec2(0.0f, 0.0f));

	Direction getLastDirection();

	void setAttacking();

	void stop();

	virtual void Update() override;
	virtual void Draw(SpriteRenderer& renderer) override;
};