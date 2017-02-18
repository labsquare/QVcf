# QVcf
A simple variant vcf parser based on Qt/C++. 
QVcf use the same semantics than [pyvcf](https://github.com/jamescasbon/PyVCF)

## Example 

```
#include <QCoreApplication>
#include "vcfreader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vcf::VcfReader reader("yourfile.vcf");
    if (reader.open())
    {
        qDebug()<<reader.infos().keys();
        qDebug()<<reader.metadata().keys();
        qDebug()<<reader.samples();

       while (reader.next())
       {
           qDebug()<<reader.record().chrom();
           qDebug()<<reader.record().pos();
           qDebug()<<reader.record().ref();
           qDebug()<<reader.record().alt();
       }


    }

    return a.exec();
}
```

