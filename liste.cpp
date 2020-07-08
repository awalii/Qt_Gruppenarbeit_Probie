#include "liste.h"
#include "ui_liste.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

Liste::Liste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Liste)
{
    ui->setupUi(this);

}

Liste::~Liste()
{
    delete ui;
}

void Liste::on_btn_laden_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"OpenFile","C:\\Users\\10783\\Desktop\\Git\\Qt_Gruppenarbeit_Probie","Text File(*.txt)"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->ui->lbl_error2->setText("empety");
        QMessageBox::information(0,"Info","keine");

    }


    else{


    QTextStream add(&file);


    this->ui->tbl_w->setRowCount(5);
    this->ui->tbl_w->setColumnCount(4);

    this->ui->tbl_w->setCurrentCell(0,0);
    this->ui->tbl_w->setItem(0,0,new QTableWidgetItem(add.readAll()));

    }




    }
