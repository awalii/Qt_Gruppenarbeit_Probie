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
    ~Eingabe();

private:
    Ui::Eingabe *ui;
};

#endif // EINGABE_H
