#ifndef DELETEDB_H
#define DELETEDB_H
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

#include <QDialog>

namespace Ui {
class DeleteDB;
}

class DeleteDB : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db3;
    explicit DeleteDB(QWidget *parent = nullptr);
    ~DeleteDB();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::DeleteDB *ui;
};

#endif // DELETEDB_H
