#include "eingabe.h"
#include "ui_eingabe.h"

Eingabe::Eingabe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Eingabe)
{
    ui->setupUi(this);
}

Eingabe::Eingabe(QString p_Gruppe, QString p_VorName, QString p_NachName, QString p_Alter, QString p_Geschlecht, QString p_WohnOrt)
{
    this->Gruppe = p_Gruppe;
    this->VorName = p_VorName;
    this->NachName = p_NachName;
    this->Alter = p_Alter;
    this->Geschlecht = p_Geschlecht;
    this->WohnOrt = p_WohnOrt;
}

Eingabe::~Eingabe()
{
    delete ui;
}

QString Eingabe::getGruppe() const
{
    return Gruppe;
}

QString Eingabe::getVorName() const
{
    return VorName;
}

QString Eingabe::getNachName() const
{
    return NachName;
}

QString Eingabe::getAlter() const
{
    return Alter;
}

QString Eingabe::getGeschlecht() const
{
    return Geschlecht;
}

QString Eingabe::getWohnOrt() const
{
    return WohnOrt;
}

void Eingabe::setAll(QString p_Gruppe, QString p_VorName, QString p_NachName, QString p_Alter, QString p_WohnOrt, QString p_Geschlecht)     //Alle zusammen bearbeiten
{
    /*this->Gruppe = p_Gruppe;
    this->VorName = p_VorName;
    this->NachName = p_NachName;
    this->Alter = p_Alter;
    this->Geschlecht = p_Geschlecht;
    this->WohnOrt = p_WohnOrt;*/
    this->ui->line_gname->setText(p_Gruppe);
    ui->line_vname->setText(p_VorName);
    ui->line_nname->setText(p_NachName);
    ui->line_alter->setText(p_Alter);
    ui->line_wohn->setText(p_WohnOrt);
    if(p_Geschlecht=="Maennlich")ui->checkBox_m->click();
    else ui->checkBox_w->click();
}

void Eingabe::on_btn_speichern_clicked()
{

    Gruppe = this->ui->line_gname->text();
    VorName = this->ui->line_vname->text();
    NachName = this->ui->line_nname->text();
    Alter = this->ui->line_alter->text();
    if(this->ui->checkBox_m->isChecked())this->Geschlecht="Maennlich";
    else if(this->ui->checkBox_w->isChecked())this->Geschlecht="Weiblich";
    WohnOrt = this->ui->line_wohn->text();


        if(Gruppe.length() > 0 && VorName.length() > 0 && NachName.length() > 0 && Alter.length() > 0 && Geschlecht != ""  && WohnOrt.length() > 0 )
        {
            this->accept();
        }

        else{

            if(Gruppe.length() == 0 ){

                this->ui->lbl_1->setText("FehlerMeldung");
                this->ui->lbl_1->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");               //lbl Show

            }
            if(VorName.length() == 0 ){

                this->ui->lbl_2->setText("FehlerMeldung");
                this->ui->lbl_2->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");
            }

             if (NachName.length() == 0 ){
                 this->ui->lbl_3->setText("FehlerMeldung");
                 this->ui->lbl_3->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");
             }
             if (Alter.length() == 0 ){
                 this->ui->lbl_4->setText("FehlerMeldung");
                 this->ui->lbl_4->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");
             }
             if(WohnOrt.length() == 0 )

             {
                 this->ui->lbl_5->setText("FehlerMeldung");
                 this->ui->lbl_5->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");
             }

             if (Geschlecht == "" ){
                 this->ui->lbl_6->setText("FehlerMeldung");
                 this->ui->lbl_6->setStyleSheet("color: #c8010b ; border: 2px solid black ; font-style:bold");
              }
        }

}

void Eingabe::on_btn_beenden_clicked()
{
    close();
}
