#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>
#include <QSettings>
#include <QStringList>

class Setting : public QMainWindow
{
    Q_OBJECT
public:
    explicit Setting(QWidget *parent = nullptr);

   void Set_SettingListPredmet(QStringList ListPredmet);
   QStringList Get_SettingListPredmet();

   void Set_SettingListPrepod(QStringList ListPrepod);
   QStringList Get_SettingListPrepod();


signals:

private:
    QStringList *ListPredmet;
    QStringList *ListPrepod;

    QSettings *SettingPredmet;
    QSettings *SettingPrepod;


};

#endif // SETTING_H
