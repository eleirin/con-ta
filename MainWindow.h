#ifndef HEAD_MAINWINDOW
#define HEAD_MAINWINDOW
#include <QMainWindow>
class QStringListModel;
class QFileSystemModel;
class QModelIndex;

class MainWindow: public QMainWindow
{
public:
    MainWindow(void);

private slots:
    void openNewBill(const QModelIndex &index);

private:
    QStringListModel *m_ListEntity;
    QFileSystemModel *m_ListFile;
};
#endif //HEAD_MAINWINDOW
