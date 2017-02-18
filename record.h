#ifndef RECORD_H
#define RECORD_H
#include <QtCore>

namespace vcf {
class Record
{
public:
    explicit Record();
    explicit Record(const QString& chrom,
           quint64 pos,
           const QString& ref,
           quint64 qual,
           const QString& filter,
           const QString& format,
           const QVariantMap& infos);

private:
    QString mChrom;
    quint64 mPos  = 0;
    QString mRef;
    QString mAlt;
    quint64 mQual = 0;
    QString mFilter;
    QVariantMap mInfos;
    QString mFormat;



};
}

#endif // RECORD_H
