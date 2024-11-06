#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Fly.h"
#include "SmartFly.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Fly *fly;  // Муха, змінюється з рівнями
    QLabel *swatter;
    QLabel *gameOverLabel;
    QRect windowArea;  // Область вікна для SmartFly
    int level = 1;     // Поточний рівень
    bool gameOver = false;

    void setupLevel(int level);   // Налаштування для рівнів
    void nextLevel();             // Перехід до наступного рівня
};

#endif
