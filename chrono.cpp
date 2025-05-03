// std::chrono::system_clock – системное время (может корректироваться).
// std::chrono::steady_clock – монотонное время (гарантированно не уменьшается).
// std::chrono::high_resolution_clock – максимально точные тики (зависит от реализации).

/*
    перевод из одной единицы измерения в другую
    duration_cast<milliseconds>(n);
*/

// nanoseconds ns;  // наносекунды
// microseconds us; // микросекунды
// milliseconds ms; // миллисекунды
// seconds s;       // секунды
// minutes min;     // минуты
// hours h;         // часы

/*
int main() {
    Текущее время с использованием system_clock
    auto now_system = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now_system);
    std::cout << "System time: " << std::ctime(&now_time);

    Текущее время с использованием steady_clock
    auto now_steady = std::chrono::steady_clock::now();
    std::cout << "Steady clock time (since epoch): " 
              << now_steady.time_since_epoch().count() << " ticks\n";

    return 0;
}
*/

/*
int main() {
    Создание длительности
    auto sec = std::chrono::seconds(2);
    auto ms = std::chrono::milliseconds(500);

    Сложение длительностей
    auto total = sec + ms;
    std::cout << "Total duration: " << total.count() << " milliseconds\n";

    Задержка на 1.5 секунды
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    return 0;
}
*/

/*  Также время можно использовать для арифметики
    auto time_sum = 1h + 30min; 1.5 часа 
*/

/* Выводит время в формате std::format("{:%Y-%m-%d %H:%M:%S}", now)
    например: 2025-04-07 14:30:45
    Работает только в C++20
*/

/*
Используйте this_thread::sleep_for когда:

    Нужна простая задержка на определенное время.
    Важна независимость от изменений системного времени.
    Измеряете производительность или делаете анимации.

Используйте this_thread::sleep_until когда:

    Нужно пробудиться в конкретное время (например, в 12:00:00).
    Работаете с расписаниями и таймерами.
    Синхронизируетесь с внешними событиями по времени.
    Например: auto wake_time = std::chrono::system_clock::now() + std::chrono::seconds(5);
*/

#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;


int main()
{
    auto system = system_clock::now();
    time_t convert = system_clock::to_time_t(system);
    cout<<"Системное время: "<< ctime(&convert);

    auto steady_start = steady_clock::now();
    for(int i=100000;i>0;i--)
    for(int j=0;j<10000;j++);
    auto steady_end = steady_clock::now();
    auto sum = duration_cast<milliseconds>(steady_end - steady_start);
    cout << "Монотонное время: " << sum.count()<<'\n';

    auto highs = high_resolution_clock::now();
    for (int i = 100000; i > 0; i--)
    for (int j = 0; j < 10000; j++);
    auto highe = high_resolution_clock::now();
    auto sumh = duration_cast<nanoseconds> (highe - highs);
    cout<< "Точные тики : "<< sumh.count()<<'\n';

    auto sums=duration_cast<seconds>(sumh);
    cout << "Точные тики (Преобразованные в секунды): "<< sums.count() << '\n';

    auto stimestd = steady_clock::now();
    this_thread::sleep_for(seconds(5));
    auto etimestd = steady_clock::now();
    auto timesum = duration_cast<seconds>(etimestd-stimestd);
    cout<< "Сон продлился: "<<timesum.count()<<"(Должен был длиться 5 секунд)"<<'\n';
}
