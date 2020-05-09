#include "add_teacher.h"
#include "ui_add_teacher.h"

#include <QDebug>
#include <QMessageBox>

Add_teacher::Add_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_teacher)
{
    ui->setupUi(this);

    // косметика Главного окна
    this->setWindowTitle("Редактор списка преподавателей");
    this->setFixedSize(this->width(), this->height());
    this->setWindowIcon(QIcon(":/new/prefix1/Teacher.png"));

    ui->lineEditAddPrepodavatelei->setToolTip("Поле для ввода преподавателя");
    ui->listWidgetPrepodavatelei->setToolTip("Поле списка преподавателей");


    List_Prepod_add = new QStringList();

    // сохранение листинга
    *List_Prepod_add = set.Get_SettingListPrepod();
    ui->listWidgetPrepodavatelei->addItems(*List_Prepod_add);

    /// косметика кнопок

    ui->pushButtonAdd->setIcon(QIcon(":/new/prefix1/greenPlus.png"));
    ui->pushButtonDelete->setIcon(QIcon(":/new/prefix1/red_minus.png"));    // заменить картинку минуса
    ui->pushButtonCancel->setIcon(QIcon(":/new/prefix1/redCancel.png"));

    ui->pushButtonAdd->setToolTip("Добавить преподавателя в список преподавателей");
    ui->pushButtonCancel->setToolTip("Закрыть редактор");
    ui->pushButtonDelete->setToolTip("Убрать преподавателя из списка преподавателей");

    ui->pushButtonAdd->setToolTipDuration(5000);
    ui->pushButtonAdd->setToolTipDuration(5000);
    ui->pushButtonAdd->setToolTipDuration(5000);

    // слоты для фокуса на кнопки(сделал как смог)
    connect(ui->listWidgetPrepodavatelei, &QListWidget::clicked, this, [=](){
        ui->pushButtonDelete->setFocus(Qt::OtherFocusReason);
    });

    connect(ui->lineEditAddPrepodavatelei, &QLineEdit::editingFinished, this, [this](){
        ui->pushButtonAdd->setFocus();
    });

}

Add_teacher::~Add_teacher()
{
    delete ui;


}


void Add_teacher::on_pushButtonCancel_clicked()
{
    ui->lineEditAddPrepodavatelei->clear();
    this->close();
}

void Add_teacher::on_pushButtonAdd_clicked()
{
    if(ui->lineEditAddPrepodavatelei->text() == "")
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Введите фамилию преподавателя");
    }

    else if(!(List_Prepod_add->filter(ui->lineEditAddPrepodavatelei->text()).isEmpty()))
    {
        QMessageBox::warning(this, "Не корректныый ввод", "Такой преподаватель уже внесён в список");
    }

    else
    {

        List_Prepod_add->append(ui->lineEditAddPrepodavatelei->text());
        set.Set_SettingListPrepod(*List_Prepod_add);

        ui->listWidgetPrepodavatelei->clear();
        ui->listWidgetPrepodavatelei->addItems(*List_Prepod_add);

        emit signals_add_teachers(*List_Prepod_add);

    }
}

void Add_teacher::on_pushButtonDelete_clicked()
{
    if(!(ui->listWidgetPrepodavatelei->isItemSelected(ui->listWidgetPrepodavatelei->currentItem()) ))
    {
        QMessageBox::warning(this, "Не выбран предмет для удаления", "Выберите предмет для удаления");
    }
    else
    {
        List_Prepod_add->removeOne(ui->listWidgetPrepodavatelei->item(ui->listWidgetPrepodavatelei->currentRow())->text());
        ui->listWidgetPrepodavatelei->takeItem(ui->listWidgetPrepodavatelei->currentRow());
        set.Set_SettingListPrepod(*List_Prepod_add);

        emit signals_add_teachers(*List_Prepod_add);
    }
    qDebug() << *List_Prepod_add;
}
