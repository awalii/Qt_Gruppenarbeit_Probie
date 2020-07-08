#ifndef EINGABE_H
#define EINGABE_H

#include <QDialog>

namespace Ui {
class Eingabe;
}

class Eingabe : public QDialog
{
    Q_OBJECT

public:
    explicit Eingabe(QWidget *parent = nullptr);

    Eingabe(QString p_Gruppe,QString p_VorName, QString p_NachName, QString p_Alter,QString p_Geschlecht ,QString p_WohnOrt );


    ~Eingabe();

    QString getGruppe() const;
    QString getVorName() const;
    QString getNachName() const;
    QString getAlter() const;
    QString getGeschlecht() const;
    QString getWohnOrt() const;


    void setAll(QString p_Gruppe,QString p_VorName, QString p_NachName, QString p_Alter,QString p_Geschlecht ,QString p_WohnOrt );       //für Alle ändern
    void setGruppe(const QString &p_Gruppe);
    void setVorName(const QString &p_VorName);
    void setNachName(const QString &p_NachName);
    void setAlter(const QString &p_Alter);
    void setGeschlecht(const QString&p_Geschlecht);
    void setWohnOrt(const QString &p_WohnOrt);


private:
    Ui::Eingabe *ui;

    QString Gruppe ;
    QString VorName;
    QString NachName;
    QString Alter;
    QString Geschlecht;
    QString WohnOrt;
};



#endif // EINGABE_H
