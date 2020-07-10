#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "liste.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->lbl_easter->hide();
    this->ui->btn_reset->hide();
    this->ui->lbl_combi->hide();
    this->ui->pushButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    if(egg==2)
    {
        this->ui->pushButton->hide();
        this->ui->lbl_easter->show();
        this->ui->btn_reset->show();
    }
    else close();
}

void MainWindow::on_btn_clear_clicked()
{
    if(egg==1)egg+=1;
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

        this->ui->lbl_error->setText("EINGABE FALSCH!");
        this->ui->lbl_error->setStyleSheet("color: #c8010b ; font-style:bold");
        egg=1;
    }
}


void MainWindow::on_rd_btn_clicked(bool checked)
{
    checked = this->ui->rd_btn->isChecked();

    if(checked == 1){
        this->ui->line_pass->setEchoMode(QLineEdit::Normal);
        this->ui->pushButton->show();
    }
    else{
        this->ui->line_pass->setEchoMode(QLineEdit::Password);
        this->ui->pushButton->hide();
    }
}


void MainWindow::on_btn_reset_clicked()
{
    this->ui->lbl_easter->hide();
    this->ui->btn_reset->hide();
    this->egg=0;
}

void MainWindow::on_pushButton_pressed()
{
    this->ui->lbl_combi->show();
    this->ui->lbl_combi->setText("LEFT,RIGHT,MIDDLE");
}

void MainWindow::on_pushButton_released()
{
    this->ui->lbl_combi->hide();
}
