#include "tables.h"

Tables::Tables(QWidget *parent) : QMainWindow(parent)
{

}


Tables::~Tables()
{

}

QTableWidget *Tables::MY_Table(QTableWidget *Tabl, QStringList *List_Predmet)
{
    Tabl->setRowCount(8);
    Tabl->setColumnCount(5);

    Tabl->setHorizontalHeaderLabels(QStringList() << "Начало" << "Предмет" << "Преподаватель" << "Часы" << "Отменён");


    Tabl->setVerticalHeaderLabels(QStringList() << QString::number(1)
                                     << QString::number(2)
                                     << QString::number(3)
                                     << QString::number(4)
                                     << QString::number(5)
                                     << QString::number(6)
                                     << QString::number(7)
                                     << QString::number(8));

//    QStringList *List_Predmet = new QStringList();
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
//    List_Predmet->append(str);

    List_Predmet->sort(Qt::CaseSensitivity::CaseSensitive); // сортировка по алфавиту

    Tabl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    Tabl->resizeColumnsToContents();
    Tabl->resizeRowsToContents();



        // выделение памяти и вставка под Комбобоксы
    for(int i = 0; i < Tabl->rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(*List_Predmet);
                Tabl->setCellWidget(i,1,My_Box);
        }

        // выделение памяти и вставка под Чекбоксы
    for (int var = 0; var < Tabl->rowCount(); var++)
        {
            QWidget *Widget_chekBox = new QWidget();
            QHBoxLayout *HLayat = new QHBoxLayout(Widget_chekBox);
            QCheckBox *My_Check_Box = new QCheckBox();

            My_Check_Box->setText("");
            HLayat->addWidget(My_Check_Box);
            HLayat->setAlignment(Qt::AlignCenter);
            HLayat->setContentsMargins(0,0,0,0);

            Tabl->setCellWidget(var, 4, Widget_chekBox);

        }

    for (int var = 0, temp = 0; var < Tabl->rowCount(); ++var, temp+=45)
        {
            QTime Time_Start(8,30);
            QTime Time;
            QTableWidgetItem *Widget_Item_Time = new QTableWidgetItem();

            Time = Time_Start.addSecs(temp*60);

            Widget_Item_Time->setText(Time.toString("hh:mm"));
            Tabl->setItem(var, 0, Widget_Item_Time);

        }

    return Tabl;
}
