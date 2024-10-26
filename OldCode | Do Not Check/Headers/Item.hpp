#pragma once

#include <string>

#include "ItemTypeEnum.hpp"

class Item {
public:
    Item (const std::string& name, ItemTypeEnum type, int layerOrder, const std::pair<int, int>& position);
    Item() = default;

    std::string getName() const;
    ItemTypeEnum getType() const;
    std::pair<int, int> getPosition() const;
    int getLayer() const;
    int getWidth() const;
    int getHeight() const;
    RGB getBoxColor() const;
    RGB getOutlineColor() const;
    RGB getTextColor() const;
    RGB getHighlightColor() const;
    std::string getData() const;
    int getTextSize() const;
    std::string getFont() const;
    AlignTypeEnum getAlignment() const;
    bool isItalic() const;
    bool isBold() const;
    bool isUnderlined() const;


    void setName(const std::string&);
    void setType(ItemTypeEnum type) {this->type = type;}
    void setPosition(std::pair<int, int>);
    void setPosition(int x, int y);
    void setLayer(int layerOrder);
    void setWidth(int value);
    void setHeight(int value);
    void setBoxColor(const RGB& value);
    void setOutlineColor(const RGB& value);
    void setTextColor(const RGB& value);
    void setHighlightColor(const RGB& value);
    void setData(const std::string& value);
    void setTextSize(int value);
    void setFont(const std::string& value);
    void setAlignment(AlignTypeEnum value);
    void setItalic(bool value);
    void setBold(bool value);
    void setUnderlined(bool value);
    

    void bringForward();
    void sendBackward();
    void bringToFront();
    void sendToBack();


private:
    std::string name;
    ItemTypeEnum type = Text;
    int layerOrder;
    std::pair<int, int> position = {0, 0};
    int width = 10;
    int height = 10;

    RGB boxColor;
    RGB outlineColor;
    RGB textColor;
    RGB highlightColor;

    // Parameters for textBox
    std::string data = "";
    int textSize = 9;
    std::string font = "Arial";
    AlignTypeEnum alignment = Center;

    bool italic = false;
    bool bold = false; 
    bool underlined = false;

};