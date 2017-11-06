#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtDebug>


class Database
{
public:
    Database();
    QString GetPersonell(QString collum ,int row);
    QString GetInventory(QString collum ,int row);
    QString GetSupplier(QString collum ,int row);
    QString GetCategories(QString collum ,int row);
    QString GetOrders(QString collum ,int row);

    QString GetPersonell(QString collum ,int row,QString extraclause1,QString extraclause2);
    QString GetInventory(QString collum ,int row,QString extraclause1,QString extraclause2);
    QString GetSupplier(QString collum ,int row,QString extraclause1,QString extraclause2);
    QString GetOrders(QString collum ,int row,QString extraclause1,QString extraclause2);

    void Update(QString table ,QString col,QString data,QString wherecol,QString wheredata);
    void Insert(QString table ,QString col,QString data);
    int Size(QString table ,QString col);
    int SizeDistinct(QString table ,QString col);
    void Delete(QString table ,QString col,QString row);
    QString Everything(QString passit);


    void SetChanged(QString table);
    bool GetChanged(QString table);


private:
    //    bool InventoryChanged=true;
    //    bool SalesChanged=true;
    //    bool SuppliersChanged=true;
    //    bool OrdersChanged=true;
    //    bool PersonellChanged=true;

};

#endif // DATABASE_H
