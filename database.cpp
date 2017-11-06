#include "database.h"

Database::Database()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    //db.setDatabaseName("/Volumes/KINGSTON/SeniorPro.bd");
    db.setDatabaseName("M:/SeniorPro.bd");
    bool open = db.open();

    //outputs error if database isn't connected based on bool open
    if(!open){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","The Database is not connected");
        messageBox.setFixedSize(500,200);
    }

}

QString Database::GetPersonell(QString collum ,int row){

    QSqlQuery query;

    if(collum=="id"){
        query.exec("SELECT ID FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="employeename"){
        query.exec("SELECT EmployeeName FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "username"){

        query.exec("SELECT UserName FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="password"){
        query.exec("SELECT Password FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="privlages"){

        query.exec("SELECT Privlages FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetPersonell accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetInventory(QString collum ,int row){

    QSqlQuery query;

    if(collum=="itemid"){
        query.exec("SELECT ItemId FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "category"){

        query.exec("SELECT Category FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="itemname"){
        query.exec("SELECT ItemName FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="Threshold"){

        query.exec("SELECT Privlages FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="amountinstock"){

        query.exec("SELECT AmountInStock FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="supplier"){

        query.exec("SELECT Supplier FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="cost"){

        query.exec("SELECT Cost FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="salesprice"){

        query.exec("SELECT SalesPrice FROM Inventory");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetInventory accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetSupplier(QString collum ,int row){
    QSqlQuery query;

    if(collum=="supplierid"){
        query.exec("SELECT SupplierId FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "suppliername"){

        query.exec("SELECT SupplierName FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="phonenumber"){
        query.exec("SELECT PhoneNumber FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="email"){

        query.exec("SELECT Email FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="estshipping"){

        query.exec("SELECT EstShipping FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="shippedon"){

        query.exec("SELECT ShippedOn FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="adress"){

        query.exec("SELECT Adress FROM Suppliers");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetSuppliers accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetCategories(QString collum ,int row){
    QSqlQuery query;

    if(collum=="category"){
        query.exec("SELECT category FROM categories");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetCategories accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetOrders(QString collum ,int row){
    QSqlQuery query;
    if(collum=="itemno"){
        query.exec("SELECT ItemNo FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "dateordered"){

        query.exec("SELECT DateOrdered FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="DateRecieved"){
        query.exec("SELECT DateRecieved FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="Status"){

        query.exec("SELECT Status FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="supplier"){

        query.exec("SELECT Supplier FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="username"){

        query.exec("SELECT UserName FROM Orders");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Orders accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}

QString Database::GetOrders(QString collum ,int row,QString extraclause1,QString extraclause2){

    QSqlQuery query;

    if(collum=="itemno"){
        query.exec("SELECT "+extraclause1+" ItemNo FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "dateordered"){

        query.exec("SELECT "+extraclause1+" DateOrdered FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="DateRecieved"){
        query.exec("SELECT "+extraclause1+" DateRecieved FROM Orders "+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="supplier"){

        query.exec("SELECT "+extraclause1+" Supplier FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="username"){

        query.exec("SELECT "+extraclause1+" UserName FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="orderno"){

        query.exec("SELECT "+extraclause1+" OrderNo FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="amount"){

        query.exec("SELECT "+extraclause1+" Amount FROM Orders"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetOrders accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetPersonell(QString collum ,int row,QString extraclause1,QString extraclause2){

    QSqlQuery query;

    if(collum=="employeename"){
        query.exec("SELECT EmployeeName FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "username"){

        query.exec("SELECT UserName FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="password"){
        query.exec("SELECT Password FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="privlages"){

        query.exec("SELECT Privlages FROM Personell");

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetPersonell accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetInventory(QString collum ,int row,QString extraclause1,QString extraclause2){

    QSqlQuery query;

    if(collum=="itemid"){
        query.exec("SELECT "+extraclause1+" ItemId FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "category"){

        query.exec("SELECT "+extraclause1+" Category FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="itemname"){
        query.exec("SELECT "+extraclause1+" ItemName FROM Inventory "+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="threshold"){

        query.exec("SELECT "+extraclause1+" Threshold FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="amountinstock"){

        query.exec("SELECT "+extraclause1+" AmountInStock FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="supplier"){

        query.exec("SELECT "+extraclause1+" Supplier FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="cost"){

        query.exec("SELECT "+extraclause1+" Cost FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="salesprice"){

        query.exec("SELECT "+extraclause1+" SalesPrice FROM Inventory"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetInventory accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}
QString Database::GetSupplier(QString collum ,int row,QString extraclause1,QString extraclause2){
    QSqlQuery query;

    if(collum=="supplierid"){
        query.exec("SELECT "+extraclause1+" SupplierId FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum == "suppliername"){

        query.exec("SELECT "+extraclause1+" SupplierName FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="phonenumber"){
        query.exec("SELECT "+extraclause1+" PhoneNumber FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="email"){

        query.exec("SELECT "+extraclause1+" Email FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="estshipping"){

        query.exec("SELECT "+extraclause1+" EstShipping FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="shippedon"){

        query.exec("SELECT "+extraclause1+" ShippedOn FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    else if(collum=="adress"){

        query.exec("SELECT "+extraclause1+" Adress FROM Suppliers"+extraclause2);

        for(int i=0;i<=row;i++)
        {
            query.next();
        }
        QSqlRecord record = query.record();
        return (record.value(0).toString());
    }
    //if it doesn't match one of these cases then an error message pops up
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","GetSuppliers accesed incorrectley");
        messageBox.setFixedSize(500,200);
    }
}

void Database::Update(QString table ,QString col,QString data,QString wherecol,QString wheredata){

    QSqlQuery q;
    q.exec("UPDATE "+table+" SET "+col+" = '"+data+"' WHERE "+wherecol+" = '"+wheredata+"'");

    //q.exec("UPDATE Sales  SET UserName = 'poopEater' WHERE ItemNo = '1' ");
}

void Database::Insert(QString table ,QString col,QString data){

    QSqlQuery q;
    q.exec("INSERT INTO "+table+" ("+col+") VALUES ("+data+")");
}

int Database::Size(QString table ,QString col){

    int howmany=0;
    QSqlQuery query;
    query.exec("SELECT "+col+" FROM "+table);
    while(  query.next()){
        howmany++;
    }
    return howmany;}
int Database::SizeDistinct(QString table ,QString col){

    int howmany=0;
    QSqlQuery query;
    query.exec("SELECT DISTINCT "+col+" FROM "+table);
    while(  query.next()){
        howmany++;
    }
    return howmany;
}

QString Database::Everything(QString passit){

    QSqlQuery query;
    query.exec(passit);

    query.next();
    QSqlRecord record = query.record();
    return (record.value(0).toString());
}

void Database::Delete(QString table ,QString col,QString row){

    QSqlQuery query;
    query.exec("DELETE FROM "+table+" WHERE "+col+" = "+row);
    //query.exec("DELETE FROM Category WHERE Category = Shitty");
}
