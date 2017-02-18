#include <QCoreApplication>
#include "vcfreader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vcf::VcfReader reader("/home/sacha/Bioinfo/tmp/mere.vcf");
    if (reader.open())
    {
        qDebug()<<reader.infos().keys();
        qDebug()<<reader.metadata().keys();
        qDebug()<<reader.samples();

       while (reader.next())
       {
           // qDebug()<<reader.record().alt();
       }


    }




    return a.exec();
}
