#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QString>
#include <QIcon>
#include <QVariant>

//TODO: Transfer to a normal class
namespace Database
{
/*** Private ***/
template <typename ...Args>
int insert_table(QString table, QStringList fields,  Args&& ...vals)
{
    QSqlQuery result(QSqlDatabase::database());

    // Well, this is ugly. Have a multiplication of ?, instead
    QStringList interrogationsList = fields;
    QString interrogations = interrogationsList.replaceInStrings(QRegExp("^.*$"), "?").join(", ");
    
    result.prepare(QString(
        "INSERT INTO %1 (%2) "
        "VALUES (%3)").arg(table, fields.join(", "), interrogations));

    int dummy[] = {(result.addBindValue(vals), 0)...};
    (void) dummy;

    result.exec();
    return result.lastInsertId().toInt();

}

int insert_event(const Event &event)
{
    return insert_table(
    "Event",
    {"Date",    "Entity", "Value",     "Created_ts",      "Author"},
    event.date, 0,        event.value, event.datecreated, event.author
    );
}

/*** Public ***/
int insert_bill(const Bill &bill)
{
    int id = insert_event(bill);
    return insert_table(
    "Bill",
    {"ID", "ID_Display",    "File",    "Category"},
     id,   bill.id_display, bill.file, 0
    );
}
}

