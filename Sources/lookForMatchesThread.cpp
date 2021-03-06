#include "../Headers/lookForMatchesThread.h"

WorkerThread::WorkerThread(const std::string &s) {
    words = s;
}

void WorkerThread::run() {
    emit startCalculating();
    std::fstream fin;
    fin.open("../words.txt");

    AhoKorasik *g = new AhoKorasik(words);

    emit startCalculating();

    int count = 0;
    Tolower newTolower;
    std::string line;
    while (fin >> line) {
        std::string result;
        newTolower.makeLower(line);
        result = g->algorithmRealization(line);
        if (!result.empty()) {
            count++;
            emit foundWords(QString::fromStdString(line));
        }
    }
    fin.close();
    emit finishedCalculating(count);
}

