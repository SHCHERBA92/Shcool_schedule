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

   void Set_Setting_List_Predmet(QStringList List_Predmet);
   QStringList Get_Setting_List_Predmet();

   void Set_Setting_List_Prepod(QStringList List_Prepod);
   QStringList Get_Setting_List_Prepod();


signals:

private:
    QStringList *List_Predmet;
    QStringList *List_Prepod;

    QSettings *Setting_predmet;
    QSettings *Setting_prepod;


};

#endif // SETTING_H
