#ifndef __BRICKS__
#define __BRICKS__

#include "../Brick/Brick.h"
#include "../Frame/Frame.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../GameEnding/GameEnding.h"

class Bricks: GameEnding
{
public:
	Bricks(sf::Vector2f& _frameDimension);
	~Bricks();
	
	enum collideWithEnum
	{
		_ALL_BRICKS,
		_HORIZONTAL_FRAME_BRICKS_
	};
	
	void draw(Frame& _frame);
	void collide(Collision& _collideWith, Bricks::collideWithEnum _collideType, int& _points);
	Brick* getBrick(size_t i);

	bool isGameEnding(sf::Text& gameResultText);
	
private: 
	Bricks(const Bricks&);
	Bricks& operator=(const Bricks&); 
	void addBrick(char c, int _posX, int _posY);
	
private:
	int m_breakableBricks;
	std::vector<Brick*> m_shapes;
};

#endif //__BRICKS__
