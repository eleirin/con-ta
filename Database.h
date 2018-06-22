#ifndef HEAD_DATABASE
#define HEAD_DATABASE
#include <QDate>
#include <QTime>
#include <QString>
class QIcon;

namespace Database
{

/*** Datatypes ***/
typedef QString Author;

struct Entity
{
    int id;
    QString name;
};

struct Category
{
    int id;
    QString name;
    QString abbreviation;
    QIcon *icon;
};

struct Event
{
    QDate date;
    Entity *entity;
    double value;
    QDateTime datecreated;
    Author author;
};

struct Bill: Event
{
    QString file;
    QString id_display;
    Category *category;
};

typedef Event Payment;
typedef Event Cancel;

/*** Fonction ***/
int insert_bill(const Bill &bill);

} 
#endif //HEAD_DATABASE
