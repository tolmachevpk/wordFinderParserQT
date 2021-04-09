#include "../Headers/parser.h"

Parser::Parser(std::string s) {
    toLower(s);
    parser(s);
}

void Parser::parser(std::string& s) {
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        words.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    if (s != "") {
        words.push_back(s);
    }
}

void Parser::toLower(std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

std::vector<std::string> Parser::getWords() {
    return words;
}