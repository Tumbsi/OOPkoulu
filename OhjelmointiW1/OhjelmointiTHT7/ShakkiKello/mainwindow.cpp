#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer1ProgressBar()));
    playtimeSeconds = 0;
    player1TimeRemaining = 0;
    player2TimeRemaining = 0;

    status = "Select playtime and start game!";
    statusLabel = new QLabel(status, this);
   // setCentralWidget(statusLabel);

    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->stopGameButton, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->sec120Button, &QPushButton::clicked, this, &MainWindow::setPlaytime120Sec);
    connect(ui->min5Button, &QPushButton::clicked, this, &MainWindow::setPlaytime5Min);
    connect(ui->switch1Button, &QPushButton::clicked, this, &MainWindow::switchToPlayer1);
    connect(ui->switch2Button, &QPushButton::clicked, this, &MainWindow::switchToPlayer2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{

    if (playtimeSeconds > 0)
    {
        player1TimeRemaining = playtimeSeconds;
        player2TimeRemaining = playtimeSeconds;
        ui->progressBar1->setValue(0);
        ui->progressBar2->setValue(0);
        timer->start(1000);
        status = "Ready to play";
        statusLabel->setText(status);
    }
}

void MainWindow::stopGame()
{

    timer->stop();
    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
    playtimeSeconds = 0;
    player1TimeRemaining = 0;
    player2TimeRemaining = 0;
    status = "New game via start button";
    statusLabel->setText(status);
}
void MainWindow::playerWon(int player)
{
    status = QString("Player %1 WON!").arg(player);
    statusLabel->setText(status);
}

void MainWindow::setPlaytime120Sec()
{
    playtimeSeconds = 120;
}

void MainWindow::setPlaytime5Min()
{
    playtimeSeconds = 300;
}

void MainWindow::switchToPlayer1()
{

    timer->stop();
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer1ProgressBar()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer2ProgressBar()));
}

void MainWindow::switchToPlayer2()
{

    timer->stop();
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer2ProgressBar()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer1ProgressBar()));
}

void MainWindow::updatePlayer1ProgressBar()
{
    if (player1TimeRemaining > 0)
    {
        player1TimeRemaining--;
        ui->progressBar1->setValue((playtimeSeconds - player1TimeRemaining) * 100 / playtimeSeconds);
        status = "Game ongoing";
        statusLabel->setText(status);
    }
    else
    {

        playerWon(1);
        timer->stop();
    }
}

void MainWindow::updatePlayer2ProgressBar()
{
    if (player2TimeRemaining > 0)
    {
        player2TimeRemaining--;
        ui->progressBar2->setValue((playtimeSeconds - player2TimeRemaining) * 100 / playtimeSeconds);
        status = "Game ongoing";
        statusLabel->setText(status);
    }
    else
    {

        timer->stop();
        playerWon(2);
    }
}
