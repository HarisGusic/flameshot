// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#pragma once

#include "src/widgets/capture/capturetoolbutton.h"
#include <QSettings>
#include <QStringList>
#include <QVariant>
#include <QVector>

class QFileSystemWatcher;
class ValueHandler;
template<class T>
class QSharedPointer;

class ConfigHandler : public QObject
{
    Q_OBJECT

public:
    explicit ConfigHandler();

    static ConfigHandler* getInstance();

    QList<CaptureToolButton::ButtonType> getButtons();
    void setButtons(const QList<CaptureToolButton::ButtonType>&);

    QVector<QColor> getUserColors();

    QString savePath();
    void setSavePath(const QString&);

    bool savePathFixed();
    void setSavePathFixed(bool);

    QColor uiMainColorValue();
    void setUIMainColor(const QColor&);

    QColor uiContrastColorValue();
    void setUIContrastColor(const QColor&);

    QColor drawColorValue();
    void setDrawColor(const QColor&);

    void setFontFamily(const QString&);
    const QString& fontFamily();

    bool showHelpValue();
    void setShowHelp(const bool);

    bool showSidePanelButtonValue();
    void setShowSidePanelButton(const bool);

    bool desktopNotificationValue();
    void setDesktopNotification(const bool);

    QString filenamePatternDefault();
    QString filenamePatternValue();
    void setFilenamePattern(const QString&);

    bool disabledTrayIconValue();
    void setDisabledTrayIcon(const bool);

    int drawThicknessValue();
    void setDrawThickness(const int);

    int drawFontSizeValue();
    void setDrawFontSize(const int);

    bool keepOpenAppLauncherValue();
    void setKeepOpenAppLauncher(const bool);

    bool checkForUpdates();
    void setCheckForUpdates(const bool);

    bool verifyLaunchFile();
    bool startupLaunchValue();
    void setStartupLaunch(const bool);

    bool showStartupLaunchMessage();
    void setShowStartupLaunchMessage(const bool);

    int contrastOpacityValue();
    void setContrastOpacity(const int);

    bool copyAndCloseAfterUploadEnabled();
    void setCopyAndCloseAfterUploadEnabled(const bool);

    bool historyConfirmationToDelete();
    void setHistoryConfirmationToDelete(const bool save);

    int uploadHistoryMaxSizeValue();
    void setUploadHistoryMaxSize(const int);

    bool saveAfterCopyValue();
    void setSaveAfterCopy(const bool);

    bool copyPathAfterSaveEnabled();
    void setCopyPathAfterSaveEnabled(const bool);

    bool useJpgForClipboard() const;
    void setUseJpgForClipboard(const bool);
    void setSaveAsFileExtension(const QString& extension);
    QString getSaveAsFileExtension();

    void setDefaultSettings();
    void setAllTheButtons();

    void setIgnoreUpdateToVersion(const QString& text);
    QString ignoreUpdateToVersion();

    void setUndoLimit(int value);
    int undoLimit();

    bool setShortcut(const QString&, const QString&);
    QString shortcut(const QString&);

    QString configFilePath() const;

    void setValue(const QString& key, const QVariant& value);
    QVariant value(const QString& key) const;
    bool contains(const QString& key) const;

    const QStringList& recognizedGeneralOptions() const;
    QStringList recognizedShortcutNames() const;
    QStringList keysFromGroup(const QString& group) const;
    bool isValidShortcutName(const QString& name) const;

    void checkAndHandleError() const;
    bool checkUnrecognizedSettings() const;
    bool checkShortcutConflicts() const;
    bool checkSemantics() const;
    void handleNewErrorState(bool error) const;
    bool hasError() const;
    QString errorMessage() const;
signals:
    void fileChanged() const;
    void error() const;
    void errorResolved() const;

private:
    QString m_strRes;
    QVariant m_varRes;
    mutable QSettings m_settings;
    QVector<QStringList> m_shortcuts;

    static bool m_hasError, m_errorCheckPending, m_skipNextErrorCheck;
    static QSharedPointer<QFileSystemWatcher> m_configWatcher;

    void ensureFileWatched() const;
    QSharedPointer<ValueHandler> valueHandler(const QString& key) const;
};
