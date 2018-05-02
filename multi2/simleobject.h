#ifndef SIMLEOBJECT_H
#define SIMLEOBJECT_H

#include <QObject>
#include"mainwindow.h"

class SimleObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ name WRITE setName NOTIFY nameChanged)

    bool m_running;
    int count;

public:
    explicit SimleObject(QObject *parent = 0);

bool running() const;

signals:

    void finished();

    void nameChanged(bool running);

public slots:
void run();
void move();
void setRunning(bool running);
};

#endif // SIMLEOBJECT_H
