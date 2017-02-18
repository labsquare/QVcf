#include "record.h"
namespace vcf{
Record::Record()
{

}

Record::Record(const QString &chrom, quint64 pos, const QString &ref, quint64 qual, const QString &filter, const QString &format, const QVariantMap &infos)
    :mChrom(chrom), mPos(pos), mRef(ref), mQual(qual), mFilter(filter),mFormat(format), mInfos(infos)
{

}

}
