#ifndef WORDPARSERFINDER_STRUCTTRIE_H
#define WORDPARSERFINDER_STRUCTTRIE_H
#include <unordered_map>

struct Trie {
    bool terminalVertex;
    std::unordered_map<char, Trie*> map;
    Trie* parent;
    char symbol;
    Trie* sufLinkCache;
    Trie* termLinkCache;
    std::string word;
};

#endif // WORDPARSERFINDER_STRUCTTRIE_H