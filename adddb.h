#ifndef ADDDB_H
#define ADDDB_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class AddDB;
}

class AddDB : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db2;
    explicit AddDB(QWidget *parent = nullptr);
    ~AddDB();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::AddDB *ui;
};

#endif // ADDDB_H
