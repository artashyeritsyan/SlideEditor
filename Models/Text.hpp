#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

class Text {
public:
    Text() {}

    void setData(const std::string& data);
    std::string getData() const;

    void setTextSize(int textSize);
    int getTextSize() const;

    void setFont(const std::string& font);
    std::string getFont() const;

    void setItalic(bool italic);
    bool getItalic() const;

    void setBold(bool bold);
    bool getBold() const;

    void setUnderlined(bool underlined);
    bool getUnderlined() const;
    
private:
    std::string data = "";
    int textSize = 9;
    std::string font = "Arial";

    bool italic = false;
    bool bold = false; 
    bool underlined = false;
};

#endif // TEXT_HPP