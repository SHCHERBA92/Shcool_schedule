#include "add_subject.h"
#include "ui_add_subject.h"

#include <QDebug>
#include <QMessageBox>

Add_Subject::Add_Subject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Subject)
{
    ui->setupUi(this);

    // косметика Главного окна
    this->setWindowTitle("Редактор списка предметов");
    this->setFixedSize(this->width(), this->height());
    this->setWindowIcon(QIcon(":/new/prefix1/backpack.png"));

    ui->lineEditAddPredmet->setToolTip("Поле для ввода преподавателя");
    ui->listWidgetSpisokPredmetov->setToolTip("Поле списка преподавателей");

    listPredmetadd = new QStringList();


    ///  сохранение Листинга
    *listPredmetadd = set.Get_SettingListPredmet();
    ui->listWidgetSpisokPredmetov->addItems(*listPredmetadd);

    /// косметика кнопок

    ui->pushButtonAdd->setIcon(QIcon(":/new/prefix1/greenPlus.png"));
    ui->pushButtonDelete->setIcon(QIcon(":/new/prefix1/red_minus.png"));    // заменить картинку минуса
    ui->pushButtonCancel->setIcon(QIcon(":/new/prefix1/redCancel.png"));

    ui->pushButtonAdd->setToolTip("Добавить преподавателя в список преподавателей");
    ui->pushButtonCancel->setToolTip("Закрыть редакктор");
    ui->pushButtonDelete->setToolTip("Убрать преподавателя из списка преподавателей");

    ui->pushButtonAdd->setToolTipDuration(5000);
    ui->pushButtonAdd->setToolTipDuration(5000);
    ui->pushButtonAdd->setToolTipDuration(5000);

    // слоты для фокуса на кнопки(сделал как смог)

    connect(ui->listWidgetSpisokPredmetov, &QListWidget::clicked, this, [=](){
        ui->pushButtonDelete->setFocus(Qt::OtherFocusReason);
    });

    connect(ui->lineEditAddPredmet, &QLineEdit::editingFinished, this, [this](){
        ui->pushButtonAdd->setFocus();
    });

}

Add_Subject::~Add_Subject()
{
    delete ui;
}

void Add_Subject::on_pushButtonCancel_clicked()
{
    ui->lineEditAddPredmet->clear();
    this->close();
}

void Add_Subject::on_pushButtonAdd_clicked()
{
    if(ui->lineEditAddPredmet->text() == "")
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Введите название предмета");
    }

    else if(!(listPredmetadd->filter(ui->lineEditAddPredmet->text()).isEmpty()))
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Такой предмет уже существует");
    }
    /////////

    else
    {
        listPredmetadd->append(ui->lineEditAddPredmet->text());
        set.Set_SettingListPredmet(*listPredmetadd);

        ui->listWidgetSpisokPredmetov->clear();
        ui->listWidgetSpisokPredmetov->addItems(*listPredmetadd);

        emit signall_Add_Subject(*listPredmetadd);
    }

}

void Add_Subject::on_pushButtonDelete_clicked()
{
    if(!(ui->listWidgetSpisokPredmetov->isItemSelected(ui->listWidgetSpisokPredmetov->currentItem()) ))
    {
        QMessageBox::warning(this, "Не выбран предмет для удаления", "Выберите предмет для удаления");
    }
    else
    {
        listPredmetadd->removeOne(ui->listWidgetSpisokPredmetov->item(ui->listWidgetSpisokPredmetov->currentRow())->text());
        ui->listWidgetSpisokPredmetov->takeItem(ui->listWidgetSpisokPredmetov->currentRow());
        set.Set_SettingListPredmet(*listPredmetadd);
        emit signall_Add_Subject(*listPredmetadd);
    }




    qDebug() << *listPredmetadd;
}
