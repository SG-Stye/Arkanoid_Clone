#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Sound.h"
#include "Brick.h"
#include "Paddle.h"
#include "Walls.h"
#include "LifeCounter.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel( float dt );
	/********************************/
	/*  User Functions              */
	void StartRound();
	void ResetBall();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr float brickWidth = 40.0f;
	static constexpr float brickHeight = 22.0f;
	static constexpr int nBricksAcross = 12;
	static constexpr int nBricksDown = 4;
	static constexpr int nBricks = nBricksAcross * nBricksDown;
	static constexpr float topSpace = brickHeight * 1.6f;
	static constexpr float wallThickness = 15.0f;
	static constexpr float fieldWidth = float( nBricksAcross ) * brickWidth;
	static constexpr float fieldHeight = float( Graphics::ScreenHeight ) - wallThickness * 2.0f;
	static constexpr Color brickColors[4] = { {100,50,30},{ 0,230,0 },{ 50,100,150 },{ 0,230,230 } };
	static constexpr Color wallColor = { 50,100,60 };
	static constexpr float readyWaitTime = 2.5f;
	// 0:not started  1:playing  2:game over 3:readywait
	int gameState = 0;
	FrameTimer ft;
	Ball ball;
	Brick bricks[nBricks];
	Paddle pad;
	Walls walls;
	LifeCounter lifeCounter;
	bool gameIsOver = false;
	float curWaitTime;
	Sound soundPad;
	Sound soundBrick;
	Sound soundFart;
	Sound soundReady;
	/********************************/
};