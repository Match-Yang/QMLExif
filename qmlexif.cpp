#include "qmlexif.h"
#include <libexif/exif-entry.h>
#include <libexif/exif-content.h>

QMLExif::QMLExif(QQuickItem *parent):
    QQuickItem(parent)
  , m_data(NULL)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

QMLExif::~QMLExif()
{
}

QString QMLExif::source() const
{
    return m_source;
}

QString QMLExif::getTagName(QMLExif::QMLExifTag tag)
{
    return QString(exif_tag_get_name_in_ifd((ExifTag)tag, (ExifIfd)m_ifd));
}

QString QMLExif::getTagTitle(QMLExif::QMLExifTag tag)
{
    return QString(exif_tag_get_title_in_ifd((ExifTag)tag, (ExifIfd)m_ifd));
}

QString QMLExif::getTagDescription(QMLExif::QMLExifTag tag)
{
    return QString(exif_tag_get_description_in_ifd((ExifTag)tag, (ExifIfd)m_ifd));
}

QString QMLExif::getTagValue(QMLExifTag tag)
{
    ExifEntry *entry = exif_content_get_entry(m_data->ifd[(ExifIfd)m_ifd], (ExifTag)tag);

    if (entry){
        char buf[1024];
        exif_entry_get_value(entry, buf, sizeof(buf));

        if (*buf) {
            return QString(buf).trimmed();
        }
    }

    return QString();
}

//QString QMLExif::getGPSValue(ExifTag tag)
//{
//    Q_UNUSED (tag)
//    return QString();
//}

QMap<QString, QString> QMLExif::getMakerNotes()
{
    QMap<QString, QString> m;
    return m;
}

QMLExif::QMLExifIfd QMLExif::ifd() const
{
    return m_ifd;
}

void QMLExif::setSource(QString source)
{
    if (m_source == source)
        return;

    m_source = source;
    m_data = exif_data_new_from_file(source.toUtf8().data());
    emit sourceChanged(source);
}

void QMLExif::setIfd(QMLExifIfd ifd)
{
    if (m_ifd == ifd)
        return;

    m_ifd = ifd;
    emit ifdChanged(ifd);
}
