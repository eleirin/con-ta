#ifndef HEAD_NEWBILL
#define HEAD_NEWBILL
#include <QDialog>
namespace Database
{
class Bill;
}
class QLineEdit;
class QDateEdit;
class QDoubleSpinBox;
class QLabel;
class QComboBox;
class QTextEdit;

class NewBill: public QDialog
{
Q_OBJECT

public:
    NewBill(const QString &filename);


private slots:
    void on_uploadingFile(void);
    void on_addBill(void);

private:
    struct Input
    {
        operator Database::Bill(void) const;

        QLineEdit *file;
        QDateEdit *date;
        QComboBox *category;
        QComboBox *entity;
        QDoubleSpinBox *value;
        QTextEdit *notes;
    } m_Input;
};

#endif //HEAD_NEWBILL
