/**************************************************************************
 * Автор: Витвинова А                                                     *
 * Задание:Вычислить таблицу значений скорости v(t)                       *
 * Вариант:1                                                              *
 *                                                                        *
 * Формула:    v = sqrt(g*m/k) * tanh(t * sqrt(g*k/m))                    *
 * Параметры:  m = 75 кг, k = 8 кг/м, g = 9.81 м/с^2                      *
 * Участок 1:  t от 0 до 1 с, шаг 0.25 (цикл do while)                    *
 * Участок 2:  t от 1 до 5 с, шаг 1.0 (цикл while)                        *
 **************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main() {
    // --- Объявление переменных ---
    // Константы задачи
    const double g = 9.81;          // Ускорение свободного падения, м/с^2
    const double mass = 75.0;       // Масса тела, кг
    const double dragCoeff = 8.0;   // Коэффициент сопротивления, кг/м

    // Параметры сетки (аргументы)
    const double firstStep = 0.25;  // Шаг на первом участке
    const double secondStep = 1.0;  // Шаг на втором участке
    const double changePoint = 1.0; // Точка перехода (граница участков)
    const double finish = 5.0;      // Конец второго участка

    // Переменные для расчета
    double argument = 0.0;          // Текущее время t
    double result = 0.0;            // Текущая скорость v
    int stepIndex = 0;              // Индекс шага для вычисления аргумента

    // Предварительный расчет общего множителя для упрощения формулы
    // sqrt(g * m / k)
    const double velocityLimit = sqrt(g * mass / dragCoeff);

    // --- Вывод заголовка таблицы ---
    cout << "Таблица значений v(t)" << endl;
    cout << "---------------------" << endl;
    cout << "   t (c)   |   v (м/с)" << endl;
    cout << "---------------------" << endl;
    cout << fixed << setprecision(3); // Фиксированная точка, 3 знака после запятой

    // --- Первый участок: цикл с постусловием (do while) ---
    // Обрабатывает точки: 0.00, 0.25, 0.50, 0.75, 1.00
    stepIndex = 0;
    do {
        argument = stepIndex * firstStep;

        // Основной расчет
        // tanh - гиперболический тангенс
        result = velocityLimit * tanh(argument * sqrt(g * dragCoeff / mass));

        cout << setw(8) << argument << " | " << setw(8) << result << endl;

        stepIndex++;
    } while (argument < changePoint);

    // --- Второй участок: цикл с предусловием (while) ---
    // Обрабатывает точки: 2.00, 3.00, 4.00, 5.00
    // Важно: начинаем с 2.00, так как 1.00 уже напечатали в первом цикле
    stepIndex = 2; // Пропускаем точку 1.0 (индекс 1), начинаем с индекса 2 (t=2)
    argument = stepIndex * secondStep;

    while (argument <= finish) {
        // Основной расчет
        result = velocityLimit * tanh(argument * sqrt(g * dragCoeff / mass));

        cout << setw(8) << argument << " | " << setw(8) << result << endl;

        stepIndex++;
        argument = stepIndex * secondStep;
    }

    cout << "---------------------" << endl;

    return 0;
}