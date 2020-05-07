#include "tables.h"

Tables::Tables(QWidget *parent) : QMainWindow(parent)
{

}


Tables::~Tables()
{

}

QTableWidget *Tables::MY_Table(QTableWidget *Tabl, QStringList *List_Predmet, QStringList *List_Prepod)
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

    List_Predmet->sort(Qt::CaseSensitivity::CaseSensitive); // сортировка по алфавиту
    List_Prepod->sort(Qt::CaseSensitivity::CaseSensitive);

        // выделение памяти и вставка под Комбобоксы для предметов
    for(int i = 0; i < Tabl->rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(*List_Predmet);
                Tabl->setCellWidget(i,1,My_Box);
        }

        // выделение памяти и вставка под Комбобоксы для преподавателей
    for(int i = 0; i < Tabl->rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(*List_Prepod);
                Tabl->setCellWidget(i,2,My_Box);
        }

        // выделение памяти и вставка под Чекбоксы
    for (int var = 0; var < Tabl->rowCount(); var++)
        {
            QWidget *Widget_chekBox = new QWidget();
            QHBoxLayout *HLayat = new QHBoxLayout(Widget_chekBox);
            auto My_Check_Box = new QCheckBox();

            My_Check_Box->setText("");
            HLayat->addWidget(My_Check_Box);
            HLayat->setAlignment(Qt::AlignCenter);
            HLayat->setContentsMargins(0,0,0,0);

            Tabl->setCellWidget(var, 4, Widget_chekBox);

            auto firstCollomWidget = Tabl->cellWidget(var,1);
            auto secondCollomWidget = Tabl->cellWidget(var,2);

            connect(My_Check_Box, &QCheckBox::stateChanged, this, [=](int a){firstCollomWidget->setDisabled(a != 0);});
            connect(My_Check_Box, &QCheckBox::stateChanged, this, [=](int a){secondCollomWidget->setDisabled(a != 0);});

        }

    for (int var = 0, temp = 0; var < Tabl->rowCount(); ++var, temp+=45)
        {
            QTime Time_Start(8,30);
            QTime Time;
            QTableWidgetItem *Widget_Item_Time = new QTableWidgetItem();

            Time = Time_Start.addSecs(temp*60);

            Widget_Item_Time->setText(Time.toString("hh:mm"));
            Widget_Item_Time->setTextAlignment(Qt::AlignmentFlag::AlignHCenter);
            Widget_Item_Time->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);
            Tabl->setItem(var, 0, Widget_Item_Time);

        }

    Tabl->resizeColumnsToContents();
    Tabl->resizeRowsToContents();
    Tabl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    Tabl->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    Tabl->setColumnWidth(0,Tabl->minimumWidth());
    Tabl->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);



    return Tabl;
}
