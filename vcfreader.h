#ifndef VCFREADER_H
#define VCFREADER_H
#include <QObject>
#include <QtCore>
namespace vcf {

class Field
{
public:
    QString id;
    QString type;
    QString description;
    QString number;
    static QVariant::Type typeFromString(const QString& type);

};


class VcfReader : public QObject
{
    Q_OBJECT
public:
    explicit VcfReader(QObject *parent = Q_NULLPTR);
    explicit VcfReader(const QString& filename, QObject * parent = Q_NULLPTR);
    explicit VcfReader(QIODevice * device, QObject * parent = Q_NULLPTR);
    const QHash<QString,Field>& infos() const;
    const QHash<QString,Field>& formats() const;

    bool open();
    bool next() const;

protected:
    void readHeader();

private:
    QIODevice * mDevice;
    QString mFilename;
    QByteArray mHeader;
    QHash<QString, Field> mInfos;
    QHash<QString, Field> mFormats;
    QHash<QString, QVariant> mMetadata;

};
}

#endif // VCFREADER_H
