import QtQuick 2.5
import QtQuick.Window 2.2
import QMLExif 1.0

Rectangle {
    id: mainWindow
    visible: true
    width: 640
    height: 480

    property var tags : [
        QMLExif.ET_WhiteBalance,
        QMLExif.ET_ColorSpace,
        QMLExif.ET_DateTimeDigitized,
        QMLExif.ET_DateTimeOriginal,
        QMLExif.ET_EXIFVersion,
        QMLExif.ET_FocalLength,
        QMLExif.ET_ExposureBiasValue,
        QMLExif.ET_ExposureMode,
        QMLExif.ET_ExposureProgram,
        QMLExif.ET_ExposureTime
    ];

    Image {
        id: img
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
        source: "./example.JPG"
    }

    Rectangle {
        id: infoRect
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 250
        color: "gray"
        opacity: 0.8

        QMLExif {
            id: exif
            source: "./example.JPG"
            ifd: QMLExif.IFD_EXIF
        }

        Component {
            id: exifDelegate

            Rectangle {
                height: 30
                width: valusView.width
                color: "transparent"

                Rectangle {
                    id: tagName
                    width: 100
                    height: parent.height
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "transparent"

                    Text {
                        width: parent.width
                        height: parent.height
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        color: "white"
                        font.pixelSize: 10
                        wrapMode: Text.WordWrap
                        text:exif.getTagName(tag) + ": "
                    }
                }

                Rectangle {
                    width: parent.width - tagName.width - 5
                    height: parent.height - 4
                    anchors.left: tagName.right
                    anchors.verticalCenter: parent.verticalCenter
                    border.width: 1
                    border.color: "white"
                    color: "transparent"

                    TextEdit {
                        id: valueEdit
                        selectByMouse: true
                        width: parent.width
                        height: parent.height
                        anchors.centerIn: parent
                        horizontalAlignment: TextEdit.AlignLeft
                        verticalAlignment: TextEdit.AlignVCenter
                        color: "white"
                        font.pixelSize: 10

                        text: exif.getTagValue(tag)
                    }
                }
            }
        }

        ListView {
            id: valusView
            clip: true
            anchors.fill: parent
            width: parent.width
            model: ListModel {
                Component.onCompleted: {
                    for (var i = 0; i < tags.length; i++) {
                        append({"tag": tags[i]})
                    }
                }
            }

            delegate:  exifDelegate
        }
    }
}
