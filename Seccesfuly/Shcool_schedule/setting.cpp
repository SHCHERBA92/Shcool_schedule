#include "setting.h"

Setting::Setting(QWidget *parent) : QMainWindow(parent)
{
    Setting_predmet = new QSettings("./List_predmet.ini", QSettings::IniFormat);
    Setting_prepod = new QSettings("./List_prepod.ini", QSettings::IniFormat);

    List_Predmet = new QStringList();
//    *List_Predmet << "Русский Язык"
//                     << "Математика"
//                     << "Геометрия"
//                     << "История"
//                     << "Биология"
//                     << "Физика"
//                     << "Химия"
//                     << "Обществознание"
//                     << "Английский"
//                     << "Труд"
//                     << "Физкультура";

//    Set_Setting_List_Predmet(*List_Predmet);

    *List_Predmet = Get_Setting_List_Predmet();

}


void Setting::Set_Setting_List_Predmet(QStringList List_Predmet)
{    
    Setting_predmet->setValue("List_Predmet" , QVariant::fromValue(List_Predmet) );
    //return Setting_predmet->value("List_Predmet").value<QStringList>();
}

QStringList Setting::Get_Setting_List_Predmet()
{
    return Setting_predmet->value("List_Predmet").value<QStringList>();
}


/////////////////////////////////////////


void Setting::Set_Setting_List_Prepod(QStringList List_Prepod)
{
    Setting_predmet->setValue("List_Prepod" , QVariant::fromValue(List_Prepod) );
}


QStringList Setting::Get_Setting_List_Prepod()
{
    return Setting_predmet->value("List_Prepod").value<QStringList>();
}
