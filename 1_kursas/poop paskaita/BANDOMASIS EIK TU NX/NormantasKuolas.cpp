#include <iostream>
#include <string>
#include <vector>
class MySentence{
private:
    std::string text;

public:
    MySentence(std::string text);
    ~MySentence();
   
    //setters
    void setText(std::string text);

    //getters
    std::string getText();

    void print();
};

class MyParagraph{
private:
    int sCount = 0;
    std::vector<std::string> Paragraph;
public:
    MyParagraph();
    ~MyParagraph();

    void setParagraph(MySentence sentence);

    std::string getParagraph();

    void print();

};
MySentence::MySentence(std::string text)
{
    setText(text);
}

MySentence::~MySentence()
{
    std::cout << "Object removed successfully" << std::endl;
    text.clear();
}

void MySentence::setText(std::string text)
{
    this -> text = text;
}

std::string MySentence::getText()
{
    return text;
}

void MySentence::print()
{
    std::cout << text << std::endl;
}

void MyParagraph::setParagraph(MySentence sentence)
{
    sCount++;
    Paragraph.push_back(sentence.getText());

}
int main()
{
    MySentence a("testas?");
    MySentence b("testavimas!");
    // MyParagraph d();
    // d.setParagraph(b);
    // d.setParagraph(a);
    // b.getText();
    a.print();
    return 0;
}