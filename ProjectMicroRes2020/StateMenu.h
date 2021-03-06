#pragma once

#include <Entropy/GameState.h>
#include <Entropy/Graphics/Window.h>
#include <Entropy/Math/Vec2.h>

#include "SpriteRenderer.h"
#include "AnimationRenderer.h"

class StateMenu : public Entropy::GameState
{
private:
	SpriteRenderer renderer;
	AnimationRenderer animRenderer;

	int selection;

	bool key_down;
	bool execute_selection;

public:
	StateMenu() : GameState("Menu", 2) {
		init();
	};

	// Inherited via GameState
	virtual bool init() override;
	virtual void input(Entropy::Graphics::Window& window) override;
	virtual void render() override;
	virtual GameState* update(GameState* gameState) override;
};
