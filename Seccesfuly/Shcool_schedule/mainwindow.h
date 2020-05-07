#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTableView>
#include <QComboBox>
#include <QStringList>
#include <QCheckBox>
#include <QTime>

#include <QDebug>

#include "tables.h"
#include "add_subject.h"
#include "add_teacher.h"
#include "setting.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // Класс для создания таблицы
    Tables *Widget_Table;

    //Класс для настроек передачи предметов или преаодавателей в таблицу
    Setting *setting_setting;

private slots:
    void on_action_2_triggered();
    void slot_add_Subject(const QStringList &str_List_Subject);

    void on_action_3_triggered();
    void slot_add_Teachers(const QStringList &str_List_Prepod);

private:
    Ui::MainWindow *ui;

    void Creat_Table(QTableWidget &Tabl);   // Метод для создания таблицы


    // Обьекты для списка предметов и преподавателей
    QStringList *List_Predmet;
    QStringList *List_Prepod;


};
#endif // MAINWINDOW_H
