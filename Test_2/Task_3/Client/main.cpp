#include <QCoreApplication>
#include <QThread>
#include "client.h"
#include "packet.h"
#include <memory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client c;

        c.Connect();

        QThread th1;
        QThread th2;

        c.moveToThread(&th1);
        c.connect(&th1, SIGNAL(started()), &c, SLOT(Transmit()));
        th1.sleep(5);
        th1.start();

        c.connect(&c, &Client::dataRead, [](int size)
                                                {

                                                    qDebug() << "Data read: " << size << "bytes";
                                                });

    return a.exec();
}

