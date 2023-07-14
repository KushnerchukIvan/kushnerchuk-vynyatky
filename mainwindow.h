#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <exception>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class WrongNumber; }
QT_END_NAMESPACE

class WrongNumber
{
public:
    WrongNumber(){};
    QString what(){return err;}
    ~WrongNumber(){};
private:
    QString err = "Помилка! Значення має бути більше 0!";
};

class WrongSide
{
public:
    WrongSide(){};
    QString what(){return err;}
    ~WrongSide(){};
private:
    QString err = "Сума двох сторін має бути більше за третю!";
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

private:
    Ui::MainWindow *ui;
    //WrongNumber wrong;
    //WrongSide wside;
    double sideA;
    double sideB;
    double sideC;
    double semiperimeter;
    double area;
    double areaTriangle();
};
#endif // MAINWINDOW_H














