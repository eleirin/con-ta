#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QSqlDatabase>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*** Translation ***/
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    /*** Setting sql connection ***/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance");
    db.open();

    /*** Main window display ***/
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
