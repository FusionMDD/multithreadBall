#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QTimer>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QSignalSpy>
#include<QTest>
#include"db.h"
class Ball : public QObject
{
    Q_OBJECT

    bool m_running;
    int count;
    bool direct;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    bool flag ;

    QTimer * mp_timer;
    QSignalSpy * spy;
    QSignalSpy * spy2;


public:


    void setSize(int x,int y);

    int getX();
    int getY();
    int getSizeX();
    int getSizeY();

    void setDirect(bool d);
    bool getDirect();
    explicit Ball(QObject *parent = nullptr);
    ~Ball();

signals:

    void finished();
    void runningChanged(bool running);

    void moveData(int x,int y,int sX,int sY);
    void write(int x,int y,bool bdir);

public slots:
    void run();
    void setPos(int x,int y);
    void takeData(int x, int y,bool dir);
    void takeData(int x ,int y,int sX,int sY);
    void moveBall();

    void finish();

};

#endif // BALL_H
