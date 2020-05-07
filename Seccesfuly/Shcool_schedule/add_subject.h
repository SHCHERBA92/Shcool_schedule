#ifndef ADD_SUBJECT_H
#define ADD_SUBJECT_H

#include <QDialog>
#include <QString>
#include <QStringList>

#include "setting.h"

namespace Ui {
class Add_Subject;
}

class Add_Subject : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Subject(QWidget *parent = nullptr);
    ~Add_Subject();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_Subject *ui;

    Setting set;    // класс по сохранению настроек

    QStringList *List_Predmet_add;

signals:
    void signall_Add(const QStringList &str_list);
};

#endif // ADD_SUBJECT_H
