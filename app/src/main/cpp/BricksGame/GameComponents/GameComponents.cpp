#include "GameComponents.h"

constexpr float BALL_RADIUS = 10.f;
constexpr float BALL_XPOSITION = 50.f;
constexpr float BALL_YPOSITION = 200.f;
constexpr float BALL_XSPEED = 2.f;
constexpr float BALL_YSPEED = 3.f;
constexpr float PEDAL_HEIGHT = 25.f;
constexpr float PEDAL_WIDTH = 150.f;
constexpr float PEDAL_XPOSITION = 300.f;
constexpr float PEDAL_YPOSITION = 500.f;
constexpr float SCORE_OFFSET_Y = 15.f;


GameComponents::GameComponents(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePosition, sf::RenderWindow& _frameWindow)
:m_frame(_frameDimensions, _framePosition, _frameWindow)
,m_ball(BALL_RADIUS, BALL_XPOSITION, BALL_YPOSITION, BALL_XSPEED, BALL_YSPEED, _frameDimensions)
,m_bricks(_frameDimensions)
,m_pedal(PEDAL_HEIGHT, PEDAL_WIDTH, PEDAL_XPOSITION, PEDAL_YPOSITION)
,m_score(sf::Vector2f(SCORE_OFFSET_Y, 0))
,m_frameDimensions(_frameDimensions)
,m_isEndOfTheGame(false)
,m_gameResult(m_ball, m_bricks, m_isEndOfTheGame, m_frameDimensions)
{
}

GameComponents::~GameComponents()
{
}

void GameComponents:: draw()
{
	m_frame.clear();
	if(!m_isEndOfTheGame)
	{
		m_ball.draw(m_frame);
		m_bricks.draw(m_frame);
		m_pedal.draw(m_frame);
	}
	m_score.draw(m_frame);
	m_gameResult.draw(m_frame);
	m_frame.display();
}

void GameComponents::handleEvent(sf::Event _event)
{
	m_frame.handleEvent(_event);
	m_pedal.handleEvent(_event);
}

void  GameComponents::animate()
{
	m_ball.animate();
	m_pedal.animate();
}

void GameComponents::collide()
{
	int points = 0;
	m_bricks.collide(m_ball, Bricks::_ALL_BRICKS, points);
	m_bricks.collide(m_pedal, Bricks::_HORIZONTAL_FRAME_BRICKS_, points);
	m_ball.collide(m_pedal, points);
	m_score.add(points);
}

void GameComponents:: run()
{
	while(m_frame.isOpen())
	{
		draw();
		sf::Event e = m_frame.pollEvents();
		handleEvent(e);
		collide();
		animate();	
	}
}
