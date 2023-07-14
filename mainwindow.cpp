#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtMath>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    /*ui->lineEdit->setValidator(new QDoubleValidator(0.001, 1000.0, 3));
    ui->lineEdit_2->setValidator(new QDoubleValidator(0.001, 1000.0, 3));
    ui->lineEdit_3->setValidator(new QDoubleValidator(0.001, 1000.0, 3));
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::areaTriangle()
{
    semiperimeter = (sideA + sideB + sideC) / 2;
    area = qSqrt(semiperimeter*(semiperimeter - sideA) * (semiperimeter - sideB) * (semiperimeter - sideC));
    return area;
}

void MainWindow::on_pushButton_clicked()
{
    QString str;
    /*try
    {
        if (areaTriangle() == 0)
        {
            throw wside;
        }
    }
    catch(WrongSide)
    {
        ui->label->setText(wrong.what());
    }
*/
    try
    {
     if (((sideA + sideB) <= sideC) || ((sideB + sideC) <= sideA) || ((sideA + sideC) <= sideB))
     {
            throw WrongSide();
     }
     str.setNum(areaTriangle());
     ui->label->setText(str + " mm2");
    }
    catch(WrongSide wside)
    {
        ui->label->setText(wside.what());
    }
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString str1 = ui->lineEdit->text();
    sideA = str1.toDouble();
    try
    {
        if (sideA <= 0)
        {
            throw WrongNumber();
        }
    }
    catch(WrongNumber wrong)
    {
        ui->label->setText(wrong.what());
    }
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    QString str2 = ui->lineEdit_2->text();
    sideB = str2.toDouble();
    try
    {
        if (sideB <= 0)
        {
            throw WrongNumber();
        }
    }
    catch(WrongNumber &wrong)
    {
        ui->label->setText(wrong.what());
    }
}


void MainWindow::on_lineEdit_3_editingFinished()
{
    QString str3 = ui->lineEdit_3->text();
    sideC = str3.toDouble();
    try
    {
        if (sideC <= 0)
        {
            throw WrongNumber();
        }
    }
    catch(WrongNumber &wrong)
    {
        ui->label->setText(wrong.what());
    }
}

