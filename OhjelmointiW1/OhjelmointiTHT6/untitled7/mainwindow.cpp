#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    state = 1;
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");

   //nums
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(numberClickHandler()));

    //operaattorit
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(operatorClickHandler()));
    connect(ui->pushButton_subtract, SIGNAL(clicked()), this, SLOT(operatorClickHandler()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(operatorClickHandler()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(operatorClickHandler()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(clearClickHandler()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(enterClickHandler()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString buttonText = button->text();
        if (state == 1)
        {
            ui->lineEdit->setText(ui->lineEdit->text() + buttonText);
        }
        else if (state == 2)
        {
            ui->lineEdit_2->setText(ui->lineEdit_2->text() + buttonText);
        }
    }
}

void MainWindow::operatorClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString buttonText = button->text();
        operand = buttonText;
        state = 2;
    }
}

void MainWindow::clearClickHandler()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    state = 1;
    operand.clear();
}

void MainWindow::enterClickHandler()
{
    if (state == 2)
    {
        QString num1Str = ui->lineEdit->text();
        QString num2Str = ui->lineEdit_2->text();

        bool conversionOk;
        float num1 = num1Str.toFloat(&conversionOk);
        if (!conversionOk)
        {
            ui->lineEdit_3->setText("Invalid Input");
            return;
        }

        float num2 = num2Str.toFloat(&conversionOk);
        if (!conversionOk)
        {
            ui->lineEdit_3->setText("Invalid Input");
            return;
        }

        float result = 0.0;
        if (operand == "+")
        {
            result = num1 + num2;
        }
        else if (operand == "-")
        {
            result = num1 - num2;
        }
        else if (operand == "*")
        {
            result = num1 * num2;
        }
        else if (operand == "/")
        {
            if (num2 != 0)
            {
                result = num1 / num2;
            }
            else
            {
                ui->lineEdit_3->setText("Error: Division by zero");
                return;
            }
        }

        ui->lineEdit_3->setText(QString::number(result));
        state = 1;
    }
}
