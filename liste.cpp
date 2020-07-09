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
    //int row=0;
    QFile file(QFileDialog::getOpenFileName(this,"OpenFile","C:\\export\\Git Perez\\Qt_Gruppenarbeit_Probie","Text File(*.txt)"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->ui->lbl_error2->setText("empty");
        QMessageBox::information(0,"Info","keine");

    }
    else
    {
        QTextStream add(&file);
        QString text=add.readAll();
        for(int i=0;i<text.size();i++)
        {
            this->ui->tbl_w->setItem(0,reihe, new QTableWidgetItem(text.section(",",reihe,reihe)));
            if(text.at(i)==",")
            {
                setreihe();
            }
            //text.remove(QRegExp(" "));
        }
        this->max=this->reihe/6;
        int tmp=0;
        for(int i=0;i<max;i++)
        {

            Gruppe=text.section(",",i+tmp,i+tmp);
            VorName=text.section(",",i+1+tmp,i+1+tmp);
            NachName=text.section(",",i+2+tmp,i+2+tmp);
            Alter=text.section(",",i+3+tmp,i+3+tmp);
            WohnOrt=text.section(",",i+4+tmp,i+4+tmp);
            Geschlecht=text.section(",",i+5+tmp,i+5+tmp);
            tmp+=5;
            Personen[i]=new Person(Gruppe,VorName,NachName,Alter,WohnOrt,Geschlecht);

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

        Personen[max]=new Person(newentry->getGruppe(),newentry->getVorName(),newentry->getNachName(),newentry->getAlter(),newentry->getWohnOrt(),newentry->getGeschlecht());
        this->ui->tbl_w->setItem(max,0, new QTableWidgetItem(newentry->getGruppe()));
        this->ui->tbl_w->setItem(max,1, new QTableWidgetItem(newentry->getVorName()));
        this->ui->tbl_w->setItem(max,2, new QTableWidgetItem(newentry->getNachName()));
        this->ui->tbl_w->setItem(max,3, new QTableWidgetItem(newentry->getAlter()));
        this->ui->tbl_w->setItem(max,4, new QTableWidgetItem(newentry->getWohnOrt()));
        this->ui->tbl_w->setItem(max,5, new QTableWidgetItem(newentry->getGeschlecht()));
        this->max+=1;
    }
}
