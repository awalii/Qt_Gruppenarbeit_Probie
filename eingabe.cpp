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

void Eingabe::setAll(QString p_Gruppe, QString p_VorName, QString p_NachName, QString p_Alter, QString p_Geschlecht, QString p_WohnOrt)     //Alle zusammen bearbeiten
{
    this->Gruppe = p_Gruppe;
    this->VorName = p_VorName;
    this->NachName = p_NachName;
    this->Alter = p_Alter;
    this->Geschlecht = p_Geschlecht;
    this->WohnOrt = p_WohnOrt;
}
