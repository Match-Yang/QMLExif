#ifndef LIBEXIF_H
#define LIBEXIF_H

#include <libexif/exif-data.h>
#include <libexif/exif-tag.h>
#include <QQuickItem>

class QMLExif : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QMLExif)

    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QMLExifIfd ifd READ ifd WRITE setIfd NOTIFY ifdChanged)

public:
    /*! Possible EXIF Image File Directories */
    enum QMLExifIfd {
        IFD_0 = 0,                /*!< */
        IFD_1,                    /*!< */
        IFD_EXIF,                 /*!< */
        IFD_GPS,                  /*!< */
        IFD_INTEROPERABILITY,     /*!< */
        IFD_COUNT                 /*!< Not a real value, just (max_value + 1). */
    };

    /*! EXIF tags */
    enum  QMLExifTag{
        ET_InterOperabilityIndex            = 0x0001,
        ET_InterOperabilityVersion          = 0x0002,
        ET_NewSubFileType                   = 0x00fe,
        ET_ImageWidth                       = 0x0100,
        ET_ImageLength                      = 0x0101,
        ET_BitsPerSample                    = 0x0102,
        ET_Compression                      = 0x0103,
        ET_PhotoMetricInterpretation        = 0x0106,
        ET_FillOrder                        = 0x010a,
        ET_DocumentName                     = 0x010d,
        ET_ImageDescription                 = 0x010e,
        ET_Make                             = 0x010f,
        ET_Model                            = 0x0110,
        ET_StripOffsets                     = 0x0111,
        ET_Orientation                      = 0x0112,
        ET_SamplesPerPixel                  = 0x0115,
        ET_RowsPerStrip                     = 0x0116,
        ET_StripByteCount                   = 0x0117,
        ET_XResolution                      = 0x011a,
        ET_YResolution                      = 0x011b,
        ET_PlanarConfiguration              = 0x011c,
        ET_ResolutionUnit                   = 0x0128,
        ET_TransferFunction                 = 0x012d,
        ET_Software                         = 0x0131,
        ET_DateTime                         = 0x0132,
        ET_Artist                           = 0x013b,
        ET_WhitePoint                       = 0x013e,
        ET_PrimaryChromaticities            = 0x013f,
        ET_SubIfds                          = 0x014a,
        ET_TransferRange                    = 0x0156,
        ET_JPEGProc                         = 0x0200,
        ET_JPEGInterchangeFormat            = 0x0201,
        ET_JPEGInterchangeFormatLength      = 0x0202,
        ET_YCBCRCoefficients                = 0x0211,
        ET_YCBCRSubSampleing                = 0x0212,
        ET_YCBCRPositioning                 = 0x0213,
        ET_ReferenceBlackWhite              = 0x0214,
        ET_XMLPacket                        = 0x02bc,
        ET_RelatedImageFileFormat           = 0x1000,
        ET_RelatedImageWidth                = 0x1001,
        ET_RelatedImageLength               = 0x1002,
        ET_CFARepeatPatternDim              = 0x828d,
        ET_CFAPattern                       = 0x828e,
        ET_BatteryLevel                     = 0x828f,
        ET_CopyRight                        = 0x8298,
        ET_ExposureTime                     = 0x829a,
        ET_FNumber                          = 0x829d,
        ET_IPTCNAA                          = 0x83bb,
        ET_ImageResources                   = 0x8649,
        ET_EXIFIFDPointer                   = 0x8769,
        ET_InterColorProfile                = 0x8773,
        ET_ExposureProgram                  = 0x8822,
        ET_SpectralSensitivity              = 0x8824,
        ET_GPSInfoIFDPointer                = 0x8825,
        ET_ISOSpeedRatings                  = 0x8827,
        ET_OECF                             = 0x8828,
        ET_TimeZoneOffset                   = 0x882a,
        ET_EXIFVersion                      = 0x9000,
        ET_DateTimeOriginal                 = 0x9003,
        ET_DateTimeDigitized                = 0x9004,
        ET_ComponentsConfiguration          = 0x9101,
        ET_CompressedBitsPerPixel           = 0x9102,
        ET_ShutterSpeedValue                = 0x9201,
        ET_ApertureValue                    = 0x9202,
        ET_BrightnessValue                  = 0x9203,
        ET_ExposureBiasValue                = 0x9204,
        ET_MaxApertureValue                 = 0x9205,
        ET_SubjectDistance                  = 0x9206,
        ET_MeteringMode                     = 0x9207,
        ET_LightSource                      = 0x9208,
        ET_Flash                            = 0x9209,
        ET_FocalLength                      = 0x920a,
        ET_SubjectArea                      = 0x9214,
        ET_TiffEPStandardID                 = 0x9216,
        ET_MakerNote                        = 0x927c,
        ET_UserComment                      = 0x9286,
        ET_SubSECTime                       = 0x9290,
        ET_SubSECTimeOriginal               = 0x9291,
        ET_SubSECTimeDigitized              = 0x9292,
        ET_XPTitle                          = 0x9c9b,
        ET_XPComment                        = 0x9c9c,
        ET_XPAuthor                         = 0x9c9d,
        ET_XPKeywords                       = 0x9c9e,
        ET_XPSubject                        = 0x9c9f,
        ET_FlashPixVersion                  = 0xa000,
        ET_ColorSpace                       = 0xa001,
        ET_PixelXDimension                  = 0xa002,
        ET_PixelYDimension                  = 0xa003,
        ET_RelatedSoundFile                 = 0xa004,
        ET_InteroperabilityIFDPointer       = 0xa005,
        ET_FlashEnergy                      = 0xa20b,
        ET_SpatialFrequencyResponse         = 0xa20c,
        ET_FocalPlaneXResolution            = 0xa20e,
        ET_FocalPlaneYResolution            = 0xa20f,
        ET_FocalPlaneResolutionUnit         = 0xa210,
        ET_SubjectLocation                  = 0xa214,
        ET_ExposureIndex                    = 0xa215,
        ET_SensingMethod                    = 0xa217,
        ET_FileSource                       = 0xa300,
        ET_SceneType                        = 0xa301,
        ET_NewCFAPattern                    = 0xa302,
        ET_CustomRendered                   = 0xa401,
        ET_ExposureMode                     = 0xa402,
        ET_WhiteBalance                     = 0xa403,
        ET_DigitalZoomRatio                 = 0xa404,
        ET_FocalLengthIn35MMFile            = 0xa405,
        ET_SceneCaptureType                 = 0xa406,
        ET_GainControl                      = 0xa407,
        ET_Contrast                         = 0xa408,
        ET_Saturation                       = 0xa409,
        ET_Sharpness                        = 0xa40a,
        ET_DeviceSettingDescription         = 0xa40b,
        ET_SubjectDistanceRange             = 0xa40c,
        ET_ImageUniqueID                    = 0xa420,
        ET_Gamma                            = 0xa500,
        ET_PrintImageMatching               = 0xc4a5,
        ET_Padding                          = 0xea1c
    };
    Q_ENUMS(QMLExifTag)

    QMLExif(QQuickItem *parent = 0);
    ~QMLExif();

    QMLExifIfd ifd() const;
    QString source() const;
    Q_INVOKABLE QString getTagName(QMLExifTag tag);
    Q_INVOKABLE QString getTagTitle(QMLExifTag tag);
    Q_INVOKABLE QString getTagDescription(QMLExifTag tag);
    Q_INVOKABLE QString getTagValue(QMLExifTag tag);
//    Q_INVOKABLE QString getGPSValue(ExifTag tag);
    Q_INVOKABLE QMap<QString, QString> getMakerNotes();

public slots:
    void setSource(QString source);
    void setIfd(QMLExifIfd ifd);

signals:
    void sourceChanged(QString source);
    void ifdChanged(QMLExifIfd ifd);

private:
    ExifData *m_data;
    QString m_source;
    QMLExifIfd m_ifd;
};

#endif // LIBEXIF_H
