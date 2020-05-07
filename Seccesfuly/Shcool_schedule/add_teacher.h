#ifndef ADD_TEACHER_H
#define ADD_TEACHER_H

#include <QDialog>
#include <QString>
#include <QStringList>

#include "setting.h"

namespace Ui {
class Add_teacher;
}

class Add_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Add_teacher(QWidget *parent = nullptr);
    ~Add_teacher();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Add_teacher *ui;

    Setting set;    // класс по сохранению настроек

    QStringList *List_Prepod_add;
signals:
    void signals_add_teachers(const QStringList &str_list);
};

#endif // ADD_TEACHER_H
