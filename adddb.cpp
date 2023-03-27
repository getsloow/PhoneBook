#include "adddb.h"
#include "ui_adddb.h"
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
AddDB::AddDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDB)
{
    ui->setupUi(this);

    this->setFixedSize(QSize(505, 400));
    this->setWindowTitle("Adaugare contact nou");

    QPixmap background2("G:/QT6DB/Images/background.png");
    ui->background2->setPixmap(background2);
}

AddDB::~AddDB()
{
    delete ui;
}

void AddDB::on_pushButton_clicked()
{       db2 = QSqlDatabase::addDatabase("QMYSQL");
        db2.setHostName("127.0.0.1");
        db2.setUserName("root");
        db2.setPassword("");
        db2.setDatabaseName("agenda_telefon");
    db2.open();
    QString nume, numar;
    nume=ui->lineEdit->text();
    numar=ui->lineEdit_2->text();

    QSqlQuery qry;
    qry.prepare("insert into contacte (Nume, Numar) values('"+nume+"','"+numar+"')");


    if(qry.exec())
      {
         QMessageBox::information(this,tr("Stocare cu succes!"),tr("Contactul a fost stocat cu succes! "));
         this->close();
      }
    else
    {
        QMessageBox::critical(this,tr("Stocare esuata!"),qry.lastError().text());
    }
}


void AddDB::on_pushButton_2_clicked()
{
    this->close();
}


void AddDB::on_checkBox_stateChanged(int arg1)
{
    QPixmap background2("G:/QT6DB/Images/background.png");
    QPixmap backgroundNight2("G:/QT6DB/Images/background_night.png");

    if(arg1)
        ui->background2->setPixmap(backgroundNight2);
    else
        ui->background2->setPixmap(background2);
}

