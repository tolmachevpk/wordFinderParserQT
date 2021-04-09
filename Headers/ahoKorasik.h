#ifndef WORDPARSERFINDER_AHOKORASIK_H
#define WORDPARSERFINDER_AHOKORASIK_H
#include "trie.h"

class AhoKorasik : private MakeTrie {
public:
    explicit AhoKorasik(const std::string& s) : MakeTrie(s) {}
    std::string algorithmRealization(const std::string &word);
    bool out(Trie* node);
private:
    Trie* sufLink(Trie* node);
    Trie* goTo(Trie* node, char a);
    Trie* termLink(Trie* node);
};

#endif // WORDPARSERFINDER_AHOKORASIK_H