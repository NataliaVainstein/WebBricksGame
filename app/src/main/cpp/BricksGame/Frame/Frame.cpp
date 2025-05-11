#include "Frame.h"
#include "../Score/Score.h"


Frame::Frame(sf::Vector2f& _frameDimensions, sf::Vector2f& _framePossition, sf::RenderWindow& _frame)
:is::GameSystem(_frame)
,m_frameDimensions(_frameDimensions)
,m_frame(_frame)
{
	m_frame.setVerticalSyncEnabled(true);
	m_frame.setPosition(sf::Vector2i(_framePossition.y, _framePossition.x));
}

Frame::~Frame()
{
}

bool Frame::isOpen()
{
	return m_frame.isOpen();
}



void Frame::clear()
{
	m_frame.clear(sf::Color::Blue);
}

void Frame::display()
{
	m_frame.display();
}

sf::Event Frame::pollEvents()
{			               
   	sf::Event event; 
	while (m_frame.pollEvent(event))
	{
		return event;
	}
	
	return event;
}

void Frame::handleEvent(sf::Event _event)
{
	switch(_event.type)
	{
		case sf::Event::Closed:
			m_frame.close();
			break;
		case sf::Event::KeyPressed:
			switch(_event.key.code)
			{
				case sf::Keyboard::Escape:
					m_frame.close();
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void Frame::draw(sf::Drawable* _shape)
{
	m_frame.draw(*_shape);
}

const sf::Vector2f& Frame::frameDimensions() const
{
		return m_frameDimensions;
}
