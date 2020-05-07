#include "add_subject.h"
#include "ui_add_subject.h"

#include <QDebug>
#include <QMessageBox>

Add_Subject::Add_Subject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Subject)
{
    ui->setupUi(this);

    List_Predmet_add = new QStringList();
//    *List_Predmet_add << "Русский Язык"
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

    *List_Predmet_add = set.Get_Setting_List_Predmet();
    ui->listWidget->addItems(*List_Predmet_add);

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
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Введите название предмета");
    }

    else if(!(List_Predmet_add->filter(ui->lineEdit->text()).isEmpty()))
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Такой предмет уже существует");
    }
    /////////

    else
    {
        List_Predmet_add->append(ui->lineEdit->text());
        set.Set_Setting_List_Predmet(*List_Predmet_add);

        ui->listWidget->clear();
        ui->listWidget->addItems(*List_Predmet_add);

        emit signall_Add(*List_Predmet_add);
    }

}

void Add_Subject::on_pushButton_clicked()
{
    List_Predmet_add->removeOne(ui->listWidget->item(ui->listWidget->currentRow())->text());
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    set.Set_Setting_List_Predmet(*List_Predmet_add);

    emit signall_Add(*List_Predmet_add);

    qDebug() << *List_Predmet_add;
}
