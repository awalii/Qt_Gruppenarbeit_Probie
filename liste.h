#ifndef LISTE_H
#define LISTE_H

#include <QDialog>
#include "person.h"

namespace Ui {
class Liste;
}

class Liste : public QDialog
{
    Q_OBJECT

public:
    explicit Liste(QWidget *parent = nullptr);
    ~Liste();

    void setreihe(){this->reihe+=1;}

private slots:
    void on_btn_laden_clicked();

    void on_btn_exit2_clicked();

    void on_btn_hin_clicked();

    void on_btn_loshenAll_clicked();

    void on_btn_loshen_clicked();

private:
    Ui::Liste *ui;
    int reihe=0;
    class Person *Personen[10];
    QString Gruppe;
    QString VorName;
    QString NachName;
    QString Alter;
    QString WohnOrt;
    QString Geschlecht;
    int max=0;
};

#endif // LISTE_H
