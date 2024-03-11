#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <QObject>

class Character: public QObject
{
    Q_OBJECT

private:
    std::string name;
    unsigned int health;
    unsigned int attackPower;
    unsigned int defense;
    QString skin;

public:
    /*
     * Constructor
     * @param n std::string : character name
     * @param h unsigned int : health points
     * @param a unsigned int : attack points
     * @param d unsigned int : defense points
     */
    Character(const std::string& n, unsigned int h, unsigned int a, unsigned int d, QObject *parent = nullptr);

    /*
     * Get character name
     * @return std::string : character name
     */
    const std::string getName() const;

    /*
     * Get character health
     * @return unsigned int : character health
     */
    unsigned int getHealth() const;

    /*
     * Get character attack
     * @return unsigned int : character attack
     */
    unsigned int getAttack() const;

    /*
     * Get character defense
     * @return unsigned int : character defense
     */
    unsigned int getDefense() const;

    /*
     * Get cheracter skin
     * @return QString : character skin
     */
    QString getSkin() const;

    void setSkin(const QString& newSkin);

    /*
     * Display character stats
     */
    void displayStats() const;

    /*
     * Attack another character
     * @param target Character : character to attack
     */
    void attack(Character& target);

signals:
    void skinChanged(const QString& newSkin);
};

#endif // CHARACTER_H
