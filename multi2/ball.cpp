#include "ball.h"
#include<iostream>
#include<QtGui>
#include<QTimer>

Ball::Ball(QObject *parent) : QObject(parent)
{
    mp_timer = 0;
    m_running = false;

}

Ball::~Ball()
{


}

void Ball::moveBall()
{

    if(getX()>400)
        direct=0;
    if(getX()<0)
        direct=1;

    if(direct)
    {
        setPos(getX()+1,getY());
    }
    else
    {
        setPos(getX()-1,getY());
    }

    spy= new QSignalSpy  (this, SIGNAL(moveData(int,int,int,int)));

    emit moveData(posX,posY,sizeX,sizeY);

    QList<QVariant> arguments = spy->takeFirst();
    QVERIFY(arguments.at(0).type() == QVariant::Int);
    QVERIFY(arguments.at(1).type() == QVariant::Int);
    QVERIFY(arguments.at(2).type() == QVariant::Int);
}

void Ball::run()
{

    mp_timer = new QTimer(this);

    spy2= new QSignalSpy (mp_timer, SIGNAL(destroyed(QObject*)));

   connect(mp_timer, &QTimer::timeout, this, &Ball::moveBall);

    mp_timer->setInterval(15);


    if (!m_running)
    {
        mp_timer->start();
        m_running = true;
    }
}

void Ball::finish()
{
    if (m_running)
    {
        emit finished();

        mp_timer->stop();

        m_running = false;
        delete mp_timer;
        Q_ASSERT(spy2->count()==1);

    }
}

void Ball:: setPos(int x,int y)
{
    posX=x;
    posY=y;

}
void Ball :: setSize(int x,int y)
{
    sizeX=x;
    sizeY=y;

}
int Ball :: getX()
{
    return posX;
}
int Ball :: getY()
{
    return posY;
}
int  Ball :: getSizeX()
{
    return sizeX;
}
int Ball :: getSizeY()
{
    return sizeY;
}

void Ball :: setDirect(bool d)
{
    direct=d;
}
bool Ball :: getDirect()
{
    return direct;
}

void Ball:: takeData(int x,int y,int sX,int sY)
{
    posX=x;
    posY=y;
    sizeX=sX;
    sizeY=sY;
}

void Ball :: takeData(int x,int y,bool dir)
{

    posX=x;
    posY=y;
    direct=dir;

}
