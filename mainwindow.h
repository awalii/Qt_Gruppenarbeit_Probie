#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_exit_clicked();

    void on_btn_clear_clicked();

    void on_btn_login_clicked();

    void on_rd_btn_clicked(bool checked);

    void on_btn_reset_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    QString Name = "test";
    QString Password = "123";
    int egg=0;
};
#endif // MAINWINDOW_H
