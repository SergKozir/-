#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Початкове налаштування першого рівня
    setupLevel(1);

    // Мухобійка
    swatter = new QLabel(this);
    QPixmap swatterImage(":/images/swatter.png");
    swatter->setPixmap(swatterImage.scaled(200, 200));
    swatter->setGeometry(200, 200, 200, 200);

    // Повідомлення про завершення гри
    gameOverLabel = new QLabel(this);
    gameOverLabel->setText("Game Over");
    gameOverLabel->setStyleSheet("QLabel { color : red; font-size: 30px; }");
    gameOverLabel->setGeometry(this->width()/2 - 100, this->height()/2 - 30, 200, 60);
    gameOverLabel->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupLevel(int level) {
    delete fly;  // Видаляємо попередню муху
    if (level == 1) {
        fly = new Fly(this);  // Базова муха
    } else if (level == 2) {
        // Створюємо зону вікна для мухи
        windowArea = QRect(this->width() - 150, 50, 100, 100);
        fly = new SmartFly(this, windowArea);
    }

    fly->show();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (gameOver) return;

    QPoint cursorPos = event->pos();
    QRect flyRect = fly->geometry();
    QRect swatterRect = swatter->geometry();

    if (flyRect.contains(cursorPos)) {
        fly->move(cursorPos);  // Викликаємо рух мухи
    }

    if (flyRect.intersects(swatterRect)) {
        fly->setVisible(false);
        gameOverLabel->setVisible(true);
        gameOver = true;
    }
}

void MainWindow::nextLevel() {
    level++;
    setupLevel(level);
}
