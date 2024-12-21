#include "Text.hpp"

void Text::setContent(const std::string &data)
{
    this->_content = data;
}

std::string Text::getContent() const
{
    return _content;
}

void Text::setTextSize(int textSize)
{
    this->_textSize = textSize;
}

int Text::getTextSize() const
{
    return _textSize;
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
    this->_italic = italic;
}

bool Text::getItalic() const
{
    return _italic;
}

void Text::setBold(bool bold)
{
    this->_bold = bold;
}

bool Text::getBold() const
{
    return _bold;
}

void Text::setUnderlined(bool underlined)
{
    this->_underlined = underlined;
}

bool Text::getUnderlined() const
{
    return _underlined;
}