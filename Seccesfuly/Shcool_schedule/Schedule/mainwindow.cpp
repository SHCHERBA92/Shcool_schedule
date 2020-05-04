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

    qDebug() << sub + "В теле MAinWindow ";

    Widget_Table = new Tables();

    /// заполняю таблицу
    Widget_Table->MY_Table(ui->tableWidget, sub);
    Widget_Table->MY_Table(ui->tableWidget_2, sub);
    Widget_Table->MY_Table(ui->tableWidget_3, sub);
    Widget_Table->MY_Table(ui->tableWidget_4, sub);
    Widget_Table->MY_Table(ui->tableWidget_5, sub);
    Widget_Table->MY_Table(ui->tableWidget_6, sub);


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
    sub = str;

    qDebug() << sub + "В методе ";

    Widget_Table->MY_Table(ui->tableWidget, sub);
    Widget_Table->MY_Table(ui->tableWidget_2, sub);
    Widget_Table->MY_Table(ui->tableWidget_3, sub);
    Widget_Table->MY_Table(ui->tableWidget_4, sub);
    Widget_Table->MY_Table(ui->tableWidget_5, sub);
    Widget_Table->MY_Table(ui->tableWidget_6, sub);

}
