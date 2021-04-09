#include "../Headers/trie.h"
#include <vector>

MakeTrie::MakeTrie(const std::string& s) {
    Parser *pars = new Parser(s);
    std::vector<std::string> parsedLine = pars->getWords();
    root = getNewTrieNode();
    if (parsedLine.size() == 0) {
        perror("You wrote only with spaces line");
    }
    for (int i = 0; i < parsedLine.size(); i++) {
        insert(parsedLine[i]);
    }
    delete pars;
}

void MakeTrie::insert(const std::string& s) {
    Trie* node = root;
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];
        if (node->map.find(x) == node->map.end()) {
            node->map[x] = getNewTrieNode();
            node->map[x]->parent = node;
            node->map[x]->symbol = x;
        }

        node = node->map[x];
    }

    node->terminalVertex = true;
    node->word = s;
}

Trie* MakeTrie::getNewTrieNode() {
    Trie* node = new Trie;
    node->terminalVertex = false;
    node->parent = nullptr;
    node->termLinkCache = nullptr;
    node->sufLinkCache = nullptr;
    node->word = "";
    return node;
}
