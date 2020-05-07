#include "add_teacher.h"
#include "ui_add_teacher.h"

#include <QDebug>
#include <QMessageBox>

Add_teacher::Add_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_teacher)
{
    ui->setupUi(this);

    List_Prepod_add = new QStringList();

    *List_Prepod_add = set.Get_Setting_List_Prepod();
    ui->listWidget->addItems(*List_Prepod_add);
}

Add_teacher::~Add_teacher()
{
    delete ui;


}


void Add_teacher::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    this->close();
}

void Add_teacher::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Введите фамилию преподавателя");
    }

    else if(!(List_Prepod_add->filter(ui->lineEdit->text()).isEmpty()))
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Такой преподаватель уже внесён в список");
    }

    else
    {

        List_Prepod_add->append(ui->lineEdit->text());
        set.Set_Setting_List_Prepod(*List_Prepod_add);

        ui->listWidget->clear();
        ui->listWidget->addItems(*List_Prepod_add);

        emit signals_add_teachers(*List_Prepod_add);

    }
}

void Add_teacher::on_pushButton_clicked()
{

    List_Prepod_add->removeOne(ui->listWidget->item(ui->listWidget->currentRow())->text());
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    set.Set_Setting_List_Prepod(*List_Prepod_add);

    emit signals_add_teachers(*List_Prepod_add);

    qDebug() << *List_Prepod_add;
}
