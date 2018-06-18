#ifndef HEAD_NEWBILL
#define HEAD_NEWBILL
#include <QDialog>
class QLineEdit;
class QDateEdit;
class QDoubleSpinBox;
class QLabel;

class NewBill: public QDialog
{
Q_OBJECT

public:
    NewBill(const QString &filename);


private slots:
    void on_uploadingFile(void);

private:
    struct Input
    {
        QLineEdit *file;
        QDateEdit *date;
        QLineEdit *category;
        QDoubleSpinBox *value;
        QLineEdit *entity;
    } m_Input;
};

#endif //HEAD_NEWBILL
