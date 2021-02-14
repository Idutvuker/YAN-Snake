# Snake game

## Игра
Тестовое задание — игра змейка. 
Использовал библиотеку SDL2 для создания окна и отрисовки.

Дополнительная фича — в игре присутсвует две змейки одновременно.
Игрок должен успевать управлять обеими змейками.

Если змейка врезается в себя или в другую змейку, то игра останавливается.

### Управление
Стрелки для управления змейкой. Пробел, чтобы сменить змейку.

## Сборка 

```shell
git clone https://github.com/Idutvuker/YAN-Snake.git
cd YAN-Snake

mkdir build
cd build
```

### Linux (g++, make)
```shell
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
```

### Windows
На Windows можно использовать mingw.
```shell
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
mingw32-make
```

Также можно скомпилировать с .sln файл и собрать его в Visual Studio (MSVC):
```shell
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release ..
```

### Запуск
```
./YAN-Snake
```

