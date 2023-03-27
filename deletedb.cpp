#include "deletedb.h"
#include "ui_deletedb.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>

DeleteDB::DeleteDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDB)
{
    ui->setupUi(this);


    this->setFixedSize(QSize(505, 400));
    this->setWindowTitle("Stergerea unui contact");

    QPixmap background2("G:/QT6DB/Images/background.png");
    ui->background2->setPixmap(background2);
}

DeleteDB::~DeleteDB()
{
    delete ui;
}

void DeleteDB::on_pushButton_clicked()
{
        db3 = QSqlDatabase::addDatabase("QMYSQL");
           db3.setHostName("127.0.0.1");
           db3.setUserName("root");
           db3.setPassword("");
           db3.setDatabaseName("agenda_telefon");
       db3.open();

       QString nume;
       nume=ui->lineEdit->text();
       QSqlQuery qry;
       qry.prepare("Delete from contacte where Nume='"+nume+"'");

       if(qry.exec())
       {
           QMessageBox::information(this,tr("Stergere"),tr("Sters cu succes!"));
           this->close();
       }
       else
       {
           QMessageBox::information(this,tr("Stergere"),qry.lastError().text());
       }
}


void DeleteDB::on_pushButton_2_clicked()
{

    this->close();
}


void DeleteDB::on_checkBox_stateChanged(int arg1)
{
    QPixmap background2("G:/QT6DB/Images/background.png");
    QPixmap backgroundNight2("G:/QT6DB/Images/background_night.png");

    if(arg1)
        ui->background2->setPixmap(backgroundNight2);
    else
        ui->background2->setPixmap(background2);

}

