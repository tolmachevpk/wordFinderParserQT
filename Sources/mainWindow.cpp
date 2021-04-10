#include "../Headers/mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QLabel *nameLabel = new QLabel(tr("Write words:"));
    wroteWords = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Result:"));
    foundResult = new QTextEdit;
    foundResult->setReadOnly(true);

    status = new QLabel(tr("Waiting words..."));

    confirmButton = new QPushButton(tr("&Confirm"));
    confirmButton->show();
    connect(confirmButton, &QPushButton::clicked, this, &MainWindow::rememberWordsForString);

    QMenu * rerunMenu = new QMenu("&Rerun");
    rerunMenu->addAction("&Rerun program", this, SLOT(rerunProgram()),
                         Qt::CTRL + Qt::Key_R);

    QMenuBar *menuBar = new QMenuBar;
    menuBar->addMenu(rerunMenu);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(wroteWords, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(foundResult, 1, 1);
    mainLayout->addWidget(confirmButton, 1, 2, Qt::AlignTop);
    mainLayout->addWidget(status, 0, 2);
    mainLayout->setMenuBar(menuBar);

    resize(1100, 700);
    setLayout(mainLayout);
    setWindowTitle(tr("Word Finder"));
}

void MainWindow::rerunProgram() {
    foundResult->clear();
    wroteWords->clear();
    wroteWords->setReadOnly(false);
    confirmButton->setEnabled(true);
    status->setText(tr("Waiting words..."));
}

void MainWindow::rememberWordsForString() {
    words = wroteWords->text().toStdString();
    if (words.length() == 0) {
        QMessageBox::information(this, tr("Empty Field"), tr("Please enter words"));
        return;
    }
    wroteWords->setReadOnly(true);
    confirmButton->setEnabled(false);
    startWorkInAThread();
}

void MainWindow::startWorkInAThread() {
    WorkerThread *workerThread = new WorkerThread(words);

    connect(workerThread, SIGNAL(foundWords(QString)), this,
            SLOT(addToResult(const QString&)));

    connect(workerThread, SIGNAL(startCalculating()), this, SLOT(started()));

    connect(workerThread, SIGNAL(finishedCalculating(const int&)),
            this, SLOT(finished(const int&)));

    workerThread->start();
}

void MainWindow::started() {
    status->setText("Calculating...");
}

void MainWindow::finished(const int &k) {
    std::string res =  "Finished! Count\nof words: " + std::to_string(k);
    status->setText(QString::fromStdString(res));
}

void MainWindow::addToResult(const QString &calculatedWord) {
    foundResult->moveCursor(QTextCursor::End);
    foundResult->insertPlainText(calculatedWord);
    foundResult->moveCursor(QTextCursor::End);
    foundResult->insertPlainText("   ");
    foundResult->show();
}
