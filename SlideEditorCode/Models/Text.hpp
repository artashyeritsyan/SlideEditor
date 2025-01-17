#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

class Text {
public:
    Text() {}
    Text(const std::string& data) : _content(data) {}

    void setContent(const std::string& data);
    std::string getContent() const;

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
    std::string _content = "";
    int _textSize = 9;
    std::string font = "Arial";

    bool _italic = false;
    bool _bold = false; 
    bool _underlined = false;
};

#endif // TEXT_HPP