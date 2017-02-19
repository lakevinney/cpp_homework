#include <QCoreApplication>
#include <QThread>
#include "client.h"
#include "packet.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client c;

    QThread th1;
    c.moveToThread(&th1);
    c.connect(&th1, SIGNAL(started()), &c, SLOT(Connect()));
    th1.start();

    c.connect(&c, &Client::dataRead, [](int size)
                                             {

                                                 qDebug() << "Data read: " << size;
                                             });

//    int i = 0;
//    while(i < 100)
//    {
//         c.connect(m_socket, SIGNAL(readyRead()),          this, SLOT(onReadyRead()));
//         c.connect(&c, &Client::dataRead, [](int size)
//                                         {

//                                             qDebug() << "Data read: " << size;
//                                         });
//    }

    return a.exec();
}

