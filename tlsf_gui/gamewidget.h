#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "character.h"

class QPushButton;
class QLabel;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

private slots:
    void playerAttack();

private:
    Character player;
    Character enemy;

    QLabel *playerNameLabel;
    QLabel *enemyNameLabel;
    QLabel *playerHealthLabel;
    QLabel *enemyHealthLabel;
    QPushButton *attackButton;
};

#endif // GAMEWIDGET_H
