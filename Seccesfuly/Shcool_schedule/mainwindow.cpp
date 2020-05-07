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

    List_Prepod = new QStringList();


    setting_setting = new Setting();
    *List_Predmet = setting_setting->Get_Setting_List_Predmet();

    *List_Prepod = setting_setting->Get_Setting_List_Prepod();



    Widget_Table = new Tables();

    /// заполняю таблицу
    Widget_Table->MY_Table(ui->tableWidget, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_2, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_3, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_4, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_5, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_6, List_Predmet, List_Prepod);




}

MainWindow::~MainWindow()
{
    delete ui;
}


// вызов слота по добавлению предмета
void MainWindow::on_action_2_triggered()
{
    Add_Subject *Subject = new Add_Subject();
    Subject->show();
    connect(Subject, &Add_Subject::signall_Add, this, &MainWindow::slot_add_Subject);
}

// вставка предмета в тело таблицы
void MainWindow::slot_add_Subject(const QStringList &str_List_Predmet)
{
   *List_Predmet = str_List_Predmet;

    Widget_Table->MY_Table(ui->tableWidget, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_2, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_3, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_4, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_5, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_6, List_Predmet, List_Prepod);

}



void MainWindow::on_action_3_triggered()
{
    Add_teacher *Teachers = new Add_teacher();
    Teachers->show();

    connect(Teachers, &Add_teacher::signals_add_teachers, this, &MainWindow::slot_add_Teachers);
}

void MainWindow::slot_add_Teachers(const QStringList &str_List_prepod)
{
    *List_Prepod = str_List_prepod;

    Widget_Table->MY_Table(ui->tableWidget, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_2, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_3, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_4, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_5, List_Predmet, List_Prepod);
    Widget_Table->MY_Table(ui->tableWidget_6, List_Predmet, List_Prepod);
}
