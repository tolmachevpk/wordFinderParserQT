#include "../Headers/mainWindow.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow addressBook;
    addressBook.show();

    return app.exec();
}
