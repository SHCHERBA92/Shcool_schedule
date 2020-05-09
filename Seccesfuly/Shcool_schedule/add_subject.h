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
    void on_pushButtonCancel_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();



private:
    Ui::Add_Subject *ui;

    Setting set;    // класс по сохранению настроек

    QStringList *listPredmetadd;

signals:
    void signall_Add_Subject(const QStringList &str_list);
};

#endif // ADD_SUBJECT_H
