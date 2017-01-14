#include "qmlexif_plugin.h"
#include "qmlexif.h"

#include <qqml.h>

void QMLExifPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<QMLExif>(uri, 1, 0, "QMLExif");
}

