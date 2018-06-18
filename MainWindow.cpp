#include "MainWindow.h"
#include <QStringListModel>
#include <QStringList>
#include <QListView>

MainWindow::MainWindow(void)
{
    QStringListModel *model = new QStringListModel();
    QStringList list = {"a", "b", "c"};
    model->setStringList(list);

    QListView *central = new QListView;
    central->setModel(model);
    central->setEditTriggers(QAbstractItemView::NoEditTriggers);
    central->setViewMode(QListView::ViewMode::IconMode);
    setCentralWidget(central);
}
