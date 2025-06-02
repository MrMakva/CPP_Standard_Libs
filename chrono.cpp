/*
? system_clock - Часы, связанные с системным временем (может быть скорректировано пользователем).

#include <iostream>
#include <chrono>

int main() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&now_time_t);
    
    return 0;
}
*/

/*
? steady_clock - Монотонные часы, которые никогда не идут назад (подходят для измерения интервалов).

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto end = std::chrono::steady_clock::now();
    
    auto diff = end - start;
    std::cout << "Elapsed time: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
              << " ms\n";
              
    return 0;
}
*/

/*
? high_resolution_clock - Часы с наивысшим доступным разрешением (может быть алиасом для system_clock или steady_clock).

#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Operation took " << duration.count() << " microseconds\n";
    
    return 0;
}
*/

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

/*
todo Представляет временной интервал.
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

/*
todo Представляет конкретный момент времени.

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    Получение текущего времени
    auto now = std::chrono::system_clock::now();
    
    Добавление интервала к временной точке
    auto in_one_hour = now + std::chrono::hours(1);
    
    Преобразование в time_t для вывода
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto in_one_hour_time_t = std::chrono::system_clock::to_time_t(in_one_hour);
    
    std::cout << "Now: " << std::ctime(&now_time_t);
    std::cout << "In one hour: " << std::ctime(&in_one_hour_time_t);
    
    Разница между временными точками
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto later = std::chrono::system_clock::now();
    auto diff = later - now;
    
    std::cout << "Slept for " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
              << " milliseconds\n";
    return 0;
}
*/

/*
todo Преобразование времени

#include <iostream>
#include <chrono>
#include <iomanip>

int main() {
    Получение текущего времени
    auto now = std::chrono::system_clock::now();
    
    Преобразование в time_t
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    
    Преобразование в локальное время
    auto local_time = *std::localtime(&now_time_t);
    
    Форматированный вывод
    std::cout << "Current time: " 
              << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S") 
              << "\n";
              
    Преобразование из time_t обратно в system_clock::time_point
    auto back_to_time_point = std::chrono::system_clock::from_time_t(now_time_t);
    
    return 0;
}
*/

/*
todo Работа с днями, месяцами и годами (C++20)

#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono;
    
    Создание даты
    auto some_day = year_month_day{year(2023)/month(6)/day(15)};
    std::cout << "Date: " << int(some_day.year()) << "-"
                         << unsigned(some_day.month()) << "-"
                         << unsigned(some_day.day()) << "\n";
    
    Арифметика с датами
    auto next_day = some_day + days(1);
    std::cout << "Next day: " << int(next_day.year()) << "-"
                              << unsigned(next_day.month()) << "-"
                              << unsigned(next_day.day()) << "\n";
    
    Получение текущей даты
    auto today = floor<days>(system_clock::now());
    year_month_day ymd{today};
    std::cout << "Today is: " << ymd << "\n";
    
    return 0;
}
*/

/*
todo Получение времени с начала эпохи

#include <iostream>
#include <chrono>

int main() {
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();
    
    std::cout << "Seconds since epoch: "
              << std::chrono::duration_cast<std::chrono::seconds>(since_epoch).count()
              << "\n";
    std::cout << "Milliseconds since epoch: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch).count()
              << "\n";
    
    return 0;
}
*/

/*
todo Ожидание до определенного времени

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    using namespace std::chrono;
    
    auto now = system_clock::now();
    auto wake_up_time = now + seconds(3);
    
    std::cout << "Current time: " 
              << system_clock::to_time_t(now) << "\n";
    std::cout << "Sleeping until: " 
              << system_clock::to_time_t(wake_up_time) << "\n";
    
    std::this_thread::sleep_until(wake_up_time);
    
    std::cout << "Woke up at: " 
              << system_clock::to_time_t(system_clock::now()) << "\n";
    
    return 0;
}
*/

/*
todo Таймер с использованием steady_clock

#include <chrono>
#include <iostream>
#include <thread>

class Timer {
    using clock = std::chrono::steady_clock;
    clock::time_point start;

public:
    Timer() : start(clock::now()) {}

    void reset() {
        start = clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            clock::now() - start).count() / 1000.0;
    }
};

int main() {
    Timer timer;

    std::this_thread::sleep_for(std::chrono::milliseconds(1234));

    std::cout << "Elapsed time: " << timer.elapsed() << " seconds\n";

    timer.reset();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Elapsed after reset: " << timer.elapsed() << " seconds\n";

    return 0;
}
*/

/*
todo Арифметика с календарными датами (C++20)

#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono;
    
    Создание даты
    auto date = year_month_day{2023_y/June/15};
    std::cout << "Initial date: " << date << "\n";
    
    Добавление месяцев с учетом разного количества дней
    auto next_month = date.year()/date.month()/date.day() + months{1};
    std::cout << "Next month: " << year_month_day{next_month} << "\n";
    
    Вычисление последнего дня месяца
    auto last_day = year_month_day{date.year()/date.month()/last};
    std::cout << "Last day of month: " << last_day << "\n";
    
    Разница между датами
    auto date1 = sys_days{2023_y/June/15};
    auto date2 = sys_days{2023_y/December/31};
    auto diff = date2 - date1;
    std::cout << "Days between: " << diff.count() << "\n";
    
    return 0;
}
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
