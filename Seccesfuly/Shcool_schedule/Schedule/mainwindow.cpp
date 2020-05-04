#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    ui->label->setAlignment(Qt::AlignHCenter);
    ui->label_2->setAlignment(Qt::AlignHCenter);
    ui->label_3->setAlignment(Qt::AlignHCenter);
    ui->label_4->setAlignment(Qt::AlignHCenter);
    ui->label_5->setAlignment(Qt::AlignHCenter);
    ui->label_6->setAlignment(Qt::AlignHCenter);






    List_Predmet = new QStringList();
    *List_Predmet << "Русский Язык"
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



    Widget_Table = new Tables();

    /// заполняю таблицу
    Widget_Table->MY_Table(ui->tableWidget, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_2, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_3, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_4, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_5, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_6, List_Predmet);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_2_triggered()
{
    Add_Subject *Subject = new Add_Subject();
    Subject->show();
    connect(Subject, &Add_Subject::signall_Add, this, &MainWindow::slot_add_Subject);
}


void MainWindow::slot_add_Subject(const QString &str)
{
   List_Predmet->append(str);


    Widget_Table->MY_Table(ui->tableWidget, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_2, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_3, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_4, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_5, List_Predmet);
    Widget_Table->MY_Table(ui->tableWidget_6, List_Predmet);

}
