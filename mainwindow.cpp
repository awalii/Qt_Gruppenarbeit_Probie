#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "liste.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    close();
}

void MainWindow::on_btn_clear_clicked()
{
    this->ui->lbl_error->clear();
    this->ui->line_name->clear();
    this->ui->line_pass->clear();
}

void MainWindow::on_btn_login_clicked()
{
    QString name = this->ui->line_name->text();
    QString password = this->ui->line_pass->text();

    if(Name == name && Password == password)

    {
        this->ui->lbl_error->clear();
        this->close();

        Liste *newlist = new Liste;
        newlist->exec();

    }else

    {
        this->ui->lbl_error->setText("Sie haben Falsche UserName oder Password eingegeben");
        this->ui->lbl_error->setStyleSheet("color: #c8010b ; font-style:bold");

    }
}


void MainWindow::on_rd_btn_clicked(bool checked)
{
    checked = this->ui->rd_btn->isChecked();

    if(checked == 1){
        this->ui->line_pass->setEchoMode(QLineEdit::Normal);
    }
    else{
        this->ui->line_pass->setEchoMode(QLineEdit::Password);
    }
}
