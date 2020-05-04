#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::Creat_Table(QTableWidget &Tabl)
{
    Tabl.setRowCount(8);
    Tabl.setColumnCount(5);

    Tabl.setHorizontalHeaderLabels(QStringList() << "Начало" << "Предмет" << "Преподаватель" << "Часы" << "Отменён");


    Tabl.setVerticalHeaderLabels(QStringList() << QString::number(1)
                                     << QString::number(2)
                                     << QString::number(3)
                                     << QString::number(4)
                                     << QString::number(5)
                                     << QString::number(6)
                                     << QString::number(7)
                                     << QString::number(8));

    QStringList List_Predmet;
    List_Predmet << "Русский Язык"
                     << "Математика"
                     << "Геометрия"
                     << "История"
                     << "Биология"
                     << "Физика"
                     << "Химия"
                     << "Обществознание"
                     << "Английский"
                     << "Труд"
                     << "Физкультура";
    List_Predmet.sort(Qt::CaseSensitivity::CaseSensitive); // сортировка по алфавиту

    Tabl.horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    Tabl.resizeColumnsToContents();
    Tabl.resizeRowsToContents();



        // выделение памяти и вставка под Комбобоксы
    for(int i = 0; i < Tabl.rowCount() ; i++ )
        {
            QComboBox *My_Box = new QComboBox();
                My_Box->addItems(List_Predmet);
                Tabl.setCellWidget(i,1,My_Box);
        }

        // выделение памяти и вставка под Чекбоксы
    for (int var = 0; var < Tabl.rowCount(); var++)
        {

            QCheckBox *My_Check_Box = new QCheckBox();

            My_Check_Box->setText("");

            Tabl.setCellWidget(var, 4, My_Check_Box);

        }

    for (int var = 0, temp = 0; var < Tabl.rowCount(); ++var, temp+=45)
        {
            QTime *Time_Start = new QTime(8,30);
            QTime *Time = new QTime();
            QTableWidgetItem *Widget_Item_Time = new QTableWidgetItem();

            *Time = Time_Start->addSecs(temp*60);

            Widget_Item_Time->setText(Time->toString("hh:mm"));
            Tabl.setItem(var, 0, Widget_Item_Time);
        }
}
