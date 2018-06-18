#ifndef HEAD_MAINWINDOW
#define HEAD_MAINWINDOW
#include <QMainWindow>
class QStringListModel;
class QFileSystemModel;

class MainWindow: public QMainWindow
{
public:
    MainWindow(void);

private:
    QStringListModel *m_ListEntity;
    QFileSystemModel *m_ListFile;
};
#endif //HEAD_MAINWINDOW
