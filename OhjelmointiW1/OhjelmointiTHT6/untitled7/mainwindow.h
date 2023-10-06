#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //oli kamppailu, nämä jääkööt kommenteiksi
    //nums 1-9+0
   /* void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    //operand etc:
    void on_pushButton_clear_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_subtract_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_equal_clicked();
*/
    void numberClickHandler();
    void operatorClickHandler();
    void clearClickHandler();
    void enterClickHandler();

private:
    Ui::MainWindow *ui;

    QString currentInput;
    QString currentResult;
    QString firstOperand;
    QString currentOperator;

    int state;
    QString operand;
};

#endif // MAINWINDOW_H
