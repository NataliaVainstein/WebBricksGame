#ifndef __GAME_COMPONENTS__
#define __GAME_COMPONENTS__


#include "../Frame/Frame.h"
#include "../Brick/Brick.h"
#include "../Bricks/Bricks.h"
#include "../Pedal/Pedal.h"
#include "../Ball/Ball.h"
#include "../Score/Score.h"
#include "../GameResult/GameResult.h"

class GameComponents
{
public: 	
	GameComponents(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePosition, sf::RenderWindow& _frameWindow);
	~GameComponents();
	
	void draw();
	void handleEvent(sf::Event _event);
	void animate();
	void collide();
	void run();
private:
	GameComponents(const GameComponents&);
	GameComponents& operator=(const GameComponents&);
	
private:
	Frame m_frame;
	Ball m_ball;
	Bricks m_bricks;
	Pedal m_pedal;
	Score m_score;
	sf::Vector2f& m_frameDimensions;
	bool m_isEndOfTheGame;
	GameResult m_gameResult;
};

#endif //__GAME_COMPONENTS__
