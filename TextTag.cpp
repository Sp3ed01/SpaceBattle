#include "TextTag.h"


TextTag::TextTag(Font *font,std::string text,const Color color,
	Vector2f position,unsigned int size)
{
	this->dtMultiplier = 62.5f;
	this->text.setFont(*font);
	this->text.setCharacterSize(size);
	this->text.setPosition(position);
	this->text.setString(text);
	this->text.setColor(color);

	this->speed = 5.f;
	this->direction.x = 0.f;
	this->direction.y = -1.f;
	this->timerMax = 10.f;
	this->timer = this->timerMax;

}



TextTag::~TextTag()
{

}

void TextTag::Update(const float& dt)
{
	//Update timer
	if (this->timer > 0.f)
	{
		this->timer -= 1.f * dt * this->dtMultiplier;
		this->text.move(this->direction.x * this->speed * dt * this->dtMultiplier,
			this->direction.y * this->speed * dt * this->dtMultiplier);
	}
	else
		this->text.setFillColor(Color(0, 0, 0, 0));
}
void TextTag::Draw(RenderTarget &target)
{
	target.draw(this->text);
}