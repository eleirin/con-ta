#ifndef HEAD_MAINWINDOW
#define HEAD_MAINWINDOW
#include <QMainWindow>
class QStringListModel;
class QFileSystemModel;
class QModelIndex;
class QAction;

class MainWindow: public QMainWindow
{
public:
    MainWindow(void);

private slots:
    void openNewBill(const QModelIndex &index);

private:
    struct Actions
    {
        QAction *newBill;
        QAction *newEntity;
        QAction *newCategory;
        QAction *settings;
    } m_Actions;

    QStringListModel *m_ListEntity;
    QFileSystemModel *m_ListFile;
};
#endif //HEAD_MAINWINDOW
