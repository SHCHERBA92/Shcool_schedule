#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ListPredmet = new QStringList();
    ListPrepod = new QStringList();

    CreatUi();  //метод для визуального оформления MainWindow

    settingSetting = new Setting();
    *ListPredmet = settingSetting->Get_SettingListPredmet();
    *ListPrepod = settingSetting->Get_SettingListPrepod();


    WidgetTable = new Tables();

    /// заполняю таблицу
    WidgetTable->creatMyTable(ui->tableWidgetMonday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetTuesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetWednesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetThursday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetFriday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetSatuday, ListPredmet, ListPrepod);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CreatUi()
{
    this->showMaximized();

    this->setWindowIcon(QIcon(":/new/prefix1/windowTitle.png"));
    ui->labelMonday->setAlignment(Qt::AlignHCenter);
    ui->labelTuesday->setAlignment(Qt::AlignHCenter);
    ui->labelWednesday->setAlignment(Qt::AlignHCenter);
    ui->labelThursday->setAlignment(Qt::AlignHCenter);
    ui->labelFriday->setAlignment(Qt::AlignHCenter);
    ui->labelSaturday->setAlignment(Qt::AlignHCenter);

    *ListPredmet << "Русский Язык"
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


    // По работе с добавление даты по недели
    QDate toDayDate(QDate::currentDate());


    if(toDayDate.dayOfWeek() == 1)  // понедельник
    {
        ui->labelDateMonday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelMonday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateMonday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(1);
        ui->labelDateTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(2);
        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(3);
        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(4);
        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(5);
        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));
    }

    if(toDayDate.dayOfWeek() == 2)  //вторник
    {
        ui->labelDateTuesday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelTuesday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(1);
        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(2);
        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(3);
        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(4);
        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-1);
        ui->labelDateMonday->setText(toDayDate.toString("dd.MM.yyyy"));

    }

    if(toDayDate.dayOfWeek() == 3)  // среда
    {
        ui->labelDateWednsday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelWednesday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(1);
        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(2);
        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(3);
        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-1);
        ui->labelTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-2);
        ui->labelMonday->setText(toDayDate.toString("dd.MM.yyyy"));
    }

    if(toDayDate.dayOfWeek() == 4)  //четверг
    {
        ui->labelDateThursday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelThursday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(1);
        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(2);
        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-1);
        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-2);
        ui->labelDateTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-3);
        ui->labelDateMonday->setText(toDayDate.toString("dd.MM.yyyy"));
    }

    if(toDayDate.dayOfWeek() == 5)  //Пятница
    {
        ui->labelDateFriday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelFriday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(1);
        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-1);
        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-2);
        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-3);
        ui->labelDateTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-4);
        ui->labelDateMonday->setText(toDayDate.toString("dd.MM.yyyy"));
    }

    if(toDayDate.dayOfWeek() == 6)  //Суббота
    {
        ui->labelDateSaturday->setFont(QFont("Times", 12, QFont::Bold));
        ui->labelSaturday->setFont(QFont("Times", 12, QFont::Bold));

        ui->labelDateSaturday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-1);
        ui->labelDateFriday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-2);
        ui->labelDateThursday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-3);
        ui->labelDateWednsday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-4);
        ui->labelDateTuesday->setText(toDayDate.toString("dd.MM.yyyy"));

        toDayDate = QDate::currentDate().addDays(-5);
        ui->labelDateMonday->setText(toDayDate.toString("dd.MM.yyyy"));
    }



}




// вызов слота по добавлению предмета
void MainWindow::on_actionEditSubject_triggered()
{
    Add_Subject *Subject = new Add_Subject();
    Subject->show();
    connect(Subject, &Add_Subject::signall_Add_Subject, this, &MainWindow::slotAddSubject);
}

// вставка предмета в тело таблицы
void MainWindow::slotAddSubject(const QStringList &strListSubject)
{
   *ListPredmet = strListSubject;

    WidgetTable->creatMyTable(ui->tableWidgetMonday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetTuesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetWednesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetThursday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetFriday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetSatuday, ListPredmet, ListPrepod);

}



void MainWindow::on_actionEdditTeachers_triggered()
{
    Add_teacher *Teachers = new Add_teacher();
    Teachers->show();

    connect(Teachers, &Add_teacher::signals_add_teachers, this, &MainWindow::slotAddTeachers);
}

void MainWindow::slotAddTeachers(const QStringList &strListPrepod)
{
    *ListPrepod = strListPrepod;

    WidgetTable->creatMyTable(ui->tableWidgetMonday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetTuesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetWednesday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetThursday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetFriday, ListPredmet, ListPrepod);
    WidgetTable->creatMyTable(ui->tableWidgetSatuday, ListPredmet, ListPrepod);
}
