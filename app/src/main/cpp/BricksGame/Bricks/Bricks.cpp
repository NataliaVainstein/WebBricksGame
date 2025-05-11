#include "Bricks.h"
#include "../StableBrick/StableBrick.h"
#include "../MovableBrick/MovableBrick.h"
#include "../LevelLoader/LevelLoader.h"
#include <string>
#include <vector>
#include "../Ball/Ball.h"
#include "../Collision/Collision.h"

class Drawer
{
public:
	Drawer(Frame& _frame)
	:m_frame(_frame)
	{
	}
	void operator()(Brick* _br)
	{
		_br->draw(m_frame);
	}
private:
		Frame& m_frame;
};

class Collider
{
public:
	Collider(Collision& _collideWith, int& _points, int& _breakableBricks)
	:m_collideWith(_collideWith)
	,m_points(_points)
	,m_breakableBricks(_breakableBricks)
	{
	}
	void operator()(Brick* _br)
	{
		if (m_collideWith.collide(*_br, m_points) == Collision::COLLISION_BREAKABLE_BRICKS)
		{
			--m_breakableBricks;
		}

	}
private:
	Collision& m_collideWith;
	int& m_points;
	int& m_breakableBricks;
};


constexpr float OFFSET  = 15.f;
constexpr float OFFSET_Y = 20.f;
constexpr float BRICKS_INTERVAL  = 10.f;
constexpr float BRICK_HEIGHT = 40.f;
constexpr float BRICK_WIDTH = 100.f;
constexpr float LEFT_STABLE_BRICK_Y_POSITION = 0.f;
constexpr float RIGHT_STABLE_BRICK_Y_POSITION = 0.f;
constexpr float TOP_STABLE_BRICK_X_POSITION = 0.f;

Bricks::Bricks(sf::Vector2f& _frameDimension)
:m_breakableBricks(0)
{

	Brick*  brLeft = new StableBrick(_frameDimension.x, BRICK_WIDTH, -BRICK_WIDTH, LEFT_STABLE_BRICK_Y_POSITION);
	Brick*  brRight = new StableBrick(_frameDimension.x,BRICK_WIDTH, _frameDimension.y, RIGHT_STABLE_BRICK_Y_POSITION);
	Brick* brTop = new StableBrick(BRICK_HEIGHT, _frameDimension.y, TOP_STABLE_BRICK_X_POSITION, -BRICK_HEIGHT);

	m_shapes.push_back(brLeft);
	m_shapes.push_back(brRight);
	m_shapes.push_back(brTop);

	std::string levelStr("/home/vboxuser/Projects/WebBricksGame/app/src/main/bin-vscode/Debug/level1.txt");
	LevelLoader level;
	size_t numLevelLines = level.numberLines();

	size_t numLine = 0;
	bool readLineRes = true;

	for (size_t numLine = 0; numLine < numLevelLines; ++ numLine)
	{
		float posX = OFFSET;
		float posY = OFFSET_Y + BRICKS_INTERVAL + numLine * (BRICKS_INTERVAL + BRICK_HEIGHT);
		std::string brickLine;
		readLineRes = level.getLine(brickLine, numLine);
		if(readLineRes)
		{
			std::string::iterator endItr = brickLine.end();
			for(std::string::iterator it = brickLine.begin(); it != endItr; ++it)
			{
				if(*it != ' ')
				{
					addBrick(*it, posX, posY);
				}

				posX += BRICK_WIDTH + BRICKS_INTERVAL;
			}
		}
	}

}

Bricks::~Bricks()
{
	for (Brick* brick : m_shapes)
	{
		delete brick;
	}

	m_shapes.clear();
}

void Bricks:: addBrick(char c, int _posX, int _posY)
{
	Brick* b;

	if(c == 'N')
	{
		b = new MovableBrick(BRICK_HEIGHT, BRICK_WIDTH, _posX, _posY);
		++m_breakableBricks;
	}
	if(c == 'S')
	{
		b = new StableBrick(BRICK_HEIGHT, BRICK_WIDTH, _posX, _posY);
	}

	m_shapes.push_back(b);
}

void Bricks::draw(Frame& _frame)
{
	std::for_each(m_shapes.begin(), m_shapes.end(), Drawer(_frame));
}

void Bricks::collide(Collision& _collideWith, Bricks::collideWithEnum _collideType, int& _points)
{
	if(_collideType == _ALL_BRICKS)
	{
		std::for_each(m_shapes.begin(), m_shapes.end(), Collider(_collideWith, _points, m_breakableBricks));
	}
	else
	{
		_collideWith.collide(*m_shapes[0], _points);
		_collideWith.collide(*m_shapes[1], _points);
	}
}

Brick* Bricks::getBrick(size_t i)
{
	return m_shapes[i];
}

bool Bricks::isGameEnding(sf::Text& gameResultText)
{
	if (m_breakableBricks == 0)
	{
		gameResultText.setString("It's a win!");
		return true;
	}

	return false;
}
