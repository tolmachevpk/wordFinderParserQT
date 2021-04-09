#include <vector>
#include <string>
#include <string>

class Parser {
public:
    Parser(std::string s);
    std::vector<std::string> getWords();

private:
    void toLower(std::string& s);
    void parser(std::string& s);
    std::vector<std::string> words;

};
