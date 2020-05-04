#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
 *Класс Tables не получилось реализовать, хадумка была сделать класс таблицы. Что бы этот класс был унаследован от QTableWidget
 * и соответствено создавал экземпляры классы QTableWidget
 *
 *
 */


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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Tables *Widget_Table;

private slots:
    void on_action_2_triggered();

    void slot_add_Subject(const QString &str);
private:
    Ui::MainWindow *ui;

    void Creat_Table(QTableWidget &Tabl);   // Метод для создания таблицы

    //QString sub;

    QStringList *List_Predmet;


};
#endif // MAINWINDOW_H
