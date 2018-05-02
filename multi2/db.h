#ifndef DB_H
#define DB_H

#include <QObject>
#include<QtSql>

class DB : public QObject
{
    Q_OBJECT

    QSqlDatabase db;
    QSqlQuery query;
public:
    explicit DB(QObject *parent = 0);

    void connectDB();
    void close();

signals:
    void sdata(int x,int y, bool dir);

public slots:
 void writeDB(int x,int y,bool bdir);
};

#endif // DB_H
