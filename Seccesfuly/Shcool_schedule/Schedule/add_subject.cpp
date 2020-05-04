#include "add_subject.h"
#include "ui_add_subject.h"

Add_Subject::Add_Subject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Subject)
{
    ui->setupUi(this);

}

Add_Subject::~Add_Subject()
{
    delete ui;
}

void Add_Subject::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    this->close();
}

void Add_Subject::on_pushButton_2_clicked()
{
    emit signall_Add(ui->lineEdit->text());
    this->close();

}
