#ifndef WORDPARSERFINDER_MAINWINDOW_H
#define WORDPARSERFINDER_MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include "lookForMatchesThread.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void rememberWordsForString();
    void addToResult(const QString&);
    void finished();
    void started();

private:
    void startWorkInAThread();
    QLineEdit *wroteWords;
    QTextEdit *foundResult;
    QPushButton *confirmButton;
    std::string words;
    QLabel *status;
};

#endif //WORDPARSERFINDER_MAINWINDOW_H
