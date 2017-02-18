#include <QCoreApplication>
#include "vcfreader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vcf::VcfReader reader("/home/sacha/Bioinfo/tmp/test.chr22.ann.vcf");
    if (reader.open())
    {
        qDebug()<<reader.infos().keys();

//       while (reader.next())
//       {
//           qDebug()<<"yo";
//       }

    }





    return a.exec();
}
