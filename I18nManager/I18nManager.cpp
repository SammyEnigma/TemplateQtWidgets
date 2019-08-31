#include "I18nManager.h"
#include <QLibraryInfo>
#include <QApplication>
#include <QSettings>



I18nManager::I18nManager()
{
    //Append available locales to _availableLocales
    LocaleInfo localeInfo;

    //Russian / ru_RU
    localeInfo = LocaleInfo();
    localeInfo.locale = QLocale::Russian;
    localeInfo.name   = firstUpperCase(localeInfo.locale.nativeLanguageName());
    localeInfo.icon   = findIcon(localeInfo.locale);
    _availableLocales.append(localeInfo);

    //C / en_US
    localeInfo = LocaleInfo();
    localeInfo.locale = QLocale::C;
    localeInfo.name   = "English";
    localeInfo.icon   = findIcon(localeInfo.locale);
    _availableLocales.append(localeInfo);

    //Load last last selected locale if possible
    QSettings settings;
    changeLocale(settings.value(_settingNameLocale, QLocale::system()).toLocale());
}

I18nManager::~I18nManager()
{
    deleteTranslators();
}

void I18nManager::changeLocalBySenderData()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action)
    {
        changeLocale(action->data().toLocale());
    }
    else
    {
        qDebug("Unknown sender");
    }
}

void I18nManager::changeLocale(const QLocale &locale)
{
    QLocale().setDefault(locale);
    qDebug(QString("Locale selected \"%1\"").arg(locale.name()).toUtf8());

    //Remove previous translations
    deleteTranslators();

    if (!isAvailableLocale(locale))
    {
        qDebug("This locale is unavailable (not installed)");
        return;
    }

    //Loading user translation files
    if (locale != QLocale::C)
    {
        _translatorApp = new QTranslator();
        if (_translatorApp->load(_userQmFilesDir + "/" + _userQmFilePrefix + locale.name()))
        {
            QApplication::installTranslator(_translatorApp);
        }
        else
        {
            qDebug("Failed to load application translation");
            delete _translatorApp;
            _translatorApp = nullptr;
        }
    }

    //Loading Qt translation files
    _translatorQt = new QTranslator();
    if (_translatorQt->load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
        QApplication::installTranslator(_translatorQt);
    }
    else
    {
        qDebug("Failed to load library translation");
        delete _translatorQt;
        _translatorQt = nullptr;
    }

    //Searching icon file
    bool foundIcon = false;
    _currentIcon = findIcon(locale, &foundIcon);

    if (!foundIcon)
    {
        qDebug("Failed to load locale icon");
    }

    //Saving
    QSettings settings;
    settings.setValue(_settingNameLocale, locale);
    settings.sync();
}

QString I18nManager::firstUpperCase(QString line){
    if (line.isEmpty())
    {
        return line;
    }
    line[0] = line[0].toUpper();
    return line;
}

QIcon I18nManager::findIcon(const QLocale &locale, bool* found)
{
    QStringList iconPostfixes;

    if (locale == QLocale::C)
    {
        iconPostfixes = QStringList({"en", "en_US"});
    }
    else
    {
        iconPostfixes = QStringList({locale.name(), locale.name().left(2)});
    }

    bool foundIcon = false;
    QIcon icon;
    for (const QString& postfixName : iconPostfixes)
    {
        icon = QIcon(_iconsDir + "/" + _iconPrefixName +  postfixName);
        if (!icon.availableSizes().isEmpty())
        {
            foundIcon = true;
            break;
        }
    }

    if (found != nullptr)
    {
        *found = foundIcon;
    }

    return icon;
}

QIcon I18nManager::currentIcon()
{
    return _currentIcon;
}

QList<LocaleInfo> I18nManager::availableLocales()
{
    return _availableLocales;
}

bool I18nManager::isAvailableLocale(const QLocale &locale)
{
    for (const LocaleInfo& localeInfo : _availableLocales)
    {
        if (localeInfo.locale == locale)
        {
            return true;
        }
    }
    return false;
}

QList<QAction*> I18nManager::buildActions(QObject* parent)
{
    QList<QAction*> actions;

    for (const LocaleInfo& localInfo : _availableLocales)
    {
        QAction* action = new QAction(parent);
        action->setText(localInfo.name);
        action->setIcon(localInfo.icon);
        action->setData(localInfo.locale);

        connect(action, SIGNAL(triggered()), this, SLOT(changeLocalBySenderData()));

        actions.append(action);
    }

    return actions;
}

void I18nManager::deleteTranslators()
{
    if (_translatorApp)
    {
        QApplication::removeTranslator(_translatorApp);
        delete _translatorApp;
        _translatorApp = nullptr;
    }

    if (_translatorQt)
    {
        QApplication::removeTranslator(_translatorQt);
        delete _translatorQt;
        _translatorQt = nullptr;
    }
}
