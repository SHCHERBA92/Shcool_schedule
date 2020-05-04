#ifndef ADD_SUBJECT_H
#define ADD_SUBJECT_H

#include <QDialog>
#include <QString>

namespace Ui {
class Add_Subject;
}

class Add_Subject : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Subject(QWidget *parent = nullptr);
    ~Add_Subject();
    QString a;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_Subject *ui;

signals:
    void signall_Add(const QString &str);
};

#endif // ADD_SUBJECT_H
