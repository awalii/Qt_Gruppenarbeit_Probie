#include "person.h"

Person::Person() :  QDialog()
{

}
Person::Person(QString p_Gruppe, QString p_VorName, QString p_NachName, QString p_Alter, QString p_WohnOrt, QString p_Geschlecht) :  QDialog()
{
    this->Gruppe = p_Gruppe;
    this->VorName = p_VorName;
    this->NachName = p_NachName;
    this->Alter = p_Alter;
    this->Geschlecht = p_Geschlecht;
    this->WohnOrt = p_WohnOrt;
}

Person::~Person()
{
}

QString Person::getGruppe() const
{
    return Gruppe;
}

QString Person::getVorName() const
{
    return VorName;
}

QString Person::getNachName() const
{
    return NachName;
}

QString Person::getAlter() const
{
    return Alter;
}

QString Person::getGeschlecht() const
{
    return Geschlecht;
}

QString Person::getWohnOrt() const
{
    return WohnOrt;
}

void Person::setAll(QString p_Gruppe, QString p_VorName, QString p_NachName, QString p_Alter, QString p_WohnOrt, QString p_Geschlecht)     //Alle zusammen bearbeiten
{
    this->Gruppe = p_Gruppe;
    this->VorName = p_VorName;
    this->NachName = p_NachName;
    this->Alter = p_Alter;
    this->Geschlecht = p_Geschlecht;
    this->WohnOrt = p_WohnOrt;
}

Person::Person(Person &OrgPerson)
{

    this->Gruppe = OrgPerson.Gruppe;
    this->VorName = OrgPerson.VorName;
    this->NachName = OrgPerson.NachName;
    this->Alter = OrgPerson.Alter;
    this->Geschlecht = OrgPerson.Geschlecht;
    this->WohnOrt = OrgPerson.WohnOrt;



}

Person &Person::operator=(Person &OrgPerson)
{
    this->Gruppe = OrgPerson.Gruppe;
    this->VorName = OrgPerson.VorName;
    this->NachName = OrgPerson.NachName;
    this->Alter = OrgPerson.Alter;
    this->Geschlecht = OrgPerson.Geschlecht;
    this->WohnOrt = OrgPerson.WohnOrt;

    return *this;
}
