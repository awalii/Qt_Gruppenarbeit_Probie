#ifndef LISTE_H
#define LISTE_H

#include <QDialog>

namespace Ui {
class Liste;
}

class Liste : public QDialog
{
    Q_OBJECT

public:
    explicit Liste(QWidget *parent = nullptr);
    ~Liste();

private slots:
    void on_btn_laden_clicked();

private:
    Ui::Liste *ui;
};

#endif // LISTE_H
