#include "MainWindow.h"
#include "NewBill.h"
#include <QStringListModel>
#include <QFileSystemModel>
#include <QStringList>
#include <QModelIndex>
#include <QListView>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(void):
    m_ListEntity(new QStringListModel()),
    m_ListFile(new QFileSystemModel())
{
    QListView *fileList;

    /*** Menu bar ***/
    QMenu *new_menu = menuBar()->addMenu("&Nouvelle...");
    {
        m_Actions.newBill = new QAction("&Facture", this);
        new_menu->addAction(m_Actions.newBill);

        m_Actions.newEntity = new QAction("&Entitée", this);
        new_menu->addAction(m_Actions.newEntity);

        m_Actions.newCategory = new QAction("&Catégorie", this);
        new_menu->addAction(m_Actions.newCategory);

        m_Actions.settings = new QAction("&Préférences", this);
        menuBar()->addAction(m_Actions.settings);
    }

    /*** Main Layout ***/
    QWidget *window = new QWidget;
        QGridLayout *mainLayout = new QGridLayout;
        {
            QListView *entityList = new QListView;
            entityList->setModel(m_ListEntity);
            entityList->setEditTriggers(QAbstractItemView::NoEditTriggers);
            entityList->setViewMode(QListView::ViewMode::IconMode);
            mainLayout->addWidget(entityList, 0, 0);

            fileList = new QListView;
            fileList->setModel(m_ListFile);
            fileList->setRootIndex(m_ListFile->index("./assets"));

            mainLayout->addWidget(fileList, 0, 1, 2, 1);

            QGroupBox *infogroupbox = new QGroupBox(tr("Informations"));
                QVBoxLayout *info = new QVBoxLayout;
                {

                    QLabel *resteAPayer = new QLabel(tr("Reste à payer: "));
                    info->addWidget(resteAPayer);

                    QLabel *resteAManger = new QLabel(tr("Reste à manger: "));
                    info->addWidget(resteAManger);

                }
                infogroupbox->setLayout(info);
            mainLayout->addWidget(infogroupbox, 1, 0);
        }
        window->setLayout(mainLayout);
    setCentralWidget(window);

    /*** Action behaviour and slot connection ***/
    connect(fileList, &QListView::clicked, this, &MainWindow::openNewBill);

    /*** Member initialisation ***/
    m_ListEntity->setStringList({"a", "b"});
    m_ListFile->setRootPath("~/oeuvre/finance/");
}

void MainWindow::openNewBill(const QModelIndex &index)
{
    QString item = m_ListFile->filePath(index);
    NewBill(item).exec();
}
