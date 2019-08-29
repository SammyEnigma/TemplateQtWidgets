#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Application information
    QCoreApplication::setApplicationName("TemplateQtWidgets");
    QCoreApplication::setOrganizationName("3dproger");
    QCoreApplication::setOrganizationDomain("https://github.com/3dproger");
    QCoreApplication::setApplicationVersion("1.0");

    //Translations
    QLocale().setDefault(QLocale::system().name());
    QString languageTag = QLocale().bcp47Name().toUtf8();

    QTranslator appTranslator;
    if (languageTag.toLower() == "c" || languageTag.toLower() == "en"){
        qApp->removeTranslator(&appTranslator);
    }
    else{
        QString i18nFileName = ":/app_" + languageTag + ".qm";

        if (appTranslator.load(i18nFileName)){
            qApp->installTranslator(&appTranslator);
        }
        else{
            qDebug(QString("Can't find application translation: \"%1\"").arg(languageTag).toUtf8());
        }

    }

    MainWindow w;
    w.show();

    return a.exec();
}
