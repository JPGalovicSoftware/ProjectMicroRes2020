#pragma once

#include <Entropy/GameState.h>
#include <Entropy/Graphics/Window.h>

#include "SpriteRenderer.h"

class StatePause : public Entropy::GameState
{
private:
	SpriteRenderer renderer;

	int selection;
	
	bool key_down;
	bool execute_selection;

public:
	StatePause() : GameState("Pause", 2) {
		init();
	};

	// Inherited via GameState
	virtual bool init() override;
	virtual void input(Entropy::Graphics::Window& window) override;
	virtual void render() override;
	virtual GameState* update(GameState* gameState) override;
};