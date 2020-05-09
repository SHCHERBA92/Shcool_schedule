#include "tables.h"

Tables::Tables(QWidget *parent) : QMainWindow(parent)
{

}


Tables::~Tables()
{

}

QTableWidget *Tables::creatMyTable(QTableWidget *Tabl, QStringList *ListPredmet, QStringList *ListPrepod)
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

    ListPredmet->sort(Qt::CaseSensitivity::CaseSensitive); // сортировка по алфавиту
    ListPrepod->sort(Qt::CaseSensitivity::CaseSensitive);



    // Вставка времени начала урока
    for (int var = 0, temp = 0; var < Tabl->rowCount(); ++var, temp+=45)
        {
            QTime Time_Start(8,30);
            QTime Time;
            QTableWidgetItem *WidgetItemTime = new QTableWidgetItem();

            Time = Time_Start.addSecs(temp*60);

            WidgetItemTime->setText(Time.toString("hh:mm"));
            WidgetItemTime->setTextAlignment(Qt::AlignmentFlag::AlignHCenter);
            WidgetItemTime->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);
            Tabl->setItem(var, 0, WidgetItemTime);

         }


        // выделение памяти и вставка под Комбобоксы для предметов
    for(int i = 0; i < Tabl->rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(*ListPredmet);
                Tabl->setCellWidget(i,1,My_Box);

        }

        // выделение памяти и вставка под Комбобоксы для преподавателей
    for(int i = 0; i < Tabl->rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(*ListPrepod);
                Tabl->setCellWidget(i,2,My_Box);

        }

    // продолжительность урока
    for (int var = 0; var < Tabl->rowCount(); ++var)
    {
        QTime timeFullLesson(0,45);

        QTableWidgetItem *widgetItemTimeFullLesson = new QTableWidgetItem();

        widgetItemTimeFullLesson->setText(timeFullLesson.toString("hh:mm"));
        widgetItemTimeFullLesson->setTextAlignment(Qt::AlignmentFlag::AlignHCenter);
        widgetItemTimeFullLesson->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);

        Tabl->setItem(var, 3, widgetItemTimeFullLesson);

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


            // работа ЧекБокса
            auto firstCollomWidget = Tabl->cellWidget(var,1);
            auto secondCollomWidget = Tabl->cellWidget(var,2);

            connect(My_Check_Box, &QCheckBox::stateChanged, this, [=](int a){firstCollomWidget->setDisabled(a != 0);});
            connect(My_Check_Box, &QCheckBox::stateChanged, this, [=](int a){secondCollomWidget->setDisabled(a != 0);});
        }


    Tabl->resizeColumnsToContents();
    Tabl->resizeRowsToContents();
    Tabl->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    Tabl->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    Tabl->setColumnWidth(0,Tabl->minimumWidth());
    Tabl->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);


    // Добавление подсказок к таблице
    for (int var = 0; var < Tabl->rowCount(); ++var)
    {
        Tabl->item(var,0)->setToolTip("Время начала урока");

        Tabl->cellWidget(var,1)->setToolTip("Нажмите, что бы выбрать предмет");
        Tabl->cellWidget(var,1)->setToolTipDuration(5000);

        Tabl->cellWidget(var,2)->setToolTip("Нажмите, что бы выбрать преподавателя");
        Tabl->cellWidget(var,2)->setToolTipDuration(5000);

        Tabl->item(var,3)->setToolTip("Время начала урока");

        Tabl->cellWidget(var,4)->setToolTip("Нажмите, что бы пометить урок как отменёный");
        Tabl->cellWidget(var,4)->setToolTipDuration(5000);

    }

    return Tabl;
}
