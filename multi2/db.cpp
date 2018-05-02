#include "db.h"

DB::DB(QObject *parent) : QObject(parent)
{


}

void DB :: writeDB(int x, int y,bool bdir)
{


    int dir=static_cast<bool>(bdir);


    {
        query.prepare("UPDATE pos SET x=:x,y=:y,dir=:dir WHERE id = 1");
        query.addBindValue(x);
        query.addBindValue(y);
        query.addBindValue(dir);
        query.exec();
    }
}

void DB:: connectDB( )
{
    QString path="database.db";

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);
    db.open();

    query=QSqlQuery(db);

    query.exec("select x,y,dir from pos where id=1");
    int x=0;
    int y=0;
    bool dir=0;

    while (query.next())
    {
        x=query.value(0).toInt();
        y = query.value(1).toInt();
        dir= query.value(2).toBool();
    }

    emit sdata(x,y,dir);

}

void  DB::close()
{

    db.close();  ;


}
