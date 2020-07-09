#include "liste.h"
#include "ui_liste.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include "eingabe.h"
#include <QDialog>
#include "person.h"

Liste::Liste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Liste)
{
    ui->setupUi(this);
    this->ui->tbl_w->setRowCount(10);
    this->ui->tbl_w->setColumnCount(6);

}

Liste::~Liste()
{
    delete ui;
}

void Liste::on_btn_laden_clicked()
{
    int row=0;
    QFile file(QFileDialog::getOpenFileName(this,"OpenFile","C:\\export\\Git Perez\\Qt_Gruppenarbeit_Probie","Text File(*.txt)"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->ui->lbl_error2->setText("empety");
        QMessageBox::information(0,"Info","keine");

    }
    else
    {
        QTextStream add(&file);
        QString text=add.readAll();
        for(int i=0;i<text.size();i++)
        {
            this->ui->tbl_w->setItem(0,row, new QTableWidgetItem(text.section(" ",row,row)));
            if(text.at(i)==" ")row++;
        }
    }
}

void Liste::on_btn_exit2_clicked()
{
    close();
}

void Liste::on_btn_hin_clicked()
{
    Eingabe *newentry= new Eingabe();
    if(newentry->exec()==QDialog::Accepted)
    {
        Personen.setAll(newentry->getGruppe(),newentry->getVorName(),newentry->getNachName(),newentry->getAlter(),newentry->getWohnOrt(),newentry->getGeschlecht());
        this->ui->tbl_w->setItem(reihe,0, new QTableWidgetItem(newentry->getGruppe()));
        this->ui->tbl_w->setItem(reihe,1, new QTableWidgetItem(newentry->getVorName()));
        this->ui->tbl_w->setItem(reihe,2, new QTableWidgetItem(newentry->getNachName()));
        this->ui->tbl_w->setItem(reihe,3, new QTableWidgetItem(newentry->getAlter()));
        this->ui->tbl_w->setItem(reihe,4, new QTableWidgetItem(newentry->getWohnOrt()));
        this->ui->tbl_w->setItem(reihe,5, new QTableWidgetItem(newentry->getGeschlecht()));
    }
}
