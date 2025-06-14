#pragma once
/*
 *
 * Создайте заголовок config.h с включением следующих макросов:

    // защиту от повторного включения
    #pragma once

    #include <cstdio>    // для fprintf
    #include <cstdlib>   // для abort
    #include <iostream>  // для std::cerr

    // 1) Версия в одном числе: major*10000 + minor*100 + patch
    #define VERSION(major, minor, patch) \
        (((major) * 10000) + ((minor) * 100) + (patch))

    // 2) Stringification: превращаем токен в строку
    #define TOSTRING_INNER(x) #x
    #define TOSTRING(x)        TOSTRING_INNER(x)

    // 3) Логирование: печать только если определён DEBUG
    #ifdef DEBUG
    #define LOG(fmt, ...) \
      do { \
        std::fprintf(stderr, "[%s:%d] " fmt "\n", \
                     __FILE__, __LINE__, ##__VA_ARGS__); \
      } while (0)
    #else
    #define LOG(fmt, ...) \
      do { } while (0)
    #endif

    // 4) ASSERT: проверка условия, иначе сообщение и abort()
    #define ASSERT(expr) \
      do { \
        if (!(expr)) { \
          std::cerr << "Assertion failed: " #expr \
                    << ", file " << __FILE__ \
                    << ", line " << __LINE__ << std::endl; \
          std::abort(); \
        } \
      } while (0)


    В main():
    Включите config.h:
    Выведите версию приложения и её строковый эквивалент:
    С помощью LOG напечатайте сообщение о старте.
    Продемонстрируйте ASSERT:
    int x = 5;
    ASSERT(x > 0);  // пройдёт
    x = -1;
    ASSERT(x > 0);  // сработает, и программа завершится

    Скомпилируйте с -DDEBUG и без него, сравните вывод.




*/


int main() {}