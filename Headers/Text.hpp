#pragma once

#include "Item.hpp"
#include "AlignTypeEnum.hpp"
#include "RGB.hpp"

class Text : Item {
public:
    Text() {}
    // TODO: write an constructor for Item class to set a shape type

private:
    std::string data;
    int textSize;
    int BoxSize;
    std::string font;
    AlignTypeEnum alignment;
    RGB color;
    RGB highlightColor;

    bool italic;
    bool bold; 
    bool underlined;
    
private:
    std::string getText() const;
    int getTextSize() const;
    int getBoxSize() const;
    std::string getFont() const;
    AlignTypeEnum getAlignment() const;
    RGB getColor() const;
    RGB getHighlightColor() const;
    bool isItalic() const;
    bool isBold() const;
    bool isUnderlined() const;

    void setText(const std::string& value);
    void setTextSize(int value);
    void setBoxSize(int value);
    void setFont(const std::string& value);
    void setAlignment(AlignTypeEnum value);
    void setColor(const RGB& value);
    void setHighlightColor(const RGB& value);
    void setItalic(bool value);
    void setBold(bool value);
    void setUnderlined(bool value);
    
};