#ifndef SETTINGSPAGECLS_H
#define SETTINGSPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"


namespace Ui
{
    class SettingsPageCls;
}

/*! \class SettingsPageCls SettingsPageCls.h
 *
 *  Docs for MyClassName
 */
class SettingsPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit SettingsPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~SettingsPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadMainPage();
/** @brief Holds true for negative values */
    void SelectAndSaveImagesPath();
/** @brief Holds true for negative values */
    void SaveConfiguration();
/** @brief Holds true for negative values */
    void LoadNewUserPage();
/** @brief Holds true for negative values */
    void LoadEditUserPage();

private:
    /** @brief Holds true for negative values */
    Ui::SettingsPageCls * ui;
/** @brief Holds true for negative values */
    void ReadConfigurationFromFile(QString a_FileNameStr);

};

#endif // SETTINGSPAGECLS_H
