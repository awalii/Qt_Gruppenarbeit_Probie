#ifndef PERSON_H
#define PERSON_H
#include <QDialog>


class Person : public QDialog
{
public:
    Person();
    Person(QString p_Gruppe,QString p_VorName, QString p_NachName, QString p_Alter ,QString p_WohnOrt ,QString p_Geschlecht);


    ~Person();

        //getter
    QString getGruppe() const;
    QString getVorName() const;
    QString getNachName() const;
    QString getAlter() const;
    QString getGeschlecht() const;
    QString getWohnOrt() const;

        //setter
    void setAll(QString p_Gruppe,QString p_VorName, QString p_NachName, QString p_Alter ,QString p_WohnOrt,QString p_Geschlecht );       //für Alle ändern
    void setGruppe(const QString &p_Gruppe);
    void setVorName(const QString &p_VorName);
    void setNachName(const QString &p_NachName);
    void setAlter(const QString &p_Alter);
    void setGeschlecht(const QString&p_Geschlecht);
    void setWohnOrt(const QString &p_WohnOrt);

         //Copy Konstruktor
    Person(Person& OrgPerson);



         //Zuweisungsoperator-Überladung
    Person& operator=(Person& OrgPerson);


private:

    QString Gruppe;
    QString VorName;
    QString NachName;
    QString Alter;
    QString Geschlecht;
    QString WohnOrt;
};

#endif // PERSON_H
