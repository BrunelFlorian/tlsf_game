#include "gamewidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent), player("Player", 100, 10, 5), enemy("Enemy", 100, 8, 3) {

    playerNameLabel = new QLabel("Player: " + QString::fromStdString(player.getName()), this);
    enemyNameLabel = new QLabel("Enemy: " + QString::fromStdString(enemy.getName()), this);
    playerHealthLabel = new QLabel("Player Health: " + QString::number(player.getHealth()), this);
    enemyHealthLabel = new QLabel("Enemy Health: " + QString::number(enemy.getHealth()), this);

    attackButton = new QPushButton("Attack", this);
    connect(attackButton, &QPushButton::clicked, this, &GameWidget::playerAttack);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(playerNameLabel);
    layout->addWidget(playerHealthLabel);
    layout->addWidget(enemyNameLabel);
    layout->addWidget(enemyHealthLabel);
    layout->addWidget(attackButton);

    setLayout(layout);
}

void GameWidget::playerAttack() {
    player.attack(enemy);
    enemyHealthLabel->setText("Enemy Health: " + QString::number(enemy.getHealth()));
    if (enemy.getHealth() <= 0) {
        enemyHealthLabel->setText("Enemy Health: 0");
        attackButton->setEnabled(false);
    }
}
