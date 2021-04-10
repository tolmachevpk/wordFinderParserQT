#include "../Headers/tolower.h"

void Tolower::makeLower(std::string &str) {
    for (int a = 0; a < str.size(); a++) {
        if ((str[a] < 97) && isalpha(str[a]))
            str[a] = str[a] + 32;
    }
}