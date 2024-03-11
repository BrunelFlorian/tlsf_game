# tlsf_game
The Legend of Segmentation Fault: A C Tale

## Description
In "The Legend of Segmentation Fault," you play as a brave adventurer on a quest to defeat the SegFault Evil and restore peace to the land. As you journey through treacherous forests, dark caves, and ancient ruins, you'll encounter a variety of enemies, allies, and items that will help or hinder you on your quest.

Your character is a skilled fighter with a variety of weapons and armor at their disposal. You'll start with a basic sword and shield, but as you progress through the game, you'll find more powerful weapons and armor to help you take on tougher enemies. You'll also need to manage your health and mana carefully, using potions and other items to heal yourself and restore your mana.

Along the way, you'll encounter a variety of enemies, from goblins and orcs to the dreaded SegFault Evil himself. Each enemy has its own strengths and weaknesses, and you'll need to use your skills and strategy to defeat them. You'll also meet helpful allies who will give you gifts and offer you advice on your journey.

The game features turn-based combat, with each turn determined randomly. You'll need to use your weapons and armor effectively to defeat your enemies and emerge victorious. And with a variety of items to find and use, you'll have plenty of opportunities to customize your character and play style.

Can you defeat SegFault Evil and restore peace to the land? The fate of the world is in your hands in "The Legend of Segmentation Fault!"

## Structure
```
.
tlsf_game/
│
├── bin/
│   └── main
│
├── build/
│   ├── BusinessLogicLayer/
│   │   ├── GameManager.o
│   │   └── FightManager.o
│   │
│   ├── DataLayer/
│   │   ├── Character.o
│   │   ├── Player.o
│   │   ├── Enemy.o
│   │   ├── Ally.o
│   │   ├── Item.o
│   │   ├── Potion.o
│   │   ├── Weapon.o
│   │   ├── Armor.o
│   │   ├── ItemType.o
│   │   └── DataHandler.o
│   │
│   └── PresentationLayer/
│       ├── CLI.o
│       ├── MusicPlayer.o
│       └── GUI.o (developed later)
│
├── include/
│   ├── BusinessLogicLayer/
│   │   ├── GameManager.h
│   │   └── FightManager.h
│   │
│   ├── DataLayer/
│   │   ├── Character.h
│   │   ├── Player.h
│   │   ├── Enemy.h
│   │   ├── Ally.h
│   │   ├── Item.h
│   │   ├── Potion.h
│   │   ├── Weapon.h
│   │   ├── Armor.h
│   │   ├── ItemType.h
│   │   └── DataHandler.h
│   │
│   └── PresentationLayer/
│       ├── CLI.h
│       ├── MusicPlayer.h
│       └── GUI.h (developed later)
│
└── src/
    ├── BusinessLogicLayer/
    │   ├── GameManager.cpp
    │   └── FightManager.cpp
    │
    ├── DataLayer/
    │   ├── Character.cpp
    │   ├── Player.cpp
    │   ├── Enemy.cpp
    │   ├── Ally.cpp
    │   ├── Item.cpp
    │   ├── Potion.cpp
    │   ├── Weapon.cpp
    │   ├── Armor.cpp
    │   ├── ItemType.cpp
    │   └── DataHandler.cpp
    │
    └── PresentationLayer/
    │   ├── CLI.cpp
    │   ├── MusicPlayer.cpp
    │   └── GUI.cpp (developed later)
    │
    └── main.cpp
```

## Language
* [C++](https://devdocs.io/cpp/)

## Prerequisites
* [GCC](https://gcc.gnu.org/) - GNU Compiler Collection
* [Make](https://www.gnu.org/software/make/) - GNU Make

## Installation
### Update package list
```
sudo apt-get update
```

### Install SDL2 (IMPORTANT)
```
sudo apt-get install libsdl2-dev libsdl2-mixer-dev
```

### Install GCC
```
sudo apt-get install gcc
```

### Install Make
```
sudo apt-get install make
```

## Build project
```
make clean && make && ./bin/main
```

## Launch project
```
./bin/main
```

## Clean project
```
make clean
```

## Author
**Florian Brunel**

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
