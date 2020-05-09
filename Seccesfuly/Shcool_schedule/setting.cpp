#include "setting.h"

Setting::Setting(QWidget *parent) : QMainWindow(parent)
{
    SettingPredmet = new QSettings("./List_predmet.ini", QSettings::IniFormat);
    SettingPrepod = new QSettings("./List_prepod.ini", QSettings::IniFormat);

    ListPredmet = new QStringList();


    *ListPredmet = Get_SettingListPredmet();

}


void Setting::Set_SettingListPredmet(QStringList List_Predmet)
{    
    SettingPredmet->setValue("List_Predmet" , QVariant::fromValue(List_Predmet) );
    //return Setting_predmet->value("List_Predmet").value<QStringList>();
}

QStringList Setting::Get_SettingListPredmet()
{
    return SettingPredmet->value("List_Predmet").value<QStringList>();
}


/////////////////////////////////////////


void Setting::Set_SettingListPrepod(QStringList List_Prepod)
{
    SettingPrepod->setValue("List_Prepod" , QVariant::fromValue(List_Prepod) );
}


QStringList Setting::Get_SettingListPrepod()
{
    return SettingPrepod->value("List_Prepod").value<QStringList>();
}
