#include "vcfreader.h"
namespace vcf {

QVariant::Type Field::typeFromString(const QString &type)
{
    QVariant::Type out = QVariant::String;

    if (type == "Integer")
        out = QVariant::Int;

    if (type == "Float")
        out = QVariant::Double;

    if (type == "Flag")
        out = QVariant::String;

    if (type == "Character")
        out = QVariant::String;

    if (type == "String")
        out = QVariant::String;

    return out;
}



VcfReader::VcfReader(QObject *parent)
    :QObject(parent)
{

}

VcfReader::VcfReader(const QString &filename, QObject *parent)
    :QObject(parent),mFilename(filename)
{
    mDevice = new QFile(filename);
}

VcfReader::VcfReader(QIODevice *device, QObject *parent)
    :QObject(parent),mDevice(device)
{


}

const QHash<QString, Field>& VcfReader::infos() const
{
    return mInfos;
}

const QHash<QString, Field> &VcfReader::formats() const
{
    return mFormats;
}

bool VcfReader::open()
{
    if (mDevice->open(QIODevice::ReadOnly))
    {
        readHeader();
        return true;
    }

    return false;

}

bool VcfReader::next() const
{

}

void VcfReader::readHeader()
{
    mMetadata.clear();
    mInfos.clear();
    mFormats.clear();

    QTextStream stream(mDevice);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        if (line.startsWith("##")){

            if (line.startsWith("##INFO"))
            {
                QRegularExpression ex("##INFO=<ID=(.+),Number=(.+),Type=(.+),Description=\"(.+)\".+");
                QRegularExpressionMatch match = ex.match(line);
                Field info;
                info.id = match.captured(1);
                info.number = match.captured(2);
                info.type = match.captured(3);
                info.description = match.captured(4);
                mInfos.insert(info.id, info);
            }

            if (line.startsWith("##FORMAT"))
            {
                QRegularExpression ex("##FORMAT=<ID=(.+),Number=(.+),Type=(.+),Description=\"(.+)\".+");
                QRegularExpressionMatch match = ex.match(line);
                Field format;
                format.id = match.captured(1);
                format.number = match.captured(2);
                format.type = match.captured(3);
                format.description = match.captured(4);
                if (match.hasMatch())
                    mFormats.insert(format.id, format);
            }

            if (line.contains(QRegularExpression("^##[^(INFO|ANN)]")))
            {
                QRegularExpression ex("##(.+)=\"(.+)\"");
                QRegularExpressionMatch match = ex.match(line);
                if (match.hasMatch())
                    mMetadata.insert(match.captured(1), match.captured(2));
            }



        }
        else
            break;
    }

    mDevice->reset();

}


}
