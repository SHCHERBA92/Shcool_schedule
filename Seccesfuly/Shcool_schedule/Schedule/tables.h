#ifndef TABLES_H
#define TABLES_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QComboBox>
#include <QCheckBox>
#include <QTime>
#include <QHBoxLayout>

class Tables : public QMainWindow
{
    Q_OBJECT
public:
    explicit Tables(QWidget *parent = nullptr);

    ~Tables();

    QTableWidget *MY_Table(QTableWidget *Table, QString str);

signals:

};

#endif // TABLES_H
