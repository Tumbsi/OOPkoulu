// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>
#include <QLabel>

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
    void startGame();
    void stopGame();
    void setPlaytime120Sec();
    void setPlaytime5Min();
    void switchToPlayer1();
    void switchToPlayer2();
    void updatePlayer1ProgressBar();
    void updatePlayer2ProgressBar();
    void playerWon(int player);

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int playtimeSeconds;
    int player1TimeRemaining;
    int player2TimeRemaining;
    QLabel* statusLabel;
    QString status;
};

#endif // MAINWINDOW_H
