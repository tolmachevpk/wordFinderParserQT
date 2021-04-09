#ifndef WORDPARSERFINDER_TRIE_H
#define WORDPARSERFINDER_TRIE_H
#include "parser.h"
#include "structTrie.h"
#include <string>

class MakeTrie {
public:
    MakeTrie(const std::string& s); // создает бор по пришедшей строке
    Trie* root;

private:
    void insert(const std::string& s);
    Trie* getNewTrieNode();
};

#endif // WORDPARSERFINDER_TRIE_H