//#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Translations
    /*QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "gui_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }*/


    /*MainWindow w;
    w.show();*/

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,795,715);
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    // create an item to put into the scene
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();
    //background->setPixmap(QPixmap(":/images/background.jpg"));
    QPixmap playerSkin(":/images/player.png");
    QGraphicsPixmapItem *playerItem = new QGraphicsPixmapItem(playerSkin);
    playerItem->setPos(100, 100);

    scene->addItem(playerItem);


    // add item to the scene
    scene->addItem(background);

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
