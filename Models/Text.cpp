#include "Text.hpp"

void Text::setData(const std::string &data)
{
    this->data = data;
}

std::string Text::getData() const
{
    return data;
}

void Text::setTextSize(int textSize)
{
    this->textSize = textSize;
}

int Text::getTextSize() const
{
    return textSize;
}

void Text::setFont(const std::string &font)
{
    this->font = font;
}

std::string Text::getFont() const
{
    return font;
}

void Text::setItalic(bool italic)
{
    this->italic = italic;
}

bool Text::getItalic() const
{
    return italic;
}

void Text::setBold(bool bold)
{
    this->bold = bold;
}

bool Text::getBold() const
{
    return bold;
}

void Text::setUnderlined(bool underlined)
{
    this->underlined = underlined;
}

bool Text::getUnderlined() const
{
    return underlined;
}