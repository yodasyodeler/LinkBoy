#include "SFML-GUI\Label.h"

Label::Label()
	:Rectangle()
{
	m_text.setScale({ .5f, .5f });
}

Label::Label(const sf::Vector2f pos, const sf::Vector2f size, const sf::Color color)
	:Rectangle(pos, size, color)
{
	m_text.setScale({ .5f, .5f });
}

Label::~Label()
{}

void Label::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void Label::setTextColor(const sf::Color color)
{
	m_text.setColor(color);
}

//void Label::setFontSize(const int size)
//{
//	m_text.setCharacterSize(size);
//}

void Label::setText(const char* text)
{
	m_text.setString(text);
}

void Label::setPadding(const unsigned int padding)
{
	m_padding = padding;
	adjustRectangle();
}

void Label::adjustRectangle()
{
	int size;
	Rectangle::adjustRectangle();

	size = (int)(((m_size.y) < 0) ? 0 : (m_size.y));
	m_text.setCharacterSize(size);
	m_text.setPosition({ m_pos.x+2, (m_size.y/4)+m_pos.y });
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Rectangle::draw(target, states);
	if (m_text.getFont() != nullptr && m_visible)
		target.draw(m_text, states);
}