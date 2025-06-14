#include "config.h"
#include <cstdio>

int main() {
    // Демонстрация VERSION и TOSTRING
    std::printf("App version: %d (%s)\n",
                VERSION(1, 2, 3),
                TOSTRING(VERSION(1, 2, 3)));

    // Логирование
    LOG("Application started");

    // Проверка через ASSERT
    int x = 5;
    ASSERT(x > 0);   // пройдёт

    x = -1;
    ASSERT(x > 0);   // тут вылетит с сообщением

    return 0;
}
