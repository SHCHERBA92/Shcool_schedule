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
#include <QDate>
#include <QCalendar>

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
    Tables *WidgetTable;

    //Класс для настроек передачи предметов или преаодавателей в таблицу
    Setting *settingSetting;

private slots:
    void on_actionEditSubject_triggered();
    void slotAddSubject(const QStringList &strListSubject);

    void on_actionEdditTeachers_triggered();
    void slotAddTeachers(const QStringList &strListPrepod);

private:
    Ui::MainWindow *ui;

    // Обьекты для списка предметов и преподавателей
    QStringList *ListPredmet;
    QStringList *ListPrepod;

    // метод для внешнего вида MainWindow
    void CreatUi();


};
#endif // MAINWINDOW_H
