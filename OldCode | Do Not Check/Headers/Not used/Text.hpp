#pragma once

#include "Item.hpp"
#include "AlignTypeEnum.hpp"
#include "RGB.hpp"

class Text : public Item {
public:
    // Text() {}

    Text(const std::string& name, 
        ItemTypeEnum type, 
        int layerOrder, 
        const std::pair<int, int>& position)
    : Item(name, type, layerOrder, position) {}

    // TODO: write an constructor for Item class to set a shape type

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
    void setFont(const std::string& value);
    void setAlignment(AlignTypeEnum value);
    void setColor(const RGB& value);
    void setHighlightColor(const RGB& value);
    void setItalic(bool value);
    void setBold(bool value);
    void setUnderlined(bool value); 

private:
    std::string data = "";
    int textSize = 9;
    std::string font = "Arial";
    AlignTypeEnum alignment = Center;

    RGB color;
    RGB highlightColor;

    bool italic = false;
    bool bold = false; 
    bool underlined = false;
   
};