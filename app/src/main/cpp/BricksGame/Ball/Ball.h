#ifndef __BALL__
#define __BALL__

#include "../Frame/Frame.h"
#include "../Collision/Collision.h"
#include "../Drawable/Drawable.h"
#include "../Animatable/Animatable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../GameEnding/GameEnding.h"

class Ball:public Animatable, public Drawable, public Collision, public sf::CircleShape, public GameEnding
{
public:
	Ball(float _radius,float _xPosition,float _yPosition,float _xspeed,float _yspeed, sf::Vector2f& _frameDimensions);
	~Ball();

	void animate();
	void draw(Frame& _frame);
	
	sf::Vector2f speed();
	const sf::Vector2f& getShapeSize() const;
	const sf::Vector2f& getShapePosition() const;
	
	COLLISION_TYPE collide(Collision& _collideWith,  int& _addPoints);
	bool isRightLeftCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize);
	bool isTopButtomCollision(const sf::Vector2f& _collideWithPos, const sf::Vector2f& _collideWithSize, const sf::Vector2f& _thisPos, const sf::Vector2f& _thisSize);

	bool isGameEnding(sf::Text& gameResultText);

private: 
	bool isBetween(float _underTest, float _lesserBound, float _greaterBound);
	
private:	
	float m_radius;
	float m_xposition;
	float m_yposition;
	float m_xspeed;
	float m_yspeed;
	sf::Vector2f m_speed;
	sf::Vector2f m_squereSize;
	sf::Vector2f& m_frameDimensions;
};


#endif //__BALL__
