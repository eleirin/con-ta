#include "MainWindow.h"
#include <QStringListModel>
#include <QFileSystemModel>
#include <QStringList>
#include <QListView>
#include <QGridLayout>

MainWindow::MainWindow(void):
    m_ListEntity(new QStringListModel()),
    m_ListFile(new QFileSystemModel())
{
    /*** Main Layout ***/
    QWidget *window = new QWidget;
        QGridLayout *mainLayout = new QGridLayout;
        {
            QListView *entityList = new QListView;
            entityList->setModel(m_ListEntity);
            entityList->setEditTriggers(QAbstractItemView::NoEditTriggers);
            entityList->setViewMode(QListView::ViewMode::IconMode);
            mainLayout->addWidget(entityList);

            QListView *fileList = new QListView;
            fileList->setModel(m_ListFile);
            fileList->setViewMode(QListView::ViewMode::IconMode);
            fileList->setRootIndex(m_ListFile->index(QDir::currentPath()));
            mainLayout->addWidget(fileList);
        }
        window->setLayout(mainLayout);
    setCentralWidget(window);

    /*** Member initialisation ***/
    m_ListEntity->setStringList({"a", "b"});
    m_ListFile->setRootPath("~/oeuvre/finance/");
}
