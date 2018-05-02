#include "simleobject.h"
#include<iostream>
#include<ball.h>
#include<QtGui>
SimleObject::SimleObject(QObject *parent) : QObject(parent)
{

}

bool SimleObject::running() const
{
    return m_running;
}

void SimleObject::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit nameChanged(running);
}

void SimleObject :: run()
{
QPainter p;

       //count=0;
    while(m_running)

    {

        //count ++;

       //std:: cout<<count<<std::endl;


        // p.begin();

         //p.drawEllipse(ball->getX(),ball->getY(),ball->getSizeX(),ball->getSizeY());

         //p.end();


    }

    emit finished();


}

/*void SimleObject :: move()
{

    Ball *ball=new Ball;


    while(m_running)

    {
        //count ++;

       //std:: cout<<count<<std::endl;




         p.begin(this);



         p.drawEllipse(ball->getX(),ball->getY(),ball->getSizeX(),ball->getSizeY());

         p.end();


    }

    emit finished();


}*/
