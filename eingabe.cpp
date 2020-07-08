#include "eingabe.h"
#include "ui_eingabe.h"

Eingabe::Eingabe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Eingabe)
{
    ui->setupUi(this);
}

Eingabe::~Eingabe()
{
    delete ui;
}
