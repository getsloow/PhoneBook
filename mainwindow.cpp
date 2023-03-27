#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddb.h"
#include "deletedb.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    ui->setupUi(this);


    QPixmap background("G:/QT6DB/Images/background.png");
    ui->background->setPixmap(background);

    QPixmap pix("G:/QT6DB/Images/logo.png");
    ui->label_pic->setPixmap(pix);
    this->setWindowTitle("Phonebook App by Francovschi Armand");
    this->setFixedSize(QSize(800, 600));

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("agenda_telefon");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(db.open()   ) {

    //    QMessageBox::information(this, "Conectat!", "Conectarea s-a realizat cu succes!");
        ui->test_con->setText("Conectat!");

                }
     else{
   //     QMessageBox::information(this, "Conectare nereusita!", "Conectarea nu s-a putut realiza");
        ui->test_con->setText("Nu s-a putut conecta!");
            }

}


void MainWindow::on_pushButton_2_clicked()
{
    db.open();
    QString nume = "";
    QString numere = "";
    QSqlQuery q;
    q.exec("SELECT * FROM  contacte");

    while (q.next()){
        nume += q.value(0).toString()+ "\n";
        numere += q.value(1).toString()+ "\n";
    }

     ui->textEdit->setText(nume);
     ui->textEdit_2->setText(numere);

     q.clear();
     db.close();
}



void MainWindow::on_pushButton_3_clicked()
{
    AddDB add;
    add.setModal(true);   // no freedom for 1st window
    add.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_5_clicked()
{
    DeleteDB ddb;
    ddb.setModal(true);
    ddb.exec();
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    QPixmap background("G:/QT6DB/Images/background.png");
    QPixmap backgroundNight("G:/QT6DB/Images/background_night.png");

    if(arg1)
        ui->background->setPixmap(backgroundNight);
    else
        ui->background->setPixmap(background);
}

