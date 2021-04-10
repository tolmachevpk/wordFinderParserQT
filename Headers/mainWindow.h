#ifndef WORDPARSERFINDER_MAINWINDOW_H
#define WORDPARSERFINDER_MAINWINDOW_H

#include <string>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QGridLayout>
#include <QMessageBox>
#include "lookForMatchesThread.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void rememberWordsForString();
    void addToResult(const QString&);
    void finished(const int &k);
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
